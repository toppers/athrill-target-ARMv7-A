#ifndef _arm_MC_DECODER_H_
#define _arm_MC_DECODER_H_

#include <stdint.h>

typedef uint8_t arm_uint8;
typedef uint16_t arm_uint16;
typedef uint32_t arm_uint32;

#define arm_OP_CODE_FORMAT_NUM	arm_OP_CODE_FORMAT_UNKNOWN

typedef enum {
	
		arm_OP_CODE_FORMAT_arm_add_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_add_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_add_spimm_a1,
	
		arm_OP_CODE_FORMAT_arm_adr_a1,
	
		arm_OP_CODE_FORMAT_arm_subs_pclr_a1,
	
		arm_OP_CODE_FORMAT_arm_cmp_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_cmn_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_sub_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_sub_spimm_a1,
	
		arm_OP_CODE_FORMAT_arm_cmp_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_mov_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_mov_imm_a2,
	
		arm_OP_CODE_FORMAT_arm_mvn_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_mov_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_mvn_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_bl_a1,
	
		arm_OP_CODE_FORMAT_arm_blx_a2,
	
		arm_OP_CODE_FORMAT_arm_blx_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_b_a1,
	
		arm_OP_CODE_FORMAT_arm_bx_a1,
	
		arm_OP_CODE_FORMAT_arm_str_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_strb_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_strh_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_strd_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_strb_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_push_a1,
	
		arm_OP_CODE_FORMAT_arm_push_a2,
	
		arm_OP_CODE_FORMAT_arm_ldr_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_ldr_literal_a1,
	
		arm_OP_CODE_FORMAT_arm_ldrb_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_ldrh_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_ldrd_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_ldr_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_ldrb_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_ldrh_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_pop_a1,
	
		arm_OP_CODE_FORMAT_arm_pop_a2,
	
		arm_OP_CODE_FORMAT_arm_nop_a1,
	
		arm_OP_CODE_FORMAT_arm_msr_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_msr2_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_mrs_a1,
	
		arm_OP_CODE_FORMAT_arm_msr2_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_mcr_a1,
	
		arm_OP_CODE_FORMAT_arm_mcr2_a2,
	
		arm_OP_CODE_FORMAT_arm_mrc_a1,
	
		arm_OP_CODE_FORMAT_arm_mrc2_a2,
	
		arm_OP_CODE_FORMAT_arm_bic_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_orr_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_orr_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_movt_a1,
	
		arm_OP_CODE_FORMAT_arm_lsl_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_lsl_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_lsr_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_bfc_a1,
	
		arm_OP_CODE_FORMAT_arm_and_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_and_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_utxb_a1,
	
		arm_OP_CODE_FORMAT_arm_utxh_a1,
	
		arm_OP_CODE_FORMAT_arm_rsb_reg_a1,
	
		arm_OP_CODE_FORMAT_arm_sbc_reg_a1,
	
	arm_OP_CODE_FORMAT_UNKNOWN,
} arm_OpCodeFormatId;

