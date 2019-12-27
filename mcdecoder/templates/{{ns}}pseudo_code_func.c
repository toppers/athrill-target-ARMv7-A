#include "arm_pseudo_code_func.h"

{% for inst in machine_decoder.extras.pseudo_codes -%}
int arm_op_exec_{{inst.name}}(struct TargetCore *core,  {{ inst.name }}_input_type *in, {{ inst.name }}_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
{% endfor -%}

