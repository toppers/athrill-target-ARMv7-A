#ifndef _ARM_PSEUDO_FPU_CODE_H_
#define _ARM_PSEUDO_FPU_CODE_H_

#include "target_cpu.h"
#include "arm_pseudo_code_type.h"
#include "coproc/arm_coproc.h"
#include "assert.h"

typedef enum {
	FPType_Nonzero = 0,
	FPType_Zero,
	FPType_Infinity,
	FPType_QNaN,
	FPType_SNaN
} FPType;

typedef enum {
	FPExc_InvalidOp = 0,
	FPExc_DivideByZero,
	FPExc_Overflow,
	FPExc_Underflow,
	FPExc_Inexact,
	FPExc_InputDenorm
} FPExcType;

static inline uint32 StandardFPSCRValue(uint32 fpscr)
{
	if ((fpscr & (1U << 26)) != 0) {
		return ( (0b000001 << 26) | 0b11000000000000000000000000 );
	}
	else {
		return ( (0b000000 << 26) | 0b11000000000000000000000000 );
	}
}

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

#endif /* _ARM_PSEUDO_FPU_CODE_H_ */
