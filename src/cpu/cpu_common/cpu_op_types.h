#ifndef _CPU_OP_TYPES_H_
#define _CPU_OP_TYPES_H_

#include "std_types.h"
#include "target_cpu.h"

typedef struct {
	char* instrName;
	sint32 imm32;
	uint32 Rd;
	uint32 cond;
	uint8 S;
	bool carry_out;
} ArmMovImmArgType;

typedef struct {
	char* instrName;
	sint32 imm32;
	uint32 Rd;
	uint32 Rn;
	uint32 cond;
	uint8 S;
} ArmAddImmArgType;

typedef struct {
	char* instrName;
	sint32 imm32;
	uint32 cond;
	InstrSetType type;
} ArmBranchImmArgType;

typedef struct {
	char* instrName;
	bool add_flag;
	bool index_flag;
	bool wback_flag;
	uint32 imm32;
	uint32 Rn;
	uint32 Rt;
	uint32 cond;
} ArmStoreImmArgType;

typedef struct {
	char* instrName;
	bool add_flag;
	bool index_flag;
	bool wback_flag;
	uint32 imm32;
	uint32 Rn;
	uint32 Rt;
	uint32 cond;
} ArmLoadImmArgType;

#endif /* _CPU_OP_TYPES_H_ */
