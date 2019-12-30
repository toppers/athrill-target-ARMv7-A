#include "arm_mcdecoder.h"

typedef struct {
    arm_uint16 *code;
    arm_OpDecodedCodeType *decoded_code;
    arm_OperationCodeType *optype;
    arm_uint16 code16;
    arm_uint32 code32;
} OpDecodeContext;

/* op constants */

    /* arm_add_imm_a1 */
    #define OP_FB_MASK_arm_add_imm_a1 (0x0fe00000l) /* fixed bits mask */
    #define OP_FB_arm_add_imm_a1 (0x02800000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_add_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_add_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_add_imm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_add_imm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_imm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_add_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_add_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_add_imm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_add_imm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_imm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_add_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_add_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_add_spimm_a1 */
    #define OP_FB_MASK_arm_add_spimm_a1 (0x0fef0000l) /* fixed bits mask */
    #define OP_FB_arm_add_spimm_a1 (0x028d0000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_add_spimm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_add_spimm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_spimm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_add_spimm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_add_spimm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_spimm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_add_spimm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_add_spimm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_spimm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_add_spimm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_add_spimm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_spimm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_adr_a1 */
    #define OP_FB_MASK_arm_adr_a1 (0x0fff0000l) /* fixed bits mask */
    #define OP_FB_arm_adr_a1 (0x028f0000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_adr_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_adr_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_adr_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_adr_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_adr_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_adr_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_adr_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_adr_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_adr_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_subs_pclr_a1 */
    #define OP_FB_MASK_arm_subs_pclr_a1 (0x0e10f000l) /* fixed bits mask */
    #define OP_FB_arm_subs_pclr_a1 (0x0210f000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_subs_pclr_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_subs_pclr_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_subs_pclr_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'opcode' */
            #define OP_SF_MASK_arm_subs_pclr_a1_opcode_0 (0x01e00000l) /* subfield mask */
            #define OP_SF_EBII_arm_subs_pclr_a1_opcode_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_subs_pclr_a1_opcode_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_subs_pclr_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_subs_pclr_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_subs_pclr_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_subs_pclr_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_subs_pclr_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_subs_pclr_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_mov_imm_a1 */
    #define OP_FB_MASK_arm_mov_imm_a1 (0x0fef0000l) /* fixed bits mask */
    #define OP_FB_arm_mov_imm_a1 (0x03a00000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_mov_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_mov_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_mov_imm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_mov_imm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_imm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_mov_imm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_mov_imm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_imm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_mov_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_mov_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_mov_imm_a2 */
    #define OP_FB_MASK_arm_mov_imm_a2 (0x0ff00000l) /* fixed bits mask */
    #define OP_FB_arm_mov_imm_a2 (0x03000000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_mov_imm_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_mov_imm_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_imm_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm4' */
            #define OP_SF_MASK_arm_mov_imm_a2_imm4_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_mov_imm_a2_imm4_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_imm_a2_imm4_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_mov_imm_a2_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_mov_imm_a2_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_imm_a2_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_mov_imm_a2_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_mov_imm_a2_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_imm_a2_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_mov_reg_a1 */
    #define OP_FB_MASK_arm_mov_reg_a1 (0x0fef0ff0l) /* fixed bits mask */
    #define OP_FB_arm_mov_reg_a1 (0x01a00000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_mov_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_mov_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_mov_reg_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_mov_reg_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_reg_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_mov_reg_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_mov_reg_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_reg_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_mov_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_mov_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mov_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_bl_a1 */
    #define OP_FB_MASK_arm_bl_a1 (0x0f000000l) /* fixed bits mask */
    #define OP_FB_arm_bl_a1 (0x0b000000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_bl_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_bl_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bl_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm24' */
            #define OP_SF_MASK_arm_bl_a1_imm24_0 (0x00ffffffl) /* subfield mask */
            #define OP_SF_EBII_arm_bl_a1_imm24_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bl_a1_imm24_0 (0) /* subfield end bit position in field */
        
    

    /* arm_blx_a2 */
    #define OP_FB_MASK_arm_blx_a2 (0xfe000000l) /* fixed bits mask */
    #define OP_FB_arm_blx_a2 (0xfa000000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'H' */
            #define OP_SF_MASK_arm_blx_a2_H_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_blx_a2_H_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_blx_a2_H_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm24' */
            #define OP_SF_MASK_arm_blx_a2_imm24_0 (0x00ffffffl) /* subfield mask */
            #define OP_SF_EBII_arm_blx_a2_imm24_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_blx_a2_imm24_0 (0) /* subfield end bit position in field */
        
    

    /* arm_b_a1 */
    #define OP_FB_MASK_arm_b_a1 (0x0f000000l) /* fixed bits mask */
    #define OP_FB_arm_b_a1 (0x0a000000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_b_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_b_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_b_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm24' */
            #define OP_SF_MASK_arm_b_a1_imm24_0 (0x00ffffffl) /* subfield mask */
            #define OP_SF_EBII_arm_b_a1_imm24_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_b_a1_imm24_0 (0) /* subfield end bit position in field */
        
    

    /* arm_bx_a1 */
    #define OP_FB_MASK_arm_bx_a1 (0x0ffffff0l) /* fixed bits mask */
    #define OP_FB_arm_bx_a1 (0x012fff10l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_bx_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_bx_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bx_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_bx_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_bx_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bx_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_str_imm_a1 */
    #define OP_FB_MASK_arm_str_imm_a1 (0x0e500000l) /* fixed bits mask */
    #define OP_FB_arm_str_imm_a1 (0x04000000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_str_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_str_imm_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_imm_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_imm_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_str_imm_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_imm_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_imm_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_str_imm_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_imm_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_imm_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_str_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_str_imm_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_imm_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_imm_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_str_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_str_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_strb_reg_a1 */
    #define OP_FB_MASK_arm_strb_reg_a1 (0x0e500010l) /* fixed bits mask */
    #define OP_FB_arm_strb_reg_a1 (0x06400000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_strb_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_strb_reg_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_reg_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_reg_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_strb_reg_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_reg_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_reg_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_strb_reg_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_reg_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_reg_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_strb_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_strb_reg_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_reg_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_reg_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_strb_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_strb_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_strb_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_strb_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_push_a1 */
    #define OP_FB_MASK_arm_push_a1 (0x0fff0000l) /* fixed bits mask */
    #define OP_FB_arm_push_a1 (0x092d0000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_push_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_push_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_push_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'register_list' */
            #define OP_SF_MASK_arm_push_a1_register_list_0 (0x0000ffffl) /* subfield mask */
            #define OP_SF_EBII_arm_push_a1_register_list_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_push_a1_register_list_0 (0) /* subfield end bit position in field */
        
    

    /* arm_push_a2 */
    #define OP_FB_MASK_arm_push_a2 (0x0fff0fffl) /* fixed bits mask */
    #define OP_FB_arm_push_a2 (0x052d0004l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_push_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_push_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_push_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_push_a2_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_push_a2_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_push_a2_Rt_0 (0) /* subfield end bit position in field */
        
    

    /* arm_ldr_imm_a1 */
    #define OP_FB_MASK_arm_ldr_imm_a1 (0x0e500000l) /* fixed bits mask */
    #define OP_FB_arm_ldr_imm_a1 (0x04100000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_ldr_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_ldr_imm_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_imm_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_imm_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_ldr_imm_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_imm_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_imm_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_ldr_imm_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_imm_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_imm_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_ldr_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_ldr_imm_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_imm_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_imm_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_ldr_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_ldrb_reg_a1 */
    #define OP_FB_MASK_arm_ldrb_reg_a1 (0x0e500010l) /* fixed bits mask */
    #define OP_FB_arm_ldrb_reg_a1 (0x06500000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_ldrb_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_ldrb_reg_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_reg_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_reg_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_ldrb_reg_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_reg_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_reg_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_ldrb_reg_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_reg_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_reg_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_ldrb_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_ldrb_reg_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_reg_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_reg_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_ldrb_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_ldrb_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_ldrb_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_pop_a1 */
    #define OP_FB_MASK_arm_pop_a1 (0x0fff0000l) /* fixed bits mask */
    #define OP_FB_arm_pop_a1 (0x08bd0000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_pop_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_pop_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_pop_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'register_list' */
            #define OP_SF_MASK_arm_pop_a1_register_list_0 (0x0000ffffl) /* subfield mask */
            #define OP_SF_EBII_arm_pop_a1_register_list_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_pop_a1_register_list_0 (0) /* subfield end bit position in field */
        
    

    /* arm_pop_a2 */
    #define OP_FB_MASK_arm_pop_a2 (0x0fff0fffl) /* fixed bits mask */
    #define OP_FB_arm_pop_a2 (0x049d0004l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_pop_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_pop_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_pop_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_pop_a2_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_pop_a2_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_pop_a2_Rt_0 (0) /* subfield end bit position in field */
        
    