typedef enum {
	
		arm_OpCodeId_arm_add_imm_a1,
	
		arm_OpCodeId_arm_add_reg_a1,
	
		arm_OpCodeId_arm_add_spimm_a1,
	
		arm_OpCodeId_arm_adr_a1,
	
		arm_OpCodeId_arm_subs_pclr_a1,
	
		arm_OpCodeId_arm_cmp_imm_a1,
	
		arm_OpCodeId_arm_cmn_imm_a1,
	
		arm_OpCodeId_arm_sub_imm_a1,
	
		arm_OpCodeId_arm_sub_spimm_a1,
	
		arm_OpCodeId_arm_cmp_reg_a1,
	
		arm_OpCodeId_arm_mov_imm_a1,
	
		arm_OpCodeId_arm_mov_imm_a2,
	
		arm_OpCodeId_arm_mvn_imm_a1,
	
		arm_OpCodeId_arm_mov_reg_a1,
	
		arm_OpCodeId_arm_mvn_reg_a1,
	
		arm_OpCodeId_arm_bl_a1,
	
		arm_OpCodeId_arm_blx_a2,
	
		arm_OpCodeId_arm_blx_reg_a1,
	
		arm_OpCodeId_arm_b_a1,
	
		arm_OpCodeId_arm_bx_a1,
	
		arm_OpCodeId_arm_str_imm_a1,
	
		arm_OpCodeId_arm_strb_imm_a1,
	
		arm_OpCodeId_arm_strh_imm_a1,
	
		arm_OpCodeId_arm_strd_imm_a1,
	
		arm_OpCodeId_arm_strb_reg_a1,
	
		arm_OpCodeId_arm_push_a1,
	
		arm_OpCodeId_arm_push_a2,
	
		arm_OpCodeId_arm_ldr_imm_a1,
	
		arm_OpCodeId_arm_ldr_literal_a1,
	
		arm_OpCodeId_arm_ldrb_imm_a1,
	
		arm_OpCodeId_arm_ldrh_imm_a1,
	
		arm_OpCodeId_arm_ldrd_imm_a1,
	
		arm_OpCodeId_arm_ldr_reg_a1,
	
		arm_OpCodeId_arm_ldrb_reg_a1,
	
		arm_OpCodeId_arm_ldrh_reg_a1,
	
		arm_OpCodeId_arm_pop_a1,
	
		arm_OpCodeId_arm_pop_a2,
	
		arm_OpCodeId_arm_nop_a1,
	
		arm_OpCodeId_arm_msr_imm_a1,
	
		arm_OpCodeId_arm_msr2_imm_a1,
	
		arm_OpCodeId_arm_mrs_a1,
	
		arm_OpCodeId_arm_msr2_reg_a1,
	
		arm_OpCodeId_arm_mcr_a1,
	
		arm_OpCodeId_arm_mcr2_a2,
	
		arm_OpCodeId_arm_mrc_a1,
	
		arm_OpCodeId_arm_mrc2_a2,
	
		arm_OpCodeId_arm_bic_imm_a1,
	
		arm_OpCodeId_arm_orr_imm_a1,
	
		arm_OpCodeId_arm_orr_reg_a1,
	
		arm_OpCodeId_arm_movt_a1,
	
		arm_OpCodeId_arm_lsl_imm_a1,
	
		arm_OpCodeId_arm_lsl_reg_a1,
	
		arm_OpCodeId_arm_lsr_imm_a1,
	
		arm_OpCodeId_arm_bfc_a1,
	
		arm_OpCodeId_arm_and_imm_a1,
	
		arm_OpCodeId_arm_and_reg_a1,
	
		arm_OpCodeId_arm_utxb_a1,
	
		arm_OpCodeId_arm_utxh_a1,
	
		arm_OpCodeId_arm_rsb_reg_a1,
	
		arm_OpCodeId_arm_sbc_reg_a1,
	
	arm_OpCodeId_Num,
} arm_OpCodeId;

typedef struct {
	arm_OpCodeFormatId	format_id;
	arm_OpCodeId		code_id;
} arm_OperationCodeType;



typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_add_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 type;	/* 6-5 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_add_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_add_spimm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_adr_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 opcode;	/* 24-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_subs_pclr_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_cmp_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_cmn_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_sub_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_sub_spimm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 type;	/* 6-5 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_cmp_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_mov_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 imm4;	/* 19-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_mov_imm_a2;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_mvn_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_mov_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 type;	/* 6-5 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_mvn_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint32 imm24;	/* 23-0 */
	
} arm_OpCodeFormatType_arm_bl_a1;

