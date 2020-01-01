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


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_add_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_add_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_add_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeImmediateData32Type	imm32;
} arm_sub_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_sub_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeImmediateData32Type	imm32;
} arm_cmp_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeCmpResultType	result;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_cmp_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_cmp_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeCmpResultType	result;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_cmp_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeBitCountType	add;
} arm_adr_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

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


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_add_spimm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeOpcodeType	opcode;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeRegisterFormType	register_form;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;

	PseudoCodeImmediateData32Type	imm32;
} arm_subs_pclr_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	PC;

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


	PseudoCodeRegisterDataType	Rd;

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


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_mov_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeInstrSetType	type;
} arm_bl_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	LR;
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
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_bx_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeSizeType	size;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeBoolAddType	add;

	PseudoCodeBoolIndexType	index;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt;
} arm_ldr_imm_input_type;

typedef struct {
	uint32	next_address;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ldr_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeSizeType	size;

	PseudoCodeSignType	sign;

	PseudoCodeConditionDataType	cond;

	PseudoCodeBoolAddType	add;

	PseudoCodeBoolIndexType	index;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt;

	PseudoCodeRegisterDataType	Rm;
} arm_ldr_reg_input_type;

typedef struct {
	uint32	next_address;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ldr_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeBitCountType	bitcount;

	PseudoCodeUnalignedAllowedType	UnalignedAllowed;

	PseudoCodeRegisterListType	registers;

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

	PseudoCodeBitCountType	bitcount;

	PseudoCodeUnalignedAllowedType	UnalignedAllowed;

	PseudoCodeRegisterListType	registers;

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

	PseudoCodeSizeType	size;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeBoolAddType	add;

	PseudoCodeBoolIndexType	index;

	PseudoCodeBoolWbackType	wback;

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

	PseudoCodeSizeType	size;

	PseudoCodeSignType	sign;

	PseudoCodeConditionDataType	cond;

	PseudoCodeBoolAddType	add;

	PseudoCodeBoolIndexType	index;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt;

	PseudoCodeRegisterDataType	Rm;
} arm_str_reg_input_type;

typedef struct {
	uint32	next_address;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_str_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;
} arm_nop_input_type;

typedef struct {
	uint32	next_address;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_nop_output_type;

#endif /* !_ARM_PSEUDO_CODE_TYPE_H_ */