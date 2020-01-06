
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
        
    

    /* arm_add_reg_a1 */
    #define OP_FB_MASK_arm_add_reg_a1 (0x0fe00010l) /* fixed bits mask */
    #define OP_FB_arm_add_reg_a1 (0x00800000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_add_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_add_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_add_reg_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_add_reg_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_reg_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_add_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_add_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_add_reg_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_add_reg_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_reg_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_add_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_add_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_add_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_add_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_add_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_add_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_add_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_cmp_imm_a1 */
    #define OP_FB_MASK_arm_cmp_imm_a1 (0x0ff0f000l) /* fixed bits mask */
    #define OP_FB_arm_cmp_imm_a1 (0x03500000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_cmp_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_cmp_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_cmp_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_cmp_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_cmp_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_cmp_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_cmp_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_cmp_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_cmp_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_cmn_imm_a1 */
    #define OP_FB_MASK_arm_cmn_imm_a1 (0x0ff0f000l) /* fixed bits mask */
    #define OP_FB_arm_cmn_imm_a1 (0x03700000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_cmn_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_cmn_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_cmn_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_cmn_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_cmn_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_cmn_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_cmn_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_cmn_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_cmn_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_sub_imm_a1 */
    #define OP_FB_MASK_arm_sub_imm_a1 (0x0fe00000l) /* fixed bits mask */
    #define OP_FB_arm_sub_imm_a1 (0x02400000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_sub_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_sub_imm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_imm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_imm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_sub_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_sub_imm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_imm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_imm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_sub_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_sub_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_sub_reg_a1 */
    #define OP_FB_MASK_arm_sub_reg_a1 (0x0fe00010l) /* fixed bits mask */
    #define OP_FB_arm_sub_reg_a1 (0x00400000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_sub_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_sub_reg_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_reg_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_reg_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_sub_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_sub_reg_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_reg_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_reg_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_sub_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_sub_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_sub_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_sub_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_sub_spimm_a1 */
    #define OP_FB_MASK_arm_sub_spimm_a1 (0x0fef0000l) /* fixed bits mask */
    #define OP_FB_arm_sub_spimm_a1 (0x024d0000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_sub_spimm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_spimm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_spimm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_sub_spimm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_spimm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_spimm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_sub_spimm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_sub_spimm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_spimm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_sub_spimm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_sub_spimm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sub_spimm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_cmp_reg_a1 */
    #define OP_FB_MASK_arm_cmp_reg_a1 (0x0ff0f010l) /* fixed bits mask */
    #define OP_FB_arm_cmp_reg_a1 (0x01500000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_cmp_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_cmp_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_cmp_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_cmp_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_cmp_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_cmp_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_cmp_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_cmp_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_cmp_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_cmp_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_cmp_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_cmp_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_cmp_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_cmp_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_cmp_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_mvn_imm_a1 */
    #define OP_FB_MASK_arm_mvn_imm_a1 (0x0fef0000l) /* fixed bits mask */
    #define OP_FB_arm_mvn_imm_a1 (0x03e00000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_mvn_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_mvn_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mvn_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_mvn_imm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_mvn_imm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mvn_imm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_mvn_imm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_mvn_imm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mvn_imm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_mvn_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_mvn_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mvn_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_mvn_reg_a1 */
    #define OP_FB_MASK_arm_mvn_reg_a1 (0x0fef0010l) /* fixed bits mask */
    #define OP_FB_arm_mvn_reg_a1 (0x01e00000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_mvn_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_mvn_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mvn_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_mvn_reg_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_mvn_reg_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mvn_reg_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_mvn_reg_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_mvn_reg_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mvn_reg_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_mvn_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_mvn_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mvn_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_mvn_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_mvn_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mvn_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_mvn_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_mvn_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mvn_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_blx_reg_a1 */
    #define OP_FB_MASK_arm_blx_reg_a1 (0x0ffffff0l) /* fixed bits mask */
    #define OP_FB_arm_blx_reg_a1 (0x012fff30l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_blx_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_blx_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_blx_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_blx_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_blx_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_blx_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_strb_imm_a1 */
    #define OP_FB_MASK_arm_strb_imm_a1 (0x0e500000l) /* fixed bits mask */
    #define OP_FB_arm_strb_imm_a1 (0x04400000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_strb_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_strb_imm_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_imm_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_imm_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_strb_imm_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_imm_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_imm_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_strb_imm_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_imm_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_imm_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_strb_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_strb_imm_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_strb_imm_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_imm_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_strb_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_strb_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strb_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_strh_imm_a1 */
    #define OP_FB_MASK_arm_strh_imm_a1 (0x0e5000f0l) /* fixed bits mask */
    #define OP_FB_arm_strh_imm_a1 (0x004000b0l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_strh_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_strh_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strh_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_strh_imm_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_strh_imm_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strh_imm_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_strh_imm_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_strh_imm_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strh_imm_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_strh_imm_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_strh_imm_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strh_imm_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_strh_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_strh_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strh_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_strh_imm_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_strh_imm_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strh_imm_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_strh_imm_a1_imm8_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_strh_imm_a1_imm8_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strh_imm_a1_imm8_0 (4) /* subfield end bit position in field */
        
            /* 1th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_strh_imm_a1_imm8_1 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_strh_imm_a1_imm8_1 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strh_imm_a1_imm8_1 (0) /* subfield end bit position in field */
        
    

    /* arm_strd_imm_a1 */
    #define OP_FB_MASK_arm_strd_imm_a1 (0x0e5000f0l) /* fixed bits mask */
    #define OP_FB_arm_strd_imm_a1 (0x004000f0l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_strd_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_strd_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strd_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_strd_imm_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_strd_imm_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strd_imm_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_strd_imm_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_strd_imm_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strd_imm_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_strd_imm_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_strd_imm_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strd_imm_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_strd_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_strd_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strd_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_strd_imm_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_strd_imm_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strd_imm_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_strd_imm_a1_imm8_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_strd_imm_a1_imm8_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strd_imm_a1_imm8_0 (4) /* subfield end bit position in field */
        
            /* 1th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_strd_imm_a1_imm8_1 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_strd_imm_a1_imm8_1 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_strd_imm_a1_imm8_1 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_ldr_literal_a1 */
    #define OP_FB_MASK_arm_ldr_literal_a1 (0x0e5f0000l) /* fixed bits mask */
    #define OP_FB_arm_ldr_literal_a1 (0x041f0000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_ldr_literal_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_literal_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_literal_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_ldr_literal_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_literal_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_literal_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_ldr_literal_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_literal_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_literal_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_ldr_literal_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_literal_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_literal_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_ldr_literal_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_literal_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_literal_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_ldr_literal_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_literal_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_literal_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_ldrb_imm_a1 */
    #define OP_FB_MASK_arm_ldrb_imm_a1 (0x0e500000l) /* fixed bits mask */
    #define OP_FB_arm_ldrb_imm_a1 (0x04500000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_ldrb_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_ldrb_imm_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_imm_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_imm_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_ldrb_imm_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_imm_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_imm_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_ldrb_imm_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_imm_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_imm_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_ldrb_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_ldrb_imm_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_imm_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_imm_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_ldrb_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_ldrb_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrb_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_ldrh_imm_a1 */
    #define OP_FB_MASK_arm_ldrh_imm_a1 (0x0e5000f0l) /* fixed bits mask */
    #define OP_FB_arm_ldrh_imm_a1 (0x005000b0l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_ldrh_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_ldrh_imm_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_imm_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_imm_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_ldrh_imm_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_imm_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_imm_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_ldrh_imm_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_imm_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_imm_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_ldrh_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_ldrh_imm_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_imm_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_imm_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_ldrh_imm_a1_imm8_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_imm_a1_imm8_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_imm_a1_imm8_0 (4) /* subfield end bit position in field */
        
            /* 1th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_ldrh_imm_a1_imm8_1 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_imm_a1_imm8_1 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_imm_a1_imm8_1 (0) /* subfield end bit position in field */
        
    

    /* arm_ldrd_imm_a1 */
    #define OP_FB_MASK_arm_ldrd_imm_a1 (0x0e5000f0l) /* fixed bits mask */
    #define OP_FB_arm_ldrd_imm_a1 (0x004000d0l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_ldrd_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrd_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrd_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_ldrd_imm_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrd_imm_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrd_imm_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_ldrd_imm_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrd_imm_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrd_imm_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_ldrd_imm_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrd_imm_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrd_imm_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_ldrd_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrd_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrd_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_ldrd_imm_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrd_imm_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrd_imm_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_ldrd_imm_a1_imm8_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrd_imm_a1_imm8_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrd_imm_a1_imm8_0 (4) /* subfield end bit position in field */
        
            /* 1th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_ldrd_imm_a1_imm8_1 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_ldrd_imm_a1_imm8_1 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrd_imm_a1_imm8_1 (0) /* subfield end bit position in field */
        
    

    /* arm_ldr_reg_a1 */
    #define OP_FB_MASK_arm_ldr_reg_a1 (0x0e500010l) /* fixed bits mask */
    #define OP_FB_arm_ldr_reg_a1 (0x06100000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_ldr_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_ldr_reg_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_reg_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_reg_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_ldr_reg_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_reg_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_reg_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_ldr_reg_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_reg_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_reg_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_ldr_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_ldr_reg_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_reg_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_reg_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_ldr_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_ldr_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_ldr_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_ldr_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldr_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_ldrh_reg_a1 */
    #define OP_FB_MASK_arm_ldrh_reg_a1 (0x0e500ff0l) /* fixed bits mask */
    #define OP_FB_arm_ldrh_reg_a1 (0x001000b0l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_ldrh_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_ldrh_reg_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_reg_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_reg_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_ldrh_reg_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_reg_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_reg_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_ldrh_reg_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_reg_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_reg_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_ldrh_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_ldrh_reg_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_reg_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_reg_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_ldrh_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_ldrh_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrh_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_nop_a1 */
    #define OP_FB_MASK_arm_nop_a1 (0x0fffffffl) /* fixed bits mask */
    #define OP_FB_arm_nop_a1 (0x0320f000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_nop_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_nop_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_nop_a1_cond_0 (0) /* subfield end bit position in field */
        
    

    /* arm_msr_imm_a1 */
    #define OP_FB_MASK_arm_msr_imm_a1 (0x0ff3f000l) /* fixed bits mask */
    #define OP_FB_arm_msr_imm_a1 (0x0320f000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_msr_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_msr_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_msr_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'mask' */
            #define OP_SF_MASK_arm_msr_imm_a1_mask_0 (0x000c0000l) /* subfield mask */
            #define OP_SF_EBII_arm_msr_imm_a1_mask_0 (18) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_msr_imm_a1_mask_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_msr_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_msr_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_msr_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_msr2_imm_a1 */
    #define OP_FB_MASK_arm_msr2_imm_a1 (0x0fb0f000l) /* fixed bits mask */
    #define OP_FB_arm_msr2_imm_a1 (0x0320f000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_msr2_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_msr2_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_msr2_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'R' */
            #define OP_SF_MASK_arm_msr2_imm_a1_R_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_msr2_imm_a1_R_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_msr2_imm_a1_R_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'mask' */
            #define OP_SF_MASK_arm_msr2_imm_a1_mask_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_msr2_imm_a1_mask_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_msr2_imm_a1_mask_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_msr2_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_msr2_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_msr2_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_mrs_a1 */
    #define OP_FB_MASK_arm_mrs_a1 (0x0fff0fffl) /* fixed bits mask */
    #define OP_FB_arm_mrs_a1 (0x010f0000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_mrs_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_mrs_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrs_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_mrs_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_mrs_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrs_a1_Rd_0 (0) /* subfield end bit position in field */
        
    

    /* arm_msr2_reg_a1 */
    #define OP_FB_MASK_arm_msr2_reg_a1 (0x0fb0fff0l) /* fixed bits mask */
    #define OP_FB_arm_msr2_reg_a1 (0x0120f000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_msr2_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_msr2_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_msr2_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'R' */
            #define OP_SF_MASK_arm_msr2_reg_a1_R_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_msr2_reg_a1_R_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_msr2_reg_a1_R_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'mask' */
            #define OP_SF_MASK_arm_msr2_reg_a1_mask_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_msr2_reg_a1_mask_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_msr2_reg_a1_mask_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_msr2_reg_a1_Rn_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_msr2_reg_a1_Rn_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_msr2_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    

    /* arm_mcr_a1 */
    #define OP_FB_MASK_arm_mcr_a1 (0x0f100010l) /* fixed bits mask */
    #define OP_FB_arm_mcr_a1 (0x0e000010l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_mcr_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_mcr_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'opc1' */
            #define OP_SF_MASK_arm_mcr_a1_opc1_0 (0x00e00000l) /* subfield mask */
            #define OP_SF_EBII_arm_mcr_a1_opc1_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr_a1_opc1_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'CRn' */
            #define OP_SF_MASK_arm_mcr_a1_CRn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_mcr_a1_CRn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr_a1_CRn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_mcr_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_mcr_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'coproc' */
            #define OP_SF_MASK_arm_mcr_a1_coproc_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_mcr_a1_coproc_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr_a1_coproc_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'opc2' */
            #define OP_SF_MASK_arm_mcr_a1_opc2_0 (0x000000e0l) /* subfield mask */
            #define OP_SF_EBII_arm_mcr_a1_opc2_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr_a1_opc2_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'CRm' */
            #define OP_SF_MASK_arm_mcr_a1_CRm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_mcr_a1_CRm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr_a1_CRm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_mcr2_a2 */
    #define OP_FB_MASK_arm_mcr2_a2 (0xff100010l) /* fixed bits mask */
    #define OP_FB_arm_mcr2_a2 (0xfe000010l) /* fixed bits */
    
        
            /* 0th subfield of the field 'opc1' */
            #define OP_SF_MASK_arm_mcr2_a2_opc1_0 (0x00e00000l) /* subfield mask */
            #define OP_SF_EBII_arm_mcr2_a2_opc1_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr2_a2_opc1_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'CRn' */
            #define OP_SF_MASK_arm_mcr2_a2_CRn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_mcr2_a2_CRn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr2_a2_CRn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_mcr2_a2_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_mcr2_a2_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr2_a2_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'coproc' */
            #define OP_SF_MASK_arm_mcr2_a2_coproc_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_mcr2_a2_coproc_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr2_a2_coproc_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'opc2' */
            #define OP_SF_MASK_arm_mcr2_a2_opc2_0 (0x000000e0l) /* subfield mask */
            #define OP_SF_EBII_arm_mcr2_a2_opc2_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr2_a2_opc2_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'CRm' */
            #define OP_SF_MASK_arm_mcr2_a2_CRm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_mcr2_a2_CRm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mcr2_a2_CRm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_mrc_a1 */
    #define OP_FB_MASK_arm_mrc_a1 (0x0f100010l) /* fixed bits mask */
    #define OP_FB_arm_mrc_a1 (0x0e100010l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_mrc_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_mrc_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'opc1' */
            #define OP_SF_MASK_arm_mrc_a1_opc1_0 (0x00e00000l) /* subfield mask */
            #define OP_SF_EBII_arm_mrc_a1_opc1_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc_a1_opc1_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'CRn' */
            #define OP_SF_MASK_arm_mrc_a1_CRn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_mrc_a1_CRn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc_a1_CRn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_mrc_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_mrc_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'coproc' */
            #define OP_SF_MASK_arm_mrc_a1_coproc_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_mrc_a1_coproc_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc_a1_coproc_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'opc2' */
            #define OP_SF_MASK_arm_mrc_a1_opc2_0 (0x000000e0l) /* subfield mask */
            #define OP_SF_EBII_arm_mrc_a1_opc2_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc_a1_opc2_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'CRm' */
            #define OP_SF_MASK_arm_mrc_a1_CRm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_mrc_a1_CRm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc_a1_CRm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_mrc2_a2 */
    #define OP_FB_MASK_arm_mrc2_a2 (0xff100010l) /* fixed bits mask */
    #define OP_FB_arm_mrc2_a2 (0xfe100010l) /* fixed bits */
    
        
            /* 0th subfield of the field 'opc1' */
            #define OP_SF_MASK_arm_mrc2_a2_opc1_0 (0x00e00000l) /* subfield mask */
            #define OP_SF_EBII_arm_mrc2_a2_opc1_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc2_a2_opc1_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'CRn' */
            #define OP_SF_MASK_arm_mrc2_a2_CRn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_mrc2_a2_CRn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc2_a2_CRn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_mrc2_a2_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_mrc2_a2_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc2_a2_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'coproc' */
            #define OP_SF_MASK_arm_mrc2_a2_coproc_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_mrc2_a2_coproc_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc2_a2_coproc_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'opc2' */
            #define OP_SF_MASK_arm_mrc2_a2_opc2_0 (0x000000e0l) /* subfield mask */
            #define OP_SF_EBII_arm_mrc2_a2_opc2_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc2_a2_opc2_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'CRm' */
            #define OP_SF_MASK_arm_mrc2_a2_CRm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_mrc2_a2_CRm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mrc2_a2_CRm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_bic_imm_a1 */
    #define OP_FB_MASK_arm_bic_imm_a1 (0x0fe00000l) /* fixed bits mask */
    #define OP_FB_arm_bic_imm_a1 (0x03c00000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_bic_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_bic_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bic_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_bic_imm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_bic_imm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bic_imm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_bic_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_bic_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bic_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_bic_imm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_bic_imm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bic_imm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_bic_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_bic_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bic_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_orr_imm_a1 */
    #define OP_FB_MASK_arm_orr_imm_a1 (0x0fe00000l) /* fixed bits mask */
    #define OP_FB_arm_orr_imm_a1 (0x03800000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_orr_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_orr_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_orr_imm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_orr_imm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_imm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_orr_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_orr_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_orr_imm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_orr_imm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_imm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_orr_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_orr_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_orr_reg_a1 */
    #define OP_FB_MASK_arm_orr_reg_a1 (0x0fe00010l) /* fixed bits mask */
    #define OP_FB_arm_orr_reg_a1 (0x01800000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_orr_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_orr_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_orr_reg_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_orr_reg_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_reg_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_orr_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_orr_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_orr_reg_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_orr_reg_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_reg_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_orr_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_orr_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_orr_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_orr_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_orr_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_orr_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_orr_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_movt_a1 */
    #define OP_FB_MASK_arm_movt_a1 (0x0ff00000l) /* fixed bits mask */
    #define OP_FB_arm_movt_a1 (0x03400000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_movt_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_movt_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_movt_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm16' */
            #define OP_SF_MASK_arm_movt_a1_imm16_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_movt_a1_imm16_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_movt_a1_imm16_0 (12) /* subfield end bit position in field */
        
            /* 1th subfield of the field 'imm16' */
            #define OP_SF_MASK_arm_movt_a1_imm16_1 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_movt_a1_imm16_1 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_movt_a1_imm16_1 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_movt_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_movt_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_movt_a1_Rd_0 (0) /* subfield end bit position in field */
        
    

    /* arm_lsl_imm_a1 */
    #define OP_FB_MASK_arm_lsl_imm_a1 (0x0fef0070l) /* fixed bits mask */
    #define OP_FB_arm_lsl_imm_a1 (0x01a00000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_lsl_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsl_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsl_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_lsl_imm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsl_imm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsl_imm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_lsl_imm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsl_imm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsl_imm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_lsl_imm_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_lsl_imm_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsl_imm_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_lsl_imm_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_lsl_imm_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsl_imm_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_lsl_reg_a1 */
    #define OP_FB_MASK_arm_lsl_reg_a1 (0x0fef00f0l) /* fixed bits mask */
    #define OP_FB_arm_lsl_reg_a1 (0x01a00010l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_lsl_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsl_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsl_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_lsl_reg_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsl_reg_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsl_reg_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_lsl_reg_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsl_reg_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsl_reg_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_lsl_reg_a1_Rm_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_lsl_reg_a1_Rm_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsl_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_lsl_reg_a1_Rn_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_lsl_reg_a1_Rn_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsl_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    

    /* arm_lsr_imm_a1 */
    #define OP_FB_MASK_arm_lsr_imm_a1 (0x0fef0070l) /* fixed bits mask */
    #define OP_FB_arm_lsr_imm_a1 (0x01a00020l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_lsr_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsr_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsr_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_lsr_imm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsr_imm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsr_imm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_lsr_imm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsr_imm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsr_imm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_lsr_imm_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_lsr_imm_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsr_imm_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_lsr_imm_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_lsr_imm_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsr_imm_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_bfc_a1 */
    #define OP_FB_MASK_arm_bfc_a1 (0x0fe0007fl) /* fixed bits mask */
    #define OP_FB_arm_bfc_a1 (0x07c0001fl) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_bfc_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_bfc_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bfc_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'msb' */
            #define OP_SF_MASK_arm_bfc_a1_msb_0 (0x001f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_bfc_a1_msb_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bfc_a1_msb_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_bfc_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_bfc_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bfc_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'lsb' */
            #define OP_SF_MASK_arm_bfc_a1_lsb_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_bfc_a1_lsb_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_bfc_a1_lsb_0 (0) /* subfield end bit position in field */
        
    

    /* arm_and_imm_a1 */
    #define OP_FB_MASK_arm_and_imm_a1 (0x0fe00000l) /* fixed bits mask */
    #define OP_FB_arm_and_imm_a1 (0x02000000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_and_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_and_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_and_imm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_and_imm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_imm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_and_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_and_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_and_imm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_and_imm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_imm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_and_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_and_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_and_reg_a1 */
    #define OP_FB_MASK_arm_and_reg_a1 (0x0fe00010l) /* fixed bits mask */
    #define OP_FB_arm_and_reg_a1 (0x00000000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_and_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_and_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_and_reg_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_and_reg_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_reg_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_and_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_and_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_and_reg_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_and_reg_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_reg_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_and_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_and_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_and_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_and_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_and_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_and_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_and_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_utxb_a1 */
    #define OP_FB_MASK_arm_utxb_a1 (0x0fff03f0l) /* fixed bits mask */
    #define OP_FB_arm_utxb_a1 (0x06ef0070l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_utxb_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_utxb_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_utxb_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_utxb_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_utxb_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_utxb_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'rotate' */
            #define OP_SF_MASK_arm_utxb_a1_rotate_0 (0x00000c00l) /* subfield mask */
            #define OP_SF_EBII_arm_utxb_a1_rotate_0 (10) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_utxb_a1_rotate_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_utxb_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_utxb_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_utxb_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_utxh_a1 */
    #define OP_FB_MASK_arm_utxh_a1 (0x0fff03f0l) /* fixed bits mask */
    #define OP_FB_arm_utxh_a1 (0x06ff0070l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_utxh_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_utxh_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_utxh_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_utxh_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_utxh_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_utxh_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'rotate' */
            #define OP_SF_MASK_arm_utxh_a1_rotate_0 (0x00000c00l) /* subfield mask */
            #define OP_SF_EBII_arm_utxh_a1_rotate_0 (10) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_utxh_a1_rotate_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_utxh_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_utxh_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_utxh_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_rsb_reg_a1 */
    #define OP_FB_MASK_arm_rsb_reg_a1 (0x0fe00010l) /* fixed bits mask */
    #define OP_FB_arm_rsb_reg_a1 (0x00600000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_rsb_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_rsb_reg_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_reg_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_reg_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_rsb_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_rsb_reg_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_reg_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_reg_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_rsb_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_rsb_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_rsb_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_sbc_reg_a1 */
    #define OP_FB_MASK_arm_sbc_reg_a1 (0x0fe00010l) /* fixed bits mask */
    #define OP_FB_arm_sbc_reg_a1 (0x00c00000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_sbc_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_sbc_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sbc_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_sbc_reg_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_sbc_reg_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sbc_reg_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_sbc_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_sbc_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sbc_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_sbc_reg_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_sbc_reg_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sbc_reg_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_sbc_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_sbc_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sbc_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_sbc_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_sbc_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sbc_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_sbc_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_sbc_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sbc_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_mul_a1 */
    #define OP_FB_MASK_arm_mul_a1 (0x0fe0f0f0l) /* fixed bits mask */
    #define OP_FB_arm_mul_a1 (0x00000090l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_mul_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_mul_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mul_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_mul_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_mul_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mul_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_mul_a1_Rd_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_mul_a1_Rd_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mul_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_mul_a1_Rm_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_mul_a1_Rm_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mul_a1_Rm_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_mul_a1_Rn_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_mul_a1_Rn_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_mul_a1_Rn_0 (0) /* subfield end bit position in field */
        
    


