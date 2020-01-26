#ifndef _ARM_PSEUDO_FPU_CODE_H_
#define _ARM_PSEUDO_FPU_CODE_H_

#include "target_cpu.h"
#include "arm_pseudo_code_type.h"
#include "coproc/arm_coproc.h"
#include "assert.h"

#define OP_SET_FREG(core, arg, op, regName)	\
do {	\
	(arg)->regName.name = #regName;	\
	(arg)->regName.regId = (op)->regName;	\
	(arg)->regName.reg.Data32 = cpu_get_freg(core, (op)->regName);	\
} while (0)

typedef enum {
	FPType_Nonzero = 0,
	FPType_Zero,
	FPType_Infinity,
	FPType_QNaN,
	FPType_SNaN
} FPType;

static inline uint32 FP_ExpBits(CoprocFpuDataSizeType size)
{
	if (size == CoprocFpuDataSize_16) {
		return 5;
	}
	else if (size == CoprocFpuDataSize_32) {
		return 8;
	}
	else {
		return 11;
	}
}
static inline uint32 FP_Bits(CoprocFpuDataSizeType size)
{
	if (size == CoprocFpuDataSize_16) {
		return 16;
	}
	else if (size == CoprocFpuDataSize_32) {
		return 32;
	}
	else {
		return 64;
	}
}
static inline void FPZero(bool sign, CoprocFpuRegisterType *data)
{
	data->reg.raw64 = 0;
	if (sign == FALSE) {
		return;
	}
	if (data->size == CoprocFpuDataSize_16) {
		data->reg.raw16 |= (1U << 15);
	}
	else if (data->size == CoprocFpuDataSize_32) {
		data->reg.raw32 |= (1U << 31);
	}
	else {
		data->reg.raw32_array[1] |= (1U << 31);
	}
	return;
}

static inline void FPTwo(CoprocFpuRegisterType *data)
{
	data->reg.raw64 = 0;
	//sign = '0';
	//exp = '1':Zeros(E-1);
	//frac = Zeros(F);
	//return sign:exp:frac;
	if (data->size == CoprocFpuDataSize_16) {
		//E = 5;
		//F = N - E - 1; ==> F= 16 - 5 - 1 = 10
		data->reg.raw16 |= (1U << 14);
	}
	else if (data->size == CoprocFpuDataSize_32) {
		//E = 8;
		//F = N - E - 1; ==> F= 32 - 8 - 1 = 23
		data->reg.raw32 |= (1U << 30);
	}
	else {
		//E = 11;
		//F = N - E - 1; ==> F= 64 - 11 - 1 = 52
		data->reg.raw32_array[1] |= (1U << 30);
	}
	return;
}

static inline void FPThree(CoprocFpuRegisterType *data)
{
	data->reg.raw64 = 0;
	//sign = '0';
	//exp = '1':Zeros(E-1);
	//frac = '1':Zeros(F-1);
	//return sign:exp:frac
	if (data->size == CoprocFpuDataSize_16) {
		//E = 5;
		//F = N - E - 1; ==> F= 16 - 5 - 1 = 10
		data->reg.raw16 |= ( (1U << 14) | (1U << 9) );
	}
	else if (data->size == CoprocFpuDataSize_32) {
		//E = 8;
		//F = N - E - 1; ==> F= 32 - 8 - 1 = 23
		data->reg.raw32 |= ( (1U << 30) | (1U << 22) );
	}
	else {
		//E = 11;
		//F = N - E - 1; ==> F= 64 - 11 - 1 = 52: 52 - 32 = 20
		data->reg.raw32_array[1] |= ( (1U << 30) | (1U << 19) );
	}
	return;
}

static inline void FPMaxNormal(bool sign, CoprocFpuRegisterType *data)
{
	data->reg.raw64 = 0xFFFFFFFFFFFFFFFFULL;
	//exp = Ones(E-1):'0';
	//frac = Ones(F);
	//return sign:exp:frac;
	if (data->size == CoprocFpuDataSize_16) {
		//E = 5;
		//F = N - E - 1; ==> F= 16 - 5 - 1 = 10
		if (sign) {
			data->reg.raw16 &= ~( 1U << 10 );
		}
		else {
			data->reg.raw16 &= ~( (1U << 15) | (1U << 10) );
		}
	}
	else if (data->size == CoprocFpuDataSize_32) {
		//E = 8;
		//F = N - E - 1; ==> F= 32 - 8 - 1 = 23
		if (sign) {
			data->reg.raw32 &= ~( 1U << 23 );
		}
		else {
			data->reg.raw32 &= ~( (1U << 31) | (1U << 23) );
		}
	}
	else {
		//E = 11;
		//F = N - E - 1; ==> F= 64 - 11 - 1 = 52: 52 - 32 = 20
		if (sign) {
			data->reg.raw32_array[1] &= ~( 1U << 20 );
		}
		else {
			data->reg.raw32_array[1] &= ~( (1U << 31) | (1U << 20) );
		}
	}
	return;
}

