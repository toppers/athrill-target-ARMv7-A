#ifndef _ARM_COPROC_FPU_H_
#define _ARM_COPROC_FPU_H_

#include "std_types.h"

typedef float float32;
typedef double float64;

#define ARM_COPROC_FPU_SINGLE_FLOAT		32U
#define ARM_COPROC_FPU_DOUBLE_FLOAT		32U

typedef struct {
	float32		r[ARM_COPROC_FPU_SINGLE_FLOAT];
} CoprocFpuSingleFloatRegisterType;

typedef struct {
	float64		r[ARM_COPROC_FPU_SINGLE_FLOAT];
} CoprocFpuDoubleFloatRegisterType;

#define FPU_STATUS_BITPOS_N		31U
#define FPU_STATUS_BITPOS_Z		30U
#define FPU_STATUS_BITPOS_C		29U
#define FPU_STATUS_BITPOS_V		28U

typedef struct {
	union {
		CoprocFpuSingleFloatRegisterType	s;
		CoprocFpuDoubleFloatRegisterType	d;
	} vfp;
	uint32 fpscr;
} CoprocCP11RegisterType;

/*
 * RMode, bits[23:22]
 *
 * Rounding Mode control field. The encoding of this field is:
 * 0b00 Round to Nearest (RN) mode
 * 0b01 Round towards Plus Infinity (RP) mode
 * 0b10 Round towards Minus Infinity (RM) mode
 * 0b11 Round towards Zero (RZ) mode.
 */
typedef enum {
    FpuRounding_RN = 0b00,
    FpuRounding_RP = 0b01,
    FpuRounding_RM = 0b10,
    FpuRounding_RZ = 0b11,
} FpuConfigRoundingType;

static inline FpuConfigRoundingType cpu_get_fpu_rmode(uint32 fpscr)
{
	return (FpuConfigRoundingType)( (fpscr >> 22U) & 0b11 );
}

typedef enum {
	CoprocFpuDataSize_16 = 0,
	CoprocFpuDataSize_32,
	CoprocFpuDataSize_64
} CoprocFpuDataSizeType;

typedef struct {
	CoprocFpuDataSizeType size;
	uint32 regId;
	union {
		float32	Data32;
		float64	Data64;
		uint16	raw16;
		uint32	raw32;
		uint64	raw64;
		uint32	raw32_array[2];
	} reg;
} CoprocFpuRegisterType;

static inline void cpu_get_freg(const CoprocCP11RegisterType *coproc11, CoprocFpuRegisterType *out)
{
	if (out->size == CoprocFpuDataSize_64) {
		out->reg.Data64 = coproc11->vfp.d.r[out->regId];
	}
	else if (out->size == CoprocFpuDataSize_32) {
		out->reg.Data32 = coproc11->vfp.d.r[out->regId];
	}
	else {
		//TODO
	}
	return;
}

static inline void cpu_set_freg(CoprocCP11RegisterType *coproc11, const CoprocFpuRegisterType *in)
{
	if (in->size == CoprocFpuDataSize_64) {
		coproc11->vfp.d.r[in->regId] = in->reg.Data64;
	}
	else if (in->size == CoprocFpuDataSize_32) {
		coproc11->vfp.d.r[in->regId] = in->reg.Data32;
	}
	else {
		//TODO
	}
	return;
}

#define OP_SET_FREG(coproc11, arg, op, regName)	\
do {	\
	(arg)->name = #regName;	\
	(arg)->freg.regId = (op)->regName;	\
	if ((op)->sz == 1) {	\
		(arg)->freg.size = CoprocFpuDataSize_64;	\
	}	\
	else {	\
		(arg)->freg.size = CoprocFpuDataSize_32;	\
	}	\
	cpu_get_freg((coproc11), &(arg)->freg);	\
} while (0)

#endif /* _ARM_COPROC_FPU_H_ */