typedef struct {
	
		arm_uint8 H;	/* 24-24 */
	
		arm_uint32 imm24;	/* 23-0 */
	
} arm_OpCodeFormatType_arm_blx_a2;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_blx_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint32 imm24;	/* 23-0 */
	
} arm_OpCodeFormatType_arm_b_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_bx_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_str_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_strb_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 imm8;	/* 11-8, 3-0 */
	
} arm_OpCodeFormatType_arm_strh_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 imm8;	/* 11-8, 3-0 */
	
} arm_OpCodeFormatType_arm_strd_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 type;	/* 6-5 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_strb_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint16 register_list;	/* 15-0 */
	
} arm_OpCodeFormatType_arm_push_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 Rt;	/* 15-12 */
	
} arm_OpCodeFormatType_arm_push_a2;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_ldr_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_ldr_literal_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_ldrb_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 imm8;	/* 11-8, 3-0 */
	
} arm_OpCodeFormatType_arm_ldrh_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 imm8;	/* 11-8, 3-0 */
	
} arm_OpCodeFormatType_arm_ldrd_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 type;	/* 6-5 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_ldr_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 type;	/* 6-5 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_ldrb_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 P;	/* 24-24 */
	
		arm_uint8 U;	/* 23-23 */
	
		arm_uint8 W;	/* 21-21 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_ldrh_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint16 register_list;	/* 15-0 */
	
} arm_OpCodeFormatType_arm_pop_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 Rt;	/* 15-12 */
	
} arm_OpCodeFormatType_arm_pop_a2;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
} arm_OpCodeFormatType_arm_nop_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 mask;	/* 19-18 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_msr_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 R;	/* 22-22 */
	
		arm_uint8 mask;	/* 19-16 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_msr2_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 Rd;	/* 15-12 */
	
} arm_OpCodeFormatType_arm_mrs_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 R;	/* 22-22 */
	
		arm_uint8 mask;	/* 19-16 */
	
		arm_uint8 Rn;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_msr2_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 opc1;	/* 23-21 */
	
		arm_uint8 CRn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 coproc;	/* 11-8 */
	
		arm_uint8 opc2;	/* 7-5 */
	
		arm_uint8 CRm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_mcr_a1;

typedef struct {
	
		arm_uint8 opc1;	/* 23-21 */
	
		arm_uint8 CRn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 coproc;	/* 11-8 */
	
		arm_uint8 opc2;	/* 7-5 */
	
		arm_uint8 CRm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_mcr2_a2;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 opc1;	/* 23-21 */
	
		arm_uint8 CRn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 coproc;	/* 11-8 */
	
		arm_uint8 opc2;	/* 7-5 */
	
		arm_uint8 CRm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_mrc_a1;

typedef struct {
	
		arm_uint8 opc1;	/* 23-21 */
	
		arm_uint8 CRn;	/* 19-16 */
	
		arm_uint8 Rt;	/* 15-12 */
	
		arm_uint8 coproc;	/* 11-8 */
	
		arm_uint8 opc2;	/* 7-5 */
	
		arm_uint8 CRm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_mrc2_a2;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_bic_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_orr_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 type;	/* 6-5 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_orr_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint16 imm16;	/* 19-16, 11-0 */
	
		arm_uint8 Rd;	/* 15-12 */
	
} arm_OpCodeFormatType_arm_movt_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_lsl_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 Rm;	/* 11-8 */
	
		arm_uint8 Rn;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_lsl_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_lsr_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 msb;	/* 20-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 lsb;	/* 11-7 */
	
} arm_OpCodeFormatType_arm_bfc_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint16 imm12;	/* 11-0 */
	
} arm_OpCodeFormatType_arm_and_imm_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 type;	/* 6-5 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_and_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 rotate;	/* 11-10 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_utxb_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 rotate;	/* 11-10 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_utxh_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 type;	/* 6-5 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_rsb_reg_a1;

typedef struct {
	
		arm_uint8 cond;	/* 31-28 */
	
		arm_uint8 S;	/* 20-20 */
	
		arm_uint8 Rn;	/* 19-16 */
	
		arm_uint8 Rd;	/* 15-12 */
	
		arm_uint8 imm5;	/* 11-7 */
	
		arm_uint8 type;	/* 6-5 */
	
		arm_uint8 Rm;	/* 3-0 */
	
} arm_OpCodeFormatType_arm_sbc_reg_a1;