/* individual op parse functions */

static int op_parse_arm_add_imm_a1(OpDecodeContext *context);

static int op_parse_arm_add_reg_a1(OpDecodeContext *context);

static int op_parse_arm_add_spimm_a1(OpDecodeContext *context);

static int op_parse_arm_adr_a1(OpDecodeContext *context);

static int op_parse_arm_subs_pclr_a1(OpDecodeContext *context);

static int op_parse_arm_cmp_imm_a1(OpDecodeContext *context);

static int op_parse_arm_cmn_imm_a1(OpDecodeContext *context);

static int op_parse_arm_sub_imm_a1(OpDecodeContext *context);

static int op_parse_arm_sub_reg_a1(OpDecodeContext *context);

static int op_parse_arm_sub_spimm_a1(OpDecodeContext *context);

static int op_parse_arm_cmp_reg_a1(OpDecodeContext *context);

static int op_parse_arm_mov_imm_a1(OpDecodeContext *context);

static int op_parse_arm_mov_imm_a2(OpDecodeContext *context);

static int op_parse_arm_mvn_imm_a1(OpDecodeContext *context);

static int op_parse_arm_mov_reg_a1(OpDecodeContext *context);

static int op_parse_arm_mvn_reg_a1(OpDecodeContext *context);

static int op_parse_arm_bl_a1(OpDecodeContext *context);

static int op_parse_arm_blx_a2(OpDecodeContext *context);

static int op_parse_arm_blx_reg_a1(OpDecodeContext *context);

static int op_parse_arm_b_a1(OpDecodeContext *context);

static int op_parse_arm_bx_a1(OpDecodeContext *context);

static int op_parse_arm_str_imm_a1(OpDecodeContext *context);

static int op_parse_arm_strb_imm_a1(OpDecodeContext *context);

static int op_parse_arm_strh_imm_a1(OpDecodeContext *context);

static int op_parse_arm_strd_imm_a1(OpDecodeContext *context);

static int op_parse_arm_strb_reg_a1(OpDecodeContext *context);

static int op_parse_arm_push_a1(OpDecodeContext *context);

static int op_parse_arm_push_a2(OpDecodeContext *context);

static int op_parse_arm_ldr_imm_a1(OpDecodeContext *context);

static int op_parse_arm_ldr_literal_a1(OpDecodeContext *context);

static int op_parse_arm_ldrb_imm_a1(OpDecodeContext *context);

static int op_parse_arm_ldrh_imm_a1(OpDecodeContext *context);

static int op_parse_arm_ldrd_imm_a1(OpDecodeContext *context);

