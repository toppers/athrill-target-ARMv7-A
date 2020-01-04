#ifndef _ARM_COPROC_OP_H_
#define _ARM_COPROC_OP_H_

#include "std_types.h"

typedef struct {
	uint32	cp;
	uint32	CRn;
	uint32	op1;
	uint32	CRm;
	uint32	op2;
} CoprocOpType;

#endif /* _ARM_COPROC_OP_H_ */
