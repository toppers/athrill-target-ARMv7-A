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


int arm_op_exec_arm_msr_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_msr_imm_a1 *op = &core->decoded_code->code.arm_msr_imm_a1;

	arm_msr_imm_input_type in;
	arm_msr_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MSR";
	in.cond = op->cond;
	in.imm32 = ARMExpandImm(op->imm12, CPU_ISSET_CY(&out.status));
	in.write_nzcvq = ((op->mask & 0x2) == 0x2);
	in.write_g = ((op->mask & 0x1) == 0x1);

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_msr_imm(core, &in, &out);
	DBG_ARM_MSR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}



int arm_op_exec_arm_msr2_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_msr2_imm_a1 *op = &core->decoded_code->code.arm_msr2_imm_a1;

	arm_msr2_imm_input_type in;
	arm_msr2_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MSR2";
	in.cond = op->cond;
	in.imm32 = ARMExpandImm(op->imm12, CPU_ISSET_CY(&out.status));
	in.mask = op->mask;
	in.write_spsr = (op->R == 1);

	out.next_address = core->pc;
	out.passed = FALSE;


	int ret = arm_op_exec_arm_msr2_imm(core, &in, &out);
	DBG_ARM_MSR2_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_mrs_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mrs_a1 *op = &core->decoded_code->code.arm_mrs_a1;

	arm_mrs_input_type in;
	arm_mrs_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MRS";

	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rd);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);

	int ret = arm_op_exec_arm_mrs(core, &in, &out);
	DBG_ARM_MRS(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
