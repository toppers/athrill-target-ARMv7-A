#ifndef _CPU_OP_TYPES_H_
#define _CPU_OP_TYPES_H_

#include "std_types.h"
#include "target_cpu.h"
#include <string.h>

/************************************************
 * pseudo code common data types
 ************************************************/
static inline const char *DbgStatusUpdateFlag(bool flag)
{
	return ( (flag != FALSE) ? "S" : "" );
}

static inline const char *DbgBoolFlag(bool flag)
{
	return ( (flag != FALSE) ? "T" : "F" );
}
static inline const char *DbgPassedFlag(bool flag)
{
	return ( (flag != FALSE) ? "Done" : "None" );
}

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
#define DBG_FMT_STR	"%s "

typedef struct {
	char* name;
	uint32 regId;
	sint32 regData;
} PseudoCodeRegisterDataType; 						/* Rn, Rd, Rt, etc */
#define DBG_FMT_PseudoCodeRegisterDataType			"%s(R%d(%d)) "
#define DBG_ARG_PseudoCodeRegisterDataType(arg)		(arg)->name, (arg)->regId, (arg)->regData

typedef sint32	PseudoCodeImmediateData32Type; 		/* imm32 */
#define DBG_FMT_PseudoCodeImmediateData32Type		"imm32(%d) "
#define DBG_ARG_PseudoCodeImmediateData32Type(arg)	(*(arg))

typedef uint32	PseudoCodeConditionDataType; 		/* cond */
#define DBG_FMT_PseudoCodeConditionDataType			"%s "
#define DBG_ARG_PseudoCodeConditionDataType(arg)	ConditionString(*(arg))

typedef uint8	PseudoCodeUpdateStatusFlagType; 	/* S */
#define DBG_FMT_PseudoCodeUpdateStatusFlagType		"%s "
#define DBG_ARG_PseudoCodeUpdateStatusFlagType(arg)	DbgStatusUpdateFlag(*(arg))

typedef uint32	PseudoCodeStatusType;
#define DBG_FMT_PseudoCodeStatusType			"status(0x%x) "
#define DBG_ARG_PseudoCodeStatusType(arg)		(*(arg))

typedef struct {
	bool	overflow;
	bool	carry;
	bool	zero;
	bool	negative;
} PseudoCodeStatusFlagType;
#define DBG_FMT_PseudoCodeStatusFlagType			"O(%s)|C(%s)|Z(%s)|N(%s) "
#define DBG_ARG_PseudoCodeStatusFlagType(arg)	DbgBoolFlag((arg)->overflow), DbgBoolFlag((arg)->carry), DbgBoolFlag((arg)->zero), DbgBoolFlag((arg)->negative)
static inline void cpu_conv_status_flag(uint32 status, PseudoCodeStatusFlagType *out)
{
	memset(out, 0, sizeof(PseudoCodeStatusFlagType));
	if (CPU_STATUS_BIT_IS_SET(status, CPU_STATUS_BITPOS_N)) {
		out->negative = TRUE;
	}
	if (CPU_STATUS_BIT_IS_SET(status, CPU_STATUS_BITPOS_V)) {
		out->overflow = TRUE;
	}
	if (CPU_STATUS_BIT_IS_SET(status, CPU_STATUS_BITPOS_C)) {
		out->carry = TRUE;
	}
	if (CPU_STATUS_BIT_IS_SET(status, CPU_STATUS_BITPOS_Z)) {
		out->zero = TRUE;
	}
}
typedef bool PseudoCodeCondPassedType;
#define DBG_FMT_PseudoCodeCondPassedType		"Passed(%s) "
#define DBG_ARG_PseudoCodeCondPassedType(arg)	DbgPassedFlag(*(arg))

#define DBG_FMT_bool		"%s "
#define DBG_ARG_bool(arg)	DbgBoolFlag(*(arg))
#define DBG_FMT_sint32		"%d "
#define DBG_ARG_sint32(arg)	(*(arg))

#define OP_SET_REG(core, arg, op, regName)	\
do {	\
	(arg)->regName.name = #regName;	\
	(arg)->regName.regId = (op)->regName;	\
	(arg)->regName.regData = cpu_get_reg(core, (op)->regName);	\
} while (0)

/************************************************/

typedef struct {
	char* instrName;
	sint32 imm32;
	uint32 Rd;
	uint32 cond;
	uint8 S;
	bool carry_out;
} ArmMovImmArgType;

typedef struct {
	char* instrName;
	sint32 imm32;
	uint32 Rd;
	uint32 Rn;
	uint32 cond;
	uint8 S;
} ArmAddImmArgType;

typedef struct {
	char* instrName;
	sint32 imm32;
	uint32 cond;
	InstrSetType type;
} ArmBranchImmArgType;

typedef struct {
	char* instrName;
	bool add_flag;
	bool index_flag;
	bool wback_flag;
	uint32 imm32;
	uint32 Rn;
	uint32 Rt;
	uint32 cond;
} ArmStoreImmArgType;

typedef struct {
	char* instrName;
	bool add_flag;
	bool index_flag;
	bool wback_flag;
	uint32 imm32;
	uint32 Rn;
	uint32 Rt;
	uint32 cond;
} ArmLoadImmArgType;

#endif /* _CPU_OP_TYPES_H_ */
