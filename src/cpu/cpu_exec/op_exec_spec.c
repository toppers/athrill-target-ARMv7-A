#include "cpu_dec/arm_mcdecoder.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"



int arm_op_exec_arm_nop_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_nop_a1 *op = &core->decoded_code->code.arm_nop_a1;

	arm_nop_input_type in;
	arm_nop_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "NOP";
	in.cond = op->cond;

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_nop(core, &in, &out);
	DBG_ARM_NOP(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
