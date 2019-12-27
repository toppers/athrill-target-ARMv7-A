#ifndef _OP_EXEC_DEBUG_H_
#define _OP_EXEC_DEBUG_H_

#include "dbg_log.h"
#include "cpu_op_types.h"

#define SKIP_RESULT(cond) ( ((cond) != FALSE) ? "FALSE" : "TRUE" )
#define SIGN_FLAG(S)	( ((S) != FALSE) ? "S" : "" )
#define FMT_STR	"%s"

#if 0
static inline void DBG_ARM_ADD_IMM(ArmAddImmArgType *arg, uint32 Rd, uint32 Rn, uint32 result, bool passed)
{
	PseudoCodeRegisterDataType reg;
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		FMT_STR FMT_STR "%s" DBG_FMT_PseudoCodeRegisterDataType ", Rn(R%d(%d)), imm12(%d): %d (skip=%s)\n",
		arg->instrName, SIGN_FLAG(arg->S), ConditionString(arg->cond), DBG_ARG_PseudoCodeRegisterDataType(&reg), (arg)->Rn, Rn,
		arg->imm32, result, SKIP_RESULT(passed)));
}
#endif

static inline void DBG_ARM_MOV_IMM(ArmMovImmArgType *arg, uint32 Rd, uint32 result, bool passed)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		"%s%s%s Rd(R%d(%d)), imm(%d): %d (skip=%s)\n",
		arg->instrName, SIGN_FLAG(arg->S), ConditionString(arg->cond), (arg)->Rd, Rd,
		arg->imm32, result, SKIP_RESULT(passed)));
}
static inline void DBG_ARM_BRANCH_IMM(ArmBranchImmArgType *arg, uint32 next_address, bool passed)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		"%s%s imm(%d): 0x%x (skip=%s)\n",
		arg->instrName, ConditionString(arg->cond), (arg)->imm32,
		next_address, SKIP_RESULT(passed)));
}
static inline void DBG_ARM_STR_IMM(ArmStoreImmArgType *arg, uint32 Rt, uint32 Rn, uint32 address, uint32 data, bool passed)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		"%s%s Rt(R%d(%d)), Rn(R%d(0x%x)), imm12(%s%d) wback=%s: %d@0x%x (skip=%s)\n",
		arg->instrName, ConditionString(arg->cond), (arg)->Rt, Rt, (arg)->Rn, Rn,
		arg->add_flag ? "+" : "-", (arg)->imm32,
		arg->wback_flag ? "TRUE" : "FALSE",
		data, address, SKIP_RESULT(passed)));
}
static inline void DBG_ARM_LDR_IMM(ArmLoadImmArgType *arg, uint32 Rt, uint32 Rn, uint32 address, uint32 data, uint32 result, bool passed)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		"%s%s Rt(R%d(%d)), Rn(R%d(0x%x)), imm12(%s%d) wback=%s %d@0x%x : %d (skip=%s)\n",
		arg->instrName, ConditionString(arg->cond), (arg)->Rt, Rt, (arg)->Rn, Rn,
		arg->add_flag ? "+" : "-", (arg)->imm32,
		arg->wback_flag ? "TRUE" : "FALSE",
		data, address, result, SKIP_RESULT(passed)));
}

#endif /* _OP_EXEC_DEBUG_H_ */
