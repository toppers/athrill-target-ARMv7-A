#include "../../src/cpu/cpu_exec/op_exec_debug.h"
#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
#include "arm_pseudo_code_func.h"



int arm_op_exec_arm_add_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_add_imm_a1 *op = &core->decoded_code->code.arm_add_imm_a1;

	arm_add_imm_input_type in;
	arm_add_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_ADD_IMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_ADD_REG_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.Rm = op->Rm;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_add_reg(core, &in, &out);
	DBG_ARM_ADD_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_add_spimm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_add_spimm_a1 *op = &core->decoded_code->code.arm_add_spimm_a1;

	arm_add_spimm_input_type in;
	arm_add_spimm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_ADD_SPIMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.SP = op->SP;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_ADR_A1";

	in.cond = op->cond;

	in.Rd = op->Rd;

	in.imm32 = op->imm32;

	in.add = op->add;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_SUBS_PCLR_A1";

	in.cond = op->cond;

	in.opcode = op->opcode;

	in.Rn = op->Rn;

	in.Rm = op->Rm;

	in.register_form = op->register_form;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.PC = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_CMP_IMM_A1";

	in.cond = op->cond;

	in.sign = op->sign;

	in.Rn = op->Rn;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.result = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_CMN_IMM_A1";

	in.cond = op->cond;

	in.sign = op->sign;

	in.Rn = op->Rn;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.result = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_cmn_imm(core, &in, &out);
	DBG_ARM_CMN_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_sub_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_sub_imm_a1 *op = &core->decoded_code->code.arm_sub_imm_a1;

	arm_sub_imm_input_type in;
	arm_sub_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_SUB_IMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_SUB_REG_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.Rm = op->Rm;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_SUB_SPIMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_sub_imm(core, &in, &out);
	DBG_ARM_SUB_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_cmp_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_cmp_reg_a1 *op = &core->decoded_code->code.arm_cmp_reg_a1;

	arm_cmp_reg_input_type in;
	arm_cmp_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_CMP_REG_A1";

	in.cond = op->cond;

	in.Rn = op->Rn;

	in.Rm = op->Rm;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.result = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_cmp_reg(core, &in, &out);
	DBG_ARM_CMP_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mov_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mov_imm_a1 *op = &core->decoded_code->code.arm_mov_imm_a1;

	arm_mov_imm_input_type in;
	arm_mov_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_MOV_IMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_mov_imm(core, &in, &out);
	DBG_ARM_MOV_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mov_imm_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mov_imm_a2 *op = &core->decoded_code->code.arm_mov_imm_a2;

	arm_mov_imm_input_type in;
	arm_mov_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_MOV_IMM_A2";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_mov_imm(core, &in, &out);
	DBG_ARM_MOV_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mvn_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mvn_imm_a1 *op = &core->decoded_code->code.arm_mvn_imm_a1;

	arm_mvn_imm_input_type in;
	arm_mvn_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_MVN_IMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_mvn_imm(core, &in, &out);
	DBG_ARM_MVN_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mov_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mov_reg_a1 *op = &core->decoded_code->code.arm_mov_reg_a1;

	arm_mov_reg_input_type in;
	arm_mov_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_MOV_REG_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_MVN_REG_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rm = op->Rm;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_mvn_reg(core, &in, &out);
	DBG_ARM_MVN_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_bl_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_bl_a1 *op = &core->decoded_code->code.arm_bl_a1;

	arm_bl_imm_input_type in;
	arm_bl_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_BL_A1";

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.type = op->type;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.LR = -1;
	

	
	int ret = arm_op_exec_arm_bl_imm(core, &in, &out);
	DBG_ARM_BL_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_blx_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_blx_a2 *op = &core->decoded_code->code.arm_blx_a2;

	arm_bl_imm_input_type in;
	arm_bl_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_BLX_A2";

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.type = op->type;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.LR = -1;
	

	
	int ret = arm_op_exec_arm_bl_imm(core, &in, &out);
	DBG_ARM_BL_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_blx_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_blx_reg_a1 *op = &core->decoded_code->code.arm_blx_reg_a1;

	arm_bl_reg_input_type in;
	arm_bl_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_BLX_REG_A1";

	in.cond = op->cond;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.LR = -1;
	

	
	int ret = arm_op_exec_arm_bl_reg(core, &in, &out);
	DBG_ARM_BL_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_b_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_b_a1 *op = &core->decoded_code->code.arm_b_a1;

	arm_b_imm_input_type in;
	arm_b_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_B_A1";

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.PC = op->PC;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	int ret = arm_op_exec_arm_b_imm(core, &in, &out);
	DBG_ARM_B_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_bx_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_bx_a1 *op = &core->decoded_code->code.arm_bx_a1;

	arm_bx_reg_input_type in;
	arm_bx_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_BX_A1";

	in.cond = op->cond;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	int ret = arm_op_exec_arm_bx_reg(core, &in, &out);
	DBG_ARM_BX_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_str_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_str_imm_a1 *op = &core->decoded_code->code.arm_str_imm_a1;

	arm_str_imm_input_type in;
	arm_str_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_STR_IMM_A1";

	in.size = op->size;

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rn = -1;
	

	
	int ret = arm_op_exec_arm_str_imm(core, &in, &out);
	DBG_ARM_STR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_strb_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_strb_imm_a1 *op = &core->decoded_code->code.arm_strb_imm_a1;

	arm_str_imm_input_type in;
	arm_str_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_STRB_IMM_A1";

	in.size = op->size;

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rn = -1;
	

	
	int ret = arm_op_exec_arm_str_imm(core, &in, &out);
	DBG_ARM_STR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_strh_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_strh_imm_a1 *op = &core->decoded_code->code.arm_strh_imm_a1;

	arm_str_imm_input_type in;
	arm_str_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_STRH_IMM_A1";

	in.size = op->size;

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rn = -1;
	

	
	int ret = arm_op_exec_arm_str_imm(core, &in, &out);
	DBG_ARM_STR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_strd_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_strd_imm_a1 *op = &core->decoded_code->code.arm_strd_imm_a1;

	arm_strd_imm_input_type in;
	arm_strd_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_STRD_IMM_A1";

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.Rn = op->Rn;

	in.Rt1 = op->Rt1;

	in.Rt2 = op->Rt2;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rn = -1;
	

	
	int ret = arm_op_exec_arm_strd_imm(core, &in, &out);
	DBG_ARM_STRD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_str_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_str_reg_a1 *op = &core->decoded_code->code.arm_str_reg_a1;

	arm_str_reg_input_type in;
	arm_str_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_STR_REG_A1";

	in.size = op->size;

	in.sign = op->sign;

	in.cond = op->cond;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	int ret = arm_op_exec_arm_str_reg(core, &in, &out);
	DBG_ARM_STR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_strb_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_strb_reg_a1 *op = &core->decoded_code->code.arm_strb_reg_a1;

	arm_str_reg_input_type in;
	arm_str_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_STRB_REG_A1";

	in.size = op->size;

	in.sign = op->sign;

	in.cond = op->cond;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	int ret = arm_op_exec_arm_str_reg(core, &in, &out);
	DBG_ARM_STR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_push_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_push_a1 *op = &core->decoded_code->code.arm_push_a1;

	arm_push_input_type in;
	arm_push_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_PUSH_A1";

	in.cond = op->cond;

	in.bitcount = op->bitcount;

	in.UnalignedAllowed = op->UnalignedAllowed;

	in.registers = op->registers;

	in.SP = op->SP;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.SP = -1;
	

	
	int ret = arm_op_exec_arm_push(core, &in, &out);
	DBG_ARM_PUSH(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_push_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_push_a2 *op = &core->decoded_code->code.arm_push_a2;

	arm_push_input_type in;
	arm_push_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_PUSH_A2";

	in.cond = op->cond;

	in.bitcount = op->bitcount;

	in.UnalignedAllowed = op->UnalignedAllowed;

	in.registers = op->registers;

	in.SP = op->SP;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.SP = -1;
	

	
	int ret = arm_op_exec_arm_push(core, &in, &out);
	DBG_ARM_PUSH(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_stmfd_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_stmfd_a1 *op = &core->decoded_code->code.arm_stmfd_a1;

	arm_stmfd_input_type in;
	arm_stmfd_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_STMFD_A1";

	in.cond = op->cond;

	in.bitcount = op->bitcount;

	in.wback = op->wback;

	in.registers = op->registers;

	in.Rn = op->Rn;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rn = -1;
	

	
	int ret = arm_op_exec_arm_stmfd(core, &in, &out);
	DBG_ARM_STMFD(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_stm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_stm_a1 *op = &core->decoded_code->code.arm_stm_a1;

	arm_stm_input_type in;
	arm_stm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_STM_A1";

	in.cond = op->cond;

	in.wback = op->wback;

	in.bitcount = op->bitcount;

	in.Rn = op->Rn;

	in.registers = op->registers;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rn = -1;
	

	
	int ret = arm_op_exec_arm_stm(core, &in, &out);
	DBG_ARM_STM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldr_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldr_imm_a1 *op = &core->decoded_code->code.arm_ldr_imm_a1;

	arm_ldr_imm_input_type in;
	arm_ldr_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LDR_IMM_A1";

	in.size = op->size;

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rt = -1;
	

	
	int ret = arm_op_exec_arm_ldr_imm(core, &in, &out);
	DBG_ARM_LDR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldr_literal_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldr_literal_a1 *op = &core->decoded_code->code.arm_ldr_literal_a1;

	arm_ldr_literal_input_type in;
	arm_ldr_literal_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LDR_LITERAL_A1";

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.add = op->add;

	in.PC = op->PC;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rt = -1;
	

	
	int ret = arm_op_exec_arm_ldr_literal(core, &in, &out);
	DBG_ARM_LDR_LITERAL(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldrb_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldrb_imm_a1 *op = &core->decoded_code->code.arm_ldrb_imm_a1;

	arm_ldr_imm_input_type in;
	arm_ldr_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LDRB_IMM_A1";

	in.size = op->size;

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rt = -1;
	

	
	int ret = arm_op_exec_arm_ldr_imm(core, &in, &out);
	DBG_ARM_LDR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldrh_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldrh_imm_a1 *op = &core->decoded_code->code.arm_ldrh_imm_a1;

	arm_ldr_imm_input_type in;
	arm_ldr_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LDRH_IMM_A1";

	in.size = op->size;

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rt = -1;
	

	
	int ret = arm_op_exec_arm_ldr_imm(core, &in, &out);
	DBG_ARM_LDR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldrd_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldrd_imm_a1 *op = &core->decoded_code->code.arm_ldrd_imm_a1;

	arm_ldrd_imm_input_type in;
	arm_ldrd_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LDRD_IMM_A1";

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.Rn = op->Rn;

	in.Rt1 = op->Rt1;

	in.Rt2 = op->Rt2;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rn = -1;
	

	
	int ret = arm_op_exec_arm_ldrd_imm(core, &in, &out);
	DBG_ARM_LDRD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldr_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldr_reg_a1 *op = &core->decoded_code->code.arm_ldr_reg_a1;

	arm_ldr_reg_input_type in;
	arm_ldr_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LDR_REG_A1";

	in.size = op->size;

	in.sign = op->sign;

	in.cond = op->cond;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rt = -1;
	

	
	int ret = arm_op_exec_arm_ldr_reg(core, &in, &out);
	DBG_ARM_LDR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldrb_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldrb_reg_a1 *op = &core->decoded_code->code.arm_ldrb_reg_a1;

	arm_ldr_reg_input_type in;
	arm_ldr_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LDRB_REG_A1";

	in.size = op->size;

	in.sign = op->sign;

	in.cond = op->cond;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rt = -1;
	

	
	int ret = arm_op_exec_arm_ldr_reg(core, &in, &out);
	DBG_ARM_LDR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldrh_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldrh_reg_a1 *op = &core->decoded_code->code.arm_ldrh_reg_a1;

	arm_ldr_reg_input_type in;
	arm_ldr_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LDRH_REG_A1";

	in.size = op->size;

	in.sign = op->sign;

	in.cond = op->cond;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rt = -1;
	

	
	int ret = arm_op_exec_arm_ldr_reg(core, &in, &out);
	DBG_ARM_LDR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_pop_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_pop_a1 *op = &core->decoded_code->code.arm_pop_a1;

	arm_pop_input_type in;
	arm_pop_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_POP_A1";

	in.cond = op->cond;

	in.bitcount = op->bitcount;

	in.UnalignedAllowed = op->UnalignedAllowed;

	in.registers = op->registers;

	in.SP = op->SP;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.SP = -1;
	

	
	int ret = arm_op_exec_arm_pop(core, &in, &out);
	DBG_ARM_POP(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_pop_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_pop_a2 *op = &core->decoded_code->code.arm_pop_a2;

	arm_pop_input_type in;
	arm_pop_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_POP_A2";

	in.cond = op->cond;

	in.bitcount = op->bitcount;

	in.UnalignedAllowed = op->UnalignedAllowed;

	in.registers = op->registers;

	in.SP = op->SP;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.SP = -1;
	

	
	int ret = arm_op_exec_arm_pop(core, &in, &out);
	DBG_ARM_POP(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldm_a1 *op = &core->decoded_code->code.arm_ldm_a1;

	arm_ldm_input_type in;
	arm_ldm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LDM_A1";

	in.cond = op->cond;

	in.wback = op->wback;

	in.bitcount = op->bitcount;

	in.Rn = op->Rn;

	in.registers = op->registers;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rn = -1;
	

	
	int ret = arm_op_exec_arm_ldm(core, &in, &out);
	DBG_ARM_LDM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_nop_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_nop_a1 *op = &core->decoded_code->code.arm_nop_a1;

	arm_nop_input_type in;
	arm_nop_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_NOP_A1";

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

	//TODO arguments setting..
	in.instrName = "ARM_MSR_IMM_A1";

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.write_nzcvq = op->write_nzcvq;

	in.write_g = op->write_g;

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

	//TODO arguments setting..
	in.instrName = "ARM_MSR2_IMM_A1";

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.mask = op->mask;

	in.write_spsr = op->write_spsr;

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

	//TODO arguments setting..
	in.instrName = "ARM_MRS_A1";

	in.cond = op->cond;

	in.Rd = op->Rd;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	

	
	int ret = arm_op_exec_arm_mrs(core, &in, &out);
	DBG_ARM_MRS(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_msr2_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_msr2_reg_a1 *op = &core->decoded_code->code.arm_msr2_reg_a1;

	arm_msr2_reg_input_type in;
	arm_msr2_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_MSR2_REG_A1";

	in.cond = op->cond;

	in.Rn = op->Rn;

	in.mask = op->mask;

	in.write_spsr = op->write_spsr;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	int ret = arm_op_exec_arm_msr2_reg(core, &in, &out);
	DBG_ARM_MSR2_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mcr_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mcr_a1 *op = &core->decoded_code->code.arm_mcr_a1;

	arm_mcr_input_type in;
	arm_mcr_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_MCR_A1";

	in.cond = op->cond;

	in.cp = op->cp;

	in.CRn = op->CRn;

	in.op1 = op->op1;

	in.CRm = op->CRm;

	in.op2 = op->op2;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	int ret = arm_op_exec_arm_mcr(core, &in, &out);
	DBG_ARM_MCR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mcr2_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mcr2_a2 *op = &core->decoded_code->code.arm_mcr2_a2;

	arm_mcr_input_type in;
	arm_mcr_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_MCR2_A2";

	in.cond = op->cond;

	in.cp = op->cp;

	in.CRn = op->CRn;

	in.op1 = op->op1;

	in.CRm = op->CRm;

	in.op2 = op->op2;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	int ret = arm_op_exec_arm_mcr(core, &in, &out);
	DBG_ARM_MCR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mrc_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mrc_a1 *op = &core->decoded_code->code.arm_mrc_a1;

	arm_mrc_input_type in;
	arm_mrc_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_MRC_A1";

	in.cond = op->cond;

	in.cp = op->cp;

	in.CRn = op->CRn;

	in.op1 = op->op1;

	in.CRm = op->CRm;

	in.op2 = op->op2;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	int ret = arm_op_exec_arm_mrc(core, &in, &out);
	DBG_ARM_MRC(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mrc2_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mrc2_a2 *op = &core->decoded_code->code.arm_mrc2_a2;

	arm_mrc_input_type in;
	arm_mrc_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_MRC2_A2";

	in.cond = op->cond;

	in.cp = op->cp;

	in.CRn = op->CRn;

	in.op1 = op->op1;

	in.CRm = op->CRm;

	in.op2 = op->op2;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	int ret = arm_op_exec_arm_mrc(core, &in, &out);
	DBG_ARM_MRC(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_bic_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_bic_imm_a1 *op = &core->decoded_code->code.arm_bic_imm_a1;

	arm_bic_imm_input_type in;
	arm_bic_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_BIC_IMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_ORR_IMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_orr_imm(core, &in, &out);
	DBG_ARM_ORR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_orr_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_orr_reg_a1 *op = &core->decoded_code->code.arm_orr_reg_a1;

	arm_orr_reg_input_type in;
	arm_orr_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_ORR_REG_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.Rm = op->Rm;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_orr_reg(core, &in, &out);
	DBG_ARM_ORR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_movt_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_movt_a1 *op = &core->decoded_code->code.arm_movt_a1;

	arm_movt_input_type in;
	arm_movt_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_MOVT_A1";

	in.cond = op->cond;

	in.Rd = op->Rd;

	in.imm16 = op->imm16;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_movt(core, &in, &out);
	DBG_ARM_MOVT(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_lsl_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_lsl_imm_a1 *op = &core->decoded_code->code.arm_lsl_imm_a1;

	arm_lsl_imm_input_type in;
	arm_lsl_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LSL_IMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_lsl_imm(core, &in, &out);
	DBG_ARM_LSL_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_lsl_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_lsl_reg_a1 *op = &core->decoded_code->code.arm_lsl_reg_a1;

	arm_lsl_reg_input_type in;
	arm_lsl_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LSL_REG_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rm = op->Rm;

	in.Rn = op->Rn;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_lsl_reg(core, &in, &out);
	DBG_ARM_LSL_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_lsr_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_lsr_imm_a1 *op = &core->decoded_code->code.arm_lsr_imm_a1;

	arm_lsr_imm_input_type in;
	arm_lsr_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LSR_IMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_lsr_imm(core, &in, &out);
	DBG_ARM_LSR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_lsr_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_lsr_reg_a1 *op = &core->decoded_code->code.arm_lsr_reg_a1;

	arm_lsr_reg_input_type in;
	arm_lsr_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LSR_REG_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rm = op->Rm;

	in.Rn = op->Rn;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_lsr_reg(core, &in, &out);
	DBG_ARM_LSR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_bfc_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_bfc_a1 *op = &core->decoded_code->code.arm_bfc_a1;

	arm_bfc_input_type in;
	arm_bfc_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_BFC_A1";

	in.cond = op->cond;

	in.msbit = op->msbit;

	in.lsbit = op->lsbit;

	in.Rd = op->Rd;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	

	
	int ret = arm_op_exec_arm_bfc(core, &in, &out);
	DBG_ARM_BFC(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_and_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_and_imm_a1 *op = &core->decoded_code->code.arm_and_imm_a1;

	arm_and_imm_input_type in;
	arm_and_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_AND_IMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_AND_REG_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.Rm = op->Rm;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_and_reg(core, &in, &out);
	DBG_ARM_AND_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_uxtb_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_uxtb_a1 *op = &core->decoded_code->code.arm_uxtb_a1;

	arm_uxt_input_type in;
	arm_uxt_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_UXTB_A1";

	in.cond = op->cond;

	in.size = op->size;

	in.Rd = op->Rd;

	in.rotate = op->rotate;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	

	
	int ret = arm_op_exec_arm_uxt(core, &in, &out);
	DBG_ARM_UXT(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_uxth_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_uxth_a1 *op = &core->decoded_code->code.arm_uxth_a1;

	arm_uxt_input_type in;
	arm_uxt_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_UXTH_A1";

	in.cond = op->cond;

	in.size = op->size;

	in.Rd = op->Rd;

	in.rotate = op->rotate;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	

	
	int ret = arm_op_exec_arm_uxt(core, &in, &out);
	DBG_ARM_UXT(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_rsb_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_rsb_reg_a1 *op = &core->decoded_code->code.arm_rsb_reg_a1;

	arm_rsb_reg_input_type in;
	arm_rsb_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_RSB_REG_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rn = op->Rn;

	in.Rd = op->Rd;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_RSB_IMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rn = op->Rn;

	in.Rd = op->Rd;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_SBC_REG_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rn = op->Rn;

	in.Rd = op->Rd;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_sbc_reg(core, &in, &out);
	DBG_ARM_SBC_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mul_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mul_a1 *op = &core->decoded_code->code.arm_mul_a1;

	arm_mul_input_type in;
	arm_mul_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_MUL_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rn = op->Rn;

	in.Rd = op->Rd;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_SMMUL_A1";

	in.cond = op->cond;

	in.round = op->round;

	in.Rn = op->Rn;

	in.Rd = op->Rd;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_SMULL_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.RdHi = op->RdHi;

	in.RdLo = op->RdLo;

	in.Rm = op->Rm;

	in.Rn = op->Rn;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.RdHi = -1;
	
	out.RdLo = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_smull(core, &in, &out);
	DBG_ARM_SMULL(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_tst_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_tst_imm_a1 *op = &core->decoded_code->code.arm_tst_imm_a1;

	arm_tst_imm_input_type in;
	arm_tst_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_TST_IMM_A1";

	in.cond = op->cond;

	in.Rn = op->Rn;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.status_flag = -1;
	

	
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

	//TODO arguments setting..
	in.instrName = "ARM_TST_REG_A1";

	in.cond = op->cond;

	in.Rn = op->Rn;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_tst_reg(core, &in, &out);
	DBG_ARM_TST_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_sxtb_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_sxtb_a1 *op = &core->decoded_code->code.arm_sxtb_a1;

	arm_sxtb_input_type in;
	arm_sxtb_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_SXTB_A1";

	in.cond = op->cond;

	in.Rd = op->Rd;

	in.rotate = op->rotate;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	

	
	int ret = arm_op_exec_arm_sxtb(core, &in, &out);
	DBG_ARM_SXTB(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_asr_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_asr_imm_a1 *op = &core->decoded_code->code.arm_asr_imm_a1;

	arm_asr_imm_input_type in;
	arm_asr_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_ASR_IMM_A1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.shift_t = op->shift_t;

	in.shift_n = op->shift_n;

	in.Rm = op->Rm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rd = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_asr_imm(core, &in, &out);
	DBG_ARM_ASR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_srs_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_srs_a1 *op = &core->decoded_code->code.arm_srs_a1;

	arm_srs_input_type in;
	arm_srs_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_SRS_A1";

	in.mode = op->mode;

	in.wback = op->wback;

	in.increment = op->increment;

	in.wordhigher = op->wordhigher;

	in.SP = op->SP;

	in.LR = op->LR;

	in.SPSR = op->SPSR;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.SP = -1;
	

	
	int ret = arm_op_exec_arm_srs(core, &in, &out);
	DBG_ARM_SRS(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_rfe_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_rfe_a1 *op = &core->decoded_code->code.arm_rfe_a1;

	arm_rfe_input_type in;
	arm_rfe_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_RFE_A1";

	in.wback = op->wback;

	in.increment = op->increment;

	in.wordhigher = op->wordhigher;

	in.Rn = op->Rn;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Rn = -1;
	

	
	int ret = arm_op_exec_arm_rfe(core, &in, &out);
	DBG_ARM_RFE(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_wfi_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_wfi_a1 *op = &core->decoded_code->code.arm_wfi_a1;

	arm_wfi_input_type in;
	arm_wfi_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_WFI_A1";

	in.cond = op->cond;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	int ret = arm_op_exec_arm_wfi(core, &in, &out);
	DBG_ARM_WFI(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vadd_freg_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vadd_freg_a2 *op = &core->decoded_code->code.arm_vadd_freg_a2;

	arm_vadd_freg_input_type in;
	arm_vadd_freg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VADD_FREG_A2";

	in.cond = op->cond;

	in.Vn = op->Vn;

	in.Vd = op->Vd;

	in.Vm = op->Vm;

	in.advsimd = op->advsimd;

	in.dp_operation = op->dp_operation;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vadd_freg(core, &in, &out);
	DBG_ARM_VADD_FREG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vldr_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vldr_a1 *op = &core->decoded_code->code.arm_vldr_a1;

	arm_vldr_input_type in;
	arm_vldr_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VLDR_A1";

	in.cond = op->cond;

	in.Rn = op->Rn;

	in.Vd = op->Vd;

	in.add = op->add;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vldr(core, &in, &out);
	DBG_ARM_VLDR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vldr_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vldr_a2 *op = &core->decoded_code->code.arm_vldr_a2;

	arm_vldr_input_type in;
	arm_vldr_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VLDR_A2";

	in.cond = op->cond;

	in.Rn = op->Rn;

	in.Vd = op->Vd;

	in.add = op->add;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vldr(core, &in, &out);
	DBG_ARM_VLDR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vcvt_df_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vcvt_df_a1 *op = &core->decoded_code->code.arm_vcvt_df_a1;

	arm_vcvt_df_input_type in;
	arm_vcvt_df_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VCVT_DF_A1";

	in.cond = op->cond;

	in.double_to_single = op->double_to_single;

	in.Vd = op->Vd;

	in.Vm = op->Vm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vcvt_df(core, &in, &out);
	DBG_ARM_VCVT_DF(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vcvt_fi_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vcvt_fi_a1 *op = &core->decoded_code->code.arm_vcvt_fi_a1;

	arm_vcvt_fi_input_type in;
	arm_vcvt_fi_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VCVT_FI_A1";

	in.cond = op->cond;

	in.dp_operation = op->dp_operation;

	in.to_integer = op->to_integer;

	in.unsigned_cvt = op->unsigned_cvt;

	in.round_zero = op->round_zero;

	in.round_nearest = op->round_nearest;

	in.Vd = op->Vd;

	in.Vm = op->Vm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vcvt_fi(core, &in, &out);
	DBG_ARM_VCVT_FI(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vstr_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vstr_a1 *op = &core->decoded_code->code.arm_vstr_a1;

	arm_vstr_input_type in;
	arm_vstr_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VSTR_A1";

	in.cond = op->cond;

	in.single_reg = op->single_reg;

	in.add = op->add;

	in.imm32 = op->imm32;

	in.Rn = op->Rn;

	in.Vd = op->Vd;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vstr(core, &in, &out);
	DBG_ARM_VSTR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vstr_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vstr_a2 *op = &core->decoded_code->code.arm_vstr_a2;

	arm_vstr_input_type in;
	arm_vstr_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VSTR_A2";

	in.cond = op->cond;

	in.single_reg = op->single_reg;

	in.add = op->add;

	in.imm32 = op->imm32;

	in.Rn = op->Rn;

	in.Vd = op->Vd;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vstr(core, &in, &out);
	DBG_ARM_VSTR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vcmp_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vcmp_a1 *op = &core->decoded_code->code.arm_vcmp_a1;

	arm_vcmp_input_type in;
	arm_vcmp_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VCMP_A1";

	in.cond = op->cond;

	in.dp_operation = op->dp_operation;

	in.quiet_nan_exc = op->quiet_nan_exc;

	in.with_zero = op->with_zero;

	in.Vd = op->Vd;

	in.Vm = op->Vm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_vcmp(core, &in, &out);
	DBG_ARM_VCMP(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vcmp_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vcmp_a2 *op = &core->decoded_code->code.arm_vcmp_a2;

	arm_vcmp_input_type in;
	arm_vcmp_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VCMP_A2";

	in.cond = op->cond;

	in.dp_operation = op->dp_operation;

	in.quiet_nan_exc = op->quiet_nan_exc;

	in.with_zero = op->with_zero;

	in.Vd = op->Vd;

	in.Vm = op->Vm;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_vcmp(core, &in, &out);
	DBG_ARM_VCMP(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vmrs_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vmrs_a1 *op = &core->decoded_code->code.arm_vmrs_a1;

	arm_vmrs_input_type in;
	arm_vmrs_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VMRS_A1";

	in.cond = op->cond;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_vmrs(core, &in, &out);
	DBG_ARM_VMRS(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vmov_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vmov_imm_a1 *op = &core->decoded_code->code.arm_vmov_imm_a1;

	arm_vmov_imm_input_type in;
	arm_vmov_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VMOV_IMM_A1";

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.imm64 = op->imm64;

	in.advsimd = op->advsimd;

	in.single_reg = op->single_reg;

	in.Vd1 = op->Vd1;

	in.Vd2 = op->Vd2;

	in.regs = op->regs;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd1 = -1;
	
	out.Vd2 = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_vmov_imm(core, &in, &out);
	DBG_ARM_VMOV_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vmov_imm_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vmov_imm_a2 *op = &core->decoded_code->code.arm_vmov_imm_a2;

	arm_vmov_imm_input_type in;
	arm_vmov_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VMOV_IMM_A2";

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.imm64 = op->imm64;

	in.advsimd = op->advsimd;

	in.single_reg = op->single_reg;

	in.Vd1 = op->Vd1;

	in.Vd2 = op->Vd2;

	in.regs = op->regs;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd1 = -1;
	
	out.Vd2 = -1;
	
	out.status_flag = -1;
	

	
	int ret = arm_op_exec_arm_vmov_imm(core, &in, &out);
	DBG_ARM_VMOV_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vmov_sreg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vmov_sreg_a1 *op = &core->decoded_code->code.arm_vmov_sreg_a1;

	arm_vmov_sreg_input_type in;
	arm_vmov_sreg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VMOV_SREG_A1";

	in.cond = op->cond;

	in.to_arm_register = op->to_arm_register;

	in.Vn = op->Vn;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vn = -1;
	
	out.Rt = -1;
	

	
	int ret = arm_op_exec_arm_vmov_sreg(core, &in, &out);
	DBG_ARM_VMOV_SREG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vsub_freg_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vsub_freg_a2 *op = &core->decoded_code->code.arm_vsub_freg_a2;

	arm_vsub_freg_input_type in;
	arm_vsub_freg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VSUB_FREG_A2";

	in.cond = op->cond;

	in.Vn = op->Vn;

	in.Vd = op->Vd;

	in.Vm = op->Vm;

	in.advsimd = op->advsimd;

	in.dp_operation = op->dp_operation;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vsub_freg(core, &in, &out);
	DBG_ARM_VSUB_FREG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vmul_freg_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vmul_freg_a2 *op = &core->decoded_code->code.arm_vmul_freg_a2;

	arm_vmul_freg_input_type in;
	arm_vmul_freg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VMUL_FREG_A2";

	in.cond = op->cond;

	in.Vn = op->Vn;

	in.Vd = op->Vd;

	in.Vm = op->Vm;

	in.advsimd = op->advsimd;

	in.dp_operation = op->dp_operation;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vmul_freg(core, &in, &out);
	DBG_ARM_VMUL_FREG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vdiv_freg_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vdiv_freg_a2 *op = &core->decoded_code->code.arm_vdiv_freg_a2;

	arm_vdiv_freg_input_type in;
	arm_vdiv_freg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VDIV_FREG_A2";

	in.cond = op->cond;

	in.Vn = op->Vn;

	in.Vd = op->Vd;

	in.Vm = op->Vm;

	in.advsimd = op->advsimd;

	in.dp_operation = op->dp_operation;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vdiv_freg(core, &in, &out);
	DBG_ARM_VDIV_FREG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vpush_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vpush_a1 *op = &core->decoded_code->code.arm_vpush_a1;

	arm_vpush_input_type in;
	arm_vpush_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VPUSH_A1";

	in.cond = op->cond;

	in.single_reg = op->single_reg;

	in.regs = op->regs;

	in.SP = op->SP;

	in.Vd = op->Vd;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.SP = -1;
	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vpush(core, &in, &out);
	DBG_ARM_VPUSH(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vpush_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vpush_a2 *op = &core->decoded_code->code.arm_vpush_a2;

	arm_vpush_input_type in;
	arm_vpush_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_VPUSH_A2";

	in.cond = op->cond;

	in.single_reg = op->single_reg;

	in.regs = op->regs;

	in.SP = op->SP;

	in.Vd = op->Vd;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	
	out.SP = -1;
	
	out.Vd = -1;
	

	
	int ret = arm_op_exec_arm_vpush(core, &in, &out);
	DBG_ARM_VPUSH(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
