#ifndef _OP_EXEC_DEBUG_H_
#define _OP_EXEC_DEBUG_H_

#include "dbg_log.h"

#define SKIP_RESULT(cond) ( ((cond) != FALSE) ? "FALSE" : "TRUE" )
#define SIGN_FLAG(S)	( ((S) != FALSE) ? "S" : "" )


static inline const char *ConditionString(uint8 cond)
{
	static const char *values[15] = {
			"EQ", //0
			"NE", //1
			"CS", //2
			"CC", //3
			"MI", //4
			"PL", //5
			"VS", //6
			"VC", //7
			"HI", //8
			"LS", //9
			"GE", //10
			"LT", //11
			"GT", //12
			"LE", //13
			"", //14
	};
	return values[cond];
}
static inline void DBG_ADD_1(arm_OpCodeFormatType_add_1 *op, uint32 Rd, uint32 Rn, uint32 imm32, uint32 result, bool passed)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		"ADD%s%s Rd(R%d(%u)), Rn(R%d(%u)), imm12(%u): %d (skip=%s)\n",
		SIGN_FLAG(op->S), ConditionString(op->cond), (op)->Rd, Rd, (op)->Rn, Rn,
		imm32, result, SKIP_RESULT(passed)));
}


#endif /* _OP_EXEC_DEBUG_H_ */
