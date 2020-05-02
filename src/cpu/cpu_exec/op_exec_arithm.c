#include "cpu_dec/arm_mcdecoder.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"


int arm_op_exec_arm_add_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_add_imm_a1 *op = &core->decoded_code->code.arm_add_imm_a1;

	arm_add_imm_input_type in;
	arm_add_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ADD";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	int ret = arm_op_exec_arm_add_imm(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_add_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_add_reg_a1 *op = &core->decoded_code->code.arm_add_reg_a1;

	arm_add_reg_input_type in;
	arm_add_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ADD";
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
	
	int ret = arm_op_exec_arm_add_reg(core, &in, &out);
	DBG_ARM_ADD_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_mla_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mla_a1 *op = &core->decoded_code->code.arm_mla_a1;

	arm_mla_input_type in;
	arm_mla_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MLA";

	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Ra);
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;

	OP_SET_REG(core, &out, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_mla(core, &in, &out);
	DBG_ARM_MLA(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mls_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mls_a1 *op = &core->decoded_code->code.arm_mls_a1;

	arm_mls_input_type in;
	arm_mls_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MLS";
	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Ra);
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;

	OP_SET_REG(core, &out, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_mls(core, &in, &out);
	DBG_ARM_MLS(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_adc_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_adc_imm_a1 *op = &core->decoded_code->code.arm_adc_imm_a1;

	arm_adc_imm_input_type in;
	arm_adc_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ADC";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);

	int ret = arm_op_exec_arm_adc_imm(core, &in, &out);
	DBG_ARM_ADC_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_adc_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_adc_reg_a1 *op = &core->decoded_code->code.arm_adc_reg_a1;

	arm_adc_reg_input_type in;
	arm_adc_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ADC";
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
	
	int ret = arm_op_exec_arm_adc_reg(core, &in, &out);
	DBG_ARM_ADC_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_add_spimm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_add_spimm_a1 *op = &core->decoded_code->code.arm_add_spimm_a1;

	arm_add_spimm_input_type in;
	arm_add_spimm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ADD";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REGID(core, &in, CpuRegId_SP, SP);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);
	
	int ret = arm_op_exec_arm_add_spimm(core, &in, &out);
	DBG_ARM_ADD_SPIMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_adr_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_adr_a1 *op = &core->decoded_code->code.arm_adr_a1;

	arm_adr_imm_input_type in;
	arm_adr_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ADR";
	in.cond = op->cond;
	in.add = TRUE;
	OP_SET_REG(core, &in, op, Rd);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	int ret = arm_op_exec_arm_adr_imm(core, &in, &out);
	DBG_ARM_ADR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_subs_pclr_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_subs_pclr_a1 *op = &core->decoded_code->code.arm_subs_pclr_a1;

	arm_subs_pclr_input_type in;
	arm_subs_pclr_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "SUBS";
	in.cond = op->cond;
	in.opcode = op->opcode;
	in.register_form = FALSE;
	OP_SET_REG(core, &in, op, Rn);
	OP_INIT_REG(core, &in, Rm);
	in.shift_n = -1;
	in.shift_n = -1;

	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	OP_SET_REGID(core, &out, CpuRegId_PC, PC);
	out.next_address = core->pc;
	out.passed = FALSE;
	
	int ret = arm_op_exec_arm_subs_pclr(core, &in, &out);
	DBG_ARM_SUBS_PCLR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_cmp_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_cmp_imm_a1 *op = &core->decoded_code->code.arm_cmp_imm_a1;

	arm_cmp_imm_input_type in;
	arm_cmp_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "CMP";

	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rn);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	out.next_address = core->pc;
	out.passed = FALSE;
	
	int ret = arm_op_exec_arm_cmp_imm(core, &in, &out);
	DBG_ARM_CMP_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_cmn_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_cmn_imm_a1 *op = &core->decoded_code->code.arm_cmn_imm_a1;

	arm_cmn_imm_input_type in;
	arm_cmn_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "CMN";

	in.cond = op->cond;
	in.sign = TRUE;
	OP_SET_REG(core, &in, op, Rn);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	out.result = FALSE;
	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_cmn_imm(core, &in, &out);
	DBG_ARM_CMN_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_cmn_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_cmn_reg_a1 *op = &core->decoded_code->code.arm_cmn_reg_a1;

	arm_cmn_reg_input_type in;
	arm_cmn_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "CMN";
	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rm);
	cpu_conv_status_flag(out.status, &out.status_flag);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = FALSE;

	int ret = arm_op_exec_arm_cmn_reg(core, &in, &out);
	DBG_ARM_CMN_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_cmp_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_cmp_reg_a1 *op = &core->decoded_code->code.arm_cmp_reg_a1;

	arm_cmp_reg_input_type in;
	arm_cmp_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "CMP";

	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rm);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);

	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);
	out.result = -1;

	int ret = arm_op_exec_arm_cmp_reg(core, &in, &out);
	DBG_ARM_CMP_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_teq_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_teq_reg_a1 *op = &core->decoded_code->code.arm_teq_reg_a1;

	arm_teq_reg_input_type in;
	arm_teq_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "TEQ";
	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rm);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);

	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);
	out.result = -1;

	int ret = arm_op_exec_arm_teq_reg(core, &in, &out);
	DBG_ARM_TEQ_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_sub_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_sub_imm_a1 *op = &core->decoded_code->code.arm_sub_imm_a1;

	arm_sub_imm_input_type in;
	arm_sub_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "SUB";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	
	int ret = arm_op_exec_arm_sub_imm(core, &in, &out);
	DBG_ARM_SUB_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_sub_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_sub_reg_a1 *op = &core->decoded_code->code.arm_sub_reg_a1;

	arm_sub_reg_input_type in;
	arm_sub_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "SUB";
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

	int ret = arm_op_exec_arm_sub_reg(core, &in, &out);
	DBG_ARM_SUB_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_sub_spimm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_sub_spimm_a1 *op = &core->decoded_code->code.arm_sub_spimm_a1;

	arm_sub_imm_input_type in;
	arm_sub_imm_output_type out;
	out.status = *cpu_get_status(core);


	in.instrName = "SUB";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REGID(core, &in, CpuRegId_SP, Rn);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	
	int ret = arm_op_exec_arm_sub_imm(core, &in, &out);
	DBG_ARM_SUB_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_sub_spreg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_sub_spreg_a1 *op = &core->decoded_code->code.arm_sub_spreg_a1;

	arm_sub_reg_input_type in;
	arm_sub_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "SUB";
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

	int ret = arm_op_exec_arm_sub_reg(core, &in, &out);
	DBG_ARM_SUB_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_rsb_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_rsb_reg_a1 *op = &core->decoded_code->code.arm_rsb_reg_a1;

	arm_rsb_reg_input_type in;
	arm_rsb_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "RSB";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rm);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);


	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_rsb_reg(core, &in, &out);
	DBG_ARM_RSB_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}



