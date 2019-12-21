#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
#include "cpu_exec/op_exec_debug.h"

int arm_op_exec_add_1(struct TargetCore *core)
{
	arm_OpCodeFormatType_add_1 *op = &core->decoded_code->code.add_1;

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
	if ((op->Rn == 0b1111) && (op->S == 1)) {
		//if Rd == ‘1111’ && S == ‘1’ then SEE SUBS PC, LR and related instructions;
		//TODO
		return 0;
	}
	uint32 imm32 = ARMExpandImm(op->imm12, CPU_ISSET_CY(cpu_get_status(core)));
	uint32 Rn = cpu_get_reg(core, op->Rn);
	uint32 Rd = cpu_get_reg(core, op->Rd);
	uint32 result = -1;
	uint32 *status = cpu_get_status(core);
	bool passed = ConditionPassed(op->cond, *status);
	if (passed != FALSE) {
		result = Rn + imm32;
		 if (op->Rd == CpuRegId_PC) {
			//TODO
			printf("NOT SUPPORTED...\n");
		 }
		 else {
			cpu_set_reg(core, op->Rd, result);
			if (op->S == 1) {
				op_chk_and_set_carry(status, Rn, imm32);
				op_chk_and_set_overflow(status, Rn, imm32);
				op_chk_and_set_zero(status, result);
				op_chk_and_set_sign(status, result);
			}
		 }
	}
	DBG_ADD_1(op, Rd, Rn, imm32, result, passed);
	core->pc += INST_ARM_SIZE;
	return 0;
}

int arm_op_exec_push_1(struct TargetCore *core)
{
	printf("enter push\n");
	return 0;
}

