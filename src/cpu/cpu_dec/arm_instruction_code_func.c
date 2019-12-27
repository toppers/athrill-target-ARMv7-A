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
	//TODO arguments setting..
	

	in.imm32 = op->imm32;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.cond = op->cond;

	in.S = op->S;

	out.next_address = core->pc;
	
	int ret = arm_op_exec_arm_add_imm_a1(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_push_1(struct TargetCore *core)
{
	arm_OpCodeFormatType_push_1 *op = &core->decoded_code->code.push_1;

	arm_add_imm_input_type in;
	arm_add_imm_output_type out;
	//TODO arguments setting..
	

	in.imm32 = op->imm32;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.cond = op->cond;

	in.S = op->S;

	out.next_address = core->pc;
	
	int ret = arm_op_exec_push_1(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mov_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mov_imm_a1 *op = &core->decoded_code->code.arm_mov_imm_a1;

	arm_add_imm_input_type in;
	arm_add_imm_output_type out;
	//TODO arguments setting..
	

	in.imm32 = op->imm32;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.cond = op->cond;

	in.S = op->S;

	out.next_address = core->pc;
	
	int ret = arm_op_exec_arm_mov_imm_a1(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mov_imm_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mov_imm_a2 *op = &core->decoded_code->code.arm_mov_imm_a2;

	arm_add_imm_input_type in;
	arm_add_imm_output_type out;
	//TODO arguments setting..
	

	in.imm32 = op->imm32;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.cond = op->cond;

	in.S = op->S;

	out.next_address = core->pc;
	
	int ret = arm_op_exec_arm_mov_imm_a2(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_bl_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_bl_a1 *op = &core->decoded_code->code.arm_bl_a1;

	arm_add_imm_input_type in;
	arm_add_imm_output_type out;
	//TODO arguments setting..
	

	in.imm32 = op->imm32;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.cond = op->cond;

	in.S = op->S;

	out.next_address = core->pc;
	
	int ret = arm_op_exec_arm_bl_a1(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_blx_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_blx_a2 *op = &core->decoded_code->code.arm_blx_a2;

	arm_add_imm_input_type in;
	arm_add_imm_output_type out;
	//TODO arguments setting..
	

	in.imm32 = op->imm32;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.cond = op->cond;

	in.S = op->S;

	out.next_address = core->pc;
	
	int ret = arm_op_exec_arm_blx_a2(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_str_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_str_imm_a1 *op = &core->decoded_code->code.arm_str_imm_a1;

	arm_add_imm_input_type in;
	arm_add_imm_output_type out;
	//TODO arguments setting..
	

	in.imm32 = op->imm32;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.cond = op->cond;

	in.S = op->S;

	out.next_address = core->pc;
	
	int ret = arm_op_exec_arm_str_imm_a1(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldr_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldr_imm_a1 *op = &core->decoded_code->code.arm_ldr_imm_a1;

	arm_add_imm_input_type in;
	arm_add_imm_output_type out;
	//TODO arguments setting..
	

	in.imm32 = op->imm32;

	in.Rd = op->Rd;

	in.Rn = op->Rn;

	in.cond = op->cond;

	in.S = op->S;

	out.next_address = core->pc;
	
	int ret = arm_op_exec_arm_ldr_imm_a1(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
