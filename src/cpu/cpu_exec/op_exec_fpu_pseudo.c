#include "arm_pseudo_code_func.h"


int arm_op_exec_arm_vadd_freg(struct TargetCore *core,  arm_vadd_freg_input_type *in, arm_vadd_freg_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if (in->dp_operation) {
			//TODO out->Vd.freg.reg.Data64 = FPAdd(core, )
		}
		else {
			//TODO
		}
	}
	out->status = *status;
	return ret;
}
