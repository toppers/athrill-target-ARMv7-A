#include "arm_pseudo_code_func.h"
#include "coproc/cp11/arm_pseudo_fpu_code.h"

#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define _GNU_SOURCE
#include <fenv.h>
#include <float.h>

#define FLOAT_EXP_BIT_POS_START		30
#define FLOAT_EXP_BIT_POS_END		23
#define FLOAT_EXP_BIT_MASK			0x7F800000
#define FLOAT_EXP_BIAS_VALUE		((sint16)127)
#define GET_FLOAT_EXP_VALUE(x) 		( (sint16)( ((FLOAT_EXP_BIT_MASK & (x)->reg.raw32) >> FLOAT_EXP_BIT_POS_END) ) )
#define GET_FLOAT_EXPB_VALUE(x) 	( GET_FLOAT_EXP_VALUE(x) - FLOAT_EXP_BIAS_VALUE )


#define DOUBLE_EXP_BIT_POS_START	30
#define DOUBLE_EXP_BIT_POS_END		20
#define DOUBLE_EXP_BIT_MASK			0x7FE00000
#define DOUBLE_EXP_BIAS_VALUE		((sint16)1023)
#define GET_DOUBLE_EXP_VALUE(x) 		( (sint16)( ((DOUBLE_EXP_BIT_MASK & (x)->reg.raw32_array[1]) >> DOUBLE_EXP_BIT_POS_END) ) )
#define GET_DOUBLE_EXPB_VALUE(x) 	( GET_DOUBLE_EXP_VALUE(x) - DOUBLE_EXP_BIAS_VALUE )


#define FLOAT_EXP_MAX				((sint16)+127)
#define FLOAT_EXP_MIN				((sint16)-126)
#define FLOAT_EXP_MAX_PLUS_1		((sint16)+128)
#define FLOAT_EXP_MIN_MINUS_1		((sint16)-127)


#define DOUBLE_EXP_MAX				((sint16)+1023)
#define DOUBLE_EXP_MIN				((sint16)-1022)
#define DOUBLE_EXP_MAX_PLUS_1		((sint16)+1024)
#define DOUBLE_EXP_MIN_MINUS_1		((sint16)-1023)


#define FLOAT_MANTISSA_POS_START	22
#define FLOAT_MANTISSA_POS_END		0
#define FLOAT_MANTISSA_BIT_MASK		0x007FFFFF
#define GET_FLOAT_MANTISSA_VALUE(x) ( ((FLOAT_MANTISSA_BIT_MASK & (x)->reg.raw32) >> FLOAT_MANTISSA_POS_END))
#define GET_FLOAT_MANTISSA_BIT_VALUE(ma, bit_pos) ( ( ((ma) & (1U << (bit_pos)) ) != 0U) ? 1U : 0U )

#define DOUBLE_MANTISSA1_POS_START		19
#define DOUBLE_MANTISSA1_POS_END		0
#define DOUBLE_MANTISSA1_BIT_MASK		0x007FFFFF

#define DOUBLE_MANTISSA0_POS_START		31
#define DOUBLE_MANTISSA0_POS_END		0
#define DOUBLE_MANTISSA0_BIT_MASK		0xFFFFFFFF

#define GET_DOUBLE_MANTISSA1_VALUE(x) ( ((DOUBLE_MANTISSA1_BIT_MASK & (x)->reg.raw32_array[1]) >> DOUBLE_MANTISSA1_POS_END))
#define GET_DOUBLE_MANTISSA0_VALUE(x) ( ((DOUBLE_MANTISSA0_BIT_MASK & (x)->reg.raw32_array[0]) >> DOUBLE_MANTISSA0_POS_END))
#define GET_DOUBLE_MANTISSA_BIT_VALUE(ma, bit_pos) ( ( ((ma) & (1U << (bit_pos)) ) != 0U) ? 1U : 0U )

/*
 * 種類　　　　指数部　　　仮数部
 * ------------------------------
 * ゼロ　　　　０　　　　　　 ０
 * 非正規化数　０　　　　　　 ０以外
 * 正規化数　　1～254　　　	  任意
 * 無限大　　　255　　　　　  ０
 * NaN　　　　 255　　　　　  ０以外
 */