static int op_parse_arm_ldr_reg_a1(OpDecodeContext *context);

static int op_parse_arm_ldrb_reg_a1(OpDecodeContext *context);

static int op_parse_arm_ldrh_reg_a1(OpDecodeContext *context);

static int op_parse_arm_pop_a1(OpDecodeContext *context);

static int op_parse_arm_pop_a2(OpDecodeContext *context);

static int op_parse_arm_nop_a1(OpDecodeContext *context);

static int op_parse_arm_msr_imm_a1(OpDecodeContext *context);

static int op_parse_arm_msr2_imm_a1(OpDecodeContext *context);

static int op_parse_arm_mrs_a1(OpDecodeContext *context);

static int op_parse_arm_msr2_reg_a1(OpDecodeContext *context);

static int op_parse_arm_mcr_a1(OpDecodeContext *context);

static int op_parse_arm_mcr2_a2(OpDecodeContext *context);

static int op_parse_arm_mrc_a1(OpDecodeContext *context);

static int op_parse_arm_mrc2_a2(OpDecodeContext *context);

static int op_parse_arm_bic_imm_a1(OpDecodeContext *context);

static int op_parse_arm_orr_imm_a1(OpDecodeContext *context);

static int op_parse_arm_orr_reg_a1(OpDecodeContext *context);

static int op_parse_arm_movt_a1(OpDecodeContext *context);

static int op_parse_arm_lsl_imm_a1(OpDecodeContext *context);

static int op_parse_arm_lsl_reg_a1(OpDecodeContext *context);

static int op_parse_arm_lsr_imm_a1(OpDecodeContext *context);

static int op_parse_arm_bfc_a1(OpDecodeContext *context);

static int op_parse_arm_and_imm_a1(OpDecodeContext *context);

static int op_parse_arm_and_reg_a1(OpDecodeContext *context);

static int op_parse_arm_utxb_a1(OpDecodeContext *context);

static int op_parse_arm_utxh_a1(OpDecodeContext *context);

static int op_parse_arm_rsb_reg_a1(OpDecodeContext *context);

static int op_parse_arm_sbc_reg_a1(OpDecodeContext *context);

