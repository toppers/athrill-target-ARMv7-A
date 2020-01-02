#include "cpu_dec/arm_mcdecoder.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"


int arm_op_exec_arm_bl_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_bl_a1 *op = &core->decoded_code->code.arm_bl_a1;

	arm_bl_imm_input_type in;
	arm_bl_imm_output_type out;
	out.status = *cpu_get_status(core);

	ZeroExtendArgType zarg[2];
	zarg[0].bitsize = 2U;
	zarg[0].data = 0;
	zarg[1].bitsize = 24U;
	zarg[1].data = op->imm24;

	in.instrName = "BL";
	in.cond = op->cond;
	in.imm32 = SignExtendArray(2, zarg);
	in.type = InstrSet_ARM;

	out.next_address = core->pc;
	out.passed = FALSE;
	out.LR.name = "LR";
	out.LR.regId = CpuRegId_LR;
	out.LR.regData = -1;
	
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

	ZeroExtendArgType zarg[3];
	zarg[0].bitsize = 1U;
	zarg[0].data = 0;
	zarg[1].bitsize = 1U;
	zarg[1].data = op->H;
	zarg[2].bitsize = 24U;
	zarg[2].data = op->imm24;

	in.instrName = "BLX";
	in.cond = ConditionAlways;
	in.imm32 = SignExtendArray(3, zarg);
	in.type = InstrSet_Thumb;

	out.next_address = core->pc;
	out.passed = FALSE;
	out.LR.name = "LR";
	out.LR.regId = CpuRegId_LR;
	out.LR.regData = -1;

	int ret = arm_op_exec_arm_bl_imm(core, &in, &out);
	DBG_ARM_BL_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_b_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_b_a1 *op = &core->decoded_code->code.arm_b_a1;

	arm_b_imm_input_type in;
	arm_b_imm_output_type out;
	out.status = *cpu_get_status(core);

	ZeroExtendArgType zarg[2];
	zarg[0].bitsize = 2U;
	zarg[0].data = 0;
	zarg[1].bitsize = 24U;
	zarg[1].data = op->imm24;

	in.instrName = "B";
	in.cond = op->cond;
	in.imm32 = SignExtendArray(2, zarg);
	OP_SET_REGID(core, &in, CpuRegId_PC, PC);

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

	in.instrName = "BX";
	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rm);

	out.next_address = core->pc;
	out.passed = FALSE;
	
	int ret = arm_op_exec_arm_bx_reg(core, &in, &out);
	DBG_ARM_BX_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