#define FLOAT_IS_ZERO(x)	( (GET_FLOAT_EXP_VALUE(x) == 0)   && (GET_FLOAT_MANTISSA_VALUE(x) == 0  ) )
#define FLOAT_IS_NORMAL(x)	( (GET_FLOAT_EXP_VALUE(x) >= 1)   && (GET_FLOAT_EXP_VALUE(x)      <= 254) )
#define FLOAT_IS_SBNORM(x)	( (GET_FLOAT_EXP_VALUE(x) == 0)   && (GET_FLOAT_MANTISSA_VALUE(x) != 0  ) )
#define FLOAT_IS_INF(x)		( (GET_FLOAT_EXP_VALUE(x) == 255) && (GET_FLOAT_MANTISSA_VALUE(x) == 0  ) )
#define FLOAT_IS_NAN(x)		( (GET_FLOAT_EXP_VALUE(x) == 255) && (GET_FLOAT_MANTISSA_VALUE(x) != 0  ) )
#define FLOAT_IS_PLUS(x)	( GET_FLOAT_SIGN_BIT_VALUE(x) == 0 )
#define FLOAT_IS_MINUS(x)	( GET_FLOAT_SIGN_BIT_VALUE(x) == 1 )


#define DOUBLE_IS_ZERO(x)	( (GET_DOUBLE_EXP_VALUE(x) == 0)   && (GET_DOUBLE_MANTISSA0_VALUE(x) == 0  ) && (GET_DOUBLE_MANTISSA1_VALUE(x) == 0  ) )
#define DOUBLE_IS_NORMAL(x)	( (GET_DOUBLE_EXP_VALUE(x) >= 1)   && (GET_DOUBLE_EXP_VALUE(x)      <= 2046) )
#define DOUBLE_IS_SBNORM(x)	( (GET_DOUBLE_EXP_VALUE(x) == 0)   && ( (GET_DOUBLE_MANTISSA0_VALUE(x) != 0  ) || (GET_DOUBLE_MANTISSA1_VALUE(x) != 0  )) )
#define DOUBLE_IS_INF(x)	( (GET_DOUBLE_EXP_VALUE(x) == 2047) && (GET_DOUBLE_MANTISSA0_VALUE(x) == 0  ) && (GET_DOUBLE_MANTISSA1_VALUE(x) == 0  ) )
#define DOUBLE_IS_NAN(x)	( (GET_DOUBLE_EXP_VALUE(x) == 2047) && ( (GET_DOUBLE_MANTISSA0_VALUE(x) != 0  ) || (GET_DOUBLE_MANTISSA1_VALUE(x) != 0  )) )
#define DOUBLE_IS_PLUS(x)	( GET_DOUBLE_SIGN_BIT_VALUE(x) == 0 )
#define DOUBLE_IS_MINUS(x)	( GET_DOUBLE_SIGN_BIT_VALUE(x) == 1 )


#define FLOAT_SET_SIGN_REVERSE(x)	\
do { \
	if (FLOAT_IS_PLUS(x)) {	\
		FLOAT_SIGN_BIT_SET(x);	\
	}	\
	else {	\
		FLOAT_SIGN_BIT_CLR(x);	\
	}	\
} while (0)

#define DOUBLE_SET_SIGN_REVERSE(x)	\
do { \
	if (DOUBLE_IS_PLUS(x)) {	\
		DOUBLE_SIGN_BIT_SET(x);	\
	}	\
	else {	\
		DOUBLE_SIGN_BIT_CLR(x);	\
	}	\
} while (0)

