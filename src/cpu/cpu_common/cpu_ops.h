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
typedef enum {
	SRType_LSL = 0,
	SRType_LSR,
	SRType_ASR,
	SRType_ROR,
	SRType_RRX,
} SRType;
#include "assert.h"

static inline uint32 LSL_C(uint32 bits_N, uint32 x, uint32 shift, bool *carry_out)
{
	ASSERT(shift > 0);
	uint32 result = x << shift;
	if (carry_out != NULL) {
		if ((x & (1U << (bits_N - 1))) != 0) {
			*carry_out = TRUE;
		}
		else {
			*carry_out = FALSE;
		}
	}
	return result;
}
static inline uint32 LSL(uint32 bits_N, uint32 x, uint32 shift)
{
	ASSERT(shift >= 0);
	if (shift == 0) {
		return x;
	}
	else {
		return LSL_C(bits_N, x, shift, NULL);
	}
}

static inline uint32 LSR_C(uint32 bits_N, uint32 x, uint32 shift, bool *carry_out)
{
	ASSERT(shift > 0);
	uint32 result = x >> shift;
	if (carry_out != NULL) {
		if ((x & 0x1) != 0) {
			*carry_out = TRUE;
		}
		else {
			*carry_out = FALSE;
		}
	}
	return result;
}
static inline uint32 LSR(uint32 bits_N, uint32 x, uint32 shift)
{
	ASSERT(shift >= 0);
	if (shift == 0) {
		return x;
	}
	else {
		return LSR_C(bits_N, x, shift, NULL);
	}
}

static inline uint32 ROR_C(uint32 bits_N, uint32 x, uint32 shift, bool *carry_out)
{
	uint32 m;
	uint32 result;

	ASSERT(shift != 0);
	m = shift % bits_N;
	result = LSR(bits_N, x, m) | LSL(bits_N, x, bits_N - m);
	if (carry_out != NULL) {
		if ((result & (1U << (bits_N - 1))) != 0U) {
			*carry_out = TRUE;
		}
		else {
			*carry_out = FALSE;
		}
	}
	return result;
}
static inline uint32 Shift_C(uint32 bits_N, uint32 value, SRType type, uint32 amount, bool carry_in, bool *carry_out)
{
	if (amount == 0) {
		if (carry_out != NULL) {
			*carry_out = carry_in;
		}
		return value;
	}
	switch (type) {
	case SRType_ROR:
		return ROR_C(bits_N, value, amount, carry_out);
	default:
		//TOOD ERROR
		return -1;
	}
}
static inline uint32 ARMExpandImm_C(uint32 imm12, bool carry_in, bool *carry_out)
{
	uint32 unrotated_value = (imm12 & 0xFF);
	uint32 amount = ( 2U * ((imm12 & 0xF00) >> 8U) );
	return Shift_C(32U, unrotated_value, SRType_ROR, amount, carry_in, carry_out);
}
static inline uint32 ARMExpandImm(uint32 imm12, bool carry_in)
{
	return ARMExpandImm_C(imm12, carry_in, NULL);
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

typedef enum {
	InstrSet_ARM = 0,
	InstrSet_Thumb,
	InstrSet_Jazelle, /* not supported */
	InstrSet_ThumbEE, /* not supported */
} InstrSetType;

static inline InstrSetType CurrentInstrSet(uint32 status)
{
	if (CPU_STATUS_BIT_IS_SET(status, CPU_STATUS_BITPOS_J)) {
		if (CPU_STATUS_BIT_IS_SET(status, CPU_STATUS_BITPOS_T)) {
			return InstrSet_ThumbEE;
		}
		else {
			return InstrSet_Jazelle;
		}
	}
	else {
		if (CPU_STATUS_BIT_IS_SET(status, CPU_STATUS_BITPOS_T)) {
			return InstrSet_Thumb;
		}
		else {
			return InstrSet_ARM;
		}
	}
}
static inline int SelectInstrSet(uint32 *status, InstrSetType type)
{
	InstrSetType current_type = CurrentInstrSet(*status);
	if (type == InstrSet_ARM) {
		if (current_type == InstrSet_ThumbEE) {
			//UNPREDICTABLE
			return -1;
		}
		CPU_STATUS_BIT_CLR(status, CPU_STATUS_BITPOS_J);
		CPU_STATUS_BIT_CLR(status, CPU_STATUS_BITPOS_T);
	}
	else if (type == InstrSet_Thumb) {
		CPU_STATUS_BIT_CLR(status, CPU_STATUS_BITPOS_J);
		CPU_STATUS_BIT_SET(status, CPU_STATUS_BITPOS_T);
	}
	else {
		// not supported
		return -1;
	}
	return 0;
}

static inline void BranchTo(TargetCoreType *core, uint32 address)
{
	core->pc = address;
	return;
}
static inline int BXWritePC(TargetCoreType *core, uint32 address)
{
	uint32 *status = cpu_get_status(core);
	InstrSetType type = CurrentInstrSet(*status);
	if (type == InstrSet_ThumbEE) {
		if ((address & 0x00000001) != 0) {
			BranchTo(core, (address & ~0x00000001));
		}
		else {
			//UNPREDICTABLE
			return -1;
		}
	}
	else {
		if ((address & 0x00000001) != 0) {
			SelectInstrSet(status, InstrSet_Thumb);
			BranchTo(core, (address & ~0x00000001));
		}
		else if ((address & 0x00000002) == 0) {
			SelectInstrSet(status, InstrSet_ARM);
			BranchTo(core, address);
		}
		else {
			//UNPREDICTABLE
			return -1;
		}
	}
	return 0;
}
static inline int BranchWritePC(TargetCoreType *core, uint32 address)
{
	uint32 *status = cpu_get_status(core);
	InstrSetType type = CurrentInstrSet(*status);
	if (type == InstrSet_ARM) {
		BranchTo(core, (address & ~0x00000003));
	}
	else if (type != InstrSet_Jazelle) {
		BranchTo(core, (address & ~0x00000001));
	}
	else {
		//not supported
		return -1;
	}
	return 0;
}

static inline int ALUWritePC(TargetCoreType *core, uint32 address)
{
	uint32 *status = cpu_get_status(core);
	InstrSetType type = CurrentInstrSet(*status);
	if (type == InstrSet_ARM) {
		return BXWritePC(core, address);
	}
	else {
		return BranchWritePC(core, address);
	}
}

#define UInt(x)		( (sint64)((uint64)((uint32)(x))) )
#define SInt(x)		((sint64)((sint32)(x)))

typedef struct {
	bool carry_out;
	bool overflow;
} AddWithCarryOutArgType;
static inline sint32 AddWithCarry(uint32 bits_N, sint32 x, sint32 y, sint32 carry_in, AddWithCarryOutArgType *out)
{
	sint64 unsigned_sum = UInt(x) + UInt(y) + UInt(carry_in);;
	sint64 signed_sum = SInt(x) + SInt(y) + UInt(carry_in);
	sint32 result = (sint32)unsigned_sum;
	if (out != NULL) {
		if (UInt(result) == unsigned_sum) {
			out->carry_out = FALSE;
		}
		else {
			out->carry_out = TRUE;
		}
		if (SInt(result) == signed_sum) {
			out->overflow = FALSE;
		}
		else {
			out->overflow = TRUE;
		}
	}
	return result;
}

static inline void cpu_update_status_flag(uint32 *status, uint32 result, bool carry_out, bool overflow)
{
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, carry_out);
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_V, overflow);
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
}
#endif /* _CPU_OPS_H_ */
