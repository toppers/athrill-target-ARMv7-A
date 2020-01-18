{# Renders the object/subject of a condition #}
{%- macro instruction_condition_object(instruction, object) -%}
    {%- if object.type == 'field' -%}
        {%- if object.element_index is none -%}
            context->decoded_code->code.{{ instruction.name }}.{{ object.field }}
        {%- else -%}
            BIT_ELEMENT(context->decoded_code->code.{{ instruction.name }}.{{ object.field }}, {{ object.element_index }})
        {%- endif -%}
    {%- elif object.type == 'immediate' -%}
        {{ object.value }}
    {%- elif object.type == 'function' -%}
        {{ object.function }}({{ instruction_condition_object(instruction, object.argument) }})
    {%- endif -%}
{%- endmacro -%}

{# Renders a condition recursively #}
{%- macro instruction_condition(instruction, condition) -%}
    {%- if condition.type == 'and' -%}
        {% for child_condition in condition.conditions %}
            {%- if not loop.first %} && {% endif -%}
            ({{ instruction_condition(instruction, child_condition) }})
        {% endfor %}
    {%- elif condition.type == 'or' -%}
        {% for child_condition in condition.conditions %}
            {%- if not loop.first %} || {% endif -%}
            ({{ instruction_condition(instruction, child_condition) }})
        {% endfor %}
    {%- elif condition.type == 'equality' -%}
        {{ instruction_condition_object(instruction, condition.subject) }} {{ condition.operator }} {{ instruction_condition_object(instruction, condition.object) }}
    {%- elif condition.type == 'in' -%}
        {% for value in condition.values %}
            {%- if not loop.first %} || {% endif -%}
            {{ instruction_condition_object(instruction, condition.subject) }} == {{ value }}
        {% endfor %}
    {%- elif condition.type == 'in_range' -%}
        {{ instruction_condition_object(instruction, condition.subject) }} >= {{ condition.value_start }} && {{ instruction_condition_object(instruction, condition.subject) }} <= {{ condition.value_end }}
    {%- endif %}
{%- endmacro -%}

#include "{{ ns }}mcdecoder.h"

#include <stdbool.h>

/* types */

typedef struct {
    {{ ns }}uint16 *code;
    {{ ns }}OpDecodedCodeType *decoded_code;
    {{ ns }}OperationCodeType *optype;
    {{ ns }}uint16 code16x1;
    {{ ns }}uint32 code16x2;
    {{ ns }}uint32 code32x1;
} OpDecodeContext;

/* op constants */
{% for inst in instruction_decoders %}
    /* {{ inst.name }} */
    #define OP_FB_MASK_{{ inst.name }} (0x{{ '%08x'|format(inst.fixed_bits_mask) }}l) /* fixed bits mask */
    #define OP_FB_{{ inst.name }} (0x{{ '%08x'|format(inst.fixed_bits) }}l) /* fixed bits */
    {% for field in inst.field_decoders %}
        {% for sf in field.subfield_decoders %}
            /* {{ sf.index }}th subfield of the field '{{ field.name }}' */
            #define OP_SF_MASK_{{ inst.name }}_{{ field.name }}_{{ sf.index }} (0x{{ '%08x'|format(sf.mask) }}l) /* subfield mask */
            #define OP_SF_EBII_{{ inst.name }}_{{ field.name }}_{{ sf.index }} ({{ sf.end_bit_in_instruction }}) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_{{ inst.name }}_{{ field.name }}_{{ sf.index }} ({{ sf.end_bit_in_field }}) /* subfield end bit position in field */
        {% endfor %}
    {% endfor %}
{% endfor %}

/* macros */
#define BIT_ELEMENT(value, element_index) (((value) & (1 << (element_index))) >> element_index)

/* function declarations */
static {{ ns }}uint32 setbit_count({{ ns }}uint32 value);
{% for tree in mcdecoder.decision_trees %}
    {%- for node in tree.root_node.all_nodes %}
        static int decision_node_code{{ tree.encoding_element_bit_length }}x{{ tree.length_of_encoding_elements }}_{{ node.index }}(OpDecodeContext *context, {{ ns }}uint32 code);
    {%- endfor -%}
{%- endfor %}
{% for inst in instruction_decoders %}
    static int op_parse_{{ inst.name }}(OpDecodeContext *context);
{%- endfor %}

/* functions for conditions */
static {{ ns }}uint32 setbit_count({{ ns }}uint32 value) {
    {{ ns }}uint32 count = 0;
    while (value) {
        count += value & 1;
        value >>= 1;
    }
    return count;
}

/* individual op parse functions */
{% for inst in instruction_decoders %}
    /* {{ inst.name }} */
    static int op_parse_{{ inst.name }}(OpDecodeContext *context) {
        if ((context->code{{ inst.encoding_element_bit_length }}x{{ inst.length_of_encoding_elements }} & OP_FB_MASK_{{ inst.name }}) != OP_FB_{{ inst.name }}) {
            return 1;
        }

        context->optype->code_id = {{ ns }}OpCodeId_{{ inst.name }};
        context->optype->format_id = {{ ns }}OP_CODE_FORMAT_{{ inst.name }};
        context->decoded_code->type_id = {{ ns }}OP_CODE_FORMAT_{{ inst.name }};
        {% for field in inst.field_decoders %}
            context->decoded_code->code.{{ inst.name }}.{{ field.name }} =
            {% for sf in field.subfield_decoders %}
                {% if not loop.first %}| {% endif %}(((context->code{{ inst.encoding_element_bit_length }}x{{ inst.length_of_encoding_elements }} & OP_SF_MASK_{{ inst.name }}_{{ field.name }}_{{ sf.index }}) >> OP_SF_EBII_{{ inst.name }}_{{ field.name }}_{{ sf.index }}) << OP_SF_EBIF_{{ inst.name }}_{{ field.name }}_{{ sf.index }}){% if loop.last %};{% endif %}
            {% endfor %}
        {% endfor %}
        {% if inst.match_condition %}
            if (!(
                {{ instruction_condition(inst, inst.match_condition) }}
            )) {
                return 1;
            }
        {% endif %}
        {% if inst.unmatch_condition %}
            if (
                {{ instruction_condition(inst, inst.unmatch_condition) }}
            ) {
                return 1;
            }
        {% endif %}
        return 0;
    }
{% endfor %}

/* decision node functions */
{% for tree in mcdecoder.decision_trees -%}
    {%- for node in tree.root_node.all_nodes %}
        static int decision_node_code{{ tree.encoding_element_bit_length }}x{{ tree.length_of_encoding_elements }}_{{ node.index }}(OpDecodeContext *context, {{ ns }}uint32 code) {
            {% for inst in node.instructions %}
                if (op_parse_{{ inst.name }}(context) == 0) {
                    return 0;
                }
            {%- endfor %}
            {% if node.fixed_bit_nodes -%}
                switch (code & 0x{{ '%08x'|format(node.mask) }}) {
                    {% for threshold_value, child_node in node.fixed_bit_nodes.items() %}
                        case 0x{{ '%08x'|format(threshold_value) }}:
                            if (decision_node_code{{ tree.encoding_element_bit_length }}x{{ tree.length_of_encoding_elements }}_{{ child_node.index }}(context, code) == 0) {
                                return 0;
                            }
                            break;
                    {%- endfor %}
                }
            {% endif -%}
            {% if node.arbitrary_bit_node %}
                if (decision_node_code{{ tree.encoding_element_bit_length }}x{{ tree.length_of_encoding_elements }}_{{ node.arbitrary_bit_node.index }}(context, code) == 0) {
                    return 0;
                }
            {%- endif %}
            return 1;
        }
    {%- endfor -%}
{%- endfor %}

/* op parse function */
int {{ ns }}op_parse({{ ns }}uint16 code[{{ ns }}OP_DECODE_MAX], {{ ns }}OpDecodedCodeType *decoded_code, {{ ns }}OperationCodeType *optype) {
    {% if machine_decoder.byteorder == 'big' %}
        {{ ns }}uint8 *raw_code = ({{ ns }}uint8 *) &code[0];
        {{ ns }}uint16 word1_16bit = ((({{ ns }}uint16) raw_code[0]) << 8) | (({{ ns }}uint16) raw_code[1]);
        {{ ns }}uint16 word2_16bit = ((({{ ns }}uint16) raw_code[2]) << 8) | (({{ ns }}uint16) raw_code[3]);
    {% endif %}

    OpDecodeContext context;
    context.code = &code[0];
    context.decoded_code = decoded_code;
    context.optype = optype;
    {% if machine_decoder.byteorder == 'little' %}
        context.code16x1 = code[0];
        context.code16x2 = ((({{ ns }}uint32) code[0]) << 16) | (({{ ns }}uint32) code[1]);
        context.code32x1 = *(({{ ns }}uint32 *) &code[0]);
    {% else %}
        context.code16x1 = word1_16bit;
        context.code16x2 = ((({{ ns }}uint32) word1_16bit) << 16) | (({{ ns }}uint32) word2_16bit);
        context.code32x1 = context.code16x2;
    {% endif %}
    {% for tree in mcdecoder.decision_trees -%}
        if (decision_node_code{{ tree.encoding_element_bit_length }}x{{ tree.length_of_encoding_elements }}_{{ tree.root_node.index }}(&context, context.code{{ tree.encoding_element_bit_length }}x{{ tree.length_of_encoding_elements }}) == 0) {
            return 0;
        }
    {% endfor %}
    return 1;
}

{{ ns }}OpExecType {{ ns }}op_exec_table[{{ ns }}OpCodeId_Num] = {
    {% for inst in instruction_decoders %}
	{ 1, {{ ns }}op_exec_{{ inst.name }} },		/* {{ inst.name }} */
    {% endfor %}
};