int arm_op_exec_arm_rsb_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_rsb_imm_a1 *op = &core->decoded_code->code.arm_rsb_imm_a1;

	arm_rsb_imm_input_type in;
	arm_rsb_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "RSB";
	in.cond = op->cond;

	in.S = op->S;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	out.next_address = core->pc;
	out.passed = FALSE;

	OP_SET_REG(core, &out, op, Rd);

	int ret = arm_op_exec_arm_rsb_imm(core, &in, &out);
	DBG_ARM_RSB_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_sbc_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_sbc_reg_a1 *op = &core->decoded_code->code.arm_sbc_reg_a1;

	arm_sbc_reg_input_type in;
	arm_sbc_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "SBC";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rm);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);

	OP_SET_REG(core, &out, op, Rd);
	out.next_address = core->pc;
	out.passed = FALSE;
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_sbc_reg(core, &in, &out);
	DBG_ARM_SBC_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_sbc_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_sbc_imm_a1 *op = &core->decoded_code->code.arm_sbc_imm_a1;

	arm_sbc_imm_input_type in;
	arm_sbc_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "SBC";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	out.next_address = core->pc;
	out.passed = FALSE;

	OP_SET_REG(core, &out, op, Rd);

	int ret = arm_op_exec_arm_sbc_imm(core, &in, &out);
	DBG_ARM_SBC_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mul_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mul_a1 *op = &core->decoded_code->code.arm_mul_a1;

	arm_mul_input_type in;
	arm_mul_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MUL";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_mul(core, &in, &out);
	DBG_ARM_MUL(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_smmul_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_smmul_a1 *op = &core->decoded_code->code.arm_smmul_a1;

	arm_smmul_input_type in;
	arm_smmul_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "SMMUL";
	in.cond = op->cond;
	in.round = (op->R == 1);
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;

	OP_SET_REG(core, &out, op, Rd);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_smmul(core, &in, &out);
	DBG_ARM_SMMUL(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_smull_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_smull_a1 *op = &core->decoded_code->code.arm_smull_a1;

	arm_smull_input_type in;
	arm_smull_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "SMULL";
	in.cond = op->cond;
	in.S = (op->S == 1);
	OP_SET_REG(core, &in, op, RdHi);
	OP_SET_REG(core, &in, op, RdLo);
	OP_SET_REG(core, &in, op, Rm);
	OP_SET_REG(core, &in, op, Rn);

	out.next_address = core->pc;
	out.passed = FALSE;

	OP_SET_REG(core, &out, op, RdHi);
	OP_SET_REG(core, &out, op, RdLo);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_smull(core, &in, &out);
	DBG_ARM_SMULL(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_umull_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_umull_a1 *op = &core->decoded_code->code.arm_umull_a1;

	arm_umull_input_type in;
	arm_umull_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "UMULL";

	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, RdHi);
	OP_SET_REG(core, &in, op, RdLo);
	OP_SET_REG(core, &in, op, Rm);
	OP_SET_REG(core, &in, op, Rn);

	out.next_address = core->pc;
	out.passed = FALSE;


	OP_SET_REG(core, &out, op, RdHi);
	OP_SET_REG(core, &out, op, RdLo);
	cpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_umull(core, &in, &out);
	DBG_ARM_UMULL(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