/* individual op parse functions */

static int op_parse_arm_add_imm_a1(OpDecodeContext *context);

static int op_parse_arm_add_spimm_a1(OpDecodeContext *context);

static int op_parse_arm_adr_a1(OpDecodeContext *context);

static int op_parse_arm_subs_pclr_a1(OpDecodeContext *context);

static int op_parse_arm_mov_imm_a1(OpDecodeContext *context);

static int op_parse_arm_mov_imm_a2(OpDecodeContext *context);

static int op_parse_arm_mov_reg_a1(OpDecodeContext *context);

static int op_parse_arm_bl_a1(OpDecodeContext *context);

static int op_parse_arm_blx_a2(OpDecodeContext *context);

static int op_parse_arm_b_a1(OpDecodeContext *context);

static int op_parse_arm_bx_a1(OpDecodeContext *context);

static int op_parse_arm_str_imm_a1(OpDecodeContext *context);

static int op_parse_arm_strb_reg_a1(OpDecodeContext *context);

static int op_parse_arm_push_a1(OpDecodeContext *context);

static int op_parse_arm_push_a2(OpDecodeContext *context);

static int op_parse_arm_ldr_imm_a1(OpDecodeContext *context);

static int op_parse_arm_ldrb_reg_a1(OpDecodeContext *context);

