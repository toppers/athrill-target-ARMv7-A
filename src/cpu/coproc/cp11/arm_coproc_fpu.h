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

#endif /* _ARM_COPROC_FPU_H_ */
