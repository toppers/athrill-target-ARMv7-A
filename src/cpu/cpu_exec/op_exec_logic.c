#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
#include "cpu_op_types.h"
#include "op_exec_debug.h"

static int arm_op_exec_arm_mov_imm(struct TargetCore *core, ArmMovImmArgType *arg)
{
	uint32 next_address = core->pc + INST_ARM_SIZE;
	bool carry_out = FALSE;
	sint32 Rd = cpu_get_reg(core, arg->Rd);
	sint32 result = arg->imm32;
	uint32 *status = cpu_get_status(core);
	bool passed = ConditionPassed(arg->cond, *status);
	if (passed != FALSE) {
		cpu_set_reg(core, arg->Rd, result);
		 if (arg->Rd != CpuRegId_PC) {
			if (arg->S != 0) {
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, carry_out);
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
			}
		 }
		 else {
			DBG_ARM_MOV_IMM(arg, Rd, result, passed);
			return ALUWritePC(core, result);
		 }
	}
	DBG_ARM_MOV_IMM(arg, Rd, result, passed);
	core->pc = next_address;
	return 0;
}

int arm_op_exec_arm_mov_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mov_imm_a1 *op = &core->decoded_code->code.arm_mov_imm_a1;

	if ((op->Rd == 0b1111) && (op->S != 0)) {
		//if Rd == ‘1111’ && S == ‘1’ then SEE SUBS PC, LR and related instructions;
		//TODO
		return 0;
	}
	ArmMovImmArgType arg;
	arg.instrName = "MOV";
	arg.imm32 = ARMExpandImm_C(op->imm12, CPU_ISSET_CY(cpu_get_status(core)), &arg.carry_out);
	arg.Rd = op->Rd;
	arg.S = op->S;
	arg.cond = op->cond;

	return arm_op_exec_arm_mov_imm(core, &arg);
}

int arm_op_exec_arm_mov_imm_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mov_imm_a2 *op = &core->decoded_code->code.arm_mov_imm_a2;
	if (op->Rd == CpuRegId_PC) {
		//TODO UNPREDICTABLE
		return -1;
	}
	ArmMovImmArgType arg;
	ZeroExtendArgType zarg[2];
	arg.instrName = "MOVW";
	zarg[0].bitsize = 12U;
	zarg[0].data = op->imm12;
	zarg[1].bitsize = 4U;
	zarg[1].data = op->imm4;
	arg.imm32 = ZeroExtendArray(2U, zarg);
	arg.Rd = op->Rd;
	arg.S = FALSE;
	arg.cond = op->cond;

	return arm_op_exec_arm_mov_imm(core, &arg);
}
