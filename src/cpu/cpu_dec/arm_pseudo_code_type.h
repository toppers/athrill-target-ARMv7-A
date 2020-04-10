#ifndef _ARM_PSEUDO_CODE_TYPE_H_
#define _ARM_PSEUDO_CODE_TYPE_H_

#include "arm_pseudo_code_common_type.h"

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

	PseudoCodeRegisterDataType	Ra;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;
} arm_mla_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_mla_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_adc_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_adc_reg_output_type;

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

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_sub_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_sub_reg_output_type;

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

	PseudoCodeSignType	sign;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeImmediateData32Type	imm32;
} arm_cmn_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeCmpResultType	result;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_cmn_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_cmn_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeCmpResultType	result;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_cmn_reg_output_type;

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

	PseudoCodeImmediateData32Type	imm32;
} arm_mvn_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_mvn_imm_output_type;

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

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_mvn_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_mvn_reg_output_type;

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

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rm;
} arm_bl_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	LR;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_bl_reg_output_type;

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


	PseudoCodeRegisterDataType	Rt;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ldr_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeBoolAddType	add;

	PseudoCodeRegisterDataType	PC;

	PseudoCodeRegisterDataType	Rt;
} arm_ldr_literal_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rt;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ldr_literal_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeBoolAddType	add;

	PseudoCodeBoolIndexType	index;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt;
} arm_ldrh_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ldrh_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeBoolAddType	add;

	PseudoCodeBoolIndexType	index;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt;
} arm_ldrsh_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ldrsh_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeBoolAddType	add;

	PseudoCodeBoolIndexType	index;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt1;

	PseudoCodeRegisterDataType	Rt2;
} arm_ldrd_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt1;

	PseudoCodeRegisterDataType	Rt2;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ldrd_imm_output_type;

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


	PseudoCodeRegisterDataType	Rt;
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

	PseudoCodeBoolWbackType	wback;

	PseudoCodeRegisterListType	registers;

	PseudoCodeRegisterDataType	Rn;
} arm_stmfd_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rn;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_stmfd_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeBitCountType	bitcount;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeRegisterListType	registers;

	PseudoCodeRegisterDataType	Rn;
} arm_stmib_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rn;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_stmib_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeBitCountType	bitcount;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterListType	registers;
} arm_stm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rn;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_stm_output_type;

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

	PseudoCodeConditionDataType	cond;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeBitCountType	bitcount;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterListType	registers;
} arm_ldm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rn;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ldm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeBitCountType	bitcount;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterListType	registers;
} arm_ldmib_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rn;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ldmib_output_type;

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

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeBoolAddType	add;

	PseudoCodeBoolIndexType	index;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rt1;

	PseudoCodeRegisterDataType	Rt2;
} arm_strd_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rn;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_strd_imm_output_type;

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

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeWriteNZCVQType	write_nzcvq;

	PseudoCodeWriteGType	write_g;
} arm_msr_imm_input_type;

typedef struct {
	uint32	next_address;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_msr_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeMaskType	mask;

	PseudoCodeWriteSpsrType	write_spsr;
} arm_msr2_imm_input_type;

typedef struct {
	uint32	next_address;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_msr2_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeMaskType	mask;

	PseudoCodeWriteSpsrType	write_spsr;
} arm_msr2_reg_input_type;

typedef struct {
	uint32	next_address;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_msr2_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rd;
} arm_mrs_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_mrs_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeCoprocType	cp;

	PseudoCodeCoprocCRnType	CRn;

	PseudoCodeCoprocOp1Type	op1;

	PseudoCodeCoprocCRmType	CRm;

	PseudoCodeCoprocOp2Type	op2;

	PseudoCodeRegisterDataType	Rt;
} arm_mcr_input_type;

typedef struct {
	uint32	next_address;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_mcr_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeCoprocType	cp;

	PseudoCodeCoprocCRnType	CRn;

	PseudoCodeCoprocOp1Type	op1;

	PseudoCodeCoprocCRmType	CRm;

	PseudoCodeCoprocOp2Type	op2;

	PseudoCodeRegisterDataType	Rt;
} arm_mrc_input_type;

