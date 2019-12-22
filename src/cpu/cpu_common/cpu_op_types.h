#ifndef _CPU_OP_TYPES_H_
#define _CPU_OP_TYPES_H_

#include "std_types.h"

typedef struct {
	char* instrName;
	sint32 imm32;
	uint32 Rd;
	uint32 cond;
	uint8 S;
	bool carry_out;
} ArmMovImmArgType;


#endif /* _CPU_OP_TYPES_H_ */
