#include "cpu_dec/arm_mcdecoder.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"


int arm_op_exec_arm_bic_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_bic_imm_a1 *op = &core->decoded_code->code.arm_bic_imm_a1;

	arm_bic_imm_input_type in;
	arm_bic_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "BIC";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_bic_imm(core, &in, &out);
	DBG_ARM_BIC_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_orr_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_orr_imm_a1 *op = &core->decoded_code->code.arm_orr_imm_a1;

	arm_orr_imm_input_type in;
	arm_orr_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ORR";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_orr_imm(core, &in, &out);
	DBG_ARM_ORR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
