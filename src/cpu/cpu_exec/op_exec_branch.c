#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
#include "cpu_exec/op_exec_debug.h"

//if ConditionPassed() then 
//EncodingSpecificOperations();
//if CurrentInstrSet() == InstrSet_ARM then
//LR = PC - 4; else
//LR = PC<31:1> : ‘1’;
//if targetInstrSet == InstrSet_ARM then
//targetAddress = Align(PC,4) + imm32; else
//targetAddress = PC + imm32; 
//SelectInstrSet(targetInstrSet); 
//BranchWritePC(targetAddress);

static int arm_op_exec_arm_branch(struct TargetCore *core, ArmBranchImmArgType *arg)
{
	sint32 next_address = core->pc;
	uint32 *status = cpu_get_status(core);
	bool passed = ConditionPassed(arg->cond, *status);
	if (passed != FALSE) {
		InstrSetType type = CurrentInstrSet(*status);
		if (type == InstrSet_ARM) {
			cpu_set_reg(core, CpuRegId_LR, ((sint32)(((sint32)(core->pc)) - ((sint32)4))));
		}
		else {
			cpu_set_reg(core, CpuRegId_LR, core->pc | 0x1);
		}
		if (arg->type == InstrSet_ARM) {
			next_address = ((sint32)Align(core->pc, 4)) + arg->imm32;
		}
		else {
			next_address = ((sint32)core->pc) + arg->imm32;
		}
		if (SelectInstrSet(status, arg->type) != 0) {
			return -1;
		}
		DBG_ARM_BRANCH_IMM(arg, next_address, passed);
		return BranchWritePC(core, next_address);
	}
	DBG_ARM_BRANCH_IMM(arg, next_address, passed);
	return 0;
}

int arm_op_exec_arm_bl_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_bl_a1 *op = &core->decoded_code->code.arm_bl_a1;
	ArmBranchImmArgType arg;
	ZeroExtendArgType zarg[2];
	zarg[0].bitsize = 2U;
	zarg[0].data = 0;
	zarg[1].bitsize = 24U;
	zarg[1].data = op->imm24;

	arg.instrName = "BL";
	arg.cond = op->cond;
	arg.imm32 = SignExtendArray(2, zarg);
	arg.type = InstrSet_ARM;
	printf("imm24=0x%x¥n", (sint32)op->imm24);
	printf("imm32=%d¥n", (sint32)arg.imm32);
	return arm_op_exec_arm_branch(core, &arg);
}
int arm_op_exec_arm_blx_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_blx_a2 *op = &core->decoded_code->code.arm_blx_a2;
	ArmBranchImmArgType arg;
	ZeroExtendArgType zarg[3];
	zarg[0].bitsize = 1U;
	zarg[0].data = 0;
	zarg[1].bitsize = 1U;
	zarg[1].data = op->H;
	zarg[2].bitsize = 24U;
	zarg[2].data = op->imm24;

	arg.instrName = "BLX";
	arg.cond = ConditionAlways;
	arg.imm32 = SignExtendArray(3, zarg);
	arg.type = InstrSet_Thumb;

	return arm_op_exec_arm_branch(core, &arg);
}
