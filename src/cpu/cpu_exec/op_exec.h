#ifndef _OP_EXEC_H_
#define _OP_EXEC_H_

#include "target_cpu.h"
#include "cpu_dec/op_codeid.h"
#include "cpu_common/cpu_ops.h"
#include "cpu_exec/op_exec_ops.h"

#define OP_EXEC_TABLE_NUM		1U /* TODO */

typedef struct {
	int (*exec) (TargetCoreType *cpu);
} OpExecType;

extern OpExecType op_exec_table[OP_EXEC_TABLE_NUM];

#endif /* _OP_EXEC_H_ */