static int op_parse_arm_mul_a1(OpDecodeContext *context);



    /* arm_add_imm_a1 */
    static int op_parse_arm_add_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_add_imm_a1) != OP_FB_arm_add_imm_a1) {
            return 1;
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
            
        

        
        
            if (
                (context->decoded_code->code.arm_add_imm_a1.cond == 15)
         || (context->decoded_code->code.arm_add_imm_a1.Rn == 13)
         || ((context->decoded_code->code.arm_add_imm_a1.Rn == 15)
         && (context->decoded_code->code.arm_add_imm_a1.S == 0)
        )
         || ((context->decoded_code->code.arm_add_imm_a1.Rd == 15)
         && (context->decoded_code->code.arm_add_imm_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_add_reg_a1 */
    static int op_parse_arm_add_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_add_reg_a1) != OP_FB_arm_add_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_add_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_add_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_add_reg_a1;
        
            context->decoded_code->code.arm_add_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_add_reg_a1_cond_0) >> OP_SF_EBII_arm_add_reg_a1_cond_0) << OP_SF_EBIF_arm_add_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_add_reg_a1_S_0) >> OP_SF_EBII_arm_add_reg_a1_S_0) << OP_SF_EBIF_arm_add_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_add_reg_a1_Rn_0) >> OP_SF_EBII_arm_add_reg_a1_Rn_0) << OP_SF_EBIF_arm_add_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_add_reg_a1_Rd_0) >> OP_SF_EBII_arm_add_reg_a1_Rd_0) << OP_SF_EBIF_arm_add_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_add_reg_a1_imm5_0) >> OP_SF_EBII_arm_add_reg_a1_imm5_0) << OP_SF_EBIF_arm_add_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.type =
            
                (((context->code32 & OP_SF_MASK_arm_add_reg_a1_type_0) >> OP_SF_EBII_arm_add_reg_a1_type_0) << OP_SF_EBIF_arm_add_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_add_reg_a1_Rm_0) >> OP_SF_EBII_arm_add_reg_a1_Rm_0) << OP_SF_EBIF_arm_add_reg_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_add_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_add_reg_a1.Rd == 15)
         && (context->decoded_code->code.arm_add_reg_a1.S == 1)
        )
         || (context->decoded_code->code.arm_add_reg_a1.Rn == 13)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_add_spimm_a1 */
    static int op_parse_arm_add_spimm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_add_spimm_a1) != OP_FB_arm_add_spimm_a1) {
            return 1;
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
            
        

        
        
            if (
                (context->decoded_code->code.arm_add_spimm_a1.cond == 15)
         || ((context->decoded_code->code.arm_add_spimm_a1.Rd == 15)
         && (context->decoded_code->code.arm_add_spimm_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
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
            
        

        
        
            if (
                context->decoded_code->code.arm_adr_a1.cond == 15
            ) {
                return 1;
            }
        
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
            
        

        
        
            if (
                context->decoded_code->code.arm_subs_pclr_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_cmp_imm_a1 */
    static int op_parse_arm_cmp_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_cmp_imm_a1) != OP_FB_arm_cmp_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_cmp_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_cmp_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_cmp_imm_a1;
        
            context->decoded_code->code.arm_cmp_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_cmp_imm_a1_cond_0) >> OP_SF_EBII_arm_cmp_imm_a1_cond_0) << OP_SF_EBIF_arm_cmp_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_cmp_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_cmp_imm_a1_Rn_0) >> OP_SF_EBII_arm_cmp_imm_a1_Rn_0) << OP_SF_EBIF_arm_cmp_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_cmp_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_cmp_imm_a1_imm12_0) >> OP_SF_EBII_arm_cmp_imm_a1_imm12_0) << OP_SF_EBIF_arm_cmp_imm_a1_imm12_0);
            
        

        
        
            if (
                context->decoded_code->code.arm_cmp_imm_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_cmn_imm_a1 */
    static int op_parse_arm_cmn_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_cmn_imm_a1) != OP_FB_arm_cmn_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_cmn_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_cmn_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_cmn_imm_a1;
        
            context->decoded_code->code.arm_cmn_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_cmn_imm_a1_cond_0) >> OP_SF_EBII_arm_cmn_imm_a1_cond_0) << OP_SF_EBIF_arm_cmn_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_cmn_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_cmn_imm_a1_Rn_0) >> OP_SF_EBII_arm_cmn_imm_a1_Rn_0) << OP_SF_EBIF_arm_cmn_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_cmn_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_cmn_imm_a1_imm12_0) >> OP_SF_EBII_arm_cmn_imm_a1_imm12_0) << OP_SF_EBIF_arm_cmn_imm_a1_imm12_0);
            
        

        
        
            if (
                context->decoded_code->code.arm_cmn_imm_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_sub_imm_a1 */
    static int op_parse_arm_sub_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_sub_imm_a1) != OP_FB_arm_sub_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_sub_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_sub_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_sub_imm_a1;
        
            context->decoded_code->code.arm_sub_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_sub_imm_a1_cond_0) >> OP_SF_EBII_arm_sub_imm_a1_cond_0) << OP_SF_EBIF_arm_sub_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_sub_imm_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_sub_imm_a1_S_0) >> OP_SF_EBII_arm_sub_imm_a1_S_0) << OP_SF_EBIF_arm_sub_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_sub_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_sub_imm_a1_Rn_0) >> OP_SF_EBII_arm_sub_imm_a1_Rn_0) << OP_SF_EBIF_arm_sub_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_sub_imm_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_sub_imm_a1_Rd_0) >> OP_SF_EBII_arm_sub_imm_a1_Rd_0) << OP_SF_EBIF_arm_sub_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_sub_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_sub_imm_a1_imm12_0) >> OP_SF_EBII_arm_sub_imm_a1_imm12_0) << OP_SF_EBIF_arm_sub_imm_a1_imm12_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_sub_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_sub_imm_a1.Rn == 15)
         && (context->decoded_code->code.arm_sub_imm_a1.S == 0)
        )
         || ((context->decoded_code->code.arm_sub_imm_a1.Rd == 15)
         && (context->decoded_code->code.arm_sub_imm_a1.S == 1)
        )
         || (context->decoded_code->code.arm_sub_imm_a1.Rn == 13)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_sub_reg_a1 */
    static int op_parse_arm_sub_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_sub_reg_a1) != OP_FB_arm_sub_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_sub_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_sub_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_sub_reg_a1;
        
            context->decoded_code->code.arm_sub_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_sub_reg_a1_cond_0) >> OP_SF_EBII_arm_sub_reg_a1_cond_0) << OP_SF_EBIF_arm_sub_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_sub_reg_a1_S_0) >> OP_SF_EBII_arm_sub_reg_a1_S_0) << OP_SF_EBIF_arm_sub_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_sub_reg_a1_Rn_0) >> OP_SF_EBII_arm_sub_reg_a1_Rn_0) << OP_SF_EBIF_arm_sub_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_sub_reg_a1_Rd_0) >> OP_SF_EBII_arm_sub_reg_a1_Rd_0) << OP_SF_EBIF_arm_sub_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_sub_reg_a1_imm5_0) >> OP_SF_EBII_arm_sub_reg_a1_imm5_0) << OP_SF_EBIF_arm_sub_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.type =
            
                (((context->code32 & OP_SF_MASK_arm_sub_reg_a1_type_0) >> OP_SF_EBII_arm_sub_reg_a1_type_0) << OP_SF_EBIF_arm_sub_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_sub_reg_a1_Rm_0) >> OP_SF_EBII_arm_sub_reg_a1_Rm_0) << OP_SF_EBIF_arm_sub_reg_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_sub_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_sub_reg_a1.Rd == 15)
         && (context->decoded_code->code.arm_sub_reg_a1.S == 1)
        )
         || (context->decoded_code->code.arm_sub_reg_a1.Rn == 13)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_sub_spimm_a1 */
    static int op_parse_arm_sub_spimm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_sub_spimm_a1) != OP_FB_arm_sub_spimm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_sub_spimm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_sub_spimm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_sub_spimm_a1;
        
            context->decoded_code->code.arm_sub_spimm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_sub_spimm_a1_cond_0) >> OP_SF_EBII_arm_sub_spimm_a1_cond_0) << OP_SF_EBIF_arm_sub_spimm_a1_cond_0);
            
        
            context->decoded_code->code.arm_sub_spimm_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_sub_spimm_a1_S_0) >> OP_SF_EBII_arm_sub_spimm_a1_S_0) << OP_SF_EBIF_arm_sub_spimm_a1_S_0);
            
        
            context->decoded_code->code.arm_sub_spimm_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_sub_spimm_a1_Rd_0) >> OP_SF_EBII_arm_sub_spimm_a1_Rd_0) << OP_SF_EBIF_arm_sub_spimm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_sub_spimm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_sub_spimm_a1_imm12_0) >> OP_SF_EBII_arm_sub_spimm_a1_imm12_0) << OP_SF_EBIF_arm_sub_spimm_a1_imm12_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_sub_spimm_a1.cond == 15)
         || ((context->decoded_code->code.arm_sub_spimm_a1.Rd == 15)
         && (context->decoded_code->code.arm_sub_spimm_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_cmp_reg_a1 */
    static int op_parse_arm_cmp_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_cmp_reg_a1) != OP_FB_arm_cmp_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_cmp_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_cmp_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_cmp_reg_a1;
        
            context->decoded_code->code.arm_cmp_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_cmp_reg_a1_cond_0) >> OP_SF_EBII_arm_cmp_reg_a1_cond_0) << OP_SF_EBIF_arm_cmp_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_cmp_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_cmp_reg_a1_Rn_0) >> OP_SF_EBII_arm_cmp_reg_a1_Rn_0) << OP_SF_EBIF_arm_cmp_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_cmp_reg_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_cmp_reg_a1_imm5_0) >> OP_SF_EBII_arm_cmp_reg_a1_imm5_0) << OP_SF_EBIF_arm_cmp_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_cmp_reg_a1.type =
            
                (((context->code32 & OP_SF_MASK_arm_cmp_reg_a1_type_0) >> OP_SF_EBII_arm_cmp_reg_a1_type_0) << OP_SF_EBIF_arm_cmp_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_cmp_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_cmp_reg_a1_Rm_0) >> OP_SF_EBII_arm_cmp_reg_a1_Rm_0) << OP_SF_EBIF_arm_cmp_reg_a1_Rm_0);
            
        

        
        
            if (
                context->decoded_code->code.arm_cmp_reg_a1.cond == 15
            ) {
                return 1;
            }
        
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
            
        

        
        
            if (
                (context->decoded_code->code.arm_mov_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_mov_imm_a1.Rd == 15)
         && (context->decoded_code->code.arm_mov_imm_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
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
            
        

        
        
            if (
                context->decoded_code->code.arm_mov_imm_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_mvn_imm_a1 */
    static int op_parse_arm_mvn_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mvn_imm_a1) != OP_FB_arm_mvn_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_mvn_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mvn_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mvn_imm_a1;
        
            context->decoded_code->code.arm_mvn_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_mvn_imm_a1_cond_0) >> OP_SF_EBII_arm_mvn_imm_a1_cond_0) << OP_SF_EBIF_arm_mvn_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_mvn_imm_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_mvn_imm_a1_S_0) >> OP_SF_EBII_arm_mvn_imm_a1_S_0) << OP_SF_EBIF_arm_mvn_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_mvn_imm_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_mvn_imm_a1_Rd_0) >> OP_SF_EBII_arm_mvn_imm_a1_Rd_0) << OP_SF_EBIF_arm_mvn_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_mvn_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_mvn_imm_a1_imm12_0) >> OP_SF_EBII_arm_mvn_imm_a1_imm12_0) << OP_SF_EBIF_arm_mvn_imm_a1_imm12_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_mvn_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_mvn_imm_a1.Rd == 15)
         && (context->decoded_code->code.arm_mvn_imm_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_mov_reg_a1 */
    static int op_parse_arm_mov_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mov_reg_a1) != OP_FB_arm_mov_reg_a1) {
            return 1;
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
            
        

        
        
            if (
                (context->decoded_code->code.arm_mov_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_mov_reg_a1.Rd == 15)
         && (context->decoded_code->code.arm_mov_reg_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_mvn_reg_a1 */
    static int op_parse_arm_mvn_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mvn_reg_a1) != OP_FB_arm_mvn_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_mvn_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mvn_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mvn_reg_a1;
        
            context->decoded_code->code.arm_mvn_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_mvn_reg_a1_cond_0) >> OP_SF_EBII_arm_mvn_reg_a1_cond_0) << OP_SF_EBIF_arm_mvn_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_mvn_reg_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_mvn_reg_a1_S_0) >> OP_SF_EBII_arm_mvn_reg_a1_S_0) << OP_SF_EBIF_arm_mvn_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_mvn_reg_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_mvn_reg_a1_Rd_0) >> OP_SF_EBII_arm_mvn_reg_a1_Rd_0) << OP_SF_EBIF_arm_mvn_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_mvn_reg_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_mvn_reg_a1_imm5_0) >> OP_SF_EBII_arm_mvn_reg_a1_imm5_0) << OP_SF_EBIF_arm_mvn_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_mvn_reg_a1.type =
            
                (((context->code32 & OP_SF_MASK_arm_mvn_reg_a1_type_0) >> OP_SF_EBII_arm_mvn_reg_a1_type_0) << OP_SF_EBIF_arm_mvn_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_mvn_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_mvn_reg_a1_Rm_0) >> OP_SF_EBII_arm_mvn_reg_a1_Rm_0) << OP_SF_EBIF_arm_mvn_reg_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_mvn_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_mvn_reg_a1.Rd == 15)
         && (context->decoded_code->code.arm_mvn_reg_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
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
            
        

        
        
            if (
                context->decoded_code->code.arm_bl_a1.cond == 15
            ) {
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

    /* arm_blx_reg_a1 */
    static int op_parse_arm_blx_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_blx_reg_a1) != OP_FB_arm_blx_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_blx_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_blx_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_blx_reg_a1;
        
            context->decoded_code->code.arm_blx_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_blx_reg_a1_cond_0) >> OP_SF_EBII_arm_blx_reg_a1_cond_0) << OP_SF_EBIF_arm_blx_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_blx_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_blx_reg_a1_Rm_0) >> OP_SF_EBII_arm_blx_reg_a1_Rm_0) << OP_SF_EBIF_arm_blx_reg_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_blx_reg_a1.cond == 15)
         || (context->decoded_code->code.arm_blx_reg_a1.Rm == 15)
        
            ) {
                return 1;
            }
        
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
            
        

        
        
            if (
                context->decoded_code->code.arm_b_a1.cond == 15
            ) {
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
            
        

        
        
            if (
                context->decoded_code->code.arm_bx_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_str_imm_a1 */
    static int op_parse_arm_str_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_str_imm_a1) != OP_FB_arm_str_imm_a1) {
            return 1;
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
            
        

        
        
            if (
                (context->decoded_code->code.arm_str_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_str_imm_a1.P == 0)
         && (context->decoded_code->code.arm_str_imm_a1.W == 1)
        )
         || ((context->decoded_code->code.arm_str_imm_a1.Rn == 13)
         && (context->decoded_code->code.arm_str_imm_a1.P == 1)
         && (context->decoded_code->code.arm_str_imm_a1.U == 0)
         && (context->decoded_code->code.arm_str_imm_a1.W == 1)
         && (context->decoded_code->code.arm_str_imm_a1.imm12 == 4)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_strb_imm_a1 */
    static int op_parse_arm_strb_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_strb_imm_a1) != OP_FB_arm_strb_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_strb_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_strb_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_strb_imm_a1;
        
            context->decoded_code->code.arm_strb_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_strb_imm_a1_cond_0) >> OP_SF_EBII_arm_strb_imm_a1_cond_0) << OP_SF_EBIF_arm_strb_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_strb_imm_a1_P_0) >> OP_SF_EBII_arm_strb_imm_a1_P_0) << OP_SF_EBIF_arm_strb_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_strb_imm_a1_U_0) >> OP_SF_EBII_arm_strb_imm_a1_U_0) << OP_SF_EBIF_arm_strb_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_strb_imm_a1_W_0) >> OP_SF_EBII_arm_strb_imm_a1_W_0) << OP_SF_EBIF_arm_strb_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_strb_imm_a1_Rn_0) >> OP_SF_EBII_arm_strb_imm_a1_Rn_0) << OP_SF_EBIF_arm_strb_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_strb_imm_a1_Rt_0) >> OP_SF_EBII_arm_strb_imm_a1_Rt_0) << OP_SF_EBIF_arm_strb_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_strb_imm_a1_imm12_0) >> OP_SF_EBII_arm_strb_imm_a1_imm12_0) << OP_SF_EBIF_arm_strb_imm_a1_imm12_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_strb_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_strb_imm_a1.P == 0)
         && (context->decoded_code->code.arm_strb_imm_a1.W == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_strh_imm_a1 */
    static int op_parse_arm_strh_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_strh_imm_a1) != OP_FB_arm_strh_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_strh_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_strh_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_strh_imm_a1;
        
            context->decoded_code->code.arm_strh_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_strh_imm_a1_cond_0) >> OP_SF_EBII_arm_strh_imm_a1_cond_0) << OP_SF_EBIF_arm_strh_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_strh_imm_a1_P_0) >> OP_SF_EBII_arm_strh_imm_a1_P_0) << OP_SF_EBIF_arm_strh_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_strh_imm_a1_U_0) >> OP_SF_EBII_arm_strh_imm_a1_U_0) << OP_SF_EBIF_arm_strh_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_strh_imm_a1_W_0) >> OP_SF_EBII_arm_strh_imm_a1_W_0) << OP_SF_EBIF_arm_strh_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_strh_imm_a1_Rn_0) >> OP_SF_EBII_arm_strh_imm_a1_Rn_0) << OP_SF_EBIF_arm_strh_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_strh_imm_a1_Rt_0) >> OP_SF_EBII_arm_strh_imm_a1_Rt_0) << OP_SF_EBIF_arm_strh_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.imm8 =
            
                (((context->code32 & OP_SF_MASK_arm_strh_imm_a1_imm8_0) >> OP_SF_EBII_arm_strh_imm_a1_imm8_0) << OP_SF_EBIF_arm_strh_imm_a1_imm8_0)
            
                | (((context->code32 & OP_SF_MASK_arm_strh_imm_a1_imm8_1) >> OP_SF_EBII_arm_strh_imm_a1_imm8_1) << OP_SF_EBIF_arm_strh_imm_a1_imm8_1);
            
        

        
        
            if (
                (context->decoded_code->code.arm_strh_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_strh_imm_a1.P == 0)
         && (context->decoded_code->code.arm_strh_imm_a1.W == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_strd_imm_a1 */
    static int op_parse_arm_strd_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_strd_imm_a1) != OP_FB_arm_strd_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_strd_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_strd_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_strd_imm_a1;
        
            context->decoded_code->code.arm_strd_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_strd_imm_a1_cond_0) >> OP_SF_EBII_arm_strd_imm_a1_cond_0) << OP_SF_EBIF_arm_strd_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_strd_imm_a1_P_0) >> OP_SF_EBII_arm_strd_imm_a1_P_0) << OP_SF_EBIF_arm_strd_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_strd_imm_a1_U_0) >> OP_SF_EBII_arm_strd_imm_a1_U_0) << OP_SF_EBIF_arm_strd_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_strd_imm_a1_W_0) >> OP_SF_EBII_arm_strd_imm_a1_W_0) << OP_SF_EBIF_arm_strd_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_strd_imm_a1_Rn_0) >> OP_SF_EBII_arm_strd_imm_a1_Rn_0) << OP_SF_EBIF_arm_strd_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_strd_imm_a1_Rt_0) >> OP_SF_EBII_arm_strd_imm_a1_Rt_0) << OP_SF_EBIF_arm_strd_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.imm8 =
            
                (((context->code32 & OP_SF_MASK_arm_strd_imm_a1_imm8_0) >> OP_SF_EBII_arm_strd_imm_a1_imm8_0) << OP_SF_EBIF_arm_strd_imm_a1_imm8_0)
            
                | (((context->code32 & OP_SF_MASK_arm_strd_imm_a1_imm8_1) >> OP_SF_EBII_arm_strd_imm_a1_imm8_1) << OP_SF_EBIF_arm_strd_imm_a1_imm8_1);
            
        

        
        
            if (
                (context->decoded_code->code.arm_strd_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_strd_imm_a1.P == 0)
         && (context->decoded_code->code.arm_strd_imm_a1.W == 1)
        )
        
            ) {
                return 1;
            }
        
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
            
        

        
        
            if (
                (context->decoded_code->code.arm_strb_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_strb_reg_a1.P == 0)
         && (context->decoded_code->code.arm_strb_reg_a1.W == 1)
        )
        
            ) {
                return 1;
            }
        
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
            
        

        
        
            if (
                context->decoded_code->code.arm_push_a1.cond == 15
            ) {
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
            
        

        
        
            if (
                (context->decoded_code->code.arm_push_a2.cond == 15)
         || (context->decoded_code->code.arm_push_a2.Rt == 13)
        
            ) {
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
            
        

        
        
            if (
                (context->decoded_code->code.arm_ldr_imm_a1.cond == 15)
         || (context->decoded_code->code.arm_ldr_imm_a1.Rn == 15)
         || ((context->decoded_code->code.arm_ldr_imm_a1.P == 0)
         && (context->decoded_code->code.arm_ldr_imm_a1.W == 1)
        )
         || ((context->decoded_code->code.arm_ldr_imm_a1.Rn == 13)
         && (context->decoded_code->code.arm_ldr_imm_a1.P == 0)
         && (context->decoded_code->code.arm_ldr_imm_a1.U == 1)
         && (context->decoded_code->code.arm_ldr_imm_a1.W == 0)
         && (context->decoded_code->code.arm_ldr_imm_a1.imm12 == 4)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_ldr_literal_a1 */
    static int op_parse_arm_ldr_literal_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_ldr_literal_a1) != OP_FB_arm_ldr_literal_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_ldr_literal_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldr_literal_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldr_literal_a1;
        
            context->decoded_code->code.arm_ldr_literal_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_literal_a1_cond_0) >> OP_SF_EBII_arm_ldr_literal_a1_cond_0) << OP_SF_EBIF_arm_ldr_literal_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldr_literal_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_literal_a1_P_0) >> OP_SF_EBII_arm_ldr_literal_a1_P_0) << OP_SF_EBIF_arm_ldr_literal_a1_P_0);
            
        
            context->decoded_code->code.arm_ldr_literal_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_literal_a1_U_0) >> OP_SF_EBII_arm_ldr_literal_a1_U_0) << OP_SF_EBIF_arm_ldr_literal_a1_U_0);
            
        
            context->decoded_code->code.arm_ldr_literal_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_literal_a1_W_0) >> OP_SF_EBII_arm_ldr_literal_a1_W_0) << OP_SF_EBIF_arm_ldr_literal_a1_W_0);
            
        
            context->decoded_code->code.arm_ldr_literal_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_literal_a1_Rt_0) >> OP_SF_EBII_arm_ldr_literal_a1_Rt_0) << OP_SF_EBIF_arm_ldr_literal_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldr_literal_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_literal_a1_imm12_0) >> OP_SF_EBII_arm_ldr_literal_a1_imm12_0) << OP_SF_EBIF_arm_ldr_literal_a1_imm12_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_ldr_literal_a1.cond == 15)
         || ((context->decoded_code->code.arm_ldr_literal_a1.P == 0)
         && (context->decoded_code->code.arm_ldr_literal_a1.W == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_ldrb_imm_a1 */
    static int op_parse_arm_ldrb_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_ldrb_imm_a1) != OP_FB_arm_ldrb_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_ldrb_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldrb_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldrb_imm_a1;
        
            context->decoded_code->code.arm_ldrb_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_imm_a1_cond_0) >> OP_SF_EBII_arm_ldrb_imm_a1_cond_0) << OP_SF_EBIF_arm_ldrb_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_imm_a1_P_0) >> OP_SF_EBII_arm_ldrb_imm_a1_P_0) << OP_SF_EBIF_arm_ldrb_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_imm_a1_U_0) >> OP_SF_EBII_arm_ldrb_imm_a1_U_0) << OP_SF_EBIF_arm_ldrb_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_imm_a1_W_0) >> OP_SF_EBII_arm_ldrb_imm_a1_W_0) << OP_SF_EBIF_arm_ldrb_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_imm_a1_Rn_0) >> OP_SF_EBII_arm_ldrb_imm_a1_Rn_0) << OP_SF_EBIF_arm_ldrb_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_imm_a1_Rt_0) >> OP_SF_EBII_arm_ldrb_imm_a1_Rt_0) << OP_SF_EBIF_arm_ldrb_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_ldrb_imm_a1_imm12_0) >> OP_SF_EBII_arm_ldrb_imm_a1_imm12_0) << OP_SF_EBIF_arm_ldrb_imm_a1_imm12_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_ldrb_imm_a1.cond == 15)
         || (context->decoded_code->code.arm_ldrb_imm_a1.Rn == 15)
         || ((context->decoded_code->code.arm_ldrb_imm_a1.P == 0)
         && (context->decoded_code->code.arm_ldrb_imm_a1.W == 1)
        )
         || (context->decoded_code->code.arm_ldrb_imm_a1.Rt == 15)
         || ((context->decoded_code->code.arm_ldrb_imm_a1.P == 0)
         || (context->decoded_code->code.arm_ldrb_imm_a1.W == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_ldrh_imm_a1 */
    static int op_parse_arm_ldrh_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_ldrh_imm_a1) != OP_FB_arm_ldrh_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_ldrh_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldrh_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldrh_imm_a1;
        
            context->decoded_code->code.arm_ldrh_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_imm_a1_cond_0) >> OP_SF_EBII_arm_ldrh_imm_a1_cond_0) << OP_SF_EBIF_arm_ldrh_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_imm_a1_P_0) >> OP_SF_EBII_arm_ldrh_imm_a1_P_0) << OP_SF_EBIF_arm_ldrh_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_imm_a1_U_0) >> OP_SF_EBII_arm_ldrh_imm_a1_U_0) << OP_SF_EBIF_arm_ldrh_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_imm_a1_W_0) >> OP_SF_EBII_arm_ldrh_imm_a1_W_0) << OP_SF_EBIF_arm_ldrh_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_imm_a1_Rn_0) >> OP_SF_EBII_arm_ldrh_imm_a1_Rn_0) << OP_SF_EBIF_arm_ldrh_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_imm_a1_Rt_0) >> OP_SF_EBII_arm_ldrh_imm_a1_Rt_0) << OP_SF_EBIF_arm_ldrh_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.imm8 =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_imm_a1_imm8_0) >> OP_SF_EBII_arm_ldrh_imm_a1_imm8_0) << OP_SF_EBIF_arm_ldrh_imm_a1_imm8_0)
            
                | (((context->code32 & OP_SF_MASK_arm_ldrh_imm_a1_imm8_1) >> OP_SF_EBII_arm_ldrh_imm_a1_imm8_1) << OP_SF_EBIF_arm_ldrh_imm_a1_imm8_1);
            
        

        
        
            if (
                (context->decoded_code->code.arm_ldrh_imm_a1.cond == 15)
         || (context->decoded_code->code.arm_ldrh_imm_a1.Rn == 15)
         || ((context->decoded_code->code.arm_ldrh_imm_a1.P == 0)
         && (context->decoded_code->code.arm_ldrh_imm_a1.W == 1)
        )
         || (context->decoded_code->code.arm_ldrh_imm_a1.Rt == 15)
         || ((context->decoded_code->code.arm_ldrh_imm_a1.P == 0)
         || (context->decoded_code->code.arm_ldrh_imm_a1.W == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_ldrd_imm_a1 */
    static int op_parse_arm_ldrd_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_ldrd_imm_a1) != OP_FB_arm_ldrd_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_ldrd_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldrd_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldrd_imm_a1;
        
            context->decoded_code->code.arm_ldrd_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_ldrd_imm_a1_cond_0) >> OP_SF_EBII_arm_ldrd_imm_a1_cond_0) << OP_SF_EBIF_arm_ldrd_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_ldrd_imm_a1_P_0) >> OP_SF_EBII_arm_ldrd_imm_a1_P_0) << OP_SF_EBIF_arm_ldrd_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_ldrd_imm_a1_U_0) >> OP_SF_EBII_arm_ldrd_imm_a1_U_0) << OP_SF_EBIF_arm_ldrd_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_ldrd_imm_a1_W_0) >> OP_SF_EBII_arm_ldrd_imm_a1_W_0) << OP_SF_EBIF_arm_ldrd_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_ldrd_imm_a1_Rn_0) >> OP_SF_EBII_arm_ldrd_imm_a1_Rn_0) << OP_SF_EBIF_arm_ldrd_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_ldrd_imm_a1_Rt_0) >> OP_SF_EBII_arm_ldrd_imm_a1_Rt_0) << OP_SF_EBIF_arm_ldrd_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.imm8 =
            
                (((context->code32 & OP_SF_MASK_arm_ldrd_imm_a1_imm8_0) >> OP_SF_EBII_arm_ldrd_imm_a1_imm8_0) << OP_SF_EBIF_arm_ldrd_imm_a1_imm8_0)
            
                | (((context->code32 & OP_SF_MASK_arm_ldrd_imm_a1_imm8_1) >> OP_SF_EBII_arm_ldrd_imm_a1_imm8_1) << OP_SF_EBIF_arm_ldrd_imm_a1_imm8_1);
            
        

        
        
            if (
                (context->decoded_code->code.arm_ldrd_imm_a1.cond == 15)
         || (context->decoded_code->code.arm_ldrd_imm_a1.Rn == 15)
         || ((context->decoded_code->code.arm_ldrd_imm_a1.P == 0)
         && (context->decoded_code->code.arm_ldrd_imm_a1.W == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_ldr_reg_a1 */
    static int op_parse_arm_ldr_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_ldr_reg_a1) != OP_FB_arm_ldr_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_ldr_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldr_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldr_reg_a1;
        
            context->decoded_code->code.arm_ldr_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_reg_a1_cond_0) >> OP_SF_EBII_arm_ldr_reg_a1_cond_0) << OP_SF_EBIF_arm_ldr_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_reg_a1_P_0) >> OP_SF_EBII_arm_ldr_reg_a1_P_0) << OP_SF_EBIF_arm_ldr_reg_a1_P_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_reg_a1_U_0) >> OP_SF_EBII_arm_ldr_reg_a1_U_0) << OP_SF_EBIF_arm_ldr_reg_a1_U_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_reg_a1_W_0) >> OP_SF_EBII_arm_ldr_reg_a1_W_0) << OP_SF_EBIF_arm_ldr_reg_a1_W_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_reg_a1_Rn_0) >> OP_SF_EBII_arm_ldr_reg_a1_Rn_0) << OP_SF_EBIF_arm_ldr_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_reg_a1_Rt_0) >> OP_SF_EBII_arm_ldr_reg_a1_Rt_0) << OP_SF_EBIF_arm_ldr_reg_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_reg_a1_imm5_0) >> OP_SF_EBII_arm_ldr_reg_a1_imm5_0) << OP_SF_EBIF_arm_ldr_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.type =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_reg_a1_type_0) >> OP_SF_EBII_arm_ldr_reg_a1_type_0) << OP_SF_EBIF_arm_ldr_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_ldr_reg_a1_Rm_0) >> OP_SF_EBII_arm_ldr_reg_a1_Rm_0) << OP_SF_EBIF_arm_ldr_reg_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_ldr_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_ldr_reg_a1.P == 0)
         && (context->decoded_code->code.arm_ldr_reg_a1.W == 1)
        )
         || (context->decoded_code->code.arm_ldr_reg_a1.Rm == 15)
         || (((context->decoded_code->code.arm_ldr_reg_a1.P == 0)
         || (context->decoded_code->code.arm_ldr_reg_a1.W == 1)
        )
         && (context->decoded_code->code.arm_ldr_reg_a1.Rn == 15)
        )
        
            ) {
                return 1;
            }
        
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
            
        

        
        
            if (
                (context->decoded_code->code.arm_ldrb_reg_a1.cond == 15)
         || (context->decoded_code->code.arm_ldrb_reg_a1.Rn == 15)
         || (context->decoded_code->code.arm_ldrb_reg_a1.Rt == 15)
         || ((context->decoded_code->code.arm_ldrb_reg_a1.P == 0)
         && (context->decoded_code->code.arm_ldrb_reg_a1.W == 1)
        )
         || (context->decoded_code->code.arm_ldrb_reg_a1.Rt == 15)
         || (((context->decoded_code->code.arm_ldrb_reg_a1.P == 0)
         || (context->decoded_code->code.arm_ldrb_reg_a1.W == 1)
        )
         && (context->decoded_code->code.arm_ldrb_reg_a1.Rn == 15)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_ldrh_reg_a1 */
    static int op_parse_arm_ldrh_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_ldrh_reg_a1) != OP_FB_arm_ldrh_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_ldrh_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldrh_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldrh_reg_a1;
        
            context->decoded_code->code.arm_ldrh_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_reg_a1_cond_0) >> OP_SF_EBII_arm_ldrh_reg_a1_cond_0) << OP_SF_EBIF_arm_ldrh_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.P =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_reg_a1_P_0) >> OP_SF_EBII_arm_ldrh_reg_a1_P_0) << OP_SF_EBIF_arm_ldrh_reg_a1_P_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.U =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_reg_a1_U_0) >> OP_SF_EBII_arm_ldrh_reg_a1_U_0) << OP_SF_EBIF_arm_ldrh_reg_a1_U_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.W =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_reg_a1_W_0) >> OP_SF_EBII_arm_ldrh_reg_a1_W_0) << OP_SF_EBIF_arm_ldrh_reg_a1_W_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_reg_a1_Rn_0) >> OP_SF_EBII_arm_ldrh_reg_a1_Rn_0) << OP_SF_EBIF_arm_ldrh_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_reg_a1_Rt_0) >> OP_SF_EBII_arm_ldrh_reg_a1_Rt_0) << OP_SF_EBIF_arm_ldrh_reg_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_ldrh_reg_a1_Rm_0) >> OP_SF_EBII_arm_ldrh_reg_a1_Rm_0) << OP_SF_EBIF_arm_ldrh_reg_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_ldrh_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_ldrh_reg_a1.P == 0)
         && (context->decoded_code->code.arm_ldrh_reg_a1.W == 1)
        )
         || (context->decoded_code->code.arm_ldrh_reg_a1.Rm == 15)
         || (context->decoded_code->code.arm_ldrh_reg_a1.Rt == 15)
         || (((context->decoded_code->code.arm_ldrh_reg_a1.P == 0)
         || (context->decoded_code->code.arm_ldrh_reg_a1.W == 1)
        )
         && (context->decoded_code->code.arm_ldrh_reg_a1.Rn == 15)
        )
        
            ) {
                return 1;
            }
        
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
            
        

        
        
            if (
                context->decoded_code->code.arm_pop_a1.cond == 15
            ) {
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
            
        

        
        
            if (
                (context->decoded_code->code.arm_pop_a2.cond == 15)
         || (context->decoded_code->code.arm_pop_a2.Rt == 13)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_nop_a1 */
    static int op_parse_arm_nop_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_nop_a1) != OP_FB_arm_nop_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_nop_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_nop_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_nop_a1;
        
            context->decoded_code->code.arm_nop_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_nop_a1_cond_0) >> OP_SF_EBII_arm_nop_a1_cond_0) << OP_SF_EBIF_arm_nop_a1_cond_0);
            
        

        
        
            if (
                context->decoded_code->code.arm_nop_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_msr_imm_a1 */
    static int op_parse_arm_msr_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_msr_imm_a1) != OP_FB_arm_msr_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_msr_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_msr_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_msr_imm_a1;
        
            context->decoded_code->code.arm_msr_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_msr_imm_a1_cond_0) >> OP_SF_EBII_arm_msr_imm_a1_cond_0) << OP_SF_EBIF_arm_msr_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_msr_imm_a1.mask =
            
                (((context->code32 & OP_SF_MASK_arm_msr_imm_a1_mask_0) >> OP_SF_EBII_arm_msr_imm_a1_mask_0) << OP_SF_EBIF_arm_msr_imm_a1_mask_0);
            
        
            context->decoded_code->code.arm_msr_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_msr_imm_a1_imm12_0) >> OP_SF_EBII_arm_msr_imm_a1_imm12_0) << OP_SF_EBIF_arm_msr_imm_a1_imm12_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_msr_imm_a1.cond == 15)
         || (context->decoded_code->code.arm_msr_imm_a1.mask == 0)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_msr2_imm_a1 */
    static int op_parse_arm_msr2_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_msr2_imm_a1) != OP_FB_arm_msr2_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_msr2_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_msr2_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_msr2_imm_a1;
        
            context->decoded_code->code.arm_msr2_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_msr2_imm_a1_cond_0) >> OP_SF_EBII_arm_msr2_imm_a1_cond_0) << OP_SF_EBIF_arm_msr2_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_msr2_imm_a1.R =
            
                (((context->code32 & OP_SF_MASK_arm_msr2_imm_a1_R_0) >> OP_SF_EBII_arm_msr2_imm_a1_R_0) << OP_SF_EBIF_arm_msr2_imm_a1_R_0);
            
        
            context->decoded_code->code.arm_msr2_imm_a1.mask =
            
                (((context->code32 & OP_SF_MASK_arm_msr2_imm_a1_mask_0) >> OP_SF_EBII_arm_msr2_imm_a1_mask_0) << OP_SF_EBIF_arm_msr2_imm_a1_mask_0);
            
        
            context->decoded_code->code.arm_msr2_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_msr2_imm_a1_imm12_0) >> OP_SF_EBII_arm_msr2_imm_a1_imm12_0) << OP_SF_EBIF_arm_msr2_imm_a1_imm12_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_msr2_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_msr2_imm_a1.mask == 0)
         && (context->decoded_code->code.arm_msr2_imm_a1.R == 0)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_mrs_a1 */
    static int op_parse_arm_mrs_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mrs_a1) != OP_FB_arm_mrs_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_mrs_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mrs_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mrs_a1;
        
            context->decoded_code->code.arm_mrs_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_mrs_a1_cond_0) >> OP_SF_EBII_arm_mrs_a1_cond_0) << OP_SF_EBIF_arm_mrs_a1_cond_0);
            
        
            context->decoded_code->code.arm_mrs_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_mrs_a1_Rd_0) >> OP_SF_EBII_arm_mrs_a1_Rd_0) << OP_SF_EBIF_arm_mrs_a1_Rd_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_mrs_a1.cond == 15)
         || (context->decoded_code->code.arm_mrs_a1.Rd == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_msr2_reg_a1 */
    static int op_parse_arm_msr2_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_msr2_reg_a1) != OP_FB_arm_msr2_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_msr2_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_msr2_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_msr2_reg_a1;
        
            context->decoded_code->code.arm_msr2_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_msr2_reg_a1_cond_0) >> OP_SF_EBII_arm_msr2_reg_a1_cond_0) << OP_SF_EBIF_arm_msr2_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_msr2_reg_a1.R =
            
                (((context->code32 & OP_SF_MASK_arm_msr2_reg_a1_R_0) >> OP_SF_EBII_arm_msr2_reg_a1_R_0) << OP_SF_EBIF_arm_msr2_reg_a1_R_0);
            
        
            context->decoded_code->code.arm_msr2_reg_a1.mask =
            
                (((context->code32 & OP_SF_MASK_arm_msr2_reg_a1_mask_0) >> OP_SF_EBII_arm_msr2_reg_a1_mask_0) << OP_SF_EBIF_arm_msr2_reg_a1_mask_0);
            
        
            context->decoded_code->code.arm_msr2_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_msr2_reg_a1_Rn_0) >> OP_SF_EBII_arm_msr2_reg_a1_Rn_0) << OP_SF_EBIF_arm_msr2_reg_a1_Rn_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_msr2_reg_a1.cond == 15)
         || (context->decoded_code->code.arm_msr2_reg_a1.mask == 0)
         || (context->decoded_code->code.arm_msr2_reg_a1.Rn == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_mcr_a1 */
    static int op_parse_arm_mcr_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mcr_a1) != OP_FB_arm_mcr_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_mcr_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mcr_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mcr_a1;
        
            context->decoded_code->code.arm_mcr_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_mcr_a1_cond_0) >> OP_SF_EBII_arm_mcr_a1_cond_0) << OP_SF_EBIF_arm_mcr_a1_cond_0);
            
        
            context->decoded_code->code.arm_mcr_a1.opc1 =
            
                (((context->code32 & OP_SF_MASK_arm_mcr_a1_opc1_0) >> OP_SF_EBII_arm_mcr_a1_opc1_0) << OP_SF_EBIF_arm_mcr_a1_opc1_0);
            
        
            context->decoded_code->code.arm_mcr_a1.CRn =
            
                (((context->code32 & OP_SF_MASK_arm_mcr_a1_CRn_0) >> OP_SF_EBII_arm_mcr_a1_CRn_0) << OP_SF_EBIF_arm_mcr_a1_CRn_0);
            
        
            context->decoded_code->code.arm_mcr_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_mcr_a1_Rt_0) >> OP_SF_EBII_arm_mcr_a1_Rt_0) << OP_SF_EBIF_arm_mcr_a1_Rt_0);
            
        
            context->decoded_code->code.arm_mcr_a1.coproc =
            
                (((context->code32 & OP_SF_MASK_arm_mcr_a1_coproc_0) >> OP_SF_EBII_arm_mcr_a1_coproc_0) << OP_SF_EBIF_arm_mcr_a1_coproc_0);
            
        
            context->decoded_code->code.arm_mcr_a1.opc2 =
            
                (((context->code32 & OP_SF_MASK_arm_mcr_a1_opc2_0) >> OP_SF_EBII_arm_mcr_a1_opc2_0) << OP_SF_EBIF_arm_mcr_a1_opc2_0);
            
        
            context->decoded_code->code.arm_mcr_a1.CRm =
            
                (((context->code32 & OP_SF_MASK_arm_mcr_a1_CRm_0) >> OP_SF_EBII_arm_mcr_a1_CRm_0) << OP_SF_EBIF_arm_mcr_a1_CRm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_mcr_a1.cond == 15)
         || (context->decoded_code->code.arm_mcr_a1.coproc == 10)
         || (context->decoded_code->code.arm_mcr_a1.coproc == 11)
         || (context->decoded_code->code.arm_mcr_a1.Rt == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_mcr2_a2 */
    static int op_parse_arm_mcr2_a2(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mcr2_a2) != OP_FB_arm_mcr2_a2) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_mcr2_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mcr2_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mcr2_a2;
        
            context->decoded_code->code.arm_mcr2_a2.opc1 =
            
                (((context->code32 & OP_SF_MASK_arm_mcr2_a2_opc1_0) >> OP_SF_EBII_arm_mcr2_a2_opc1_0) << OP_SF_EBIF_arm_mcr2_a2_opc1_0);
            
        
            context->decoded_code->code.arm_mcr2_a2.CRn =
            
                (((context->code32 & OP_SF_MASK_arm_mcr2_a2_CRn_0) >> OP_SF_EBII_arm_mcr2_a2_CRn_0) << OP_SF_EBIF_arm_mcr2_a2_CRn_0);
            
        
            context->decoded_code->code.arm_mcr2_a2.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_mcr2_a2_Rt_0) >> OP_SF_EBII_arm_mcr2_a2_Rt_0) << OP_SF_EBIF_arm_mcr2_a2_Rt_0);
            
        
            context->decoded_code->code.arm_mcr2_a2.coproc =
            
                (((context->code32 & OP_SF_MASK_arm_mcr2_a2_coproc_0) >> OP_SF_EBII_arm_mcr2_a2_coproc_0) << OP_SF_EBIF_arm_mcr2_a2_coproc_0);
            
        
            context->decoded_code->code.arm_mcr2_a2.opc2 =
            
                (((context->code32 & OP_SF_MASK_arm_mcr2_a2_opc2_0) >> OP_SF_EBII_arm_mcr2_a2_opc2_0) << OP_SF_EBIF_arm_mcr2_a2_opc2_0);
            
        
            context->decoded_code->code.arm_mcr2_a2.CRm =
            
                (((context->code32 & OP_SF_MASK_arm_mcr2_a2_CRm_0) >> OP_SF_EBII_arm_mcr2_a2_CRm_0) << OP_SF_EBIF_arm_mcr2_a2_CRm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_mcr2_a2.coproc == 10)
         || (context->decoded_code->code.arm_mcr2_a2.coproc == 11)
         || (context->decoded_code->code.arm_mcr2_a2.Rt == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_mrc_a1 */
    static int op_parse_arm_mrc_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mrc_a1) != OP_FB_arm_mrc_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_mrc_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mrc_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mrc_a1;
        
            context->decoded_code->code.arm_mrc_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_mrc_a1_cond_0) >> OP_SF_EBII_arm_mrc_a1_cond_0) << OP_SF_EBIF_arm_mrc_a1_cond_0);
            
        
            context->decoded_code->code.arm_mrc_a1.opc1 =
            
                (((context->code32 & OP_SF_MASK_arm_mrc_a1_opc1_0) >> OP_SF_EBII_arm_mrc_a1_opc1_0) << OP_SF_EBIF_arm_mrc_a1_opc1_0);
            
        
            context->decoded_code->code.arm_mrc_a1.CRn =
            
                (((context->code32 & OP_SF_MASK_arm_mrc_a1_CRn_0) >> OP_SF_EBII_arm_mrc_a1_CRn_0) << OP_SF_EBIF_arm_mrc_a1_CRn_0);
            
        
            context->decoded_code->code.arm_mrc_a1.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_mrc_a1_Rt_0) >> OP_SF_EBII_arm_mrc_a1_Rt_0) << OP_SF_EBIF_arm_mrc_a1_Rt_0);
            
        
            context->decoded_code->code.arm_mrc_a1.coproc =
            
                (((context->code32 & OP_SF_MASK_arm_mrc_a1_coproc_0) >> OP_SF_EBII_arm_mrc_a1_coproc_0) << OP_SF_EBIF_arm_mrc_a1_coproc_0);
            
        
            context->decoded_code->code.arm_mrc_a1.opc2 =
            
                (((context->code32 & OP_SF_MASK_arm_mrc_a1_opc2_0) >> OP_SF_EBII_arm_mrc_a1_opc2_0) << OP_SF_EBIF_arm_mrc_a1_opc2_0);
            
        
            context->decoded_code->code.arm_mrc_a1.CRm =
            
                (((context->code32 & OP_SF_MASK_arm_mrc_a1_CRm_0) >> OP_SF_EBII_arm_mrc_a1_CRm_0) << OP_SF_EBIF_arm_mrc_a1_CRm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_mrc_a1.cond == 15)
         || (context->decoded_code->code.arm_mrc_a1.coproc == 10)
         || (context->decoded_code->code.arm_mrc_a1.coproc == 11)
         || (context->decoded_code->code.arm_mrc_a1.Rt == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_mrc2_a2 */
    static int op_parse_arm_mrc2_a2(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mrc2_a2) != OP_FB_arm_mrc2_a2) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_mrc2_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mrc2_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mrc2_a2;
        
            context->decoded_code->code.arm_mrc2_a2.opc1 =
            
                (((context->code32 & OP_SF_MASK_arm_mrc2_a2_opc1_0) >> OP_SF_EBII_arm_mrc2_a2_opc1_0) << OP_SF_EBIF_arm_mrc2_a2_opc1_0);
            
        
            context->decoded_code->code.arm_mrc2_a2.CRn =
            
                (((context->code32 & OP_SF_MASK_arm_mrc2_a2_CRn_0) >> OP_SF_EBII_arm_mrc2_a2_CRn_0) << OP_SF_EBIF_arm_mrc2_a2_CRn_0);
            
        
            context->decoded_code->code.arm_mrc2_a2.Rt =
            
                (((context->code32 & OP_SF_MASK_arm_mrc2_a2_Rt_0) >> OP_SF_EBII_arm_mrc2_a2_Rt_0) << OP_SF_EBIF_arm_mrc2_a2_Rt_0);
            
        
            context->decoded_code->code.arm_mrc2_a2.coproc =
            
                (((context->code32 & OP_SF_MASK_arm_mrc2_a2_coproc_0) >> OP_SF_EBII_arm_mrc2_a2_coproc_0) << OP_SF_EBIF_arm_mrc2_a2_coproc_0);
            
        
            context->decoded_code->code.arm_mrc2_a2.opc2 =
            
                (((context->code32 & OP_SF_MASK_arm_mrc2_a2_opc2_0) >> OP_SF_EBII_arm_mrc2_a2_opc2_0) << OP_SF_EBIF_arm_mrc2_a2_opc2_0);
            
        
            context->decoded_code->code.arm_mrc2_a2.CRm =
            
                (((context->code32 & OP_SF_MASK_arm_mrc2_a2_CRm_0) >> OP_SF_EBII_arm_mrc2_a2_CRm_0) << OP_SF_EBIF_arm_mrc2_a2_CRm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_mrc2_a2.coproc == 10)
         || (context->decoded_code->code.arm_mrc2_a2.coproc == 11)
         || (context->decoded_code->code.arm_mrc2_a2.Rt == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_bic_imm_a1 */
    static int op_parse_arm_bic_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_bic_imm_a1) != OP_FB_arm_bic_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_bic_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_bic_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_bic_imm_a1;
        
            context->decoded_code->code.arm_bic_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_bic_imm_a1_cond_0) >> OP_SF_EBII_arm_bic_imm_a1_cond_0) << OP_SF_EBIF_arm_bic_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_bic_imm_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_bic_imm_a1_S_0) >> OP_SF_EBII_arm_bic_imm_a1_S_0) << OP_SF_EBIF_arm_bic_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_bic_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_bic_imm_a1_Rn_0) >> OP_SF_EBII_arm_bic_imm_a1_Rn_0) << OP_SF_EBIF_arm_bic_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_bic_imm_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_bic_imm_a1_Rd_0) >> OP_SF_EBII_arm_bic_imm_a1_Rd_0) << OP_SF_EBIF_arm_bic_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_bic_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_bic_imm_a1_imm12_0) >> OP_SF_EBII_arm_bic_imm_a1_imm12_0) << OP_SF_EBIF_arm_bic_imm_a1_imm12_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_bic_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_bic_imm_a1.Rd == 15)
         || (context->decoded_code->code.arm_bic_imm_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_orr_imm_a1 */
    static int op_parse_arm_orr_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_orr_imm_a1) != OP_FB_arm_orr_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_orr_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_orr_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_orr_imm_a1;
        
            context->decoded_code->code.arm_orr_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_orr_imm_a1_cond_0) >> OP_SF_EBII_arm_orr_imm_a1_cond_0) << OP_SF_EBIF_arm_orr_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_orr_imm_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_orr_imm_a1_S_0) >> OP_SF_EBII_arm_orr_imm_a1_S_0) << OP_SF_EBIF_arm_orr_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_orr_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_orr_imm_a1_Rn_0) >> OP_SF_EBII_arm_orr_imm_a1_Rn_0) << OP_SF_EBIF_arm_orr_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_orr_imm_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_orr_imm_a1_Rd_0) >> OP_SF_EBII_arm_orr_imm_a1_Rd_0) << OP_SF_EBIF_arm_orr_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_orr_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_orr_imm_a1_imm12_0) >> OP_SF_EBII_arm_orr_imm_a1_imm12_0) << OP_SF_EBIF_arm_orr_imm_a1_imm12_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_orr_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_orr_imm_a1.Rd == 15)
         || (context->decoded_code->code.arm_orr_imm_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_orr_reg_a1 */
    static int op_parse_arm_orr_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_orr_reg_a1) != OP_FB_arm_orr_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_orr_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_orr_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_orr_reg_a1;
        
            context->decoded_code->code.arm_orr_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_orr_reg_a1_cond_0) >> OP_SF_EBII_arm_orr_reg_a1_cond_0) << OP_SF_EBIF_arm_orr_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_orr_reg_a1_S_0) >> OP_SF_EBII_arm_orr_reg_a1_S_0) << OP_SF_EBIF_arm_orr_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_orr_reg_a1_Rn_0) >> OP_SF_EBII_arm_orr_reg_a1_Rn_0) << OP_SF_EBIF_arm_orr_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_orr_reg_a1_Rd_0) >> OP_SF_EBII_arm_orr_reg_a1_Rd_0) << OP_SF_EBIF_arm_orr_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_orr_reg_a1_imm5_0) >> OP_SF_EBII_arm_orr_reg_a1_imm5_0) << OP_SF_EBIF_arm_orr_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.type =
            
                (((context->code32 & OP_SF_MASK_arm_orr_reg_a1_type_0) >> OP_SF_EBII_arm_orr_reg_a1_type_0) << OP_SF_EBIF_arm_orr_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_orr_reg_a1_Rm_0) >> OP_SF_EBII_arm_orr_reg_a1_Rm_0) << OP_SF_EBIF_arm_orr_reg_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_orr_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_orr_reg_a1.Rd == 15)
         || (context->decoded_code->code.arm_orr_reg_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_movt_a1 */
    static int op_parse_arm_movt_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_movt_a1) != OP_FB_arm_movt_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_movt_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_movt_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_movt_a1;
        
            context->decoded_code->code.arm_movt_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_movt_a1_cond_0) >> OP_SF_EBII_arm_movt_a1_cond_0) << OP_SF_EBIF_arm_movt_a1_cond_0);
            
        
            context->decoded_code->code.arm_movt_a1.imm16 =
            
                (((context->code32 & OP_SF_MASK_arm_movt_a1_imm16_0) >> OP_SF_EBII_arm_movt_a1_imm16_0) << OP_SF_EBIF_arm_movt_a1_imm16_0)
            
                | (((context->code32 & OP_SF_MASK_arm_movt_a1_imm16_1) >> OP_SF_EBII_arm_movt_a1_imm16_1) << OP_SF_EBIF_arm_movt_a1_imm16_1);
            
        
            context->decoded_code->code.arm_movt_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_movt_a1_Rd_0) >> OP_SF_EBII_arm_movt_a1_Rd_0) << OP_SF_EBIF_arm_movt_a1_Rd_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_movt_a1.cond == 15)
         || (context->decoded_code->code.arm_movt_a1.Rd == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_lsl_imm_a1 */
    static int op_parse_arm_lsl_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_lsl_imm_a1) != OP_FB_arm_lsl_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_lsl_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_lsl_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_lsl_imm_a1;
        
            context->decoded_code->code.arm_lsl_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_lsl_imm_a1_cond_0) >> OP_SF_EBII_arm_lsl_imm_a1_cond_0) << OP_SF_EBIF_arm_lsl_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_lsl_imm_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_lsl_imm_a1_S_0) >> OP_SF_EBII_arm_lsl_imm_a1_S_0) << OP_SF_EBIF_arm_lsl_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_lsl_imm_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_lsl_imm_a1_Rd_0) >> OP_SF_EBII_arm_lsl_imm_a1_Rd_0) << OP_SF_EBIF_arm_lsl_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_lsl_imm_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_lsl_imm_a1_imm5_0) >> OP_SF_EBII_arm_lsl_imm_a1_imm5_0) << OP_SF_EBIF_arm_lsl_imm_a1_imm5_0);
            
        
            context->decoded_code->code.arm_lsl_imm_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_lsl_imm_a1_Rm_0) >> OP_SF_EBII_arm_lsl_imm_a1_Rm_0) << OP_SF_EBIF_arm_lsl_imm_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_lsl_imm_a1.cond == 15)
         || (context->decoded_code->code.arm_lsl_imm_a1.imm5 == 0)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_lsl_reg_a1 */
    static int op_parse_arm_lsl_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_lsl_reg_a1) != OP_FB_arm_lsl_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_lsl_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_lsl_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_lsl_reg_a1;
        
            context->decoded_code->code.arm_lsl_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_lsl_reg_a1_cond_0) >> OP_SF_EBII_arm_lsl_reg_a1_cond_0) << OP_SF_EBIF_arm_lsl_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_lsl_reg_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_lsl_reg_a1_S_0) >> OP_SF_EBII_arm_lsl_reg_a1_S_0) << OP_SF_EBIF_arm_lsl_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_lsl_reg_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_lsl_reg_a1_Rd_0) >> OP_SF_EBII_arm_lsl_reg_a1_Rd_0) << OP_SF_EBIF_arm_lsl_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_lsl_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_lsl_reg_a1_Rm_0) >> OP_SF_EBII_arm_lsl_reg_a1_Rm_0) << OP_SF_EBIF_arm_lsl_reg_a1_Rm_0);
            
        
            context->decoded_code->code.arm_lsl_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_lsl_reg_a1_Rn_0) >> OP_SF_EBII_arm_lsl_reg_a1_Rn_0) << OP_SF_EBIF_arm_lsl_reg_a1_Rn_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_lsl_reg_a1.cond == 15)
         || (context->decoded_code->code.arm_lsl_reg_a1.Rd == 15)
         || (context->decoded_code->code.arm_lsl_reg_a1.Rm == 15)
         || (context->decoded_code->code.arm_lsl_reg_a1.Rn == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_lsr_imm_a1 */
    static int op_parse_arm_lsr_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_lsr_imm_a1) != OP_FB_arm_lsr_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_lsr_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_lsr_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_lsr_imm_a1;
        
            context->decoded_code->code.arm_lsr_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_lsr_imm_a1_cond_0) >> OP_SF_EBII_arm_lsr_imm_a1_cond_0) << OP_SF_EBIF_arm_lsr_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_lsr_imm_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_lsr_imm_a1_S_0) >> OP_SF_EBII_arm_lsr_imm_a1_S_0) << OP_SF_EBIF_arm_lsr_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_lsr_imm_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_lsr_imm_a1_Rd_0) >> OP_SF_EBII_arm_lsr_imm_a1_Rd_0) << OP_SF_EBIF_arm_lsr_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_lsr_imm_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_lsr_imm_a1_imm5_0) >> OP_SF_EBII_arm_lsr_imm_a1_imm5_0) << OP_SF_EBIF_arm_lsr_imm_a1_imm5_0);
            
        
            context->decoded_code->code.arm_lsr_imm_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_lsr_imm_a1_Rm_0) >> OP_SF_EBII_arm_lsr_imm_a1_Rm_0) << OP_SF_EBIF_arm_lsr_imm_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_lsr_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_lsr_imm_a1.Rd == 15)
         && (context->decoded_code->code.arm_lsr_imm_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_bfc_a1 */
    static int op_parse_arm_bfc_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_bfc_a1) != OP_FB_arm_bfc_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_bfc_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_bfc_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_bfc_a1;
        
            context->decoded_code->code.arm_bfc_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_bfc_a1_cond_0) >> OP_SF_EBII_arm_bfc_a1_cond_0) << OP_SF_EBIF_arm_bfc_a1_cond_0);
            
        
            context->decoded_code->code.arm_bfc_a1.msb =
            
                (((context->code32 & OP_SF_MASK_arm_bfc_a1_msb_0) >> OP_SF_EBII_arm_bfc_a1_msb_0) << OP_SF_EBIF_arm_bfc_a1_msb_0);
            
        
            context->decoded_code->code.arm_bfc_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_bfc_a1_Rd_0) >> OP_SF_EBII_arm_bfc_a1_Rd_0) << OP_SF_EBIF_arm_bfc_a1_Rd_0);
            
        
            context->decoded_code->code.arm_bfc_a1.lsb =
            
                (((context->code32 & OP_SF_MASK_arm_bfc_a1_lsb_0) >> OP_SF_EBII_arm_bfc_a1_lsb_0) << OP_SF_EBIF_arm_bfc_a1_lsb_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_bfc_a1.cond == 15)
         || (context->decoded_code->code.arm_bfc_a1.Rd == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_and_imm_a1 */
    static int op_parse_arm_and_imm_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_and_imm_a1) != OP_FB_arm_and_imm_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_and_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_and_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_and_imm_a1;
        
            context->decoded_code->code.arm_and_imm_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_and_imm_a1_cond_0) >> OP_SF_EBII_arm_and_imm_a1_cond_0) << OP_SF_EBIF_arm_and_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_and_imm_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_and_imm_a1_S_0) >> OP_SF_EBII_arm_and_imm_a1_S_0) << OP_SF_EBIF_arm_and_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_and_imm_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_and_imm_a1_Rn_0) >> OP_SF_EBII_arm_and_imm_a1_Rn_0) << OP_SF_EBIF_arm_and_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_and_imm_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_and_imm_a1_Rd_0) >> OP_SF_EBII_arm_and_imm_a1_Rd_0) << OP_SF_EBIF_arm_and_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_and_imm_a1.imm12 =
            
                (((context->code32 & OP_SF_MASK_arm_and_imm_a1_imm12_0) >> OP_SF_EBII_arm_and_imm_a1_imm12_0) << OP_SF_EBIF_arm_and_imm_a1_imm12_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_and_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_and_imm_a1.Rd == 15)
         && (context->decoded_code->code.arm_and_imm_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_and_reg_a1 */
    static int op_parse_arm_and_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_and_reg_a1) != OP_FB_arm_and_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_and_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_and_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_and_reg_a1;
        
            context->decoded_code->code.arm_and_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_and_reg_a1_cond_0) >> OP_SF_EBII_arm_and_reg_a1_cond_0) << OP_SF_EBIF_arm_and_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_and_reg_a1_S_0) >> OP_SF_EBII_arm_and_reg_a1_S_0) << OP_SF_EBIF_arm_and_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_and_reg_a1_Rn_0) >> OP_SF_EBII_arm_and_reg_a1_Rn_0) << OP_SF_EBIF_arm_and_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_and_reg_a1_Rd_0) >> OP_SF_EBII_arm_and_reg_a1_Rd_0) << OP_SF_EBIF_arm_and_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_and_reg_a1_imm5_0) >> OP_SF_EBII_arm_and_reg_a1_imm5_0) << OP_SF_EBIF_arm_and_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.type =
            
                (((context->code32 & OP_SF_MASK_arm_and_reg_a1_type_0) >> OP_SF_EBII_arm_and_reg_a1_type_0) << OP_SF_EBIF_arm_and_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_and_reg_a1_Rm_0) >> OP_SF_EBII_arm_and_reg_a1_Rm_0) << OP_SF_EBIF_arm_and_reg_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_and_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_and_reg_a1.Rd == 15)
         && (context->decoded_code->code.arm_and_reg_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_utxb_a1 */
    static int op_parse_arm_utxb_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_utxb_a1) != OP_FB_arm_utxb_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_utxb_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_utxb_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_utxb_a1;
        
            context->decoded_code->code.arm_utxb_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_utxb_a1_cond_0) >> OP_SF_EBII_arm_utxb_a1_cond_0) << OP_SF_EBIF_arm_utxb_a1_cond_0);
            
        
            context->decoded_code->code.arm_utxb_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_utxb_a1_Rd_0) >> OP_SF_EBII_arm_utxb_a1_Rd_0) << OP_SF_EBIF_arm_utxb_a1_Rd_0);
            
        
            context->decoded_code->code.arm_utxb_a1.rotate =
            
                (((context->code32 & OP_SF_MASK_arm_utxb_a1_rotate_0) >> OP_SF_EBII_arm_utxb_a1_rotate_0) << OP_SF_EBIF_arm_utxb_a1_rotate_0);
            
        
            context->decoded_code->code.arm_utxb_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_utxb_a1_Rm_0) >> OP_SF_EBII_arm_utxb_a1_Rm_0) << OP_SF_EBIF_arm_utxb_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_utxb_a1.cond == 15)
         || (context->decoded_code->code.arm_utxb_a1.Rd == 15)
         || (context->decoded_code->code.arm_utxb_a1.Rm == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_utxh_a1 */
    static int op_parse_arm_utxh_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_utxh_a1) != OP_FB_arm_utxh_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_utxh_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_utxh_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_utxh_a1;
        
            context->decoded_code->code.arm_utxh_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_utxh_a1_cond_0) >> OP_SF_EBII_arm_utxh_a1_cond_0) << OP_SF_EBIF_arm_utxh_a1_cond_0);
            
        
            context->decoded_code->code.arm_utxh_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_utxh_a1_Rd_0) >> OP_SF_EBII_arm_utxh_a1_Rd_0) << OP_SF_EBIF_arm_utxh_a1_Rd_0);
            
        
            context->decoded_code->code.arm_utxh_a1.rotate =
            
                (((context->code32 & OP_SF_MASK_arm_utxh_a1_rotate_0) >> OP_SF_EBII_arm_utxh_a1_rotate_0) << OP_SF_EBIF_arm_utxh_a1_rotate_0);
            
        
            context->decoded_code->code.arm_utxh_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_utxh_a1_Rm_0) >> OP_SF_EBII_arm_utxh_a1_Rm_0) << OP_SF_EBIF_arm_utxh_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_utxh_a1.cond == 15)
         || (context->decoded_code->code.arm_utxh_a1.Rd == 15)
         || (context->decoded_code->code.arm_utxh_a1.Rm == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_rsb_reg_a1 */
    static int op_parse_arm_rsb_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_rsb_reg_a1) != OP_FB_arm_rsb_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_rsb_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_rsb_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_rsb_reg_a1;
        
            context->decoded_code->code.arm_rsb_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_rsb_reg_a1_cond_0) >> OP_SF_EBII_arm_rsb_reg_a1_cond_0) << OP_SF_EBIF_arm_rsb_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_rsb_reg_a1_S_0) >> OP_SF_EBII_arm_rsb_reg_a1_S_0) << OP_SF_EBIF_arm_rsb_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_rsb_reg_a1_Rn_0) >> OP_SF_EBII_arm_rsb_reg_a1_Rn_0) << OP_SF_EBIF_arm_rsb_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_rsb_reg_a1_Rd_0) >> OP_SF_EBII_arm_rsb_reg_a1_Rd_0) << OP_SF_EBIF_arm_rsb_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_rsb_reg_a1_imm5_0) >> OP_SF_EBII_arm_rsb_reg_a1_imm5_0) << OP_SF_EBIF_arm_rsb_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.type =
            
                (((context->code32 & OP_SF_MASK_arm_rsb_reg_a1_type_0) >> OP_SF_EBII_arm_rsb_reg_a1_type_0) << OP_SF_EBIF_arm_rsb_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_rsb_reg_a1_Rm_0) >> OP_SF_EBII_arm_rsb_reg_a1_Rm_0) << OP_SF_EBIF_arm_rsb_reg_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_rsb_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_rsb_reg_a1.Rd == 15)
         && (context->decoded_code->code.arm_rsb_reg_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_sbc_reg_a1 */
    static int op_parse_arm_sbc_reg_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_sbc_reg_a1) != OP_FB_arm_sbc_reg_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_sbc_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_sbc_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_sbc_reg_a1;
        
            context->decoded_code->code.arm_sbc_reg_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_sbc_reg_a1_cond_0) >> OP_SF_EBII_arm_sbc_reg_a1_cond_0) << OP_SF_EBIF_arm_sbc_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_sbc_reg_a1_S_0) >> OP_SF_EBII_arm_sbc_reg_a1_S_0) << OP_SF_EBIF_arm_sbc_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_sbc_reg_a1_Rn_0) >> OP_SF_EBII_arm_sbc_reg_a1_Rn_0) << OP_SF_EBIF_arm_sbc_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_sbc_reg_a1_Rd_0) >> OP_SF_EBII_arm_sbc_reg_a1_Rd_0) << OP_SF_EBIF_arm_sbc_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.imm5 =
            
                (((context->code32 & OP_SF_MASK_arm_sbc_reg_a1_imm5_0) >> OP_SF_EBII_arm_sbc_reg_a1_imm5_0) << OP_SF_EBIF_arm_sbc_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.type =
            
                (((context->code32 & OP_SF_MASK_arm_sbc_reg_a1_type_0) >> OP_SF_EBII_arm_sbc_reg_a1_type_0) << OP_SF_EBIF_arm_sbc_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_sbc_reg_a1_Rm_0) >> OP_SF_EBII_arm_sbc_reg_a1_Rm_0) << OP_SF_EBIF_arm_sbc_reg_a1_Rm_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_sbc_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_sbc_reg_a1.Rd == 15)
         && (context->decoded_code->code.arm_sbc_reg_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_mul_a1 */
    static int op_parse_arm_mul_a1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_arm_mul_a1) != OP_FB_arm_mul_a1) {
            return 1;
        }
    

        context->optype->code_id = arm_OpCodeId_arm_mul_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mul_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mul_a1;
        
            context->decoded_code->code.arm_mul_a1.cond =
            
                (((context->code32 & OP_SF_MASK_arm_mul_a1_cond_0) >> OP_SF_EBII_arm_mul_a1_cond_0) << OP_SF_EBIF_arm_mul_a1_cond_0);
            
        
            context->decoded_code->code.arm_mul_a1.S =
            
                (((context->code32 & OP_SF_MASK_arm_mul_a1_S_0) >> OP_SF_EBII_arm_mul_a1_S_0) << OP_SF_EBIF_arm_mul_a1_S_0);
            
        
            context->decoded_code->code.arm_mul_a1.Rd =
            
                (((context->code32 & OP_SF_MASK_arm_mul_a1_Rd_0) >> OP_SF_EBII_arm_mul_a1_Rd_0) << OP_SF_EBIF_arm_mul_a1_Rd_0);
            
        
            context->decoded_code->code.arm_mul_a1.Rm =
            
                (((context->code32 & OP_SF_MASK_arm_mul_a1_Rm_0) >> OP_SF_EBII_arm_mul_a1_Rm_0) << OP_SF_EBIF_arm_mul_a1_Rm_0);
            
        
            context->decoded_code->code.arm_mul_a1.Rn =
            
                (((context->code32 & OP_SF_MASK_arm_mul_a1_Rn_0) >> OP_SF_EBII_arm_mul_a1_Rn_0) << OP_SF_EBIF_arm_mul_a1_Rn_0);
            
        

        
        
            if (
                (context->decoded_code->code.arm_mul_a1.cond == 15)
         || (context->decoded_code->code.arm_mul_a1.Rd == 15)
         || (context->decoded_code->code.arm_mul_a1.Rm == 15)
         || (context->decoded_code->code.arm_mul_a1.Rn == 15)
        
            ) {
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
    
        if (op_parse_arm_add_reg_a1(&context) == 0) {
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
    
        if (op_parse_arm_cmp_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_cmn_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_sub_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_sub_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_sub_spimm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_cmp_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mov_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mov_imm_a2(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mvn_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mov_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mvn_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_bl_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_blx_a2(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_blx_reg_a1(&context) == 0) {
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
    
        if (op_parse_arm_strb_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_strh_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_strd_imm_a1(&context) == 0) {
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
    
        if (op_parse_arm_ldr_literal_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_ldrb_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_ldrh_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_ldrd_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_ldr_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_ldrb_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_ldrh_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_pop_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_pop_a2(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_nop_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_msr_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_msr2_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mrs_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_msr2_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mcr_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mcr2_a2(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mrc_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mrc2_a2(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_bic_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_orr_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_orr_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_movt_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_lsl_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_lsl_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_lsr_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_bfc_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_and_imm_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_and_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_utxb_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_utxh_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_rsb_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_sbc_reg_a1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_arm_mul_a1(&context) == 0) {
            return 0;
        }
    

    return 1;
}

arm_OpExecType arm_op_exec_table[arm_OpCodeId_Num] = {
    
	{ 1, arm_op_exec_arm_add_imm_a1 },		/* arm_add_imm_a1 */
    
	{ 1, arm_op_exec_arm_add_reg_a1 },		/* arm_add_reg_a1 */
    
	{ 1, arm_op_exec_arm_add_spimm_a1 },		/* arm_add_spimm_a1 */
    
	{ 1, arm_op_exec_arm_adr_a1 },		/* arm_adr_a1 */
    
	{ 1, arm_op_exec_arm_subs_pclr_a1 },		/* arm_subs_pclr_a1 */
    
	{ 1, arm_op_exec_arm_cmp_imm_a1 },		/* arm_cmp_imm_a1 */
    
	{ 1, arm_op_exec_arm_cmn_imm_a1 },		/* arm_cmn_imm_a1 */
    
	{ 1, arm_op_exec_arm_sub_imm_a1 },		/* arm_sub_imm_a1 */
    
	{ 1, arm_op_exec_arm_sub_reg_a1 },		/* arm_sub_reg_a1 */
    
	{ 1, arm_op_exec_arm_sub_spimm_a1 },		/* arm_sub_spimm_a1 */
    
	{ 1, arm_op_exec_arm_cmp_reg_a1 },		/* arm_cmp_reg_a1 */
    
	{ 1, arm_op_exec_arm_mov_imm_a1 },		/* arm_mov_imm_a1 */
    
	{ 1, arm_op_exec_arm_mov_imm_a2 },		/* arm_mov_imm_a2 */
    
	{ 1, arm_op_exec_arm_mvn_imm_a1 },		/* arm_mvn_imm_a1 */
    
	{ 1, arm_op_exec_arm_mov_reg_a1 },		/* arm_mov_reg_a1 */
    
	{ 1, arm_op_exec_arm_mvn_reg_a1 },		/* arm_mvn_reg_a1 */
    
	{ 1, arm_op_exec_arm_bl_a1 },		/* arm_bl_a1 */
    
	{ 1, arm_op_exec_arm_blx_a2 },		/* arm_blx_a2 */
    
	{ 1, arm_op_exec_arm_blx_reg_a1 },		/* arm_blx_reg_a1 */
    
	{ 1, arm_op_exec_arm_b_a1 },		/* arm_b_a1 */
    
	{ 1, arm_op_exec_arm_bx_a1 },		/* arm_bx_a1 */
    
	{ 1, arm_op_exec_arm_str_imm_a1 },		/* arm_str_imm_a1 */
    
	{ 1, arm_op_exec_arm_strb_imm_a1 },		/* arm_strb_imm_a1 */
    
	{ 1, arm_op_exec_arm_strh_imm_a1 },		/* arm_strh_imm_a1 */
    
	{ 1, arm_op_exec_arm_strd_imm_a1 },		/* arm_strd_imm_a1 */
    
	{ 1, arm_op_exec_arm_strb_reg_a1 },		/* arm_strb_reg_a1 */
    
	{ 1, arm_op_exec_arm_push_a1 },		/* arm_push_a1 */
    
	{ 1, arm_op_exec_arm_push_a2 },		/* arm_push_a2 */
    
	{ 1, arm_op_exec_arm_ldr_imm_a1 },		/* arm_ldr_imm_a1 */
    
	{ 1, arm_op_exec_arm_ldr_literal_a1 },		/* arm_ldr_literal_a1 */
    
	{ 1, arm_op_exec_arm_ldrb_imm_a1 },		/* arm_ldrb_imm_a1 */
    
	{ 1, arm_op_exec_arm_ldrh_imm_a1 },		/* arm_ldrh_imm_a1 */
    
	{ 1, arm_op_exec_arm_ldrd_imm_a1 },		/* arm_ldrd_imm_a1 */
    
	{ 1, arm_op_exec_arm_ldr_reg_a1 },		/* arm_ldr_reg_a1 */
    
	{ 1, arm_op_exec_arm_ldrb_reg_a1 },		/* arm_ldrb_reg_a1 */
    
	{ 1, arm_op_exec_arm_ldrh_reg_a1 },		/* arm_ldrh_reg_a1 */
    
	{ 1, arm_op_exec_arm_pop_a1 },		/* arm_pop_a1 */
    
	{ 1, arm_op_exec_arm_pop_a2 },		/* arm_pop_a2 */
    
	{ 1, arm_op_exec_arm_nop_a1 },		/* arm_nop_a1 */
    
	{ 1, arm_op_exec_arm_msr_imm_a1 },		/* arm_msr_imm_a1 */
    
	{ 1, arm_op_exec_arm_msr2_imm_a1 },		/* arm_msr2_imm_a1 */
    
	{ 1, arm_op_exec_arm_mrs_a1 },		/* arm_mrs_a1 */
    
	{ 1, arm_op_exec_arm_msr2_reg_a1 },		/* arm_msr2_reg_a1 */
    
	{ 1, arm_op_exec_arm_mcr_a1 },		/* arm_mcr_a1 */
    
	{ 1, arm_op_exec_arm_mcr2_a2 },		/* arm_mcr2_a2 */
    
	{ 1, arm_op_exec_arm_mrc_a1 },		/* arm_mrc_a1 */
    
	{ 1, arm_op_exec_arm_mrc2_a2 },		/* arm_mrc2_a2 */
    
	{ 1, arm_op_exec_arm_bic_imm_a1 },		/* arm_bic_imm_a1 */
    
	{ 1, arm_op_exec_arm_orr_imm_a1 },		/* arm_orr_imm_a1 */
    
	{ 1, arm_op_exec_arm_orr_reg_a1 },		/* arm_orr_reg_a1 */
    
	{ 1, arm_op_exec_arm_movt_a1 },		/* arm_movt_a1 */
    
	{ 1, arm_op_exec_arm_lsl_imm_a1 },		/* arm_lsl_imm_a1 */
    
	{ 1, arm_op_exec_arm_lsl_reg_a1 },		/* arm_lsl_reg_a1 */
    
	{ 1, arm_op_exec_arm_lsr_imm_a1 },		/* arm_lsr_imm_a1 */
    
	{ 1, arm_op_exec_arm_bfc_a1 },		/* arm_bfc_a1 */
    
	{ 1, arm_op_exec_arm_and_imm_a1 },		/* arm_and_imm_a1 */
    
	{ 1, arm_op_exec_arm_and_reg_a1 },		/* arm_and_reg_a1 */
    
	{ 1, arm_op_exec_arm_utxb_a1 },		/* arm_utxb_a1 */
    
	{ 1, arm_op_exec_arm_utxh_a1 },		/* arm_utxh_a1 */
    
	{ 1, arm_op_exec_arm_rsb_reg_a1 },		/* arm_rsb_reg_a1 */
    
	{ 1, arm_op_exec_arm_sbc_reg_a1 },		/* arm_sbc_reg_a1 */
    
	{ 1, arm_op_exec_arm_mul_a1 },		/* arm_mul_a1 */
    
};