static inline bool float_is_qnan(CoprocFpuRegisterType *x)
{
	if (!FLOAT_IS_NAN(x)) {
		return FALSE;
	}
	if ((x->reg.raw32 & (1U << FLOAT_MANTISSA_POS_START)) != 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
static inline bool float_is_snan(CoprocFpuRegisterType *x)
{
	if (!FLOAT_IS_NAN(x)) {
		return FALSE;
	}
	if ((x->reg.raw32 & (1U << FLOAT_MANTISSA_POS_START)) != 0) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

static inline void float_get_qnan(CoprocFpuRegisterType *x)
{
	x->reg.raw32 = 0x7FFFFFFF;
	return;
}
static inline void float_get_snan(CoprocFpuRegisterType *x)
{
	x->reg.raw32 = ( 0x7FFFFFFF & ~(1U << FLOAT_MANTISSA_POS_START) );
	return;
}


static inline bool double_is_qnan(CoprocFpuRegisterType *x)
{
	if (!DOUBLE_IS_NAN(x)) {
		return FALSE;
	}
	if ((x->reg.raw32_array[1] & (1U << DOUBLE_MANTISSA1_POS_START)) != 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
static inline bool double_is_snan(CoprocFpuRegisterType *x)
{
	if (!DOUBLE_IS_NAN(x)) {
		return FALSE;
	}
	if ((x->reg.raw32_array[1] & (1U << DOUBLE_MANTISSA1_POS_START)) != 0) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

static inline void double_get_qnan(CoprocFpuRegisterType *x)
{
	x->reg.raw32_array[1] = 0x7FFFFFFF;
	x->reg.raw32_array[0] = 0xFFFFFFFF;
	return;
}
static inline void double_get_snan(CoprocFpuRegisterType *x)
{
	x->reg.raw32_array[1] = ( 0x7FFFFFFF & ~(1U << DOUBLE_MANTISSA1_POS_START) );
	x->reg.raw32_array[0] = 0xFFFFFFFF;
	return;
}

static void prepare_float_op(FpuConfigRoundingType cfg)
{

	switch (cfg) {
	case FpuRounding_RN:
		(void)fesetround(FE_TONEAREST);
		break;
	case FpuRounding_RP:
		(void)fesetround(FE_UPWARD);
		break;
	case FpuRounding_RM:
		(void)fesetround(FE_DOWNWARD);
		break;
	case FpuRounding_RZ:
		(void)fesetround(FE_TOWARDZERO);
		break;
	default:
		(void)fesetround(FE_TONEAREST);
		break;
	}
	(void)feclearexcept(FE_ALL_EXCEPT);
	return;
}
static void end_float_op(void)
{
	if (fetestexcept(FE_ALL_EXCEPT) == 0) {
		return;
	}
    if (fetestexcept(FE_DIVBYZERO)) {
    }
    if (fetestexcept(FE_INEXACT)) {
    }
    if (fetestexcept(FE_INVALID)) {
    }
    if (fetestexcept(FE_OVERFLOW)) {
    }
    if (fetestexcept(FE_UNDERFLOW)) {
    }
    return;
}
#define FLOAT_SIGN_BIT_POS		31
#define FLOAT_SIGN_BIT_PTRN		(1U << FLOAT_SIGN_BIT_POS)
#define FLOAT_SIGN_BIT_MASK		~(1U << FLOAT_SIGN_BIT_POS)
#define GET_FLOAT_SIGN_BIT_VALUE(x) ( (((FLOAT_SIGN_BIT_PTRN) & (x)->reg.raw32) != 0) ? 1U : 0U )
#define FLOAT_SIGN_BIT_SET(x)	\
do {	\
	(x)->reg.raw32 |= FLOAT_SIGN_BIT_PTRN;	\
} while (0)

#define FLOAT_SIGN_BIT_CLR(x)	\
do {	\
	(x).binary &= FLOAT_SIGN_BIT_MASK;	\
} while (0)
#define DOUBLE_SIGN_BIT_POS		FLOAT_SIGN_BIT_POS
#define DOUBLE_SIGN_BIT_PTRN	FLOAT_SIGN_BIT_PTRN
#define DOUBLE_SIGN_BIT_MASK		FLOAT_SIGN_BIT_MASK
#define GET_DOUBLE_SIGN_BIT_VALUE(x) ( (((DOUBLE_SIGN_BIT_PTRN) & (x)->reg.raw32_array[1]) != 0) ? 1U : 0U )
#define DOUBLE_SIGN_BIT_SET(x)	\
do {	\
	(x)->reg.raw32_array[1] |= DOUBLE_SIGN_BIT_PTRN;	\
} while (0)

#define DOUBLE_SIGN_BIT_CLR(x)	\
do {	\
	(x)->reg.raw32_array[1] &= DOUBLE_SIGN_BIT_MASK;	\
} while (0)


static inline void fpu_update_status_flag(uint32 *status, PseudoCodeFloatStatusFlagType *status_flag)
{
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, status_flag->carry);
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_V, status_flag->overflow);
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, status_flag->zero);
	CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, status_flag->negative);
	return;
}

static inline void set_subnormal_operand_float(CoprocFpuRegisterType *operand)
{
    if (!FLOAT_IS_SBNORM(operand)) {
        return;
    }
    if (FLOAT_IS_MINUS(operand)) {
        operand->reg.raw32 = 0;
        FLOAT_SIGN_BIT_SET(operand);
    }
    else {
        operand->reg.raw32 = 0;
    }
    return;
}

static inline void set_subnormal_result_float(FpuConfigRoundingType cfg, CoprocFpuRegisterType *result)
{
    if (!FLOAT_IS_SBNORM(result)) {
        return;
    }
    switch (cfg) {
    case FpuRounding_RN:
    case FpuRounding_RZ:
        if (FLOAT_IS_MINUS(result)) {
            FLOAT_SIGN_BIT_SET(result);
            result->reg.raw32 = 0;
        }
        else {
            result->reg.raw32 = 0;
        }
        break;
    case FpuRounding_RP:
        if (FLOAT_IS_MINUS(result)) {
            result->reg.raw32 = 0;
            FLOAT_SIGN_BIT_SET(result);
        }
        else {
            result->reg.Data32 = FLT_MIN;
        }
        break;
    case FpuRounding_RM:
        if (FLOAT_IS_MINUS(result)) {
            result->reg.Data32 = FLT_MIN;
            FLOAT_SIGN_BIT_SET(result);
        }
        else {
            result->reg.raw32 = 0;
        }
        break;
    default:
        break;
    }

    return;
}
static inline void set_subnormal_operand_double(CoprocFpuRegisterType *operand)
{
    if (!DOUBLE_IS_SBNORM(operand)) {
        return;
    }
    if (DOUBLE_IS_MINUS(operand)) {
        operand->reg.raw32_array[0] = 0;
        operand->reg.raw32_array[1] = 0;
        DOUBLE_SIGN_BIT_SET(operand);
    }
    else {
        operand->reg.raw32_array[0] = 0;
        operand->reg.raw32_array[1] = 0;
    }
    return;
}

static inline void set_subnormal_result_double(FpuConfigRoundingType cfg, CoprocFpuRegisterType *result)
{
    if (!DOUBLE_IS_SBNORM(result)) {
        return;
    }
    switch (cfg) {
    case FpuRounding_RN:
    case FpuRounding_RZ:
        if (DOUBLE_IS_MINUS(result)) {
            DOUBLE_SIGN_BIT_SET(result);
            result->reg.raw32_array[0] = 0;
            result->reg.raw32_array[1] = 0;
        }
        else {
            result->reg.raw32_array[0] = 0;
            result->reg.raw32_array[1] = 0;
        }
        break;
    case FpuRounding_RP:
        if (DOUBLE_IS_MINUS(result)) {
            result->reg.raw32_array[0] = 0;
            result->reg.raw32_array[1] = 0;
            DOUBLE_SIGN_BIT_SET(result);
        }
        else {
            result->reg.Data64 = DBL_MIN;
        }
        break;
    case FpuRounding_RM:
        if (DOUBLE_IS_MINUS(result)) {
            result->reg.Data64 = DBL_MIN;
            DOUBLE_SIGN_BIT_SET(result);
        }
        else {
            result->reg.raw32_array[0] = 0;
            result->reg.raw32_array[1] = 0;
        }
        break;
    default:
        break;
    }

    return;
}

static inline void set_subnormal_operand(CoprocFpuRegisterType *operand)
{
	if (operand->size == CoprocFpuDataSize_64) {
		set_subnormal_operand_double(operand);
	}
	else {
		set_subnormal_operand_float(operand);
	}
	return;
}
static inline void set_subnormal_result(FpuConfigRoundingType cfg, CoprocFpuRegisterType *result)
{
	if (result->size == CoprocFpuDataSize_64) {
		set_subnormal_result_double(cfg, result);
	}
	else {
		set_subnormal_result_float(cfg, result);
	}
	return;
}
static void FPAdd(uint32 fpscr, CoprocFpuRegisterType *op1, CoprocFpuRegisterType *op2, bool fpscr_controlled, CoprocFpuRegisterType *result)
{
	uint32 fpscr_val = (fpscr_controlled) ? fpscr : StandardFPSCRValue(fpscr);
	FpuConfigRoundingType cfg = cpu_get_fpu_rmode(fpscr_val);

    set_subnormal_operand(op1);
    set_subnormal_operand(op2);
	prepare_float_op(cfg);
	{
		if (op1->size == CoprocFpuDataSize_64) {
			result->reg.Data64 = op1->reg.Data64 + op2->reg.Data64;
		}
		else {
			result->reg.Data32 = op1->reg.Data32 + op2->reg.Data32;
		}
	}
	end_float_op();
    set_subnormal_result(cfg, result);
    return;
}

static void FPSub(uint32 fpscr, CoprocFpuRegisterType *op1, CoprocFpuRegisterType *op2, bool fpscr_controlled, CoprocFpuRegisterType *result)
{
	uint32 fpscr_val = (fpscr_controlled) ? fpscr : StandardFPSCRValue(fpscr);
	FpuConfigRoundingType cfg = cpu_get_fpu_rmode(fpscr_val);

    set_subnormal_operand(op1);
    set_subnormal_operand(op2);
	prepare_float_op(cfg);
	{
		if (op1->size == CoprocFpuDataSize_64) {
			result->reg.Data64 = op1->reg.Data64 - op2->reg.Data64;
		}
		else {
			result->reg.Data32 = op1->reg.Data32 - op2->reg.Data32;
		}
	}
	end_float_op();
    set_subnormal_result(cfg, result);
    return;
}

static void FPMul(uint32 fpscr, CoprocFpuRegisterType *op1, CoprocFpuRegisterType *op2, bool fpscr_controlled, CoprocFpuRegisterType *result)
{
	uint32 fpscr_val = (fpscr_controlled) ? fpscr : StandardFPSCRValue(fpscr);
	FpuConfigRoundingType cfg = cpu_get_fpu_rmode(fpscr_val);

    set_subnormal_operand(op1);
    set_subnormal_operand(op2);
	prepare_float_op(cfg);
	{
		if (op1->size == CoprocFpuDataSize_64) {
			result->reg.Data64 = op1->reg.Data64 * op2->reg.Data64;
		}
		else {
			result->reg.Data32 = op1->reg.Data32 * op2->reg.Data32;
		}
	}
	end_float_op();
    set_subnormal_result(cfg, result);
    return;
}

static void FPDiv(uint32 fpscr, CoprocFpuRegisterType *op1, CoprocFpuRegisterType *op2, bool fpscr_controlled, CoprocFpuRegisterType *result)
{
	uint32 fpscr_val = (fpscr_controlled) ? fpscr : StandardFPSCRValue(fpscr);
	FpuConfigRoundingType cfg = cpu_get_fpu_rmode(fpscr_val);

    set_subnormal_operand(op1);
    set_subnormal_operand(op2);
	prepare_float_op(cfg);
	{
		if (op1->size == CoprocFpuDataSize_64) {
			result->reg.Data64 = op1->reg.Data64 / op2->reg.Data64;
		}
		else {
			result->reg.Data32 = op1->reg.Data32 / op2->reg.Data32;
		}
	}
	end_float_op();
    set_subnormal_result(cfg, result);
    return;
}
static void FPDoubleToSingle(uint32 fpscr, CoprocFpuRegisterType *op1, bool fpscr_controlled, CoprocFpuRegisterType *result)
{
	uint32 fpscr_val = (fpscr_controlled) ? fpscr : StandardFPSCRValue(fpscr);
	FpuConfigRoundingType cfg = cpu_get_fpu_rmode(fpscr_val);

    set_subnormal_operand(op1);
	prepare_float_op(cfg);
    {
        result->reg.Data32 = (float32)(op1->reg.Data64);
    }
	end_float_op();
    set_subnormal_result(cfg, result);

	return;
}


static void FPSingleToDouble(uint32 fpscr, CoprocFpuRegisterType *op1, bool fpscr_controlled, CoprocFpuRegisterType *result)
{
	uint32 fpscr_val = (fpscr_controlled) ? fpscr : StandardFPSCRValue(fpscr);
	FpuConfigRoundingType cfg = cpu_get_fpu_rmode(fpscr_val);

    set_subnormal_operand(op1);
	prepare_float_op(cfg);
    {
        result->reg.Data64 = (float64)(op1->reg.Data32);
    }
	end_float_op();
    set_subnormal_result(cfg, result);

	return;
}
static void FPCompare(uint32 fpscr, CoprocFpuRegisterType *op1, CoprocFpuRegisterType *op2, bool quiet_nan_exc, bool fpscr_controlled, PseudoCodeFloatStatusFlagType *status)
{
	//fpscr_val = if fpscr_controlled then FPSCR else StandardFPSCRValue();
	//uint32 fpscr_val = (fpscr_controlled) ? fpscr : StandardFPSCRValue(fpscr);

	if (op1->size == CoprocFpuDataSize_64) {
		//if type1==FPType_SNaN || type1==FPType_QNaN || type2==FPType_SNaN || type2==FPType_QNaN then
		//result = ('0','0','1','1');
		if (double_is_snan(op1) || double_is_qnan(op1) || double_is_snan(op2) || double_is_qnan(op2)) {
			status->negative = FALSE;
			status->zero = FALSE;
			status->carry = TRUE;
			status->overflow = TRUE;
		}
		else if (op1->reg.Data64 == op2->reg.Data64) {
			//result = ('0','1','1','0');
			status->negative = FALSE;
			status->zero = TRUE;
			status->carry = TRUE;
			status->overflow = FALSE;
		}
		else if (op1->reg.Data64 < op2->reg.Data64) {
			//result = ('1','0','0','0');
			status->negative = TRUE;
			status->zero = FALSE;
			status->carry = FALSE;
			status->overflow = FALSE;
		}
		else {
			//result = ('0','0','1','0');
			status->negative = FALSE;
			status->zero = FALSE;
			status->carry = TRUE;
			status->overflow = FALSE;
		}
	}
	else {
		//if type1==FPType_SNaN || type1==FPType_QNaN || type2==FPType_SNaN || type2==FPType_QNaN then
		//result = ('0','0','1','1');
		if (float_is_snan(op1) || float_is_qnan(op1) || float_is_snan(op2) || float_is_qnan(op2)) {
			status->negative = FALSE;
			status->zero = FALSE;
			status->carry = TRUE;
			status->overflow = TRUE;
		}
		else if (op1->reg.Data32 == op2->reg.Data32) {
			//result = ('0','1','1','0');
			status->negative = FALSE;
			status->zero = TRUE;
			status->carry = TRUE;
			status->overflow = FALSE;
		}
		else if (op1->reg.Data32 < op2->reg.Data32) {
			//result = ('1','0','0','0');
			status->negative = TRUE;
			status->zero = FALSE;
			status->carry = FALSE;
			status->overflow = FALSE;
		}
		else {
			//result = ('0','0','1','0');
			status->negative = FALSE;
			status->zero = FALSE;
			status->carry = TRUE;
			status->overflow = FALSE;
		}
	}
	return;
}
int arm_op_exec_arm_vadd_freg(struct TargetCore *core,  arm_vadd_freg_input_type *in, arm_vadd_freg_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		FPAdd(cpu_get_fpscr(core), &in->Vn.freg, &in->Vm.freg, TRUE, &out->Vd.freg);
		cpu_set_freg(&core->coproc.cp11, &out->Vd.freg);
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_vsub_freg(struct TargetCore *core,  arm_vsub_freg_input_type *in, arm_vsub_freg_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		FPSub(cpu_get_fpscr(core), &in->Vn.freg, &in->Vm.freg, TRUE, &out->Vd.freg);
		cpu_set_freg(&core->coproc.cp11, &out->Vd.freg);
	}
	out->status = *status;
	return ret;
}


int arm_op_exec_arm_vmul_freg(struct TargetCore *core,  arm_vmul_freg_input_type *in, arm_vmul_freg_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		FPMul(cpu_get_fpscr(core), &in->Vn.freg, &in->Vm.freg, TRUE, &out->Vd.freg);
		cpu_set_freg(&core->coproc.cp11, &out->Vd.freg);
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_vdiv_freg(struct TargetCore *core,  arm_vdiv_freg_input_type *in, arm_vdiv_freg_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		FPDiv(cpu_get_fpscr(core), &in->Vn.freg, &in->Vm.freg, TRUE, &out->Vd.freg);
		cpu_set_freg(&core->coproc.cp11, &out->Vd.freg);
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_vldr(struct TargetCore *core,  arm_vldr_input_type *in, arm_vldr_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		uint32 base = (in->Rn.regId == CpuRegId_PC) ? Align(in->Rn.regData, 4) : in->Rn.regData;
		uint32 address = (in->add) ? (base + in->imm32) : (base - in->imm32);
		if (in->Vd.freg.size == CoprocFpuDataSize_32) {
			//S[d] = MemA[address,4];
			ret = MemA_R(core, address, 4, (uint8*)&out->Vd.freg.reg.raw32);
			if (ret < 0) {
				goto done;
			}
		}
		else {
			uint32 word1;
			uint32 word2;
			ret = MemA_R(core, address, 4, (uint8*)&word1);
			if (ret < 0) {
				goto done;
			}
			ret = MemA_R(core, address + 4, 4, (uint8*)&word2);
			if (ret < 0) {
				goto done;
			}
			if (CPU_STATUS_BIT_IS_SET(*status, CPU_STATUS_BITPOS_E)) {
				//Big-endian operation
				out->Vd.freg.reg.raw32_array[0] = word2;
				out->Vd.freg.reg.raw32_array[1] = word1;
			}
			else {
				//Little-endian operation
				out->Vd.freg.reg.raw32_array[0] = word1;
				out->Vd.freg.reg.raw32_array[1] = word2;
			}
		}
		cpu_set_freg(&core->coproc.cp11, &out->Vd.freg);
	}
done:
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_vstr(struct TargetCore *core,  arm_vstr_input_type *in, arm_vstr_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//address = if add then (R[n] + imm32) else (R[n] - imm32);
		uint32 address = (in->add) ? (in->Rn.regData + in->imm32) : (in->Rn.regData - in->imm32);
		if (in->single_reg) {
			//MemA[address,4] = S[d];
			ret = MemA_W(core, address, 4, (uint8*)&in->Vd.freg.reg.raw32);
			if (ret < 0) {
				goto done;
			}
		}
		else {
			// Store as two word-aligned words in the correct order for current endianness.
			//MemA[address,4] = if BigEndian() then D[d]<63:32> else D[d]<31:0>;
			//MemA[address+4,4] = if BigEndian() then D[d]<31:0> else D[d]<63:32>;
			if (CPU_STATUS_BIT_IS_SET(*status, CPU_STATUS_BITPOS_E)) {
				//Big-endian operation
				ret = MemA_W(core, address, 4, (uint8*)&in->Vd.freg.reg.raw32_array[1]);
				if (ret < 0) {
					goto done;
				}
				ret = MemA_W(core, address + 4, 4, (uint8*)&in->Vd.freg.reg.raw32_array[0]);
				if (ret < 0) {
					goto done;
				}
			}
			else {
				//Little-endian operation
				ret = MemA_W(core, address, 4, (uint8*)&in->Vd.freg.reg.raw32_array[0]);
				if (ret < 0) {
					goto done;
				}
				ret = MemA_W(core, address + 4, 4, (uint8*)&in->Vd.freg.reg.raw32_array[1]);
				if (ret < 0) {
					goto done;
				}
			}
		}
	}
done:
	out->status = *status;
	return ret;
}


int arm_op_exec_arm_vcvt_df(struct TargetCore *core,  arm_vcvt_df_input_type *in, arm_vcvt_df_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if (in->double_to_single) {
			FPDoubleToSingle(cpu_get_fpscr(core), &in->Vm.freg, TRUE, &out->Vd.freg);
		}
		else {
			FPSingleToDouble(cpu_get_fpscr(core), &in->Vm.freg, TRUE, &out->Vd.freg);
		}
		cpu_set_freg(&core->coproc.cp11, &out->Vd.freg);
	}
	out->status = *status;
	return ret;
}


int arm_op_exec_arm_vcvt_fi(struct TargetCore *core,  arm_vcvt_fi_input_type *in, arm_vcvt_fi_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if (in->to_integer) {
			if (in->dp_operation) {
				//S[d] = FPToFixed(D[m], 32, 0, unsigned, round_zero, TRUE);
				if (in->unsigned_cvt) {
					out->Vd.freg.reg.raw32 = (uint32)in->Vm.freg.reg.Data64;
				}
				else {
					out->Vd.freg.reg.raw32 = (sint32)in->Vm.freg.reg.Data64;
				}
			}
			else {
				//S[d] = FPToFixed(S[m], 32, 0, unsigned, round_zero, TRUE);
				if (in->unsigned_cvt) {
					out->Vd.freg.reg.raw32 = (uint32)in->Vm.freg.reg.Data32;
				}
				else {
					out->Vd.freg.reg.raw32 = (sint32)in->Vm.freg.reg.Data32;
				}
			}
		}
		else {
			if (in->dp_operation) {
				//D[d] = FixedToFP(S[m], 64, 0, unsigned, round_nearest, TRUE);
				if (in->unsigned_cvt) {
					out->Vd.freg.reg.Data64 = (float64)in->Vm.freg.reg.raw32;
				}
				else {
					out->Vd.freg.reg.Data64 = (float64)((sint32)in->Vm.freg.reg.raw32);
				}
			}
			else {
				//S[d] = FixedToFP(S[m], 32, 0, unsigned, round_nearest, TRUE);
				if (in->unsigned_cvt) {
					out->Vd.freg.reg.Data32 = (float32)in->Vm.freg.reg.raw32;
				}
				else {
					out->Vd.freg.reg.Data32 = (float32)((sint32)in->Vm.freg.reg.raw32);
				}
			}
		}
		cpu_set_freg(&core->coproc.cp11, &out->Vd.freg);
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_vcmp(struct TargetCore *core,  arm_vcmp_input_type *in, arm_vcmp_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if (in->dp_operation) {
			//op64 = if with_zero then FPZero(‘0’,64) else D[m];
			if (in->with_zero) {
				in->Vm.freg.reg.raw64 = 0;
			}
			//(FPSCR.N, FPSCR.Z, FPSCR.C, FPSCR.V) = FPCompare(D[d], op64, quiet_nan_exc, TRUE);
		}
		else {
			//op32 = if with_zero then FPZero(‘0’,32) else S[m];
			if (in->with_zero) {
				in->Vm.freg.reg.raw32 = 0;
			}
			//(FPSCR.N, FPSCR.Z, FPSCR.C, FPSCR.V) = FPCompare(S[d], op32, quiet_nan_exc, TRUE);
		}
		FPCompare(cpu_get_fpscr(core), &in->Vd.freg, &in->Vm.freg, in->quiet_nan_exc, TRUE, &out->status_flag);
		fpu_update_status_flag(status, &out->status_flag);
	}
	out->status = *status;
	return ret;
}


int arm_op_exec_arm_vmrs(struct TargetCore *core,  arm_vmrs_input_type *in, arm_vmrs_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if (in->Rt.regId != CpuRegId_PC) {
			in->Rt.regData = *status;
		}
		else {
			uint32 *cpsr = cpu_get_status(core);
			//APSR.N = FPSCR.N;
			//APSR.Z = FPSCR.Z;
			//APSR.C = FPSCR.C;
			//APSR.V = FPSCR.V;
			CPU_STATUS_BIT_UPDATE(cpsr, CPU_STATUS_BITPOS_C, CPU_STATUS_BIT_IS_SET(*status, FPU_STATUS_BITPOS_C));
			CPU_STATUS_BIT_UPDATE(cpsr, CPU_STATUS_BITPOS_V, CPU_STATUS_BIT_IS_SET(*status, FPU_STATUS_BITPOS_V));
			CPU_STATUS_BIT_UPDATE(cpsr, CPU_STATUS_BITPOS_Z, CPU_STATUS_BIT_IS_SET(*status, FPU_STATUS_BITPOS_Z));
			CPU_STATUS_BIT_UPDATE(cpsr, CPU_STATUS_BITPOS_N, CPU_STATUS_BIT_IS_SET(*status, FPU_STATUS_BITPOS_N));
		}
	}
	out->status = *status;
	return ret;
}


int arm_op_exec_arm_vmov_imm(struct TargetCore *core,  arm_vmov_imm_input_type *in, arm_vmov_imm_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//if single_register then
		if (in->single_reg) {
			out->Vd1.freg.reg.raw32 = in->imm32;
			cpu_set_freg(&core->coproc.cp11, &out->Vd1.freg);
		}
		else {
			uint32 *array = (uint32*)&in->imm64;
			out->Vd1.freg.reg.raw32_array[0] = array[0];
			out->Vd1.freg.reg.raw32_array[1] = array[1];
			cpu_set_freg(&core->coproc.cp11, &out->Vd1.freg);
			if (in->regs == 2) {
				out->Vd2.freg.reg.raw32_array[0] = array[0];
				out->Vd2.freg.reg.raw32_array[1] = array[1];
				cpu_set_freg(&core->coproc.cp11, &out->Vd2.freg);
			}
		}
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_vmov_sreg(struct TargetCore *core,  arm_vmov_sreg_input_type *in, arm_vmov_sreg_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if (in->to_arm_register) {
			out->Rt.regData = in->Vn.freg.reg.raw32;
			cpu_set_reg(core, out->Rt.regId, out->Rt.regData);
		}
		else {
			out->Vn.freg.reg.raw32 = in->Rt.regData;
			cpu_set_freg(&core->coproc.cp11, &out->Vn.freg);
		}
	}
	out->status = *status;
	return ret;
}


int arm_op_exec_arm_vpush(struct TargetCore *core,  arm_vpush_input_type *in, arm_vpush_output_type *out)
{
	int ret = 0;
	uint32 *status = fpu_get_status(&core->coproc.cp11);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		int i;
		//address = SP - imm32;
		//SP = SP - imm32;
		uint32 address = (uint32)in->SP.regData - in->imm32;
		CoprocFpuRegisterType fdata;
		out->SP.regData = address;
		fdata = in->Vd.freg;
		if (in->single_reg) {
			for (i = 0; i < (in->regs - 1); i++) {
				//MemA[address,4] = S[d+r]; address = address+4;
				fdata.regId = in->Vd.freg.regId + i;
				cpu_get_freg(&core->coproc.cp11, &fdata);
				ret = MemA_W(core, address, 4, (uint8*)&fdata.reg.raw32);
				if (ret < 0) {
					goto done;
				}
				address = address + 4;
			}
		}
		else {
			for (i = 0; i < (in->regs - 1); i++) {
				fdata.regId = in->Vd.freg.regId + i;
				cpu_get_freg(&core->coproc.cp11, &fdata);
				//MemA[address,4] = if BigEndian() then D[d+r]<63:32> else D[d+r]<31:0>;
				//MemA[address+4,4] = if BigEndian() then D[d+r]<31:0> else D[d+r]<63:32>;
				if (CPU_STATUS_BIT_IS_SET(*status, CPU_STATUS_BITPOS_E)) {
					//Big-endian operation
					ret = MemA_W(core, address, 4, (uint8*)&fdata.reg.raw32_array[1]);
					if (ret < 0) {
						goto done;
					}
					ret = MemA_W(core, address + 4, 4, (uint8*)&fdata.reg.raw32_array[0]);
					if (ret < 0) {
						goto done;
					}
				}
				else {
					//Little-endian operation
					ret = MemA_W(core, address, 4, (uint8*)&fdata.reg.raw32_array[0]);
					if (ret < 0) {
						goto done;
					}
					ret = MemA_W(core, address + 4, 4, (uint8*)&fdata.reg.raw32_array[1]);
					if (ret < 0) {
						goto done;
					}
				}
				address = address + 8;
			}
		}
	}
done:
	out->status = *status;
	return ret;
}

