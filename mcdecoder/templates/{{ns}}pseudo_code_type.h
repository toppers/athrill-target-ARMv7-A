#ifndef _{{ ns|upper }}PSEUDO_CODE_TYPE_H_
#define _{{ ns|upper }}PSEUDO_CODE_TYPE_H_

#include "cpu_op_types.h"

{% for inst in machine_decoder.extras.pseudo_codes -%}

typedef struct {
	char* instrName;
{% for key, value in inst.inputs.items() %}
	{{value}}	{{key}};
{% endfor -%}
} {{ inst.name }}_input_type;

typedef struct {
	uint32	next_address;
{% for key, value in inst.outputs.items() %}
	{{value}}	{{key}};
{% endfor -%}
	PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} {{ inst.name }}_output_type;

{% endfor -%}


#endif /* !_{{ ns|upper }}PSEUDO_CODE_TYPE_H_ */
