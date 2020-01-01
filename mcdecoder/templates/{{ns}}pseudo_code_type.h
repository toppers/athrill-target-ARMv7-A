#ifndef _{{ ns|upper }}PSEUDO_CODE_TYPE_H_
#define _{{ ns|upper }}PSEUDO_CODE_TYPE_H_

#include "arm_pseudo_code_common_type.h"

{% for inst in machine_decoder.extras.pseudo_codes -%}

typedef struct {
	char* instrName;
{% for key, value in inst.inputs.items() %}
	{{value}}	{{key}};
{% endfor -%}
} {{ inst.name }}_input_type;

typedef struct {
	uint32	next_address;
{% if inst.outputs is defined %}
{% for key, value in inst.outputs.items() %}
	{{value}}	{{key}};
{% endfor -%}
{% endif -%}
	PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} {{ inst.name }}_output_type;

{% endfor -%}


#endif /* !_{{ ns|upper }}PSEUDO_CODE_TYPE_H_ */
