#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
#include "op_exec_debug.h"

int arm_op_exec_arm_add_imm_a1(struct TargetCore *core)
{
	uint32 next_address = core->pc + INST_ARM_SIZE;
	arm_OpCodeFormatType_arm_add_imm_a1 *op = &core->decoded_code->code.arm_add_imm_a1;

	if ((op->Rn == 0b1111) && (op->S == 0)) {
		//if Rn == ‘1111’ && S == ‘0’ then SEE ADR;
		//TODO
		return 0;
	}
	else if (op->Rn == 0b1101) {
		//if Rn == ‘1101’ then SEE ADD (SP plus immediate);
		//TODO
		return 0;
	}
	else if ((op->Rn == 0b1111) && (op->S != 0)) {
		//if Rd == ‘1111’ && S == ‘1’ then SEE SUBS PC, LR and related instructions;
		//TODO
		return 0;
	}
	ArmAddImmArgType arg;

	arg.imm32 = ARMExpandImm(op->imm12, CPU_ISSET_CY(cpu_get_status(core)));
	arg.Rd = op->Rd;
	arg.Rn = op->Rn;
	arg.instrName = "ADD";
	arg.S = op->S;
	arg.cond = op->cond;
	sint32 Rn = cpu_get_reg(core, op->Rn);
	sint32 Rd = cpu_get_reg(core, op->Rd);
	sint32 result = -1;
	uint32 *status = cpu_get_status(core);
	bool passed = ConditionPassed(op->cond, *status);
	AddWithCarryOutArgType add_arg;
	if (passed != FALSE) {
		result = AddWithCarry(32, Rn, arg.imm32, FALSE, &add_arg);
		 if (op->Rd != CpuRegId_PC) {
			cpu_set_reg(core, op->Rd, result);
			if (op->S != 0) {
				cpu_update_status_flag(status, result, add_arg.carry_out, add_arg.overflow);
			}
		 }
		 else {
			DBG_ARM_ADD_IMM(&arg, Rd, Rn, result, passed);
			return ALUWritePC(core, result);
		 }
	}
	DBG_ARM_ADD_IMM(&arg, Rd, Rn, result, passed);
	core->pc = next_address;
	return 0;
}

int arm_op_exec_push_1(struct TargetCore *core)
{
	printf("enter push\n");
	return 0;
}

