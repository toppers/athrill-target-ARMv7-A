#include "cpu_dec/arm_mcdecoder.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"



int arm_op_exec_arm_vadd_freg_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vadd_freg_a2 *op = &core->decoded_code->code.arm_vadd_freg_a2;

	arm_vadd_freg_input_type in;
	arm_vadd_freg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "VADD";
	in.cond = op->cond;
	OP_SET_FREG(&core->coproc.cp11, &in.Vn, op, Vn);
	OP_SET_FREG(&core->coproc.cp11, &in.Vd, op, Vd);
	OP_SET_FREG(&core->coproc.cp11, &in.Vm, op, Vm);

	in.advsimd = FALSE;
	in.dp_operation = (op->sz == 1);

	out.next_address = core->pc;
	out.passed = FALSE;

	OP_SET_FREG(&core->coproc.cp11, &out.Vd, op, Vd);

	int ret = arm_op_exec_arm_vadd_freg(core, &in, &out);
	DBG_ARM_VADD_FREG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
