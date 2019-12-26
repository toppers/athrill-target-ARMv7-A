#ifndef _{{ ns }}MC_DECODER_H_
#define _{{ ns }}MC_DECODER_H_

#include <stdint.h>

typedef uint8_t {{ ns }}uint8;
typedef uint16_t {{ ns }}uint16;
typedef uint32_t {{ ns }}uint32;

#define {{ ns }}OP_CODE_FORMAT_NUM	{{ ns }}OP_CODE_FORMAT_UNKNOWN

typedef enum {
	{% for inst in instruction_decoders %}
		{{ ns }}OP_CODE_FORMAT_{{ inst.name }},
	{% endfor %}
	{{ ns }}OP_CODE_FORMAT_UNKNOWN,
} {{ ns }}OpCodeFormatId;

typedef enum {
	{% for inst in instruction_decoders %}
		{{ ns }}OpCodeId_{{ inst.name }},
	{% endfor %}
	{{ ns }}OpCodeId_Num,
} {{ ns }}OpCodeId;

typedef struct {
	{{ ns }}OpCodeFormatId	format_id;
	{{ ns }}OpCodeId		code_id;
} {{ ns }}OperationCodeType;


{% for inst in instruction_decoders %}
typedef struct {
	{% for field in inst.field_decoders %}
		{{ ns }}uint{{ field.type_bit_size }} {{ field.name }};	/* {% for sf in field.subfield_decoders %}{{ sf.start_bit_in_instruction }}-{{ sf.end_bit_in_instruction }}{% if not loop.last %}, {% endif %}{% endfor %} */
	{% endfor %}
} {{ ns }}OpCodeFormatType_{{ inst.name }};
{% endfor %}

typedef struct {
	{{ ns }}OpCodeFormatId type_id;
    union {
		{% for inst in instruction_decoders %}
        	{{ ns }}OpCodeFormatType_{{ inst.name }} {{ inst.name }};
		{% endfor %}
    } code;
} {{ ns }}OpDecodedCodeType;

#define {{ ns }}OP_DECODE_MAX	(3)

extern int {{ ns }}op_parse({{ ns }}uint16 code[{{ ns }}OP_DECODE_MAX], {{ ns }}OpDecodedCodeType *decoded_code, {{ ns }}OperationCodeType *optype);

struct TargetCore;
typedef struct {
	int clocks;
	int (*exec) (struct TargetCore *cpu);
} {{ ns }}OpExecType;
extern {{ ns }}OpExecType {{ ns }}op_exec_table[{{ ns }}OpCodeId_Num];

{% for inst in instruction_decoders -%}
extern int {{ ns }}op_exec_{{ inst.name }}(struct TargetCore *core);
{% endfor -%}


#endif /* !_{{ ns }}MC_DECODER_H_ */
