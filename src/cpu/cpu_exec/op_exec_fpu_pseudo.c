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
int arm_op_exec_arm_vadd_freg(struct TargetCore *core,  arm_vadd_freg_input_type *in, arm_vadd_freg_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		FPAdd(cpu_get_fpscr(core), &in->Vn.freg, &in->Vm.freg, TRUE, &out->Vd.freg);
		cpu_set_freg(&core->coproc.cp11, &out->Vd.freg);
	}
	out->status = *status;
	return ret;
}


int arm_op_exec_arm_vldr(struct TargetCore *core,  arm_vldr_input_type *in, arm_vldr_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
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
	uint32 *status = cpu_get_status(core);
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
	uint32 *status = cpu_get_status(core);
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

