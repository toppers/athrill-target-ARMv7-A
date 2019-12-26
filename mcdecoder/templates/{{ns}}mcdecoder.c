#include "{{ ns }}mcdecoder.h"

typedef struct {
    {{ ns }}uint16 *code;
    {{ ns }}OpDecodedCodeType *decoded_code;
    {{ ns }}OperationCodeType *optype;
    {{ ns }}uint16 code16;
    {{ ns }}uint32 code32;
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

/* individual op parse functions */
{% for inst in instruction_decoders %}
    /* {{ inst.name }} */
    static int op_parse_{{ inst.name }}(OpDecodeContext *context) {
        if ((context->code{{ inst.type_bit_size }} & OP_FB_MASK_{{ inst.name }}) != OP_FB_{{ inst.name }}) {
            return 1;
        }

        context->optype->code_id = {{ ns }}OpCodeId_{{ inst.name }};
        context->optype->format_id = {{ ns }}OP_CODE_FORMAT_{{ inst.name }};
        context->decoded_code->type_id = {{ ns }}OP_CODE_FORMAT_{{ inst.name }};
        {% for field in inst.field_decoders %}
            context->decoded_code->code.{{ inst.name }}.{{ field.name }} =
            {% for sf in field.subfield_decoders %}
                {% if not loop.first %}| {% endif %}(((context->code{{ inst.type_bit_size }} & OP_SF_MASK_{{ inst.name }}_{{ field.name }}_{{ sf.index }}) >> OP_SF_EBII_{{ inst.name }}_{{ field.name }}_{{ sf.index }}) << OP_SF_EBIF_{{ inst.name }}_{{ field.name }}_{{ sf.index }}){% if loop.last %};{% endif %}
            {% endfor %}
        {% endfor %}

        {% if inst.conditions %}
            if (!(
                {% for cond in inst.conditions %}
                    {%- if not loop.first %} && {% endif -%}
                    {%- if cond.type == 'equality' -%}
                        context->decoded_code->code.{{ inst.name }}.{{ cond.field }} {{ cond.operator }} {{ cond.value }}
                    {%- elif cond.type == 'in_range' -%}
                        context->decoded_code->code.{{ inst.name }}.{{ cond.field }} >= {{ cond.value_start }} && context->decoded_code->code.{{ inst.name }}.{{ cond.field }} <= {{ cond.value_end }}
                    {%- endif %}
                {% endfor %}
            )) {
                return 1;
            }
        {% endif %}
        return 0;
    }
{% endfor %}

/* op parse function */
int {{ ns }}op_parse({{ ns }}uint16 code[{{ ns }}OP_DECODE_MAX], {{ ns }}OpDecodedCodeType *decoded_code, {{ ns }}OperationCodeType *optype) {
    OpDecodeContext context;
    context.code = &code[0];
    context.decoded_code = decoded_code;
    context.optype = optype;
    context.code16 = ({{ ns }}uint16) code[0];
    context.code32 = *(({{ ns }}uint32 *) &code[0]);

    {% for inst in instruction_decoders %}
        if (op_parse_{{ inst.name }}(&context) == 0) {
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