typedef struct {
	uint32	next_address;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_mrc_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeImmediateData32Type	imm32;
} arm_bic_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_bic_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_bic_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_bic_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rs;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_bic_shift_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_bic_shift_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeLsbType	lsb;

	PseudoCodeMsbType	msb;
} arm_ubfx_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_ubfx_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeImmediateData32Type	imm32;
} arm_orr_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_orr_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeImmediateData32Type	imm32;
} arm_eor_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_eor_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_orr_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_orr_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_eor_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_eor_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeImmediateData16Type	imm16;
} arm_movt_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_movt_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;

	PseudoCodeRegisterDataType	Rm;
} arm_lsl_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_lsl_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeRegisterDataType	Rn;
} arm_lsl_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_lsl_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;

	PseudoCodeRegisterDataType	Rm;
} arm_lsr_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_lsr_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeRegisterDataType	Rn;
} arm_lsr_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_lsr_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeMsbitType	msbit;

	PseudoCodeLsbitType	lsbit;

	PseudoCodeRegisterDataType	Rd;
} arm_bfc_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_bfc_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeMsbitType	msbit;

	PseudoCodeLsbitType	lsbit;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;
} arm_bfi_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_bfi_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeImmediateData32Type	imm32;
} arm_and_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_and_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_and_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_and_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeRegisterDataType	Rs;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;
} arm_and_shift_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_and_shift_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeSizeType	size;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRotationType	rotate;

	PseudoCodeRegisterDataType	Rm;
} arm_uxt_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_uxt_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;

	PseudoCodeRegisterDataType	Rm;
} arm_rsb_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_rsb_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeImmediateData32Type	imm32;
} arm_rsb_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_rsb_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;

	PseudoCodeRegisterDataType	Rm;
} arm_sbc_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_sbc_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rm;
} arm_mul_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_mul_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRoundType	round;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rm;
} arm_smmul_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_smmul_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	RdHi;

	PseudoCodeRegisterDataType	RdLo;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeRegisterDataType	Rn;
} arm_smull_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	RdHi;

	PseudoCodeRegisterDataType	RdLo;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_smull_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	RdHi;

	PseudoCodeRegisterDataType	RdLo;

	PseudoCodeRegisterDataType	Rm;

	PseudoCodeRegisterDataType	Rn;
} arm_umull_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	RdHi;

	PseudoCodeRegisterDataType	RdLo;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_umull_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeImmediateData32Type	imm32;
} arm_tst_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_tst_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;

	PseudoCodeRegisterDataType	Rm;
} arm_tst_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_tst_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRotationType	rotate;

	PseudoCodeRegisterDataType	Rm;
} arm_sxtb_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_sxtb_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRotationType	rotate;

	PseudoCodeRegisterDataType	Rm;
} arm_sxth_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_sxth_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeUpdateStatusFlagType	S;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeSRType	shift_t;

	PseudoCodeShiftNType	shift_n;

	PseudoCodeRegisterDataType	Rm;
} arm_asr_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;

	PseudoCodeStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_asr_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeModeType	mode;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeBoolIncrementType	increment;

	PseudoCodeBoolWordHigherType	wordhigher;

	PseudoCodeRegisterDataType	SP;

	PseudoCodeRegisterDataType	LR;

	PseudoCodeSPSRType	SPSR;
} arm_srs_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	SP;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_srs_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rd;

	PseudoCodeRegisterDataType	Rm;
} arm_clz_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_clz_output_type;

typedef struct {
	char* instrName;

	PseudoCodeBoolWbackType	wback;

	PseudoCodeBoolIncrementType	increment;

	PseudoCodeBoolWordHigherType	wordhigher;

	PseudoCodeRegisterDataType	Rn;
} arm_rfe_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	Rn;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_rfe_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;
} arm_wfi_input_type;

