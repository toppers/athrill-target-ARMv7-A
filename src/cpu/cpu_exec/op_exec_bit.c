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

int arm_op_exec_arm_bic_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_bic_reg_a1 *op = &core->decoded_code->code.arm_bic_reg_a1;

	arm_bic_reg_input_type in;
	arm_bic_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "BIC";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rm);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);

	out.next_address = core->pc;
	out.passed = FALSE;

	OP_SET_REG(core, &out, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_bic_reg(core, &in, &out);
	DBG_ARM_BIC_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_bic_shift_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_bic_shift_reg_a1 *op = &core->decoded_code->code.arm_bic_shift_reg_a1;

	arm_bic_shift_reg_input_type in;
	arm_bic_shift_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "BIC";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rs);
	OP_SET_REG(core, &in, op, Rm);

	in.shift_t = DecodeRegShift(op->type);
	in.shift_n =(uint8)cpu_get_reg(core, op->Rs);

	out.next_address = core->pc;
	out.passed = FALSE;


	OP_SET_REG(core, &out, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_bic_shift_reg(core, &in, &out);
	DBG_ARM_BIC_SHIFT_REG(core, &in, &out);

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

int arm_op_exec_arm_eor_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_eor_imm_a1 *op = &core->decoded_code->code.arm_eor_imm_a1;

	arm_eor_imm_input_type in;
	arm_eor_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "EOR";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm_C(op->imm12, out.status_flag.carry, &out.status_flag.carry);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_eor_imm(core, &in, &out);
	DBG_ARM_EOR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_orr_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_orr_reg_a1 *op = &core->decoded_code->code.arm_orr_reg_a1;

	arm_orr_reg_input_type in;
	arm_orr_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ORR";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rm);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);


	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_orr_reg(core, &in, &out);
	DBG_ARM_ORR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_eor_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_eor_reg_a1 *op = &core->decoded_code->code.arm_eor_reg_a1;

	arm_eor_reg_input_type in;
	arm_eor_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "EOR";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rm);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);


	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_eor_reg(core, &in, &out);
	DBG_ARM_EOR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_orr_shift_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_orr_shift_reg_a1 *op = &core->decoded_code->code.arm_orr_shift_reg_a1;

	arm_orr_reg_input_type in;
	arm_orr_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ORR";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rm);
	//shift_t = DecodeRegShift(type);
	in.shift_t = DecodeRegShift(op->type);
	//shift_n = UInt(R[s]<7:0>);
	in.shift_n =(uint8)cpu_get_reg(core, op->Rs);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_orr_reg(core, &in, &out);
	DBG_ARM_ORR_REG(core, &in, &out);

	core->pc = out.next_address;

	return ret;
}

int arm_op_exec_arm_bfc_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_bfc_a1 *op = &core->decoded_code->code.arm_bfc_a1;

	arm_bfc_input_type in;
	arm_bfc_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "BFC";
	in.cond = op->cond;
	in.msbit = op->msb;
	in.lsbit = op->lsb;
	OP_SET_REG(core, &in, op, Rd);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_bfc(core, &in, &out);
	DBG_ARM_BFC(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}



int arm_op_exec_arm_uxtb_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_uxtb_a1 *op = &core->decoded_code->code.arm_uxtb_a1;

	arm_uxt_input_type in;
	arm_uxt_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "UXTB";
	in.size = 1U;
	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rd);
	//rotation = UInt(rotate:’000’);
	in.rotate = (op->rotate << 3U);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);

	int ret = arm_op_exec_arm_uxt(core, &in, &out);
	DBG_ARM_UXT(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_sxtb_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_sxtb_a1 *op = &core->decoded_code->code.arm_sxtb_a1;

	arm_sxtb_input_type in;
	arm_sxtb_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "SXTB";
	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rd);
	in.rotate = (op->rotate << 3U);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);

	int ret = arm_op_exec_arm_sxtb(core, &in, &out);
	DBG_ARM_SXTB(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_sxth_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_sxth_a1 *op = &core->decoded_code->code.arm_sxth_a1;

	arm_sxth_input_type in;
	arm_sxth_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "SXTH";
	in.cond = op->cond;

	OP_SET_REG(core, &in, op, Rd);
	in.rotate = (op->rotate << 3U);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);

	int ret = arm_op_exec_arm_sxth(core, &in, &out);
	DBG_ARM_SXTH(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
int arm_op_exec_arm_uxth_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_uxth_a1 *op = &core->decoded_code->code.arm_uxth_a1;

	arm_uxt_input_type in;
	arm_uxt_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "UXTH";
	in.size = 2U;
	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rd);
	//rotation = UInt(rotate:’000’);
	in.rotate = (op->rotate << 3U);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);

	int ret = arm_op_exec_arm_uxt(core, &in, &out);
	DBG_ARM_UXT(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_and_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_and_imm_a1 *op = &core->decoded_code->code.arm_and_imm_a1;

	arm_and_imm_input_type in;
	arm_and_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "AND";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm_C(op->imm12, CPU_ISSET_CY(cpu_get_status(core)), &out.status_flag.carry);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);

	int ret = arm_op_exec_arm_and_imm(core, &in, &out);
	DBG_ARM_AND_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_and_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_and_reg_a1 *op = &core->decoded_code->code.arm_and_reg_a1;

	arm_and_reg_input_type in;
	arm_and_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "AND";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rm);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_and_reg(core, &in, &out);
	DBG_ARM_AND_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_tst_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_tst_imm_a1 *op = &core->decoded_code->code.arm_tst_imm_a1;

	arm_tst_imm_input_type in;
	arm_tst_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "TST";

	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rn);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm_C(op->imm12, CPU_ISSET_CY(cpu_get_status(core)), &out.status_flag.carry);

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_tst_imm(core, &in, &out);
	DBG_ARM_TST_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_tst_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_tst_reg_a1 *op = &core->decoded_code->code.arm_tst_reg_a1;

	arm_tst_reg_input_type in;
	arm_tst_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "TST";
	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rn);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_tst_reg(core, &in, &out);
	DBG_ARM_TST_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_clz_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_clz_a1 *op = &core->decoded_code->code.arm_clz_a1;

	arm_clz_input_type in;
	arm_clz_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "CLZ";

	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);

	int ret = arm_op_exec_arm_clz(core, &in, &out);
	DBG_ARM_CLZ(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
