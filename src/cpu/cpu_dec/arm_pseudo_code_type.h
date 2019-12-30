#ifndef _ARM_PSEUDO_CODE_TYPE_H_
#define _ARM_PSEUDO_CODE_TYPE_H_

#include "cpu_op_types.h"

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeImmediateData32Type	imm32;
} arm_add_imm_input_type;

typedef struct {
	uint32	next_address;

	sint32	result;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_add_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeImmediateData32Type	imm32;

	bool	add;
} arm_adr_imm_input_type;

typedef struct {
	uint32	next_address;

	sint32	result;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_adr_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	SP;

	PseudoCodeImmediateData32Type	imm32;
} arm_add_spimm_input_type;

typedef struct {
	uint32	next_address;

	sint32	result;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_add_spimm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	uint8	opcode;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	bool	register_form;

	sint32	shift_t;

	sint32	shift_n;

	PseudoCodeImmediateData32Type	imm32;
} arm_subs_pclr_input_type;

typedef struct {
	uint32	next_address;

	sint32	result;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_subs_pclr_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeImmediateData32Type	imm32;
} arm_mov_imm_input_type;

typedef struct {
	uint32	next_address;

	sint32	result;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_mov_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rm;
} arm_mov_reg_input_type;

typedef struct {
	uint32	next_address;

	sint32	result;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_mov_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	sint32	type;
} arm_bl_imm_input_type;

typedef struct {
	uint32	next_address;

	PseudoCodeRegisterDataType	LR;

	sint32	result;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_bl_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeRegisterDataType	PC;
} arm_b_imm_input_type;

typedef struct {
	uint32	next_address;

	sint32	result;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_b_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rm;
} arm_bx_reg_input_type;

typedef struct {
	uint32	next_address;

	sint32	result;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_bx_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	bool	add;

	bool	index;

	bool	wback;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt;
} arm_ldr_imm_input_type;

typedef struct {
	uint32	next_address;

	uint32	result;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ldr_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	bool	add;

	bool	index;

	bool	wback;

	SRType	shift_t;

	uint32	shift_n;

	uint32	size;

	bool	sign;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt;

	PseudoCodeRegisterDataType	Rm;
} arm_ldr_reg_input_type;

typedef struct {
	uint32	next_address;

	uint32	result;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ldr_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	uint8	bitcount;

	bool	UnalignedAllowed;

	uint32	registers;

	PseudoCodeRegisterDataType	SP;
} arm_push_input_type;

typedef struct {
	uint32	next_address;

	PseudoCodeRegisterDataType	SP;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_push_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	uint8	bitcount;

	bool	UnalignedAllowed;

	uint32	registers;

	PseudoCodeRegisterDataType	SP;
} arm_pop_input_type;

typedef struct {
	uint32	next_address;

	PseudoCodeRegisterDataType	SP;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_pop_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	bool	add;

	bool	index;

	bool	wback;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt;
} arm_str_imm_input_type;

typedef struct {
	uint32	next_address;

	PseudoCodeRegisterDataType	Rn;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_str_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	bool	add;

	bool	index;

	bool	wback;

	SRType	shift_t;

	uint32	shift_n;

	uint32	size;

	bool	sign;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt;

	PseudoCodeRegisterDataType	Rm;
} arm_str_reg_input_type;

typedef struct {
	uint32	next_address;

	uint32	result;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_str_reg_output_type;

#endif /* !_ARM_PSEUDO_CODE_TYPE_H_ */