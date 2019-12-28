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

	out.result = -1;

	out.status_flag = -1;

	
	int ret = arm_op_exec_arm_add_imm(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_push_1(struct TargetCore *core)
{
	arm_OpCodeFormatType_push_1 *op = &core->decoded_code->code.push_1;

	arm_add_imm_input_type in;
	arm_add_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "PUSH_1";

	in.cond = op->cond;

	in.S = op->S;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.imm32 = op->imm32;

	out.next_address = core->pc;
	out.passed = FALSE;

	out.result = -1;

	out.status_flag = -1;

	
	int ret = arm_op_exec_arm_add_imm(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

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

	out.result = -1;

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

	out.result = -1;

	out.status_flag = -1;

	
	int ret = arm_op_exec_arm_mov_imm(core, &in, &out);
	DBG_ARM_MOV_IMM(core, &in, &out);

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

	out.result = -1;

	
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

	out.result = -1;

	
	int ret = arm_op_exec_arm_bl_imm(core, &in, &out);
	DBG_ARM_BL_IMM(core, &in, &out);

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


int arm_op_exec_arm_ldr_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldr_imm_a1 *op = &core->decoded_code->code.arm_ldr_imm_a1;

	arm_ldr_imm_input_type in;
	arm_ldr_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "ARM_LDR_IMM_A1";

	in.cond = op->cond;

	in.imm32 = op->imm32;

	in.add = op->add;

	in.index = op->index;

	in.wback = op->wback;

	in.Rn = op->Rn;

	in.Rt = op->Rt;

	out.next_address = core->pc;
	out.passed = FALSE;

	out.result = -1;

	
	int ret = arm_op_exec_arm_ldr_imm(core, &in, &out);
	DBG_ARM_LDR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
