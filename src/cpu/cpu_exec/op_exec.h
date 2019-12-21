#ifndef _OP_EXEC_H_
#define _OP_EXEC_H_

#include "target_cpu.h"
#include "op_dec_types.h"

typedef struct {
	int clocks;
	int (*exec) (TargetCoreType *cpu);
} OpExecType;
extern OpExecType op_exec_table[arm_OpCodeId_Num];

#endif /* _OP_EXEC_H_ */
