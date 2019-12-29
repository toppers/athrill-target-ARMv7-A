#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
#include "cpu_op_types.h"
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

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = -1;
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm_C(op->imm12, CPU_ISSET_CY(cpu_get_status(core)), &out.status_flag.carry);

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

	in.instrName = "MOVW";
	in.cond = op->cond;
	in.S = FALSE;
	OP_SET_REG(core, &in, op, Rd);

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = -1;
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

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = -1;
	cpu_conv_status_flag(out.status, &out.status_flag);

	
	int ret = arm_op_exec_arm_mov_reg(core, &in, &out);
	DBG_ARM_MOV_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}