static int op_parse_arm_pop_a1(OpDecodeContext *context);

static int op_parse_arm_pop_a2(OpDecodeContext *context);



    /* arm_add_imm_a1 */
    static int op_parse_arm_add_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_add_imm_a1) != OP_FB_arm_add_imm_a1) {
            return 1;
        }
    
        if (op_parse_arm_adr_a1(context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_subs_pclr_a1(context) == 0) {
            return 0;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_add_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_add_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_add_imm_a1;
        
            context->decoded_code->code.arm_add_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_add_imm_a1_cond_0) >> OP_SF_EBII_arm_add_imm_a1_cond_0) << OP_SF_EBIF_arm_add_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_add_imm_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_add_imm_a1_S_0) >> OP_SF_EBII_arm_add_imm_a1_S_0) << OP_SF_EBIF_arm_add_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_add_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_add_imm_a1_Rn_0) >> OP_SF_EBII_arm_add_imm_a1_Rn_0) << OP_SF_EBIF_arm_add_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_add_imm_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_add_imm_a1_Rd_0) >> OP_SF_EBII_arm_add_imm_a1_Rd_0) << OP_SF_EBIF_arm_add_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_add_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_add_imm_a1_imm12_0) >> OP_SF_EBII_arm_add_imm_a1_imm12_0) << OP_SF_EBIF_arm_add_imm_a1_imm12_0);
            
        

        
            if (!(
                context->decoded_code->code.arm_add_imm_a1.Rn != 13
                
            )) {
                return 1;
            }
        
        return 0;
    }

    /* arm_add_spimm_a1 */
    static int op_parse_arm_add_spimm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_add_spimm_a1) != OP_FB_arm_add_spimm_a1) {
            return 1;
        }
    
        if (op_parse_arm_subs_pclr_a1(context) == 0) {
            return 0;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_add_spimm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_add_spimm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_add_spimm_a1;
        
            context->decoded_code->code.arm_add_spimm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_add_spimm_a1_cond_0) >> OP_SF_EBII_arm_add_spimm_a1_cond_0) << OP_SF_EBIF_arm_add_spimm_a1_cond_0);
            
        
            context->decoded_code->code.arm_add_spimm_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_add_spimm_a1_S_0) >> OP_SF_EBII_arm_add_spimm_a1_S_0) << OP_SF_EBIF_arm_add_spimm_a1_S_0);
            
        
            context->decoded_code->code.arm_add_spimm_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_add_spimm_a1_Rd_0) >> OP_SF_EBII_arm_add_spimm_a1_Rd_0) << OP_SF_EBIF_arm_add_spimm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_add_spimm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_add_spimm_a1_imm12_0) >> OP_SF_EBII_arm_add_spimm_a1_imm12_0) << OP_SF_EBIF_arm_add_spimm_a1_imm12_0);
            
        

        
        return 0;
    }

    /* arm_adr_a1 */
    static int op_parse_arm_adr_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_adr_a1) != OP_FB_arm_adr_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_adr_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_adr_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_adr_a1;
        
            context->decoded_code->code.arm_adr_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_adr_a1_cond_0) >> OP_SF_EBII_arm_adr_a1_cond_0) << OP_SF_EBIF_arm_adr_a1_cond_0);
            
        
            context->decoded_code->code.arm_adr_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_adr_a1_Rd_0) >> OP_SF_EBII_arm_adr_a1_Rd_0) << OP_SF_EBIF_arm_adr_a1_Rd_0);
            
        
            context->decoded_code->code.arm_adr_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_adr_a1_imm12_0) >> OP_SF_EBII_arm_adr_a1_imm12_0) << OP_SF_EBIF_arm_adr_a1_imm12_0);
            
        

        
        return 0;
    }

    /* arm_subs_pclr_a1 */
    static int op_parse_arm_subs_pclr_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_subs_pclr_a1) != OP_FB_arm_subs_pclr_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_subs_pclr_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_subs_pclr_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_subs_pclr_a1;
        
            context->decoded_code->code.arm_subs_pclr_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_subs_pclr_a1_cond_0) >> OP_SF_EBII_arm_subs_pclr_a1_cond_0) << OP_SF_EBIF_arm_subs_pclr_a1_cond_0);
            
        
            context->decoded_code->code.arm_subs_pclr_a1.opcode =
            
                (((context->code32 & OP_SF_MASK_arm_subs_pclr_a1_opcode_0) >> OP_SF_EBII_arm_subs_pclr_a1_opcode_0) << OP_SF_EBIF_arm_subs_pclr_a1_opcode_0);
            
        
            context->decoded_code->code.arm_subs_pclr_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_subs_pclr_a1_Rn_0) >> OP_SF_EBII_arm_subs_pclr_a1_Rn_0) << OP_SF_EBIF_arm_subs_pclr_a1_Rn_0);
            
        
            context->decoded_code->code.arm_subs_pclr_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_subs_pclr_a1_imm12_0) >> OP_SF_EBII_arm_subs_pclr_a1_imm12_0) << OP_SF_EBIF_arm_subs_pclr_a1_imm12_0);
            
        

        
        return 0;
    }

    /* arm_mov_imm_a1 */
    static int op_parse_arm_mov_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mov_imm_a1) != OP_FB_arm_mov_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_mov_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mov_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mov_imm_a1;
        
            context->decoded_code->code.arm_mov_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_mov_imm_a1_cond_0) >> OP_SF_EBII_arm_mov_imm_a1_cond_0) << OP_SF_EBIF_arm_mov_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_mov_imm_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_mov_imm_a1_S_0) >> OP_SF_EBII_arm_mov_imm_a1_S_0) << OP_SF_EBIF_arm_mov_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_mov_imm_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_mov_imm_a1_Rd_0) >> OP_SF_EBII_arm_mov_imm_a1_Rd_0) << OP_SF_EBIF_arm_mov_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_mov_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_mov_imm_a1_imm12_0) >> OP_SF_EBII_arm_mov_imm_a1_imm12_0) << OP_SF_EBIF_arm_mov_imm_a1_imm12_0);
            
        

        
        return 0;
    }

    /* arm_mov_imm_a2 */
    static int op_parse_arm_mov_imm_a2(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mov_imm_a2) != OP_FB_arm_mov_imm_a2) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_mov_imm_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mov_imm_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mov_imm_a2;
        
            context->decoded_code->code.arm_mov_imm_a2.cond =
            
                (((context->code32 & OP_SF_MASK_arm_mov_imm_a2_cond_0) >> OP_SF_EBII_arm_mov_imm_a2_cond_0) << OP_SF_EBIF_arm_mov_imm_a2_cond_0);
            
        
            context->decoded_code->code.arm_mov_imm_a2.imm4 =
            
                (((context->code32 & OP_SF_MASK_arm_mov_imm_a2_imm4_0) >> OP_SF_EBII_arm_mov_imm_a2_imm4_0) << OP_SF_EBIF_arm_mov_imm_a2_imm4_0);
            
        
            context->decoded_code->code.arm_mov_imm_a2.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_mov_imm_a2_Rd_0) >> OP_SF_EBII_arm_mov_imm_a2_Rd_0) << OP_SF_EBIF_arm_mov_imm_a2_Rd_0);
            
        
            context->decoded_code->code.arm_mov_imm_a2.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_mov_imm_a2_imm12_0) >> OP_SF_EBII_arm_mov_imm_a2_imm12_0) << OP_SF_EBIF_arm_mov_imm_a2_imm12_0);
            
        

        
        return 0;
    }

    /* arm_mov_reg_a1 */
    static int op_parse_arm_mov_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mov_reg_a1) != OP_FB_arm_mov_reg_a1) {
            return 1;
        }
    
        if (op_parse_arm_subs_pclr_a1(context) == 0) {
            return 0;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_mov_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mov_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mov_reg_a1;
        
            context->decoded_code->code.arm_mov_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_mov_reg_a1_cond_0) >> OP_SF_EBII_arm_mov_reg_a1_cond_0) << OP_SF_EBIF_arm_mov_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_mov_reg_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_mov_reg_a1_S_0) >> OP_SF_EBII_arm_mov_reg_a1_S_0) << OP_SF_EBIF_arm_mov_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_mov_reg_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_mov_reg_a1_Rd_0) >> OP_SF_EBII_arm_mov_reg_a1_Rd_0) << OP_SF_EBIF_arm_mov_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_mov_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_mov_reg_a1_Rm_0) >> OP_SF_EBII_arm_mov_reg_a1_Rm_0) << OP_SF_EBIF_arm_mov_reg_a1_Rm_0);
            
        

        
        return 0;
    }

    /* arm_bl_a1 */
    static int op_parse_arm_bl_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_bl_a1) != OP_FB_arm_bl_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_bl_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_bl_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_bl_a1;
        
            context->decoded_code->code.arm_bl_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_bl_a1_cond_0) >> OP_SF_EBII_arm_bl_a1_cond_0) << OP_SF_EBIF_arm_bl_a1_cond_0);
            
        
            context->decoded_code->code.arm_bl_a1.imm24 =
            
                (((context->code32 & OP_SF_MASK_arm_bl_a1_imm24_0) >> OP_SF_EBII_arm_bl_a1_imm24_0) << OP_SF_EBIF_arm_bl_a1_imm24_0);
            
        

        
            if (!(
                context->decoded_code->code.arm_bl_a1.cond != 15
                
            )) {
                return 1;
            }
        
        return 0;
    }

    /* arm_blx_a2 */
    static int op_parse_arm_blx_a2(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_blx_a2) != OP_FB_arm_blx_a2) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_blx_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_blx_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_blx_a2;
        
            context->decoded_code->code.arm_blx_a2.H =
            
                (((context->code32 & OP_SF_MASK_arm_blx_a2_H_0) >> OP_SF_EBII_arm_blx_a2_H_0) << OP_SF_EBIF_arm_blx_a2_H_0);
            
        
            context->decoded_code->code.arm_blx_a2.imm24 =
            
                (((context->code32 & OP_SF_MASK_arm_blx_a2_imm24_0) >> OP_SF_EBII_arm_blx_a2_imm24_0) << OP_SF_EBIF_arm_blx_a2_imm24_0);
            
        

        
        return 0;
    }

    /* arm_b_a1 */
    static int op_parse_arm_b_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_b_a1) != OP_FB_arm_b_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_b_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_b_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_b_a1;
        
            context->decoded_code->code.arm_b_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_b_a1_cond_0) >> OP_SF_EBII_arm_b_a1_cond_0) << OP_SF_EBIF_arm_b_a1_cond_0);
            
        
            context->decoded_code->code.arm_b_a1.imm24 =
            
                (((context->code32 & OP_SF_MASK_arm_b_a1_imm24_0) >> OP_SF_EBII_arm_b_a1_imm24_0) << OP_SF_EBIF_arm_b_a1_imm24_0);
            
        

        
            if (!(
                context->decoded_code->code.arm_b_a1.cond != 15
                
            )) {
                return 1;
            }
        
        return 0;
    }

    /* arm_bx_a1 */
    static int op_parse_arm_bx_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_bx_a1) != OP_FB_arm_bx_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_bx_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_bx_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_bx_a1;
        
            context->decoded_code->code.arm_bx_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_bx_a1_cond_0) >> OP_SF_EBII_arm_bx_a1_cond_0) << OP_SF_EBIF_arm_bx_a1_cond_0);
            
        
            context->decoded_code->code.arm_bx_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_bx_a1_Rm_0) >> OP_SF_EBII_arm_bx_a1_Rm_0) << OP_SF_EBIF_arm_bx_a1_Rm_0);
            
        

        
            if (!(
                context->decoded_code->code.arm_bx_a1.cond != 15
                
            )) {
                return 1;
            }
        
        return 0;
    }

    /* arm_str_imm_a1 */
    static int op_parse_arm_str_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_str_imm_a1) != OP_FB_arm_str_imm_a1) {
            return 1;
        }
    
        if (op_parse_arm_push_a2(context) == 0) {
            return 0;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_str_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_str_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_str_imm_a1;
        
            context->decoded_code->code.arm_str_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_str_imm_a1_cond_0) >> OP_SF_EBII_arm_str_imm_a1_cond_0) << OP_SF_EBIF_arm_str_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_str_imm_a1_P_0) >> OP_SF_EBII_arm_str_imm_a1_P_0) << OP_SF_EBIF_arm_str_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_str_imm_a1_U_0) >> OP_SF_EBII_arm_str_imm_a1_U_0) << OP_SF_EBIF_arm_str_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_str_imm_a1_W_0) >> OP_SF_EBII_arm_str_imm_a1_W_0) << OP_SF_EBIF_arm_str_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_str_imm_a1_Rn_0) >> OP_SF_EBII_arm_str_imm_a1_Rn_0) << OP_SF_EBIF_arm_str_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_str_imm_a1_Rt_0) >> OP_SF_EBII_arm_str_imm_a1_Rt_0) << OP_SF_EBIF_arm_str_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_str_imm_a1_imm12_0) >> OP_SF_EBII_arm_str_imm_a1_imm12_0) << OP_SF_EBIF_arm_str_imm_a1_imm12_0);
            
        

        
        return 0;
    }

    /* arm_strb_reg_a1 */
    static int op_parse_arm_strb_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_strb_reg_a1) != OP_FB_arm_strb_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_strb_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_strb_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_strb_reg_a1;
        
            context->decoded_code->code.arm_strb_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_strb_reg_a1_cond_0) >> OP_SF_EBII_arm_strb_reg_a1_cond_0) << OP_SF_EBIF_arm_strb_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_strb_reg_a1_P_0) >> OP_SF_EBII_arm_strb_reg_a1_P_0) << OP_SF_EBIF_arm_strb_reg_a1_P_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_strb_reg_a1_U_0) >> OP_SF_EBII_arm_strb_reg_a1_U_0) << OP_SF_EBIF_arm_strb_reg_a1_U_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_strb_reg_a1_W_0) >> OP_SF_EBII_arm_strb_reg_a1_W_0) << OP_SF_EBIF_arm_strb_reg_a1_W_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_strb_reg_a1_Rn_0) >> OP_SF_EBII_arm_strb_reg_a1_Rn_0) << OP_SF_EBIF_arm_strb_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_strb_reg_a1_Rt_0) >> OP_SF_EBII_arm_strb_reg_a1_Rt_0) << OP_SF_EBIF_arm_strb_reg_a1_Rt_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_strb_reg_a1_imm5_0) >> OP_SF_EBII_arm_strb_reg_a1_imm5_0) << OP_SF_EBIF_arm_strb_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.type =
            
                (((context->code32 & OP_SF_MASK_arm_strb_reg_a1_type_0) >> OP_SF_EBII_arm_strb_reg_a1_type_0) << OP_SF_EBIF_arm_strb_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_strb_reg_a1_Rm_0) >> OP_SF_EBII_arm_strb_reg_a1_Rm_0) << OP_SF_EBIF_arm_strb_reg_a1_Rm_0);
            
        

        
        return 0;
    }

    /* arm_push_a1 */
    static int op_parse_arm_push_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_push_a1) != OP_FB_arm_push_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_push_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_push_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_push_a1;
        
            context->decoded_code->code.arm_push_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_push_a1_cond_0) >> OP_SF_EBII_arm_push_a1_cond_0) << OP_SF_EBIF_arm_push_a1_cond_0);
            
        
            context->decoded_code->code.arm_push_a1.register_list =
            
                (((context->code32 & OP_SF_MASK_arm_push_a1_register_list_0) >> OP_SF_EBII_arm_push_a1_register_list_0) << OP_SF_EBIF_arm_push_a1_register_list_0);
            
        

        
            if (!(
                context->decoded_code->code.arm_push_a1.cond != 15
                
            )) {
                return 1;
            }
        
        return 0;
    }

    /* arm_push_a2 */
    static int op_parse_arm_push_a2(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_push_a2) != OP_FB_arm_push_a2) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_push_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_push_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_push_a2;
        
            context->decoded_code->code.arm_push_a2.cond =
            
                (((context->code32 & OP_SF_MASK_arm_push_a2_cond_0) >> OP_SF_EBII_arm_push_a2_cond_0) << OP_SF_EBIF_arm_push_a2_cond_0);
            
        
            context->decoded_code->code.arm_push_a2.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_push_a2_Rt_0) >> OP_SF_EBII_arm_push_a2_Rt_0) << OP_SF_EBIF_arm_push_a2_Rt_0);
            
        

        
            if (!(
                context->decoded_code->code.arm_push_a2.cond != 15
                
            )) {
                return 1;
            }
        
        return 0;
    }

    /* arm_ldr_imm_a1 */
    static int op_parse_arm_ldr_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_ldr_imm_a1) != OP_FB_arm_ldr_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_ldr_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldr_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldr_imm_a1;
        
            context->decoded_code->code.arm_ldr_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_imm_a1_cond_0) >> OP_SF_EBII_arm_ldr_imm_a1_cond_0) << OP_SF_EBIF_arm_ldr_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_imm_a1_P_0) >> OP_SF_EBII_arm_ldr_imm_a1_P_0) << OP_SF_EBIF_arm_ldr_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_imm_a1_U_0) >> OP_SF_EBII_arm_ldr_imm_a1_U_0) << OP_SF_EBIF_arm_ldr_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_imm_a1_W_0) >> OP_SF_EBII_arm_ldr_imm_a1_W_0) << OP_SF_EBIF_arm_ldr_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_imm_a1_Rn_0) >> OP_SF_EBII_arm_ldr_imm_a1_Rn_0) << OP_SF_EBIF_arm_ldr_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_imm_a1_Rt_0) >> OP_SF_EBII_arm_ldr_imm_a1_Rt_0) << OP_SF_EBIF_arm_ldr_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_imm_a1_imm12_0) >> OP_SF_EBII_arm_ldr_imm_a1_imm12_0) << OP_SF_EBIF_arm_ldr_imm_a1_imm12_0);
            
        

        
        return 0;
    }

    /* arm_ldrb_reg_a1 */
    static int op_parse_arm_ldrb_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_ldrb_reg_a1) != OP_FB_arm_ldrb_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_ldrb_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldrb_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldrb_reg_a1;
        
            context->decoded_code->code.arm_ldrb_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_reg_a1_cond_0) >> OP_SF_EBII_arm_ldrb_reg_a1_cond_0) << OP_SF_EBIF_arm_ldrb_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_reg_a1_P_0) >> OP_SF_EBII_arm_ldrb_reg_a1_P_0) << OP_SF_EBIF_arm_ldrb_reg_a1_P_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_reg_a1_U_0) >> OP_SF_EBII_arm_ldrb_reg_a1_U_0) << OP_SF_EBIF_arm_ldrb_reg_a1_U_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_reg_a1_W_0) >> OP_SF_EBII_arm_ldrb_reg_a1_W_0) << OP_SF_EBIF_arm_ldrb_reg_a1_W_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_reg_a1_Rn_0) >> OP_SF_EBII_arm_ldrb_reg_a1_Rn_0) << OP_SF_EBIF_arm_ldrb_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_reg_a1_Rt_0) >> OP_SF_EBII_arm_ldrb_reg_a1_Rt_0) << OP_SF_EBIF_arm_ldrb_reg_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_reg_a1_imm5_0) >> OP_SF_EBII_arm_ldrb_reg_a1_imm5_0) << OP_SF_EBIF_arm_ldrb_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.type =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_reg_a1_type_0) >> OP_SF_EBII_arm_ldrb_reg_a1_type_0) << OP_SF_EBIF_arm_ldrb_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_reg_a1_Rm_0) >> OP_SF_EBII_arm_ldrb_reg_a1_Rm_0) << OP_SF_EBIF_arm_ldrb_reg_a1_Rm_0);
            
        

        
        return 0;
    }

    /* arm_pop_a1 */
    static int op_parse_arm_pop_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_pop_a1) != OP_FB_arm_pop_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_pop_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_pop_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_pop_a1;
        
            context->decoded_code->code.arm_pop_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_pop_a1_cond_0) >> OP_SF_EBII_arm_pop_a1_cond_0) << OP_SF_EBIF_arm_pop_a1_cond_0);
            
        
            context->decoded_code->code.arm_pop_a1.register_list =
            
                (((context->code32 & OP_SF_MASK_arm_pop_a1_register_list_0) >> OP_SF_EBII_arm_pop_a1_register_list_0) << OP_SF_EBIF_arm_pop_a1_register_list_0);
            
        

        
            if (!(
                context->decoded_code->code.arm_pop_a1.cond != 15
                
            )) {
                return 1;
            }
        
        return 0;
    }

    /* arm_pop_a2 */
    static int op_parse_arm_pop_a2(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_pop_a2) != OP_FB_arm_pop_a2) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_pop_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_pop_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_pop_a2;
        
            context->decoded_code->code.arm_pop_a2.cond =
            
                (((context->code32 & OP_SF_MASK_arm_pop_a2_cond_0) >> OP_SF_EBII_arm_pop_a2_cond_0) << OP_SF_EBIF_arm_pop_a2_cond_0);
            
        
            context->decoded_code->code.arm_pop_a2.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_pop_a2_Rt_0) >> OP_SF_EBII_arm_pop_a2_Rt_0) << OP_SF_EBIF_arm_pop_a2_Rt_0);
            
        

        
            if (!(
                context->decoded_code->code.arm_pop_a2.cond != 15
                
            )) {
                return 1;
            }
        
        return 0;
    }


