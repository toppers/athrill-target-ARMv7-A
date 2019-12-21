#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "dbg_log.h"
#include "bus.h"

int arm_op_exec_add_1(struct TargetCore *core)
{
	arm_OpCodeFormatType_add_1 *op = &core->decoded_code->code.add_1;
	sint32 imm32 = OpSignExtend(12, op->imm12);
	sint32 Rn = cpu_get_reg(core, op->Rn);
	sint32 Rd = cpu_get_reg(core, op->Rd);
	sint32 result;
	uint32 *status = cpu_get_status(core);

	if (ConditionPassed(op->cond, *status) == TRUE) {
		result = Rn + imm32;
		 if (op->Rd == CpuRegId_PC) {
			//TODO
			printf("NOT SUPPORTED...\n");
		 }
		 else {
			DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
					"0x%x: ADD Rd(R%d(%d)), Rn(R%d(%d)), imm12(%d):%d\n",
					core->pc, op->Rd, Rd, op->Rn, Rn, imm32, result));
			cpu_set_reg(core, op->Rd, result);
			op_chk_and_set_carry(status, Rn, imm32);
			op_chk_and_set_overflow(status, Rn, imm32);
			op_chk_and_set_zero(status, result);
			op_chk_and_set_sign(status, result);
		 }
	}
	else {
		DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
				"0x%x: ADD Rd(R%d(%d)), Rn(R%d(%d)), imm12(%d):%s\n",
				core->pc, op->Rd, Rd, op->Rn, Rn, imm32, "SKIPPED"));
	}
	core->pc += INST_ARM_SIZE;
	return 0;
}

int arm_op_exec_push_1(struct TargetCore *core)
{
	printf("enter push\n");
	return 0;
}

