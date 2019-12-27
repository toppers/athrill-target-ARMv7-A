#include "arm_pseudo_code_func.h"

int arm_op_exec_arm_add_imm(struct TargetCore *core,  arm_add_imm_input_type *in, arm_add_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
