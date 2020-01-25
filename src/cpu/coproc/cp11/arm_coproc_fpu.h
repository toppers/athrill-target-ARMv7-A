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


typedef struct {
	bool is64;
	uint32 regId;
	union {
		float32	Data32;
		float64	Data64;
	} reg;
} CoprocFpuRegisterType;

static inline void cpu_get_freg(const CoprocCP11RegisterType *coproc11, CoprocFpuRegisterType *out)
{
	if (out->is64 != FALSE) {
		out->reg.Data64 = coproc11->vfp.d.r[out->regId];
	}
	else {
		out->reg.Data32 = coproc11->vfp.d.r[out->regId];
	}
	return;
}

static inline void cpu_set_freg(CoprocCP11RegisterType *coproc11, const CoprocFpuRegisterType *in)
{
	if (in->is64 != FALSE) {
		coproc11->vfp.d.r[in->regId] = in->reg.Data64;
	}
	else {
		coproc11->vfp.d.r[in->regId] = in->reg.Data32;
	}
	return;
}

#define OP_SET_FREG(coproc11, arg, op, regName)	\
do {	\
	(arg)->name = #regName;	\
	(arg)->freg.regId = (op)->regName;	\
	(arg)->freg.is64 = ((op)->sz == 1);	\
	cpu_get_freg((coproc11), &(arg)->freg);	\
} while (0)

#endif /* _ARM_COPROC_FPU_H_ */