typedef struct {
	uint32	next_address;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_wfi_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeFloatRegisterDataType	Vn;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatRegisterDataType	Vm;

	PseudoCodeBoolWbackType	advsimd;

	PseudoCodeBoolIncrementType	dp_operation;
} arm_vadd_freg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vadd_freg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeFloatRegisterDataType	Vn;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatRegisterDataType	Vm;

	PseudoCodeBoolWbackType	advsimd;

	PseudoCodeBoolIncrementType	dp_operation;
} arm_vsub_freg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vsub_freg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeFloatRegisterDataType	Vn;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatRegisterDataType	Vm;

	PseudoCodeBoolWbackType	advsimd;

	PseudoCodeBoolIncrementType	dp_operation;
} arm_vmul_freg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vmul_freg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeFloatRegisterDataType	Vn;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatRegisterDataType	Vm;

	PseudoCodeBoolWbackType	advsimd;

	PseudoCodeBoolIncrementType	dp_operation;
} arm_vdiv_freg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vdiv_freg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeBoolAddType	add;

	PseudoCodeImmediateData32Type	imm32;
} arm_vldr_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vldr_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeDoubleToSingleType	double_to_single;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatRegisterDataType	Vm;
} arm_vcvt_df_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vcvt_df_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeBoolIncrementType	dp_operation;

	PseudoCodeToIntegerType	to_integer;

	PseudoCodeUnsignedCvtType	unsigned_cvt;

	PseudoCodeRoundZeroType	round_zero;

	PseudoCodeRoundNearestType	round_nearest;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatRegisterDataType	Vm;
} arm_vcvt_fi_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vcvt_fi_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeSingleRegType	single_reg;

	PseudoCodeBoolAddType	add;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeRegisterDataType	Rn;

	PseudoCodeFloatRegisterDataType	Vd;
} arm_vstr_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vstr_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeBoolIncrementType	dp_operation;

	PseudoCodeQuietNanExcType	quiet_nan_exc;

	PseudoCodeWithZeroType	with_zero;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatRegisterDataType	Vm;
} arm_vcmp_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vcmp_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeRegisterDataType	Rt;
} arm_vmrs_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vmrs_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeImmediateData32Type	imm32;

	PseudoCodeImmediateData64Type	imm64;

	PseudoCodeBoolWbackType	advsimd;

	PseudoCodeSingleRegType	single_reg;

	PseudoCodeFloatRegisterDataType	Vd1;

	PseudoCodeFloatRegisterDataType	Vd2;

	PseudoCodeRegNumType	regs;
} arm_vmov_imm_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd1;

	PseudoCodeFloatRegisterDataType	Vd2;

	PseudoCodeFloatStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vmov_imm_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeSingleRegType	single_reg;

	PseudoCodeBoolWbackType	advsimd;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatRegisterDataType	Vm;

	PseudoCodeRegNumType	regs;
} arm_vmov_reg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vmov_reg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeBoolIncrementType	dp_operation;

	PseudoCodeBoolWbackType	advsimd;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatRegisterDataType	Vm;

	PseudoCodeRegNumType	regs;
} arm_vneg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vneg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeBoolIncrementType	dp_operation;

	PseudoCodeBoolWbackType	advsimd;

	PseudoCodeBoolAddType	add;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatRegisterDataType	Vn;

	PseudoCodeFloatRegisterDataType	Vm;

	PseudoCodeRegNumType	regs;
} arm_vmla_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeFloatStatusFlagType	status_flag;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vmla_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeToArmRegisterType	to_arm_register;

	PseudoCodeFloatRegisterDataType	Vn;

	PseudoCodeRegisterDataType	Rt;
} arm_vmov_sreg_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeFloatRegisterDataType	Vn;

	PseudoCodeRegisterDataType	Rt;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vmov_sreg_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeSingleRegType	single_reg;

	PseudoCodeRegNumType	regs;

	PseudoCodeRegisterDataType	SP;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeImmediateData32Type	imm32;
} arm_vpush_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	SP;

	PseudoCodeFloatRegisterDataType	Vd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vpush_output_type;

typedef struct {
	char* instrName;

	PseudoCodeConditionDataType	cond;

	PseudoCodeSingleRegType	single_reg;

	PseudoCodeRegNumType	regs;

	PseudoCodeRegisterDataType	SP;

	PseudoCodeFloatRegisterDataType	Vd;

	PseudoCodeImmediateData32Type	imm32;
} arm_vpop_input_type;

typedef struct {
	uint32	next_address;


	PseudoCodeRegisterDataType	SP;

	PseudoCodeFloatRegisterDataType	Vd;
PseudoCodeStatusType		status;
	PseudoCodeCondPassedType	passed;
} arm_vpop_output_type;

#endif /* !_ARM_PSEUDO_CODE_TYPE_H_ */