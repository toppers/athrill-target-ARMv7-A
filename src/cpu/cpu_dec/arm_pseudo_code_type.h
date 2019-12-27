#ifndef _arm_PSEUDO_CODE_TYPE_H_
#define _arm_PSEUDO_CODE_TYPE_H_

#include "cpu_op_types.h"

typedef struct {
	char* instrName;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;
} arm_add_imm_input_type;

typedef struct {
	uint32	next_address;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;
} arm_add_imm_output_type;

#endif /* !_arm_PSEUDO_CODE_TYPE_H_ */