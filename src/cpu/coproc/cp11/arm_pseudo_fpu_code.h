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

#endif /* _ARM_PSEUDO_FPU_CODE_H_ */