static inline void FPInfinity(bool sign, CoprocFpuRegisterType *data)
{
	data->reg.raw64 = 0;
	//exp = Ones(E);
	//frac = Zeros(F);
	//return sign:exp:frac;
	if (data->size == CoprocFpuDataSize_16) {
		//E = 5;
		//F = N - E - 1; ==> F= 16 - 5 - 1 = 10
		if (sign) {
			data->reg.raw16 |= ( (1U << 15) | (0x1F << 10) );
		}
		else {
			data->reg.raw16 |= ( 0x1F << 10 );
		}
	}
	else if (data->size == CoprocFpuDataSize_32) {
		//E = 8;
		//F = N - E - 1; ==> F= 32 - 8 - 1 = 23
		if (sign) {
			data->reg.raw32 |= ( (1U << 31) | (0xFF << 23) );
		}
		else {
			data->reg.raw32 |= ( 0xFF << 23 );
		}
	}
	else {
		//E = 11;
		//F = N - E - 1; ==> F= 64 - 11 - 1 = 52: 52 - 32 = 20
		if (sign) {
			data->reg.raw32_array[1] |= ( (1U << 31) | (0x7FF << 20) );
		}
		else {
			data->reg.raw32_array[1] |= ( 0xFF << 20 );
		}
	}
	return;
}

static inline void FPDefaultNaN(CoprocFpuRegisterType *data)
{
	data->reg.raw64 = 0;
	//sign = '0';
	//exp = Ones(E);
	//frac = '1':Zeros(F-1);
	//return sign:exp:frac;
	if (data->size == CoprocFpuDataSize_16) {
		//E = 5;
		//F = N - E - 1; ==> F= 16 - 5 - 1 = 10
		data->reg.raw16 |= ( 1U << 9 );
	}
	else if (data->size == CoprocFpuDataSize_32) {
		//E = 8;
		//F = N - E - 1; ==> F= 32 - 8 - 1 = 23
		data->reg.raw32 |= ( 1U << 22 );
	}
	else {
		//E = 11;
		//F = N - E - 1; ==> F= 64 - 11 - 1 = 52: 52 - 32 = 20
		data->reg.raw32_array[1] |= ( 1U << 19 );
	}
	return;
}
static inline void FPAdd(CoprocFpuRegisterType *op1, CoprocFpuRegisterType *op2, bool fpscr_controlled, CoprocFpuRegisterType *result)
{
	//TODO
	//fpscr_val = if fpscr_controlled then FPSCR else StandardFPSCRValue();
	//(type1,sign1,value1) = FPUnpack(op1, fpscr_val);
	//(type2,sign2,value2) = FPUnpack(op2, fpscr_val);
	//(done,result) = FPProcessNaNs(type1, type2, op1, op2, fpscr_val);
	//if !done then
		//inf1 = (type1 == FPType_Infinity); inf2 = (type2 == FPType_Infinity);
		//zero1 = (type1 == FPType_Zero); zero2 = (type2 == FPType_Zero);
		//if inf1 && inf2 && sign1 == NOT(sign2) then
			//result = FPDefaultNaN(N);
			//FPProcessException(FPExc_InvalidOp, fpscr_val);
		//elsif (inf1 && sign1 == '0') || (inf2 && sign2 == '0') then
			//result = FPInfinity('0', N);
		//elsif (inf1 && sign1 == '1') || (inf2 && sign2 == '1') then
			//result = FPInfinity('1', N);
		//elsif zero1 && zero2 && sign1 == sign2 then
			//result = FPZero(sign1, N);
		//else
			//result_value = value1 + value2;
			//if result_value == 0.0 then // Sign of exact zero result depends on rounding mode
				//result_sign = if fpscr_val<23:22> == '10' then '1' else '0';
				//result = FPZero(result_sign, N);
			//else
				//result = FPRound(result_value, N, fpscr_val);
	//return result;
}
#endif /* _ARM_PSEUDO_FPU_CODE_H_ */
