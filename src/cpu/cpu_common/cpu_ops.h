#ifndef _CPU_OPS_H_
#define _CPU_OPS_H_
#include "target_cpu.h"
#include "cpu_op_types.h"

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

static inline uint32 ROR(uint32 bits_N, uint32 x, uint32 shift)
{
	uint32 result;

	if (shift == 0) {
		result = x;
	}
	else {
		result = ROR_C(bits_N, x, shift, NULL);
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

static inline uint32 Shift(uint32 bits_N, uint32 value, SRType type, uint32 amount, bool carry_in)
{
	return Shift_C(bits_N, value, type, amount, carry_in, NULL);
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
#define ConditionAlways		0b111
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
	case ConditionAlways:
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

static inline void BranchTo(uint32 *pc, uint32 address)
{
	*pc = address;
	return;
}
static inline int BXWritePC(uint32 *pc, uint32 *status, uint32 address)
{
	InstrSetType type = CurrentInstrSet(*status);
	if (type == InstrSet_ThumbEE) {
		if ((address & 0x00000001) != 0) {
			BranchTo(pc, (address & ~0x00000001));
		}
		else {
			//UNPREDICTABLE
			return -1;
		}
	}
	else {
		if ((address & 0x00000001) != 0) {
			SelectInstrSet(status, InstrSet_Thumb);
			BranchTo(pc, (address & ~0x00000001));
		}
		else if ((address & 0x00000002) == 0) {
			SelectInstrSet(status, InstrSet_ARM);
			BranchTo(pc, address);
		}
		else {
			//UNPREDICTABLE
			return -1;
		}
	}
	return 0;
}
static inline int BranchWritePC(uint32 *pc, uint32 *status, uint32 address)
{
	InstrSetType type = CurrentInstrSet(*status);
	if (type == InstrSet_ARM) {
		BranchTo(pc, (address & ~0x00000003));
	}
	else if (type != InstrSet_Jazelle) {
		BranchTo(pc, (address & ~0x00000001));
	}
	else {
		//not supported
		return -1;
	}
	return 0;
}
#define LoadWritePC(pc, status, addr)	BXWritePC(pc, status, addr)

static inline int ALUWritePC(uint32 *pc, uint32 *status, uint32 address)
{
	InstrSetType type = CurrentInstrSet(*status);
	if (type == InstrSet_ARM) {
		return BXWritePC(pc, status, address);
	}
	else {
		return BranchWritePC(pc, status, address);
	}
}

#define UInt(x)		( (sint64)((uint64)((uint32)(x))) )
#define SInt(x)		((sint64)((sint32)(x)))

static inline sint32 AddWithCarry(uint32 bits_N, sint32 x, sint32 y, sint32 carry_in, PseudoCodeStatusFlagType *out)
{
	sint64 unsigned_sum = UInt(x) + UInt(y) + UInt(carry_in);;
	sint64 signed_sum = SInt(x) + SInt(y) + UInt(carry_in);
	sint32 result = (sint32)unsigned_sum;
	if (out != NULL) {
		if (UInt(result) == unsigned_sum) {
			out->carry = FALSE;
		}
		else {
			out->carry = TRUE;
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

static inline void cpu_update_status_flag(uint32 *status, uint32 result, PseudoCodeStatusFlagType *status_flag)
{
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, status_flag->carry);
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_V, status_flag->overflow);
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
}

typedef struct {
	uint32 bitsize;
	uint32 data;
} ZeroExtendArgType;

static inline uint32 ZeroExtendArray(uint32 array_num, ZeroExtendArgType *array)
{
	uint32 result = 0;
	uint32 bits = 0;
	int i;
	for (i = 0; i < array_num; i++) {
		result |= (array[i].data << bits);
		bits += array[i].bitsize;
	}
	return result;
}
static inline sint32 SignExtendArray(uint32 array_num, ZeroExtendArgType *array)
{
	uint32 result = 0;
	uint32 bits = 0;
	int i;
	for (i = 0; i < array_num; i++) {
		result |= (array[i].data << bits);
		bits += array[i].bitsize;
	}
	return op_sign_extend(bits - 1, result);
}
#define Align(x, y)	(y) * ((x) / (y))
#define UnalignedSupport()		TRUE
#define BYTEMASK_BIT_ISSET(bytemask, bitpos) 	( (bytemask) & ~(1U << (bitpos)) )

static inline void user_cpsr_set(uint32 *status, uint32 mask, uint32 value)
{
	*status = ( ((*status) & ~mask) | (value & mask) );
	return;
}
static inline int CPSRWriteByInstr(TargetCoreType *core, uint32 value, uint8 bytemask, bool is_excpt_return)
{
	uint32 *status = cpu_get_status(core);
	bool privileged = CurrentModeIsNotUser(*status);
	bool nmfi = IsSCTLR_NMFI(core);

	if (BYTEMASK_BIT_ISSET(bytemask, 3) != 0) {
		//CPSR<31:27> = value<31:27>; // N,Z,C,V,Q flags
		user_cpsr_set(status, 0xF8000000, value);
	}
	if (is_excpt_return) {
		//CPSR<26:24> = value<26:24>; // IT<1:0>,J execution state bits
		user_cpsr_set(status, 0x07000000, value);
	}
	if (BYTEMASK_BIT_ISSET(bytemask, 2) != 0) {
		// bits <23:20> are reserved SBZP bits
		//CPSR<19:16> = value<19:16>; // GE<3:0> flags
		user_cpsr_set(status, 0x000F0000, value);
	}
	if (BYTEMASK_BIT_ISSET(bytemask, 1) != 0) {
		if (is_excpt_return) {
			//CPSR<15:10> = value<15:10>; // IT<7:2> execution state bits
			//CPSR<9> = value<9>; // E bit is user-writable
			user_cpsr_set(status, 0x0000FE00, value);
		}
		if (privileged && (IsSecure(core) || IsSCR_AW(core) || HaveVirtExt(core))) {
			//CPSR<8> = value<8>; // A interrupt mask
			user_cpsr_set(status, 0x00000100, value);
		}
		if (BYTEMASK_BIT_ISSET(bytemask, 0) != 0) {
			if (privileged) {
				//CPSR<7> = value<7>; // I interrupt mask
				user_cpsr_set(status, 0x00000080, value);
			}
			if (privileged && (!nmfi || (BYTEMASK_BIT_ISSET(value, 6) == 0)) &&
				( IsSecure(core) || IsSCR_FW(core) || HaveVirtExt(core)) ) {
				//CPSR<6> = value<6>; // F interrupt mask
				user_cpsr_set(status, 0x00000040, value);
			}
			if (is_excpt_return) {
				//CPSR<5> = value<5>; // T execution state bit
				user_cpsr_set(status, 0x00000020, value);
			}
			if (privileged) {
				uint8 value4_0 = (value & 0x1F);
				uint32 cpsr_m = ((*status) & 0x1F);
				//value<4:0>
				if (BadMode(value4_0, core)) {
					//UNPREDICTABLE;
					return -1;
				}
				else {
					// Check for attempts to enter modes only permitted in Secure state from
					// Non-secure state. These are Monitor mode ('10110'), and FIQ mode ('10001')
					// if the Security Extensions have reserved it. The definition of UNPREDICTABLE
					// does not permit the resulting behavior to be a security hole.
					if (!IsSecure(core) && (value4_0 == 0b10110)) {
						//then UNPREDICTABLE;
						return -1;
					} 
					if (!IsSecure(core) && (value4_0 == 0b10001) && IsNSACR_RFR(core)) {
						//then UNPREDICTABLE;
						return -1;
					}
					// There is no Hyp mode ('11010') in Secure state, so that is UNPREDICTABLE
					if ((IsSCR_NS(core) == FALSE) && (value4_0 == 0b11010)) {
						 //then UNPREDICTABLE;
						 return -1;
					}
					// Cannot move into Hyp mode directly from a Non-secure PL1 mode
					if (!IsSecure(core) && (cpsr_m != 0b11010) && (value4_0 == 0b11010)) {
						//UNPREDICTABLE;
						return -1;
					}
					// Cannot move out of Hyp mode with this function except on an exception return
					if ((cpsr_m == 0b11010) && (value4_0 != 0b11010) && !is_excpt_return) {
						//UNPREDICTABLE;
						return -1;
					}
					// CPSR<4:0>, mode bits
					user_cpsr_set(status, 0x0000001F, value4_0);
				}
			}
		}
	}
	return 0;
}

#endif /* _CPU_OPS_H_ */
