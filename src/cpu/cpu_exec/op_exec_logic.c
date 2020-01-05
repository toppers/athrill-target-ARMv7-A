#include "cpu_dec/arm_mcdecoder.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"



int arm_op_exec_arm_mov_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mov_imm_a1 *op = &core->decoded_code->code.arm_mov_imm_a1;

	arm_mov_imm_input_type in;
	arm_mov_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MOV";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm_C(op->imm12, CPU_ISSET_CY(cpu_get_status(core)), &out.status_flag.carry);

	int ret = arm_op_exec_arm_mov_imm(core, &in, &out);
	DBG_ARM_MOV_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_lsl_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_lsl_imm_a1 *op = &core->decoded_code->code.arm_lsl_imm_a1;

	arm_lsl_imm_input_type in;
	arm_lsl_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LSL";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	DecodeImmShift(0b00, op->imm5, &in.shift_t, &in.shift_n);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_lsl_imm(core, &in, &out);
	DBG_ARM_LSL_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_lsr_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_lsr_imm_a1 *op = &core->decoded_code->code.arm_lsr_imm_a1;

	arm_lsr_imm_input_type in;
	arm_lsr_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LSR";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	DecodeImmShift(0b01, op->imm5, &in.shift_t, &in.shift_n);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_lsr_imm(core, &in, &out);
	DBG_ARM_LSR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
int arm_op_exec_arm_lsl_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_lsl_reg_a1 *op = &core->decoded_code->code.arm_lsl_reg_a1;

	arm_lsl_reg_input_type in;
	arm_lsl_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LSL";
	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rm);
	OP_SET_REG(core, &in, op, Rn);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_lsl_reg(core, &in, &out);
	DBG_ARM_LSL_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mov_imm_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mov_imm_a2 *op = &core->decoded_code->code.arm_mov_imm_a2;

	arm_mov_imm_input_type in;
	arm_mov_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MOVW";
	in.cond = op->cond;
	in.S = FALSE;
	OP_SET_REG(core, &in, op, Rd);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);
	ZeroExtendArgType zarg[2];
	zarg[0].bitsize = 12U;
	zarg[0].data = op->imm12;
	zarg[1].bitsize = 4U;
	zarg[1].data = op->imm4;
	in.imm32 = ZeroExtendArray(2U, zarg);

	int ret = arm_op_exec_arm_mov_imm(core, &in, &out);
	DBG_ARM_MOV_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mov_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mov_reg_a1 *op = &core->decoded_code->code.arm_mov_reg_a1;

	arm_mov_reg_input_type in;
	arm_mov_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MOV";

	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rm);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);

	
	int ret = arm_op_exec_arm_mov_reg(core, &in, &out);
	DBG_ARM_MOV_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mvn_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mvn_reg_a1 *op = &core->decoded_code->code.arm_mvn_reg_a1;

	arm_mvn_reg_input_type in;
	arm_mvn_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MVN";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rm);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_mvn_reg(core, &in, &out);
	DBG_ARM_MVN_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}



int arm_op_exec_arm_movt_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_movt_a1 *op = &core->decoded_code->code.arm_movt_a1;

	arm_movt_input_type in;
	arm_movt_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MOVT";
	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rd);
	in.imm16 = op->imm16;

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_movt(core, &in, &out);
	DBG_ARM_MOVT(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