typedef struct {
	arm_OpCodeFormatId type_id;
    union {
		
        	arm_OpCodeFormatType_arm_add_imm_a1 arm_add_imm_a1;
		
        	arm_OpCodeFormatType_arm_add_reg_a1 arm_add_reg_a1;
		
        	arm_OpCodeFormatType_arm_add_spimm_a1 arm_add_spimm_a1;
		
        	arm_OpCodeFormatType_arm_adr_a1 arm_adr_a1;
		
        	arm_OpCodeFormatType_arm_subs_pclr_a1 arm_subs_pclr_a1;
		
        	arm_OpCodeFormatType_arm_cmp_imm_a1 arm_cmp_imm_a1;
		
        	arm_OpCodeFormatType_arm_cmn_imm_a1 arm_cmn_imm_a1;
		
        	arm_OpCodeFormatType_arm_sub_imm_a1 arm_sub_imm_a1;
		
        	arm_OpCodeFormatType_arm_sub_spimm_a1 arm_sub_spimm_a1;
		
        	arm_OpCodeFormatType_arm_cmp_reg_a1 arm_cmp_reg_a1;
		
        	arm_OpCodeFormatType_arm_mov_imm_a1 arm_mov_imm_a1;
		
        	arm_OpCodeFormatType_arm_mov_imm_a2 arm_mov_imm_a2;
		
        	arm_OpCodeFormatType_arm_mvn_imm_a1 arm_mvn_imm_a1;
		
        	arm_OpCodeFormatType_arm_mov_reg_a1 arm_mov_reg_a1;
		
        	arm_OpCodeFormatType_arm_mvn_reg_a1 arm_mvn_reg_a1;
		
        	arm_OpCodeFormatType_arm_bl_a1 arm_bl_a1;
		
        	arm_OpCodeFormatType_arm_blx_a2 arm_blx_a2;
		
        	arm_OpCodeFormatType_arm_blx_reg_a1 arm_blx_reg_a1;
		
        	arm_OpCodeFormatType_arm_b_a1 arm_b_a1;
		
        	arm_OpCodeFormatType_arm_bx_a1 arm_bx_a1;
		
        	arm_OpCodeFormatType_arm_str_imm_a1 arm_str_imm_a1;
		
        	arm_OpCodeFormatType_arm_strb_imm_a1 arm_strb_imm_a1;
		
        	arm_OpCodeFormatType_arm_strh_imm_a1 arm_strh_imm_a1;
		
        	arm_OpCodeFormatType_arm_strd_imm_a1 arm_strd_imm_a1;
		
        	arm_OpCodeFormatType_arm_strb_reg_a1 arm_strb_reg_a1;
		
        	arm_OpCodeFormatType_arm_push_a1 arm_push_a1;
		
        	arm_OpCodeFormatType_arm_push_a2 arm_push_a2;
		
        	arm_OpCodeFormatType_arm_ldr_imm_a1 arm_ldr_imm_a1;
		
        	arm_OpCodeFormatType_arm_ldr_literal_a1 arm_ldr_literal_a1;
		
        	arm_OpCodeFormatType_arm_ldrb_imm_a1 arm_ldrb_imm_a1;
		
        	arm_OpCodeFormatType_arm_ldrh_imm_a1 arm_ldrh_imm_a1;
		
        	arm_OpCodeFormatType_arm_ldrd_imm_a1 arm_ldrd_imm_a1;
		
        	arm_OpCodeFormatType_arm_ldr_reg_a1 arm_ldr_reg_a1;
		
        	arm_OpCodeFormatType_arm_ldrb_reg_a1 arm_ldrb_reg_a1;
		
        	arm_OpCodeFormatType_arm_ldrh_reg_a1 arm_ldrh_reg_a1;
		
        	arm_OpCodeFormatType_arm_pop_a1 arm_pop_a1;
		
        	arm_OpCodeFormatType_arm_pop_a2 arm_pop_a2;
		
        	arm_OpCodeFormatType_arm_nop_a1 arm_nop_a1;
		
        	arm_OpCodeFormatType_arm_msr_imm_a1 arm_msr_imm_a1;
		
        	arm_OpCodeFormatType_arm_msr2_imm_a1 arm_msr2_imm_a1;
		
        	arm_OpCodeFormatType_arm_mrs_a1 arm_mrs_a1;
		
        	arm_OpCodeFormatType_arm_msr2_reg_a1 arm_msr2_reg_a1;
		
        	arm_OpCodeFormatType_arm_mcr_a1 arm_mcr_a1;
		
        	arm_OpCodeFormatType_arm_mcr2_a2 arm_mcr2_a2;
		
        	arm_OpCodeFormatType_arm_mrc_a1 arm_mrc_a1;
		
        	arm_OpCodeFormatType_arm_mrc2_a2 arm_mrc2_a2;
		
        	arm_OpCodeFormatType_arm_bic_imm_a1 arm_bic_imm_a1;
		
        	arm_OpCodeFormatType_arm_orr_imm_a1 arm_orr_imm_a1;
		
        	arm_OpCodeFormatType_arm_orr_reg_a1 arm_orr_reg_a1;
		
        	arm_OpCodeFormatType_arm_movt_a1 arm_movt_a1;
		
        	arm_OpCodeFormatType_arm_lsl_imm_a1 arm_lsl_imm_a1;
		
        	arm_OpCodeFormatType_arm_lsl_reg_a1 arm_lsl_reg_a1;
		
        	arm_OpCodeFormatType_arm_lsr_imm_a1 arm_lsr_imm_a1;
		
        	arm_OpCodeFormatType_arm_bfc_a1 arm_bfc_a1;
		
        	arm_OpCodeFormatType_arm_and_imm_a1 arm_and_imm_a1;
		
        	arm_OpCodeFormatType_arm_and_reg_a1 arm_and_reg_a1;
		
        	arm_OpCodeFormatType_arm_utxb_a1 arm_utxb_a1;
		
        	arm_OpCodeFormatType_arm_utxh_a1 arm_utxh_a1;
		
        	arm_OpCodeFormatType_arm_rsb_reg_a1 arm_rsb_reg_a1;
		
        	arm_OpCodeFormatType_arm_sbc_reg_a1 arm_sbc_reg_a1;
		
    } code;
} arm_OpDecodedCodeType;

