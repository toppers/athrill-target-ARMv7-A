#include "arm_pseudo_code_func.h"

{% for inst in machine_decoder.extras.pseudo_codes -%}
int arm_op_exec_{{inst.name}}(struct TargetCore *core,  {{ inst.name }}_input_type *in, {{ inst.name }}_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
        result = in->Rm.regData;
		cpu_set_reg(core, in->Rd.regId, result);
		if (in->Rd.regId != CpuRegId_PC) {
            ret = 0;
		}
		else {
			ret = ALUWritePC(&out->next_address, status, result);
		}
		out->Rd.regData = result;
	}
	out->status = *status;
	return ret;
}
{% endfor -%}

