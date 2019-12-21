#ifndef _CPU_OPS_H_
#define _CPU_OPS_H_
#include "target_cpu.h"

#define CPU_PSW_S		(1 << 31)	/* N */
#define CPU_PSW_Z		(1 << 30)	/* Z */
#define CPU_PSW_CY		(1 << 29)	/* C */
#define CPU_PSW_OV		(1 << 28)	/* V */

#define CPU_SET_CY(status)		(*status) |= CPU_PSW_CY
#define CPU_CLR_CY(status)		(*status) &= ~CPU_PSW_CY
#define CPU_ISSET_CY(status)	( ((*status) & CPU_PSW_CY) == CPU_PSW_CY)

#define CPU_SET_OV(status)		(*status) |= CPU_PSW_OV
#define CPU_CLR_OV(status)		(*status) &= ~CPU_PSW_OV
#define CPU_ISSET_OV(status)	( ((*status) & CPU_PSW_OV) == CPU_PSW_OV)

#define CPU_SET_S(status)		(*status) |= CPU_PSW_S
#define CPU_CLR_S(status)		(*status) &= ~CPU_PSW_S
#define CPU_ISSET_S(status)	( ((*status) & CPU_PSW_S) == CPU_PSW_S)

#define CPU_SET_Z(status)		(*status) |= CPU_PSW_Z
#define CPU_CLR_Z(status)		(*status) &= ~CPU_PSW_Z
#define CPU_ISSET_Z(status)	( ((*status) & CPU_PSW_Z) == CPU_PSW_Z)


static inline void op_chk_and_set_carry(uint32 *status, uint32 a32, uint32 b32)
{
	uint64 tmp1 = a32;
	uint64 tmp2 = b32;
	uint64 result = tmp1 + tmp2;

	if (result > CPU_REG_UINT_MAX) {
		CPU_SET_CY(status);
	}
	else {
		CPU_CLR_CY(status);
	}
	return;
}

static inline void op_chk_and_set_overflow(uint32 *status, sint64 a64, sint64 b64)
{
	sint64 result = a64 + b64;

	if (result > (sint64)CPU_REG_PLUS_MAX) {
		CPU_SET_OV(status);
	}
	else if (result < (sint64)CPU_REG_MINUS_MAX) {
		CPU_SET_OV(status);
	}
	else {
		CPU_CLR_OV(status);
	}
	return;
}

static inline void op_chk_and_set_sign(uint32 *status, sint32 result)
{
	if (result < 0) {
		CPU_SET_S(status);
	}
	else {
		CPU_CLR_S(status);
	}
	return;
}

static inline void op_chk_and_set_zero(uint32 *status, sint32 result)
{
	if (result == 0) {
		CPU_SET_Z(status);
	}
	else {
		CPU_CLR_Z(status);
	}
	return;
}

/*
 * 指定されたbitに符号ビットがある場合は31bitまで1埋めする(符号拡張)
 */
static inline sint32 op_sign_extend(uint32 bit, uint32 data)
{
	int i;
	if (data & (1 << bit)) {
		for (i = bit; i < 32; i++) {
			data = ( data | (1 << i) );
		}
	}
	return data;
}
#define OP_FORMAT2_IMM_SIGN_EXTEND(data)	op_sign_extend(4, (data))

/*
 * 指定されたbitから31bitまで０埋めする
 */
static inline uint32 op_zero_extend(uint32 bit, uint32 data)
{
	int i;
	for (i = bit; i < 32; i++) {
		data = ( data & ~(1 << i) );
	}
	return data;
}

static inline char *addr2devregname(uint32 addr)
{
	//TODO
	return "NULL";
}
#define OpSignExtend(size, data)	op_sign_extend(((size) - 1), (uint32)(data))
#define OpZeroExtend(size, data)	op_zero_extend((size), (uint32)(data))

static inline bool ConditionPassed(uint8 cond, uint32 status)
{
	uint8 cond1_3 = (cond & 0xF) >> 1U;
	uint8 cond0 = (cond & 0x1);
	bool result = FALSE;
	switch (cond1_3) {
	case 0b000:
		//when ‘000’ result = (APSR.Z == ‘1’); // EQ or NE
		result = CPU_ISSET_Z(&status);
		break;
	case 0b001:
		//when ‘001’ result = (APSR.C == ‘1’); // CS or CC
		result = CPU_ISSET_CY(&status);
		break;
	case 0b010:
		//when ‘010’ result = (APSR.N == ‘1’); // MI or PL
		result = CPU_ISSET_S(&status);
		break;
	case 0b011:
		//when ‘011’ result = (APSR.V == ‘1’); // VS or VC
		result = CPU_ISSET_OV(&status);
		break;
	case 0b100:
		//when ‘100’ result = (APSR.C == ‘1’) && (APSR.Z == ‘0’); // HI or LS
		result = (CPU_ISSET_CY(&status) && CPU_ISSET_Z(&status));
		break;
	case 0b101:
		//when ‘101’ result = (APSR.N == APSR.V); // GE or LT
		result = (CPU_ISSET_S(&status) == CPU_ISSET_OV(&status));
		break;
	case 0b110:
		//when ‘110’ result = (APSR.N == APSR.V) && (APSR.Z == ‘0’); // GT or LE
		result = ((CPU_ISSET_S(&status) == CPU_ISSET_OV(&status)) && CPU_ISSET_Z(&status));
		break;
	case 0b111:
		//when ‘111’ result = TRUE; // A
		result = TRUE;
		break;
	default:
		//TODO ERROR
		break;
	}
	//if cond<0> == ‘1’ && cond != ‘1111’ then
	//result = !result
	if (cond0 == 0x1 && (cond != 0xF)) {
		result = ~result;
	}
	return result;
}

#endif /* _CPU_OPS_H_ */