/* op parse function */
int arm_op_parse(arm_uint16 code[arm_OP_DECODE_MAX], arm_OpDecodedCodeType *decoded_code, arm_OperationCodeType *optype) {
    OpDecodeContext context;
    context.code = &code[0];
    context.decoded_code = decoded_code;
    context.optype = optype;
    context.code16 = (arm_uint16) code[0];
    context.code32 = *((arm_uint32 *) &code[0]);

    
        if (op_parse_arm_add_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_add_spimm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_adr_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_subs_pclr_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mov_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mov_imm_a2(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mov_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_bl_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_blx_a2(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_b_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_bx_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_str_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_strb_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_push_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_push_a2(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_ldr_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_ldrb_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_pop_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_pop_a2(&context) == 0) {
            return 0;
        }
    

    return 1;
}

arm_OpExecType arm_op_exec_table[arm_OpCodeId_Num] = {
    
	{ 1, arm_op_exec_arm_add_imm_a1 },		/* arm_add_imm_a1 */
    
	{ 1, arm_op_exec_arm_add_spimm_a1 },		/* arm_add_spimm_a1 */
    
	{ 1, arm_op_exec_arm_adr_a1 },		/* arm_adr_a1 */
    
	{ 1, arm_op_exec_arm_subs_pclr_a1 },		/* arm_subs_pclr_a1 */
    
	{ 1, arm_op_exec_arm_mov_imm_a1 },		/* arm_mov_imm_a1 */
    
	{ 1, arm_op_exec_arm_mov_imm_a2 },		/* arm_mov_imm_a2 */
    
	{ 1, arm_op_exec_arm_mov_reg_a1 },		/* arm_mov_reg_a1 */
    
	{ 1, arm_op_exec_arm_bl_a1 },		/* arm_bl_a1 */
    
	{ 1, arm_op_exec_arm_blx_a2 },		/* arm_blx_a2 */
    
	{ 1, arm_op_exec_arm_b_a1 },		/* arm_b_a1 */
    
	{ 1, arm_op_exec_arm_bx_a1 },		/* arm_bx_a1 */
    
	{ 1, arm_op_exec_arm_str_imm_a1 },		/* arm_str_imm_a1 */
    
	{ 1, arm_op_exec_arm_strb_reg_a1 },		/* arm_strb_reg_a1 */
    
	{ 1, arm_op_exec_arm_push_a1 },		/* arm_push_a1 */
    
	{ 1, arm_op_exec_arm_push_a2 },		/* arm_push_a2 */
    
	{ 1, arm_op_exec_arm_ldr_imm_a1 },		/* arm_ldr_imm_a1 */
    
	{ 1, arm_op_exec_arm_ldrb_reg_a1 },		/* arm_ldrb_reg_a1 */
    
	{ 1, arm_op_exec_arm_pop_a1 },		/* arm_pop_a1 */
    
	{ 1, arm_op_exec_arm_pop_a2 },		/* arm_pop_a2 */
    
};