#define arm_OP_DECODE_MAX	(3)

extern int arm_op_parse(arm_uint16 code[arm_OP_DECODE_MAX], arm_OpDecodedCodeType *decoded_code, arm_OperationCodeType *optype);

struct TargetCore;
typedef struct {
	int clocks;
	int (*exec) (struct TargetCore *cpu);
} arm_OpExecType;
extern arm_OpExecType arm_op_exec_table[arm_OpCodeId_Num];

extern int arm_op_exec_arm_add_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_add_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_add_spimm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_adr_a1(struct TargetCore *core);
extern int arm_op_exec_arm_subs_pclr_a1(struct TargetCore *core);
extern int arm_op_exec_arm_cmp_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_cmn_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_sub_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_sub_spimm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_cmp_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_mov_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_mov_imm_a2(struct TargetCore *core);
extern int arm_op_exec_arm_mvn_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_mov_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_mvn_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_bl_a1(struct TargetCore *core);
extern int arm_op_exec_arm_blx_a2(struct TargetCore *core);
extern int arm_op_exec_arm_blx_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_b_a1(struct TargetCore *core);
extern int arm_op_exec_arm_bx_a1(struct TargetCore *core);
extern int arm_op_exec_arm_str_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_strb_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_strh_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_strd_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_strb_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_push_a1(struct TargetCore *core);
extern int arm_op_exec_arm_push_a2(struct TargetCore *core);
extern int arm_op_exec_arm_ldr_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_ldr_literal_a1(struct TargetCore *core);
extern int arm_op_exec_arm_ldrb_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_ldrh_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_ldrd_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_ldr_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_ldrb_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_ldrh_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_pop_a1(struct TargetCore *core);
extern int arm_op_exec_arm_pop_a2(struct TargetCore *core);
extern int arm_op_exec_arm_nop_a1(struct TargetCore *core);
extern int arm_op_exec_arm_msr_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_msr2_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_mrs_a1(struct TargetCore *core);
extern int arm_op_exec_arm_msr2_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_mcr_a1(struct TargetCore *core);
extern int arm_op_exec_arm_mcr2_a2(struct TargetCore *core);
extern int arm_op_exec_arm_mrc_a1(struct TargetCore *core);
extern int arm_op_exec_arm_mrc2_a2(struct TargetCore *core);
extern int arm_op_exec_arm_bic_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_orr_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_orr_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_movt_a1(struct TargetCore *core);
extern int arm_op_exec_arm_lsl_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_lsl_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_lsr_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_bfc_a1(struct TargetCore *core);
extern int arm_op_exec_arm_and_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_and_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_utxb_a1(struct TargetCore *core);
extern int arm_op_exec_arm_utxh_a1(struct TargetCore *core);
extern int arm_op_exec_arm_rsb_reg_a1(struct TargetCore *core);
extern int arm_op_exec_arm_sbc_reg_a1(struct TargetCore *core);
#endif /* !_arm_MC_DECODER_H_ */