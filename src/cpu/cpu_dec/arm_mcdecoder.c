#include "arm_mcdecoder.h"

#include <stdbool.h>

/* types */

typedef struct {
    arm_uint16 *code;
    arm_OpDecodedCodeType *decoded_code;
    arm_OperationCodeType *optype;
    arm_uint16 code16x1;
    arm_uint32 code16x2;
    arm_uint32 code32x1;
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
        
    

    /* arm_adc_reg_a1 */
    #define OP_FB_MASK_arm_adc_reg_a1 (0x0fe00010l) /* fixed bits mask */
    #define OP_FB_arm_adc_reg_a1 (0x00a00000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_adc_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_adc_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_adc_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_adc_reg_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_adc_reg_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_adc_reg_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_adc_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_adc_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_adc_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_adc_reg_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_adc_reg_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_adc_reg_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_adc_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_adc_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_adc_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_adc_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_adc_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_adc_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_adc_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_adc_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_adc_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_str_reg_a1 */
    #define OP_FB_MASK_arm_str_reg_a1 (0x0e500010l) /* fixed bits mask */
    #define OP_FB_arm_str_reg_a1 (0x06000000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_str_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_str_reg_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_reg_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_reg_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_str_reg_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_reg_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_reg_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_str_reg_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_reg_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_reg_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_str_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_str_reg_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_str_reg_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_reg_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_str_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_str_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_str_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_str_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_str_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_str_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_str_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_stmfd_a1 */
    #define OP_FB_MASK_arm_stmfd_a1 (0x0fd00000l) /* fixed bits mask */
    #define OP_FB_arm_stmfd_a1 (0x09000000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_stmfd_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_stmfd_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_stmfd_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_stmfd_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_stmfd_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_stmfd_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_stmfd_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_stmfd_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_stmfd_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'register_list' */
            #define OP_SF_MASK_arm_stmfd_a1_register_list_0 (0x0000ffffl) /* subfield mask */
            #define OP_SF_EBII_arm_stmfd_a1_register_list_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_stmfd_a1_register_list_0 (0) /* subfield end bit position in field */
        
    

    /* arm_stm_a1 */
    #define OP_FB_MASK_arm_stm_a1 (0x0fd00000l) /* fixed bits mask */
    #define OP_FB_arm_stm_a1 (0x08800000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_stm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_stm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_stm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_stm_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_stm_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_stm_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_stm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_stm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_stm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'register_list' */
            #define OP_SF_MASK_arm_stm_a1_register_list_0 (0x0000ffffl) /* subfield mask */
            #define OP_SF_EBII_arm_stm_a1_register_list_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_stm_a1_register_list_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_ldrsh_imm_a1 */
    #define OP_FB_MASK_arm_ldrsh_imm_a1 (0x0e5000f0l) /* fixed bits mask */
    #define OP_FB_arm_ldrsh_imm_a1 (0x005000f0l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_ldrsh_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrsh_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrsh_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_ldrsh_imm_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrsh_imm_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrsh_imm_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_ldrsh_imm_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrsh_imm_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrsh_imm_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_ldrsh_imm_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrsh_imm_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrsh_imm_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_ldrsh_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrsh_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrsh_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_ldrsh_imm_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrsh_imm_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrsh_imm_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_ldrsh_imm_a1_imm8_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_ldrsh_imm_a1_imm8_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrsh_imm_a1_imm8_0 (4) /* subfield end bit position in field */
        
            /* 1th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_ldrsh_imm_a1_imm8_1 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_ldrsh_imm_a1_imm8_1 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldrsh_imm_a1_imm8_1 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_ldm_a1 */
    #define OP_FB_MASK_arm_ldm_a1 (0x0fd00000l) /* fixed bits mask */
    #define OP_FB_arm_ldm_a1 (0x08900000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_ldm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_ldm_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldm_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldm_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_ldm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_ldm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'register_list' */
            #define OP_SF_MASK_arm_ldm_a1_register_list_0 (0x0000ffffl) /* subfield mask */
            #define OP_SF_EBII_arm_ldm_a1_register_list_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_ldm_a1_register_list_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_lsr_reg_a1 */
    #define OP_FB_MASK_arm_lsr_reg_a1 (0x0fef00f0l) /* fixed bits mask */
    #define OP_FB_arm_lsr_reg_a1 (0x01a00030l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_lsr_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsr_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsr_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_lsr_reg_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsr_reg_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsr_reg_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_lsr_reg_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_lsr_reg_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsr_reg_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_lsr_reg_a1_Rm_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_lsr_reg_a1_Rm_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsr_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_lsr_reg_a1_Rn_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_lsr_reg_a1_Rn_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_lsr_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_uxtb_a1 */
    #define OP_FB_MASK_arm_uxtb_a1 (0x0fff03f0l) /* fixed bits mask */
    #define OP_FB_arm_uxtb_a1 (0x06ef0070l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_uxtb_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_uxtb_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_uxtb_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_uxtb_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_uxtb_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_uxtb_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'rotate' */
            #define OP_SF_MASK_arm_uxtb_a1_rotate_0 (0x00000c00l) /* subfield mask */
            #define OP_SF_EBII_arm_uxtb_a1_rotate_0 (10) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_uxtb_a1_rotate_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_uxtb_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_uxtb_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_uxtb_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_uxth_a1 */
    #define OP_FB_MASK_arm_uxth_a1 (0x0fff03f0l) /* fixed bits mask */
    #define OP_FB_arm_uxth_a1 (0x06ff0070l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_uxth_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_uxth_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_uxth_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_uxth_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_uxth_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_uxth_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'rotate' */
            #define OP_SF_MASK_arm_uxth_a1_rotate_0 (0x00000c00l) /* subfield mask */
            #define OP_SF_EBII_arm_uxth_a1_rotate_0 (10) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_uxth_a1_rotate_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_uxth_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_uxth_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_uxth_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_rsb_imm_a1 */
    #define OP_FB_MASK_arm_rsb_imm_a1 (0x0fe00000l) /* fixed bits mask */
    #define OP_FB_arm_rsb_imm_a1 (0x02600000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_rsb_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_rsb_imm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_imm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_imm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_rsb_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_rsb_imm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_imm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_imm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_rsb_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_rsb_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rsb_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

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
        
    

    /* arm_smmul_a1 */
    #define OP_FB_MASK_arm_smmul_a1 (0x0ff0f0d0l) /* fixed bits mask */
    #define OP_FB_arm_smmul_a1 (0x0750f010l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_smmul_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_smmul_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_smmul_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_smmul_a1_Rd_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_smmul_a1_Rd_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_smmul_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_smmul_a1_Rm_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_smmul_a1_Rm_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_smmul_a1_Rm_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'R' */
            #define OP_SF_MASK_arm_smmul_a1_R_0 (0x00000020l) /* subfield mask */
            #define OP_SF_EBII_arm_smmul_a1_R_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_smmul_a1_R_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_smmul_a1_Rn_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_smmul_a1_Rn_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_smmul_a1_Rn_0 (0) /* subfield end bit position in field */
        
    

    /* arm_smull_a1 */
    #define OP_FB_MASK_arm_smull_a1 (0x0fe000f0l) /* fixed bits mask */
    #define OP_FB_arm_smull_a1 (0x00c00090l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_smull_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_smull_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_smull_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_smull_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_smull_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_smull_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'RdHi' */
            #define OP_SF_MASK_arm_smull_a1_RdHi_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_smull_a1_RdHi_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_smull_a1_RdHi_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'RdLo' */
            #define OP_SF_MASK_arm_smull_a1_RdLo_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_smull_a1_RdLo_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_smull_a1_RdLo_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_smull_a1_Rm_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_smull_a1_Rm_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_smull_a1_Rm_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_smull_a1_Rn_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_smull_a1_Rn_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_smull_a1_Rn_0 (0) /* subfield end bit position in field */
        
    

    /* arm_tst_imm_a1 */
    #define OP_FB_MASK_arm_tst_imm_a1 (0x0ff0f000l) /* fixed bits mask */
    #define OP_FB_arm_tst_imm_a1 (0x03100000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_tst_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_tst_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_tst_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_tst_imm_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_tst_imm_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_tst_imm_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_arm_tst_imm_a1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_arm_tst_imm_a1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_tst_imm_a1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* arm_tst_reg_a1 */
    #define OP_FB_MASK_arm_tst_reg_a1 (0x0ff0f010l) /* fixed bits mask */
    #define OP_FB_arm_tst_reg_a1 (0x01100000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_tst_reg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_tst_reg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_tst_reg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_tst_reg_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_tst_reg_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_tst_reg_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_tst_reg_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_tst_reg_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_tst_reg_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'type' */
            #define OP_SF_MASK_arm_tst_reg_a1_type_0 (0x00000060l) /* subfield mask */
            #define OP_SF_EBII_arm_tst_reg_a1_type_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_tst_reg_a1_type_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_tst_reg_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_tst_reg_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_tst_reg_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_sxtb_a1 */
    #define OP_FB_MASK_arm_sxtb_a1 (0x0fff03f0l) /* fixed bits mask */
    #define OP_FB_arm_sxtb_a1 (0x06af0070l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_sxtb_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_sxtb_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sxtb_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_sxtb_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_sxtb_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sxtb_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'rotate' */
            #define OP_SF_MASK_arm_sxtb_a1_rotate_0 (0x00000c00l) /* subfield mask */
            #define OP_SF_EBII_arm_sxtb_a1_rotate_0 (10) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sxtb_a1_rotate_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_sxtb_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_sxtb_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sxtb_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_sxth_a1 */
    #define OP_FB_MASK_arm_sxth_a1 (0x0fff03f0l) /* fixed bits mask */
    #define OP_FB_arm_sxth_a1 (0x06bf0070l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_sxth_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_sxth_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sxth_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_sxth_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_sxth_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sxth_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'rotate' */
            #define OP_SF_MASK_arm_sxth_a1_rotate_0 (0x00000c00l) /* subfield mask */
            #define OP_SF_EBII_arm_sxth_a1_rotate_0 (10) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sxth_a1_rotate_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_sxth_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_sxth_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_sxth_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_asr_imm_a1 */
    #define OP_FB_MASK_arm_asr_imm_a1 (0x0fef0070l) /* fixed bits mask */
    #define OP_FB_arm_asr_imm_a1 (0x01a00040l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_asr_imm_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_asr_imm_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_asr_imm_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_arm_asr_imm_a1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_asr_imm_a1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_asr_imm_a1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_asr_imm_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_asr_imm_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_asr_imm_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm5' */
            #define OP_SF_MASK_arm_asr_imm_a1_imm5_0 (0x00000f80l) /* subfield mask */
            #define OP_SF_EBII_arm_asr_imm_a1_imm5_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_asr_imm_a1_imm5_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_asr_imm_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_asr_imm_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_asr_imm_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_srs_a1 */
    #define OP_FB_MASK_arm_srs_a1 (0xfe5fffe0l) /* fixed bits mask */
    #define OP_FB_arm_srs_a1 (0xf84d0500l) /* fixed bits */
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_srs_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_srs_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_srs_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_srs_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_srs_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_srs_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_srs_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_srs_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_srs_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'mode' */
            #define OP_SF_MASK_arm_srs_a1_mode_0 (0x0000001fl) /* subfield mask */
            #define OP_SF_EBII_arm_srs_a1_mode_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_srs_a1_mode_0 (0) /* subfield end bit position in field */
        
    

    /* arm_clz_a1 */
    #define OP_FB_MASK_arm_clz_a1 (0x0fff0ff0l) /* fixed bits mask */
    #define OP_FB_arm_clz_a1 (0x016f0f10l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_clz_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_clz_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_clz_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_arm_clz_a1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_clz_a1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_clz_a1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rm' */
            #define OP_SF_MASK_arm_clz_a1_Rm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_clz_a1_Rm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_clz_a1_Rm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_rfe_a1 */
    #define OP_FB_MASK_arm_rfe_a1 (0xfe50ffffl) /* fixed bits mask */
    #define OP_FB_arm_rfe_a1 (0xf8100a00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'P' */
            #define OP_SF_MASK_arm_rfe_a1_P_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_rfe_a1_P_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rfe_a1_P_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_rfe_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_rfe_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rfe_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'W' */
            #define OP_SF_MASK_arm_rfe_a1_W_0 (0x00200000l) /* subfield mask */
            #define OP_SF_EBII_arm_rfe_a1_W_0 (21) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rfe_a1_W_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_rfe_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_rfe_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_rfe_a1_Rn_0 (0) /* subfield end bit position in field */
        
    

    /* arm_wfi_a1 */
    #define OP_FB_MASK_arm_wfi_a1 (0x0fffffffl) /* fixed bits mask */
    #define OP_FB_arm_wfi_a1 (0x0320f003l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_wfi_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_wfi_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_wfi_a1_cond_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vadd_freg_a2 */
    #define OP_FB_MASK_arm_vadd_freg_a2 (0x0fb00e50l) /* fixed bits mask */
    #define OP_FB_arm_vadd_freg_a2 (0x0e300a00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vadd_freg_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vadd_freg_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vadd_freg_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vadd_freg_a2_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vadd_freg_a2_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vadd_freg_a2_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vn' */
            #define OP_SF_MASK_arm_vadd_freg_a2_Vn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_vadd_freg_a2_Vn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vadd_freg_a2_Vn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vadd_freg_a2_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vadd_freg_a2_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vadd_freg_a2_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'sz' */
            #define OP_SF_MASK_arm_vadd_freg_a2_sz_0 (0x00000100l) /* subfield mask */
            #define OP_SF_EBII_arm_vadd_freg_a2_sz_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vadd_freg_a2_sz_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'N' */
            #define OP_SF_MASK_arm_vadd_freg_a2_N_0 (0x00000080l) /* subfield mask */
            #define OP_SF_EBII_arm_vadd_freg_a2_N_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vadd_freg_a2_N_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'M' */
            #define OP_SF_MASK_arm_vadd_freg_a2_M_0 (0x00000020l) /* subfield mask */
            #define OP_SF_EBII_arm_vadd_freg_a2_M_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vadd_freg_a2_M_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vm' */
            #define OP_SF_MASK_arm_vadd_freg_a2_Vm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_vadd_freg_a2_Vm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vadd_freg_a2_Vm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vldr_a1 */
    #define OP_FB_MASK_arm_vldr_a1 (0x0f300f00l) /* fixed bits mask */
    #define OP_FB_arm_vldr_a1 (0x0d100b00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vldr_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_vldr_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vldr_a1_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a1_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a1_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_vldr_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vldr_a1_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a1_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a1_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_vldr_a1_imm8_0 (0x000000ffl) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a1_imm8_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a1_imm8_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vldr_a2 */
    #define OP_FB_MASK_arm_vldr_a2 (0x0f300f00l) /* fixed bits mask */
    #define OP_FB_arm_vldr_a2 (0x0d100a00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vldr_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_vldr_a2_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a2_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a2_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vldr_a2_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a2_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a2_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_vldr_a2_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a2_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a2_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vldr_a2_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a2_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a2_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_vldr_a2_imm8_0 (0x000000ffl) /* subfield mask */
            #define OP_SF_EBII_arm_vldr_a2_imm8_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vldr_a2_imm8_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vcvt_df_a1 */
    #define OP_FB_MASK_arm_vcvt_df_a1 (0x0fbf0ed0l) /* fixed bits mask */
    #define OP_FB_arm_vcvt_df_a1 (0x0eb70ac0l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vcvt_df_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_df_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_df_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vcvt_df_a1_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_df_a1_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_df_a1_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vcvt_df_a1_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_df_a1_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_df_a1_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'sz' */
            #define OP_SF_MASK_arm_vcvt_df_a1_sz_0 (0x00000100l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_df_a1_sz_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_df_a1_sz_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'M' */
            #define OP_SF_MASK_arm_vcvt_df_a1_M_0 (0x00000020l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_df_a1_M_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_df_a1_M_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vm' */
            #define OP_SF_MASK_arm_vcvt_df_a1_Vm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_df_a1_Vm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_df_a1_Vm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vcvt_fi_a1 */
    #define OP_FB_MASK_arm_vcvt_fi_a1 (0x0fb80e50l) /* fixed bits mask */
    #define OP_FB_arm_vcvt_fi_a1 (0x0eb80a40l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vcvt_fi_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_fi_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_fi_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vcvt_fi_a1_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_fi_a1_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_fi_a1_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'opc2' */
            #define OP_SF_MASK_arm_vcvt_fi_a1_opc2_0 (0x00070000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_fi_a1_opc2_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_fi_a1_opc2_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vcvt_fi_a1_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_fi_a1_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_fi_a1_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'sz' */
            #define OP_SF_MASK_arm_vcvt_fi_a1_sz_0 (0x00000100l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_fi_a1_sz_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_fi_a1_sz_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'op' */
            #define OP_SF_MASK_arm_vcvt_fi_a1_op_0 (0x00000080l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_fi_a1_op_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_fi_a1_op_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'M' */
            #define OP_SF_MASK_arm_vcvt_fi_a1_M_0 (0x00000020l) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_fi_a1_M_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_fi_a1_M_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vm' */
            #define OP_SF_MASK_arm_vcvt_fi_a1_Vm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_vcvt_fi_a1_Vm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcvt_fi_a1_Vm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vstr_a1 */
    #define OP_FB_MASK_arm_vstr_a1 (0x0f300f00l) /* fixed bits mask */
    #define OP_FB_arm_vstr_a1 (0x0d000b00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vstr_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_vstr_a1_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a1_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a1_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vstr_a1_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a1_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a1_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_vstr_a1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vstr_a1_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a1_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a1_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_vstr_a1_imm8_0 (0x000000ffl) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a1_imm8_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a1_imm8_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vstr_a2 */
    #define OP_FB_MASK_arm_vstr_a2 (0x0f300f00l) /* fixed bits mask */
    #define OP_FB_arm_vstr_a2 (0x0d000a00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vstr_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'U' */
            #define OP_SF_MASK_arm_vstr_a2_U_0 (0x00800000l) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a2_U_0 (23) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a2_U_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vstr_a2_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a2_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a2_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_arm_vstr_a2_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a2_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a2_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vstr_a2_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a2_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a2_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_vstr_a2_imm8_0 (0x000000ffl) /* subfield mask */
            #define OP_SF_EBII_arm_vstr_a2_imm8_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vstr_a2_imm8_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vcmp_a1 */
    #define OP_FB_MASK_arm_vcmp_a1 (0x0fbf0e50l) /* fixed bits mask */
    #define OP_FB_arm_vcmp_a1 (0x0eb40a40l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vcmp_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vcmp_a1_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a1_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a1_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vcmp_a1_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a1_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a1_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'sz' */
            #define OP_SF_MASK_arm_vcmp_a1_sz_0 (0x00000100l) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a1_sz_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a1_sz_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'E' */
            #define OP_SF_MASK_arm_vcmp_a1_E_0 (0x00000080l) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a1_E_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a1_E_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'M' */
            #define OP_SF_MASK_arm_vcmp_a1_M_0 (0x00000020l) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a1_M_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a1_M_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vm' */
            #define OP_SF_MASK_arm_vcmp_a1_Vm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a1_Vm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a1_Vm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vcmp_a2 */
    #define OP_FB_MASK_arm_vcmp_a2 (0x0fbf0e7fl) /* fixed bits mask */
    #define OP_FB_arm_vcmp_a2 (0x0eb50a40l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vcmp_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vcmp_a2_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a2_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a2_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vcmp_a2_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a2_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a2_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'sz' */
            #define OP_SF_MASK_arm_vcmp_a2_sz_0 (0x00000100l) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a2_sz_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a2_sz_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'E' */
            #define OP_SF_MASK_arm_vcmp_a2_E_0 (0x00000080l) /* subfield mask */
            #define OP_SF_EBII_arm_vcmp_a2_E_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vcmp_a2_E_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vmrs_a1 */
    #define OP_FB_MASK_arm_vmrs_a1 (0x0fff0fffl) /* fixed bits mask */
    #define OP_FB_arm_vmrs_a1 (0x0ef10a10l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vmrs_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmrs_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmrs_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_vmrs_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmrs_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmrs_a1_Rt_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vmov_imm_a1 */
    #define OP_FB_MASK_arm_vmov_imm_a1 (0xfeb80090l) /* fixed bits mask */
    #define OP_FB_arm_vmov_imm_a1 (0xf2800010l) /* fixed bits */
    
        
            /* 0th subfield of the field 'i' */
            #define OP_SF_MASK_arm_vmov_imm_a1_i_0 (0x01000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a1_i_0 (24) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a1_i_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vmov_imm_a1_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a1_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a1_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm7' */
            #define OP_SF_MASK_arm_vmov_imm_a1_imm7_0 (0x00070000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a1_imm7_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a1_imm7_0 (4) /* subfield end bit position in field */
        
            /* 1th subfield of the field 'imm7' */
            #define OP_SF_MASK_arm_vmov_imm_a1_imm7_1 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a1_imm7_1 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a1_imm7_1 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vmov_imm_a1_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a1_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a1_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'cmode' */
            #define OP_SF_MASK_arm_vmov_imm_a1_cmode_0 (0x00000f00l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a1_cmode_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a1_cmode_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Q' */
            #define OP_SF_MASK_arm_vmov_imm_a1_Q_0 (0x00000040l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a1_Q_0 (6) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a1_Q_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'op' */
            #define OP_SF_MASK_arm_vmov_imm_a1_op_0 (0x00000020l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a1_op_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a1_op_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vmov_imm_a2 */
    #define OP_FB_MASK_arm_vmov_imm_a2 (0x0fb00ef0l) /* fixed bits mask */
    #define OP_FB_arm_vmov_imm_a2 (0x0eb00a00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vmov_imm_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vmov_imm_a2_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a2_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a2_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_vmov_imm_a2_imm8_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a2_imm8_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a2_imm8_0 (4) /* subfield end bit position in field */
        
            /* 1th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_vmov_imm_a2_imm8_1 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a2_imm8_1 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a2_imm8_1 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vmov_imm_a2_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a2_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a2_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'sz' */
            #define OP_SF_MASK_arm_vmov_imm_a2_sz_0 (0x00000100l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_imm_a2_sz_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_imm_a2_sz_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vmov_sreg_a1 */
    #define OP_FB_MASK_arm_vmov_sreg_a1 (0x0fe00f7fl) /* fixed bits mask */
    #define OP_FB_arm_vmov_sreg_a1 (0x0e000a10l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vmov_sreg_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_sreg_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_sreg_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'op' */
            #define OP_SF_MASK_arm_vmov_sreg_a1_op_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_sreg_a1_op_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_sreg_a1_op_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vn' */
            #define OP_SF_MASK_arm_vmov_sreg_a1_Vn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_sreg_a1_Vn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_sreg_a1_Vn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rt' */
            #define OP_SF_MASK_arm_vmov_sreg_a1_Rt_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_sreg_a1_Rt_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_sreg_a1_Rt_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'N' */
            #define OP_SF_MASK_arm_vmov_sreg_a1_N_0 (0x00000080l) /* subfield mask */
            #define OP_SF_EBII_arm_vmov_sreg_a1_N_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmov_sreg_a1_N_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vsub_freg_a2 */
    #define OP_FB_MASK_arm_vsub_freg_a2 (0x0fb00e50l) /* fixed bits mask */
    #define OP_FB_arm_vsub_freg_a2 (0x0e300a40l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vsub_freg_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vsub_freg_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vsub_freg_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vsub_freg_a2_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vsub_freg_a2_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vsub_freg_a2_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vn' */
            #define OP_SF_MASK_arm_vsub_freg_a2_Vn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_vsub_freg_a2_Vn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vsub_freg_a2_Vn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vsub_freg_a2_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vsub_freg_a2_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vsub_freg_a2_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'sz' */
            #define OP_SF_MASK_arm_vsub_freg_a2_sz_0 (0x00000100l) /* subfield mask */
            #define OP_SF_EBII_arm_vsub_freg_a2_sz_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vsub_freg_a2_sz_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'N' */
            #define OP_SF_MASK_arm_vsub_freg_a2_N_0 (0x00000080l) /* subfield mask */
            #define OP_SF_EBII_arm_vsub_freg_a2_N_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vsub_freg_a2_N_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'M' */
            #define OP_SF_MASK_arm_vsub_freg_a2_M_0 (0x00000020l) /* subfield mask */
            #define OP_SF_EBII_arm_vsub_freg_a2_M_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vsub_freg_a2_M_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vm' */
            #define OP_SF_MASK_arm_vsub_freg_a2_Vm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_vsub_freg_a2_Vm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vsub_freg_a2_Vm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vmul_freg_a2 */
    #define OP_FB_MASK_arm_vmul_freg_a2 (0x0fb00e50l) /* fixed bits mask */
    #define OP_FB_arm_vmul_freg_a2 (0x0e200a00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vmul_freg_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmul_freg_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmul_freg_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vmul_freg_a2_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmul_freg_a2_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmul_freg_a2_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vn' */
            #define OP_SF_MASK_arm_vmul_freg_a2_Vn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmul_freg_a2_Vn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmul_freg_a2_Vn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vmul_freg_a2_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vmul_freg_a2_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmul_freg_a2_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'sz' */
            #define OP_SF_MASK_arm_vmul_freg_a2_sz_0 (0x00000100l) /* subfield mask */
            #define OP_SF_EBII_arm_vmul_freg_a2_sz_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmul_freg_a2_sz_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'N' */
            #define OP_SF_MASK_arm_vmul_freg_a2_N_0 (0x00000080l) /* subfield mask */
            #define OP_SF_EBII_arm_vmul_freg_a2_N_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmul_freg_a2_N_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'M' */
            #define OP_SF_MASK_arm_vmul_freg_a2_M_0 (0x00000020l) /* subfield mask */
            #define OP_SF_EBII_arm_vmul_freg_a2_M_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmul_freg_a2_M_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vm' */
            #define OP_SF_MASK_arm_vmul_freg_a2_Vm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_vmul_freg_a2_Vm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vmul_freg_a2_Vm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vdiv_freg_a2 */
    #define OP_FB_MASK_arm_vdiv_freg_a2 (0x0fb00e50l) /* fixed bits mask */
    #define OP_FB_arm_vdiv_freg_a2 (0x0e800a00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vdiv_freg_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vdiv_freg_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vdiv_freg_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vdiv_freg_a2_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vdiv_freg_a2_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vdiv_freg_a2_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vn' */
            #define OP_SF_MASK_arm_vdiv_freg_a2_Vn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_arm_vdiv_freg_a2_Vn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vdiv_freg_a2_Vn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vdiv_freg_a2_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vdiv_freg_a2_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vdiv_freg_a2_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'sz' */
            #define OP_SF_MASK_arm_vdiv_freg_a2_sz_0 (0x00000100l) /* subfield mask */
            #define OP_SF_EBII_arm_vdiv_freg_a2_sz_0 (8) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vdiv_freg_a2_sz_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'N' */
            #define OP_SF_MASK_arm_vdiv_freg_a2_N_0 (0x00000080l) /* subfield mask */
            #define OP_SF_EBII_arm_vdiv_freg_a2_N_0 (7) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vdiv_freg_a2_N_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'M' */
            #define OP_SF_MASK_arm_vdiv_freg_a2_M_0 (0x00000020l) /* subfield mask */
            #define OP_SF_EBII_arm_vdiv_freg_a2_M_0 (5) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vdiv_freg_a2_M_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vm' */
            #define OP_SF_MASK_arm_vdiv_freg_a2_Vm_0 (0x0000000fl) /* subfield mask */
            #define OP_SF_EBII_arm_vdiv_freg_a2_Vm_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vdiv_freg_a2_Vm_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vpush_a1 */
    #define OP_FB_MASK_arm_vpush_a1 (0x0fbf0f00l) /* fixed bits mask */
    #define OP_FB_arm_vpush_a1 (0x0d2d0b00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vpush_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpush_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpush_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vpush_a1_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpush_a1_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpush_a1_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vpush_a1_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpush_a1_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpush_a1_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_vpush_a1_imm8_0 (0x000000ffl) /* subfield mask */
            #define OP_SF_EBII_arm_vpush_a1_imm8_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpush_a1_imm8_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vpush_a2 */
    #define OP_FB_MASK_arm_vpush_a2 (0x0fbf0f00l) /* fixed bits mask */
    #define OP_FB_arm_vpush_a2 (0x0d2d0a00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vpush_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpush_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpush_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vpush_a2_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpush_a2_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpush_a2_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vpush_a2_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpush_a2_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpush_a2_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_vpush_a2_imm8_0 (0x000000ffl) /* subfield mask */
            #define OP_SF_EBII_arm_vpush_a2_imm8_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpush_a2_imm8_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vpop_a1 */
    #define OP_FB_MASK_arm_vpop_a1 (0x0fbf0f00l) /* fixed bits mask */
    #define OP_FB_arm_vpop_a1 (0x0cbd0b00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vpop_a1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpop_a1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpop_a1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vpop_a1_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpop_a1_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpop_a1_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vpop_a1_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpop_a1_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpop_a1_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_vpop_a1_imm8_0 (0x000000ffl) /* subfield mask */
            #define OP_SF_EBII_arm_vpop_a1_imm8_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpop_a1_imm8_0 (0) /* subfield end bit position in field */
        
    

    /* arm_vpop_a2 */
    #define OP_FB_MASK_arm_vpop_a2 (0x0fbf0f00l) /* fixed bits mask */
    #define OP_FB_arm_vpop_a2 (0x0cbd0a00l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_arm_vpop_a2_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpop_a2_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpop_a2_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'D' */
            #define OP_SF_MASK_arm_vpop_a2_D_0 (0x00400000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpop_a2_D_0 (22) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpop_a2_D_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Vd' */
            #define OP_SF_MASK_arm_vpop_a2_Vd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_arm_vpop_a2_Vd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpop_a2_Vd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm8' */
            #define OP_SF_MASK_arm_vpop_a2_imm8_0 (0x000000ffl) /* subfield mask */
            #define OP_SF_EBII_arm_vpop_a2_imm8_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_arm_vpop_a2_imm8_0 (0) /* subfield end bit position in field */
        
    


/* macros */
#define BIT_ELEMENT(value, element_index) (((value) & (1 << (element_index))) >> element_index)

/* function declarations */
static arm_uint32 setbit_count(arm_uint32 value);

        static int decision_node_code32x1_0(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_1(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_2(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_3(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_4(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_5(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_6(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_7(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_8(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_9(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_10(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_11(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_12(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_13(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_14(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_15(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_16(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_17(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_18(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_19(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_20(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_21(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_22(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_23(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_24(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_25(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_26(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_27(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_28(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_29(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_30(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_31(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_32(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_33(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_34(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_35(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_36(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_37(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_38(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_39(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_40(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_41(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_42(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_43(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_44(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_45(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_46(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_47(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_48(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_49(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_50(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_51(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_52(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_53(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_54(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_55(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_56(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_57(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_58(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_59(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_60(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_61(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_62(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_63(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_64(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_65(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_66(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_67(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_68(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_69(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_70(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_71(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_72(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_73(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_74(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_75(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_76(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_77(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_78(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_79(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_80(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_81(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_82(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_83(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_84(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_85(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_86(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_87(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_88(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_89(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_90(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_91(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_92(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_93(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_94(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_95(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_96(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_97(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_98(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_99(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_100(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_101(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_102(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_103(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_104(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_105(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_106(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_107(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_108(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_109(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_110(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_111(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_112(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_113(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_114(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_115(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_116(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_117(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_118(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_119(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_120(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_121(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_122(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_123(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_124(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_125(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_126(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_127(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_128(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_129(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_130(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_131(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_132(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_133(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_134(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_135(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_136(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_137(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_138(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_139(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_140(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_141(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_142(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_143(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_144(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_145(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_146(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_147(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_148(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_149(OpDecodeContext *context, arm_uint32 code);
        static int decision_node_code32x1_150(OpDecodeContext *context, arm_uint32 code);

    static int op_parse_arm_add_imm_a1(OpDecodeContext *context);
    static int op_parse_arm_add_reg_a1(OpDecodeContext *context);
    static int op_parse_arm_adc_reg_a1(OpDecodeContext *context);
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
    static int op_parse_arm_str_reg_a1(OpDecodeContext *context);
    static int op_parse_arm_strb_reg_a1(OpDecodeContext *context);
    static int op_parse_arm_push_a1(OpDecodeContext *context);
    static int op_parse_arm_push_a2(OpDecodeContext *context);
    static int op_parse_arm_stmfd_a1(OpDecodeContext *context);
    static int op_parse_arm_stm_a1(OpDecodeContext *context);
    static int op_parse_arm_ldr_imm_a1(OpDecodeContext *context);
    static int op_parse_arm_ldr_literal_a1(OpDecodeContext *context);
    static int op_parse_arm_ldrb_imm_a1(OpDecodeContext *context);
    static int op_parse_arm_ldrh_imm_a1(OpDecodeContext *context);
    static int op_parse_arm_ldrd_imm_a1(OpDecodeContext *context);
    static int op_parse_arm_ldr_reg_a1(OpDecodeContext *context);
    static int op_parse_arm_ldrb_reg_a1(OpDecodeContext *context);
    static int op_parse_arm_ldrsh_imm_a1(OpDecodeContext *context);
    static int op_parse_arm_ldrh_reg_a1(OpDecodeContext *context);
    static int op_parse_arm_pop_a1(OpDecodeContext *context);
    static int op_parse_arm_pop_a2(OpDecodeContext *context);
    static int op_parse_arm_ldm_a1(OpDecodeContext *context);
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
    static int op_parse_arm_lsr_reg_a1(OpDecodeContext *context);
    static int op_parse_arm_bfc_a1(OpDecodeContext *context);
    static int op_parse_arm_and_imm_a1(OpDecodeContext *context);
    static int op_parse_arm_and_reg_a1(OpDecodeContext *context);
    static int op_parse_arm_uxtb_a1(OpDecodeContext *context);
    static int op_parse_arm_uxth_a1(OpDecodeContext *context);
    static int op_parse_arm_rsb_reg_a1(OpDecodeContext *context);
    static int op_parse_arm_rsb_imm_a1(OpDecodeContext *context);
    static int op_parse_arm_sbc_reg_a1(OpDecodeContext *context);
    static int op_parse_arm_mul_a1(OpDecodeContext *context);
    static int op_parse_arm_smmul_a1(OpDecodeContext *context);
    static int op_parse_arm_smull_a1(OpDecodeContext *context);
    static int op_parse_arm_tst_imm_a1(OpDecodeContext *context);
    static int op_parse_arm_tst_reg_a1(OpDecodeContext *context);
    static int op_parse_arm_sxtb_a1(OpDecodeContext *context);
    static int op_parse_arm_sxth_a1(OpDecodeContext *context);
    static int op_parse_arm_asr_imm_a1(OpDecodeContext *context);
    static int op_parse_arm_srs_a1(OpDecodeContext *context);
    static int op_parse_arm_clz_a1(OpDecodeContext *context);
    static int op_parse_arm_rfe_a1(OpDecodeContext *context);
    static int op_parse_arm_wfi_a1(OpDecodeContext *context);
    static int op_parse_arm_vadd_freg_a2(OpDecodeContext *context);
    static int op_parse_arm_vldr_a1(OpDecodeContext *context);
    static int op_parse_arm_vldr_a2(OpDecodeContext *context);
    static int op_parse_arm_vcvt_df_a1(OpDecodeContext *context);
    static int op_parse_arm_vcvt_fi_a1(OpDecodeContext *context);
    static int op_parse_arm_vstr_a1(OpDecodeContext *context);
    static int op_parse_arm_vstr_a2(OpDecodeContext *context);
    static int op_parse_arm_vcmp_a1(OpDecodeContext *context);
    static int op_parse_arm_vcmp_a2(OpDecodeContext *context);
    static int op_parse_arm_vmrs_a1(OpDecodeContext *context);
    static int op_parse_arm_vmov_imm_a1(OpDecodeContext *context);
    static int op_parse_arm_vmov_imm_a2(OpDecodeContext *context);
    static int op_parse_arm_vmov_sreg_a1(OpDecodeContext *context);
    static int op_parse_arm_vsub_freg_a2(OpDecodeContext *context);
    static int op_parse_arm_vmul_freg_a2(OpDecodeContext *context);
    static int op_parse_arm_vdiv_freg_a2(OpDecodeContext *context);
    static int op_parse_arm_vpush_a1(OpDecodeContext *context);
    static int op_parse_arm_vpush_a2(OpDecodeContext *context);
    static int op_parse_arm_vpop_a1(OpDecodeContext *context);
    static int op_parse_arm_vpop_a2(OpDecodeContext *context);

/* functions for conditions */
static arm_uint32 setbit_count(arm_uint32 value) {
    arm_uint32 count = 0;
    while (value) {
        count += value & 1;
        value >>= 1;
    }
    return count;
}

/* individual op parse functions */

    /* arm_add_imm_a1 */
    static int op_parse_arm_add_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_add_imm_a1) != OP_FB_arm_add_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_add_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_add_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_add_imm_a1;
        
            context->decoded_code->code.arm_add_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_imm_a1_cond_0) >> OP_SF_EBII_arm_add_imm_a1_cond_0) << OP_SF_EBIF_arm_add_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_add_imm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_imm_a1_S_0) >> OP_SF_EBII_arm_add_imm_a1_S_0) << OP_SF_EBIF_arm_add_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_add_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_imm_a1_Rn_0) >> OP_SF_EBII_arm_add_imm_a1_Rn_0) << OP_SF_EBIF_arm_add_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_add_imm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_imm_a1_Rd_0) >> OP_SF_EBII_arm_add_imm_a1_Rd_0) << OP_SF_EBIF_arm_add_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_add_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_imm_a1_imm12_0) >> OP_SF_EBII_arm_add_imm_a1_imm12_0) << OP_SF_EBIF_arm_add_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_add_reg_a1) != OP_FB_arm_add_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_add_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_add_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_add_reg_a1;
        
            context->decoded_code->code.arm_add_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_reg_a1_cond_0) >> OP_SF_EBII_arm_add_reg_a1_cond_0) << OP_SF_EBIF_arm_add_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_reg_a1_S_0) >> OP_SF_EBII_arm_add_reg_a1_S_0) << OP_SF_EBIF_arm_add_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_reg_a1_Rn_0) >> OP_SF_EBII_arm_add_reg_a1_Rn_0) << OP_SF_EBIF_arm_add_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_reg_a1_Rd_0) >> OP_SF_EBII_arm_add_reg_a1_Rd_0) << OP_SF_EBIF_arm_add_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_reg_a1_imm5_0) >> OP_SF_EBII_arm_add_reg_a1_imm5_0) << OP_SF_EBIF_arm_add_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_reg_a1_type_0) >> OP_SF_EBII_arm_add_reg_a1_type_0) << OP_SF_EBIF_arm_add_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_add_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_reg_a1_Rm_0) >> OP_SF_EBII_arm_add_reg_a1_Rm_0) << OP_SF_EBIF_arm_add_reg_a1_Rm_0);
            
        
        
        
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

    /* arm_adc_reg_a1 */
    static int op_parse_arm_adc_reg_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_adc_reg_a1) != OP_FB_arm_adc_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_adc_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_adc_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_adc_reg_a1;
        
            context->decoded_code->code.arm_adc_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_adc_reg_a1_cond_0) >> OP_SF_EBII_arm_adc_reg_a1_cond_0) << OP_SF_EBIF_arm_adc_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_adc_reg_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_adc_reg_a1_S_0) >> OP_SF_EBII_arm_adc_reg_a1_S_0) << OP_SF_EBIF_arm_adc_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_adc_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_adc_reg_a1_Rn_0) >> OP_SF_EBII_arm_adc_reg_a1_Rn_0) << OP_SF_EBIF_arm_adc_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_adc_reg_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_adc_reg_a1_Rd_0) >> OP_SF_EBII_arm_adc_reg_a1_Rd_0) << OP_SF_EBIF_arm_adc_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_adc_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_adc_reg_a1_imm5_0) >> OP_SF_EBII_arm_adc_reg_a1_imm5_0) << OP_SF_EBIF_arm_adc_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_adc_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_adc_reg_a1_type_0) >> OP_SF_EBII_arm_adc_reg_a1_type_0) << OP_SF_EBIF_arm_adc_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_adc_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_adc_reg_a1_Rm_0) >> OP_SF_EBII_arm_adc_reg_a1_Rm_0) << OP_SF_EBIF_arm_adc_reg_a1_Rm_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_adc_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_adc_reg_a1.Rd == 15)
         && (context->decoded_code->code.arm_adc_reg_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_add_spimm_a1 */
    static int op_parse_arm_add_spimm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_add_spimm_a1) != OP_FB_arm_add_spimm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_add_spimm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_add_spimm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_add_spimm_a1;
        
            context->decoded_code->code.arm_add_spimm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_spimm_a1_cond_0) >> OP_SF_EBII_arm_add_spimm_a1_cond_0) << OP_SF_EBIF_arm_add_spimm_a1_cond_0);
            
        
            context->decoded_code->code.arm_add_spimm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_spimm_a1_S_0) >> OP_SF_EBII_arm_add_spimm_a1_S_0) << OP_SF_EBIF_arm_add_spimm_a1_S_0);
            
        
            context->decoded_code->code.arm_add_spimm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_spimm_a1_Rd_0) >> OP_SF_EBII_arm_add_spimm_a1_Rd_0) << OP_SF_EBIF_arm_add_spimm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_add_spimm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_add_spimm_a1_imm12_0) >> OP_SF_EBII_arm_add_spimm_a1_imm12_0) << OP_SF_EBIF_arm_add_spimm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_adr_a1) != OP_FB_arm_adr_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_adr_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_adr_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_adr_a1;
        
            context->decoded_code->code.arm_adr_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_adr_a1_cond_0) >> OP_SF_EBII_arm_adr_a1_cond_0) << OP_SF_EBIF_arm_adr_a1_cond_0);
            
        
            context->decoded_code->code.arm_adr_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_adr_a1_Rd_0) >> OP_SF_EBII_arm_adr_a1_Rd_0) << OP_SF_EBIF_arm_adr_a1_Rd_0);
            
        
            context->decoded_code->code.arm_adr_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_adr_a1_imm12_0) >> OP_SF_EBII_arm_adr_a1_imm12_0) << OP_SF_EBIF_arm_adr_a1_imm12_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_adr_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_subs_pclr_a1 */
    static int op_parse_arm_subs_pclr_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_subs_pclr_a1) != OP_FB_arm_subs_pclr_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_subs_pclr_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_subs_pclr_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_subs_pclr_a1;
        
            context->decoded_code->code.arm_subs_pclr_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_subs_pclr_a1_cond_0) >> OP_SF_EBII_arm_subs_pclr_a1_cond_0) << OP_SF_EBIF_arm_subs_pclr_a1_cond_0);
            
        
            context->decoded_code->code.arm_subs_pclr_a1.opcode =
            
                (((context->code32x1 & OP_SF_MASK_arm_subs_pclr_a1_opcode_0) >> OP_SF_EBII_arm_subs_pclr_a1_opcode_0) << OP_SF_EBIF_arm_subs_pclr_a1_opcode_0);
            
        
            context->decoded_code->code.arm_subs_pclr_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_subs_pclr_a1_Rn_0) >> OP_SF_EBII_arm_subs_pclr_a1_Rn_0) << OP_SF_EBIF_arm_subs_pclr_a1_Rn_0);
            
        
            context->decoded_code->code.arm_subs_pclr_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_subs_pclr_a1_imm12_0) >> OP_SF_EBII_arm_subs_pclr_a1_imm12_0) << OP_SF_EBIF_arm_subs_pclr_a1_imm12_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_subs_pclr_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_cmp_imm_a1 */
    static int op_parse_arm_cmp_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_cmp_imm_a1) != OP_FB_arm_cmp_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_cmp_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_cmp_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_cmp_imm_a1;
        
            context->decoded_code->code.arm_cmp_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_cmp_imm_a1_cond_0) >> OP_SF_EBII_arm_cmp_imm_a1_cond_0) << OP_SF_EBIF_arm_cmp_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_cmp_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_cmp_imm_a1_Rn_0) >> OP_SF_EBII_arm_cmp_imm_a1_Rn_0) << OP_SF_EBIF_arm_cmp_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_cmp_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_cmp_imm_a1_imm12_0) >> OP_SF_EBII_arm_cmp_imm_a1_imm12_0) << OP_SF_EBIF_arm_cmp_imm_a1_imm12_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_cmp_imm_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_cmn_imm_a1 */
    static int op_parse_arm_cmn_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_cmn_imm_a1) != OP_FB_arm_cmn_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_cmn_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_cmn_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_cmn_imm_a1;
        
            context->decoded_code->code.arm_cmn_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_cmn_imm_a1_cond_0) >> OP_SF_EBII_arm_cmn_imm_a1_cond_0) << OP_SF_EBIF_arm_cmn_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_cmn_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_cmn_imm_a1_Rn_0) >> OP_SF_EBII_arm_cmn_imm_a1_Rn_0) << OP_SF_EBIF_arm_cmn_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_cmn_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_cmn_imm_a1_imm12_0) >> OP_SF_EBII_arm_cmn_imm_a1_imm12_0) << OP_SF_EBIF_arm_cmn_imm_a1_imm12_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_cmn_imm_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_sub_imm_a1 */
    static int op_parse_arm_sub_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_sub_imm_a1) != OP_FB_arm_sub_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_sub_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_sub_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_sub_imm_a1;
        
            context->decoded_code->code.arm_sub_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_imm_a1_cond_0) >> OP_SF_EBII_arm_sub_imm_a1_cond_0) << OP_SF_EBIF_arm_sub_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_sub_imm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_imm_a1_S_0) >> OP_SF_EBII_arm_sub_imm_a1_S_0) << OP_SF_EBIF_arm_sub_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_sub_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_imm_a1_Rn_0) >> OP_SF_EBII_arm_sub_imm_a1_Rn_0) << OP_SF_EBIF_arm_sub_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_sub_imm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_imm_a1_Rd_0) >> OP_SF_EBII_arm_sub_imm_a1_Rd_0) << OP_SF_EBIF_arm_sub_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_sub_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_imm_a1_imm12_0) >> OP_SF_EBII_arm_sub_imm_a1_imm12_0) << OP_SF_EBIF_arm_sub_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_sub_reg_a1) != OP_FB_arm_sub_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_sub_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_sub_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_sub_reg_a1;
        
            context->decoded_code->code.arm_sub_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_reg_a1_cond_0) >> OP_SF_EBII_arm_sub_reg_a1_cond_0) << OP_SF_EBIF_arm_sub_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_reg_a1_S_0) >> OP_SF_EBII_arm_sub_reg_a1_S_0) << OP_SF_EBIF_arm_sub_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_reg_a1_Rn_0) >> OP_SF_EBII_arm_sub_reg_a1_Rn_0) << OP_SF_EBIF_arm_sub_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_reg_a1_Rd_0) >> OP_SF_EBII_arm_sub_reg_a1_Rd_0) << OP_SF_EBIF_arm_sub_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_reg_a1_imm5_0) >> OP_SF_EBII_arm_sub_reg_a1_imm5_0) << OP_SF_EBIF_arm_sub_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_reg_a1_type_0) >> OP_SF_EBII_arm_sub_reg_a1_type_0) << OP_SF_EBIF_arm_sub_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_sub_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_reg_a1_Rm_0) >> OP_SF_EBII_arm_sub_reg_a1_Rm_0) << OP_SF_EBIF_arm_sub_reg_a1_Rm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_sub_spimm_a1) != OP_FB_arm_sub_spimm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_sub_spimm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_sub_spimm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_sub_spimm_a1;
        
            context->decoded_code->code.arm_sub_spimm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_spimm_a1_cond_0) >> OP_SF_EBII_arm_sub_spimm_a1_cond_0) << OP_SF_EBIF_arm_sub_spimm_a1_cond_0);
            
        
            context->decoded_code->code.arm_sub_spimm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_spimm_a1_S_0) >> OP_SF_EBII_arm_sub_spimm_a1_S_0) << OP_SF_EBIF_arm_sub_spimm_a1_S_0);
            
        
            context->decoded_code->code.arm_sub_spimm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_spimm_a1_Rd_0) >> OP_SF_EBII_arm_sub_spimm_a1_Rd_0) << OP_SF_EBIF_arm_sub_spimm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_sub_spimm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_sub_spimm_a1_imm12_0) >> OP_SF_EBII_arm_sub_spimm_a1_imm12_0) << OP_SF_EBIF_arm_sub_spimm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_cmp_reg_a1) != OP_FB_arm_cmp_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_cmp_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_cmp_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_cmp_reg_a1;
        
            context->decoded_code->code.arm_cmp_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_cmp_reg_a1_cond_0) >> OP_SF_EBII_arm_cmp_reg_a1_cond_0) << OP_SF_EBIF_arm_cmp_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_cmp_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_cmp_reg_a1_Rn_0) >> OP_SF_EBII_arm_cmp_reg_a1_Rn_0) << OP_SF_EBIF_arm_cmp_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_cmp_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_cmp_reg_a1_imm5_0) >> OP_SF_EBII_arm_cmp_reg_a1_imm5_0) << OP_SF_EBIF_arm_cmp_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_cmp_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_cmp_reg_a1_type_0) >> OP_SF_EBII_arm_cmp_reg_a1_type_0) << OP_SF_EBIF_arm_cmp_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_cmp_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_cmp_reg_a1_Rm_0) >> OP_SF_EBII_arm_cmp_reg_a1_Rm_0) << OP_SF_EBIF_arm_cmp_reg_a1_Rm_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_cmp_reg_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_mov_imm_a1 */
    static int op_parse_arm_mov_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_mov_imm_a1) != OP_FB_arm_mov_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_mov_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mov_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mov_imm_a1;
        
            context->decoded_code->code.arm_mov_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_imm_a1_cond_0) >> OP_SF_EBII_arm_mov_imm_a1_cond_0) << OP_SF_EBIF_arm_mov_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_mov_imm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_imm_a1_S_0) >> OP_SF_EBII_arm_mov_imm_a1_S_0) << OP_SF_EBIF_arm_mov_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_mov_imm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_imm_a1_Rd_0) >> OP_SF_EBII_arm_mov_imm_a1_Rd_0) << OP_SF_EBIF_arm_mov_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_mov_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_imm_a1_imm12_0) >> OP_SF_EBII_arm_mov_imm_a1_imm12_0) << OP_SF_EBIF_arm_mov_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_mov_imm_a2) != OP_FB_arm_mov_imm_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_mov_imm_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mov_imm_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mov_imm_a2;
        
            context->decoded_code->code.arm_mov_imm_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_imm_a2_cond_0) >> OP_SF_EBII_arm_mov_imm_a2_cond_0) << OP_SF_EBIF_arm_mov_imm_a2_cond_0);
            
        
            context->decoded_code->code.arm_mov_imm_a2.imm4 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_imm_a2_imm4_0) >> OP_SF_EBII_arm_mov_imm_a2_imm4_0) << OP_SF_EBIF_arm_mov_imm_a2_imm4_0);
            
        
            context->decoded_code->code.arm_mov_imm_a2.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_imm_a2_Rd_0) >> OP_SF_EBII_arm_mov_imm_a2_Rd_0) << OP_SF_EBIF_arm_mov_imm_a2_Rd_0);
            
        
            context->decoded_code->code.arm_mov_imm_a2.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_imm_a2_imm12_0) >> OP_SF_EBII_arm_mov_imm_a2_imm12_0) << OP_SF_EBIF_arm_mov_imm_a2_imm12_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_mov_imm_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_mvn_imm_a1 */
    static int op_parse_arm_mvn_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_mvn_imm_a1) != OP_FB_arm_mvn_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_mvn_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mvn_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mvn_imm_a1;
        
            context->decoded_code->code.arm_mvn_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_mvn_imm_a1_cond_0) >> OP_SF_EBII_arm_mvn_imm_a1_cond_0) << OP_SF_EBIF_arm_mvn_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_mvn_imm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_mvn_imm_a1_S_0) >> OP_SF_EBII_arm_mvn_imm_a1_S_0) << OP_SF_EBIF_arm_mvn_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_mvn_imm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_mvn_imm_a1_Rd_0) >> OP_SF_EBII_arm_mvn_imm_a1_Rd_0) << OP_SF_EBIF_arm_mvn_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_mvn_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mvn_imm_a1_imm12_0) >> OP_SF_EBII_arm_mvn_imm_a1_imm12_0) << OP_SF_EBIF_arm_mvn_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_mov_reg_a1) != OP_FB_arm_mov_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_mov_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mov_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mov_reg_a1;
        
            context->decoded_code->code.arm_mov_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_reg_a1_cond_0) >> OP_SF_EBII_arm_mov_reg_a1_cond_0) << OP_SF_EBIF_arm_mov_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_mov_reg_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_reg_a1_S_0) >> OP_SF_EBII_arm_mov_reg_a1_S_0) << OP_SF_EBIF_arm_mov_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_mov_reg_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_reg_a1_Rd_0) >> OP_SF_EBII_arm_mov_reg_a1_Rd_0) << OP_SF_EBIF_arm_mov_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_mov_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_mov_reg_a1_Rm_0) >> OP_SF_EBII_arm_mov_reg_a1_Rm_0) << OP_SF_EBIF_arm_mov_reg_a1_Rm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_mvn_reg_a1) != OP_FB_arm_mvn_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_mvn_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mvn_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mvn_reg_a1;
        
            context->decoded_code->code.arm_mvn_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_mvn_reg_a1_cond_0) >> OP_SF_EBII_arm_mvn_reg_a1_cond_0) << OP_SF_EBIF_arm_mvn_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_mvn_reg_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_mvn_reg_a1_S_0) >> OP_SF_EBII_arm_mvn_reg_a1_S_0) << OP_SF_EBIF_arm_mvn_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_mvn_reg_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_mvn_reg_a1_Rd_0) >> OP_SF_EBII_arm_mvn_reg_a1_Rd_0) << OP_SF_EBIF_arm_mvn_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_mvn_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mvn_reg_a1_imm5_0) >> OP_SF_EBII_arm_mvn_reg_a1_imm5_0) << OP_SF_EBIF_arm_mvn_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_mvn_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_mvn_reg_a1_type_0) >> OP_SF_EBII_arm_mvn_reg_a1_type_0) << OP_SF_EBIF_arm_mvn_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_mvn_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_mvn_reg_a1_Rm_0) >> OP_SF_EBII_arm_mvn_reg_a1_Rm_0) << OP_SF_EBIF_arm_mvn_reg_a1_Rm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_bl_a1) != OP_FB_arm_bl_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_bl_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_bl_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_bl_a1;
        
            context->decoded_code->code.arm_bl_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_bl_a1_cond_0) >> OP_SF_EBII_arm_bl_a1_cond_0) << OP_SF_EBIF_arm_bl_a1_cond_0);
            
        
            context->decoded_code->code.arm_bl_a1.imm24 =
            
                (((context->code32x1 & OP_SF_MASK_arm_bl_a1_imm24_0) >> OP_SF_EBII_arm_bl_a1_imm24_0) << OP_SF_EBIF_arm_bl_a1_imm24_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_bl_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_blx_a2 */
    static int op_parse_arm_blx_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_blx_a2) != OP_FB_arm_blx_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_blx_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_blx_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_blx_a2;
        
            context->decoded_code->code.arm_blx_a2.H =
            
                (((context->code32x1 & OP_SF_MASK_arm_blx_a2_H_0) >> OP_SF_EBII_arm_blx_a2_H_0) << OP_SF_EBIF_arm_blx_a2_H_0);
            
        
            context->decoded_code->code.arm_blx_a2.imm24 =
            
                (((context->code32x1 & OP_SF_MASK_arm_blx_a2_imm24_0) >> OP_SF_EBII_arm_blx_a2_imm24_0) << OP_SF_EBIF_arm_blx_a2_imm24_0);
            
        
        
        
        return 0;
    }

    /* arm_blx_reg_a1 */
    static int op_parse_arm_blx_reg_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_blx_reg_a1) != OP_FB_arm_blx_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_blx_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_blx_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_blx_reg_a1;
        
            context->decoded_code->code.arm_blx_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_blx_reg_a1_cond_0) >> OP_SF_EBII_arm_blx_reg_a1_cond_0) << OP_SF_EBIF_arm_blx_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_blx_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_blx_reg_a1_Rm_0) >> OP_SF_EBII_arm_blx_reg_a1_Rm_0) << OP_SF_EBIF_arm_blx_reg_a1_Rm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_b_a1) != OP_FB_arm_b_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_b_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_b_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_b_a1;
        
            context->decoded_code->code.arm_b_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_b_a1_cond_0) >> OP_SF_EBII_arm_b_a1_cond_0) << OP_SF_EBIF_arm_b_a1_cond_0);
            
        
            context->decoded_code->code.arm_b_a1.imm24 =
            
                (((context->code32x1 & OP_SF_MASK_arm_b_a1_imm24_0) >> OP_SF_EBII_arm_b_a1_imm24_0) << OP_SF_EBIF_arm_b_a1_imm24_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_b_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_bx_a1 */
    static int op_parse_arm_bx_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_bx_a1) != OP_FB_arm_bx_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_bx_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_bx_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_bx_a1;
        
            context->decoded_code->code.arm_bx_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_bx_a1_cond_0) >> OP_SF_EBII_arm_bx_a1_cond_0) << OP_SF_EBIF_arm_bx_a1_cond_0);
            
        
            context->decoded_code->code.arm_bx_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_bx_a1_Rm_0) >> OP_SF_EBII_arm_bx_a1_Rm_0) << OP_SF_EBIF_arm_bx_a1_Rm_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_bx_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_str_imm_a1 */
    static int op_parse_arm_str_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_str_imm_a1) != OP_FB_arm_str_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_str_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_str_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_str_imm_a1;
        
            context->decoded_code->code.arm_str_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_imm_a1_cond_0) >> OP_SF_EBII_arm_str_imm_a1_cond_0) << OP_SF_EBIF_arm_str_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_imm_a1_P_0) >> OP_SF_EBII_arm_str_imm_a1_P_0) << OP_SF_EBIF_arm_str_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_imm_a1_U_0) >> OP_SF_EBII_arm_str_imm_a1_U_0) << OP_SF_EBIF_arm_str_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_imm_a1_W_0) >> OP_SF_EBII_arm_str_imm_a1_W_0) << OP_SF_EBIF_arm_str_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_imm_a1_Rn_0) >> OP_SF_EBII_arm_str_imm_a1_Rn_0) << OP_SF_EBIF_arm_str_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_imm_a1_Rt_0) >> OP_SF_EBII_arm_str_imm_a1_Rt_0) << OP_SF_EBIF_arm_str_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_str_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_imm_a1_imm12_0) >> OP_SF_EBII_arm_str_imm_a1_imm12_0) << OP_SF_EBIF_arm_str_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_strb_imm_a1) != OP_FB_arm_strb_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_strb_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_strb_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_strb_imm_a1;
        
            context->decoded_code->code.arm_strb_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_imm_a1_cond_0) >> OP_SF_EBII_arm_strb_imm_a1_cond_0) << OP_SF_EBIF_arm_strb_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_imm_a1_P_0) >> OP_SF_EBII_arm_strb_imm_a1_P_0) << OP_SF_EBIF_arm_strb_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_imm_a1_U_0) >> OP_SF_EBII_arm_strb_imm_a1_U_0) << OP_SF_EBIF_arm_strb_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_imm_a1_W_0) >> OP_SF_EBII_arm_strb_imm_a1_W_0) << OP_SF_EBIF_arm_strb_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_imm_a1_Rn_0) >> OP_SF_EBII_arm_strb_imm_a1_Rn_0) << OP_SF_EBIF_arm_strb_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_imm_a1_Rt_0) >> OP_SF_EBII_arm_strb_imm_a1_Rt_0) << OP_SF_EBIF_arm_strb_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_strb_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_imm_a1_imm12_0) >> OP_SF_EBII_arm_strb_imm_a1_imm12_0) << OP_SF_EBIF_arm_strb_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_strh_imm_a1) != OP_FB_arm_strh_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_strh_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_strh_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_strh_imm_a1;
        
            context->decoded_code->code.arm_strh_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_strh_imm_a1_cond_0) >> OP_SF_EBII_arm_strh_imm_a1_cond_0) << OP_SF_EBIF_arm_strh_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_strh_imm_a1_P_0) >> OP_SF_EBII_arm_strh_imm_a1_P_0) << OP_SF_EBIF_arm_strh_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_strh_imm_a1_U_0) >> OP_SF_EBII_arm_strh_imm_a1_U_0) << OP_SF_EBIF_arm_strh_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_strh_imm_a1_W_0) >> OP_SF_EBII_arm_strh_imm_a1_W_0) << OP_SF_EBIF_arm_strh_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_strh_imm_a1_Rn_0) >> OP_SF_EBII_arm_strh_imm_a1_Rn_0) << OP_SF_EBIF_arm_strh_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_strh_imm_a1_Rt_0) >> OP_SF_EBII_arm_strh_imm_a1_Rt_0) << OP_SF_EBIF_arm_strh_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_strh_imm_a1.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_strh_imm_a1_imm8_0) >> OP_SF_EBII_arm_strh_imm_a1_imm8_0) << OP_SF_EBIF_arm_strh_imm_a1_imm8_0)
            
                | (((context->code32x1 & OP_SF_MASK_arm_strh_imm_a1_imm8_1) >> OP_SF_EBII_arm_strh_imm_a1_imm8_1) << OP_SF_EBIF_arm_strh_imm_a1_imm8_1);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_strd_imm_a1) != OP_FB_arm_strd_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_strd_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_strd_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_strd_imm_a1;
        
            context->decoded_code->code.arm_strd_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_strd_imm_a1_cond_0) >> OP_SF_EBII_arm_strd_imm_a1_cond_0) << OP_SF_EBIF_arm_strd_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_strd_imm_a1_P_0) >> OP_SF_EBII_arm_strd_imm_a1_P_0) << OP_SF_EBIF_arm_strd_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_strd_imm_a1_U_0) >> OP_SF_EBII_arm_strd_imm_a1_U_0) << OP_SF_EBIF_arm_strd_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_strd_imm_a1_W_0) >> OP_SF_EBII_arm_strd_imm_a1_W_0) << OP_SF_EBIF_arm_strd_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_strd_imm_a1_Rn_0) >> OP_SF_EBII_arm_strd_imm_a1_Rn_0) << OP_SF_EBIF_arm_strd_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_strd_imm_a1_Rt_0) >> OP_SF_EBII_arm_strd_imm_a1_Rt_0) << OP_SF_EBIF_arm_strd_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_strd_imm_a1.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_strd_imm_a1_imm8_0) >> OP_SF_EBII_arm_strd_imm_a1_imm8_0) << OP_SF_EBIF_arm_strd_imm_a1_imm8_0)
            
                | (((context->code32x1 & OP_SF_MASK_arm_strd_imm_a1_imm8_1) >> OP_SF_EBII_arm_strd_imm_a1_imm8_1) << OP_SF_EBIF_arm_strd_imm_a1_imm8_1);
            
        
        
        
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

    /* arm_str_reg_a1 */
    static int op_parse_arm_str_reg_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_str_reg_a1) != OP_FB_arm_str_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_str_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_str_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_str_reg_a1;
        
            context->decoded_code->code.arm_str_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_reg_a1_cond_0) >> OP_SF_EBII_arm_str_reg_a1_cond_0) << OP_SF_EBIF_arm_str_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_str_reg_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_reg_a1_P_0) >> OP_SF_EBII_arm_str_reg_a1_P_0) << OP_SF_EBIF_arm_str_reg_a1_P_0);
            
        
            context->decoded_code->code.arm_str_reg_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_reg_a1_U_0) >> OP_SF_EBII_arm_str_reg_a1_U_0) << OP_SF_EBIF_arm_str_reg_a1_U_0);
            
        
            context->decoded_code->code.arm_str_reg_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_reg_a1_W_0) >> OP_SF_EBII_arm_str_reg_a1_W_0) << OP_SF_EBIF_arm_str_reg_a1_W_0);
            
        
            context->decoded_code->code.arm_str_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_reg_a1_Rn_0) >> OP_SF_EBII_arm_str_reg_a1_Rn_0) << OP_SF_EBIF_arm_str_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_str_reg_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_reg_a1_Rt_0) >> OP_SF_EBII_arm_str_reg_a1_Rt_0) << OP_SF_EBIF_arm_str_reg_a1_Rt_0);
            
        
            context->decoded_code->code.arm_str_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_reg_a1_imm5_0) >> OP_SF_EBII_arm_str_reg_a1_imm5_0) << OP_SF_EBIF_arm_str_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_str_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_reg_a1_type_0) >> OP_SF_EBII_arm_str_reg_a1_type_0) << OP_SF_EBIF_arm_str_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_str_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_str_reg_a1_Rm_0) >> OP_SF_EBII_arm_str_reg_a1_Rm_0) << OP_SF_EBIF_arm_str_reg_a1_Rm_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_str_reg_a1.cond == 15)
         || (context->decoded_code->code.arm_str_reg_a1.Rm == 15)
         || ((context->decoded_code->code.arm_str_reg_a1.P == 0)
         && (context->decoded_code->code.arm_str_reg_a1.W == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_strb_reg_a1 */
    static int op_parse_arm_strb_reg_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_strb_reg_a1) != OP_FB_arm_strb_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_strb_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_strb_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_strb_reg_a1;
        
            context->decoded_code->code.arm_strb_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_reg_a1_cond_0) >> OP_SF_EBII_arm_strb_reg_a1_cond_0) << OP_SF_EBIF_arm_strb_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_reg_a1_P_0) >> OP_SF_EBII_arm_strb_reg_a1_P_0) << OP_SF_EBIF_arm_strb_reg_a1_P_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_reg_a1_U_0) >> OP_SF_EBII_arm_strb_reg_a1_U_0) << OP_SF_EBIF_arm_strb_reg_a1_U_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_reg_a1_W_0) >> OP_SF_EBII_arm_strb_reg_a1_W_0) << OP_SF_EBIF_arm_strb_reg_a1_W_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_reg_a1_Rn_0) >> OP_SF_EBII_arm_strb_reg_a1_Rn_0) << OP_SF_EBIF_arm_strb_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_reg_a1_Rt_0) >> OP_SF_EBII_arm_strb_reg_a1_Rt_0) << OP_SF_EBIF_arm_strb_reg_a1_Rt_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_reg_a1_imm5_0) >> OP_SF_EBII_arm_strb_reg_a1_imm5_0) << OP_SF_EBIF_arm_strb_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_reg_a1_type_0) >> OP_SF_EBII_arm_strb_reg_a1_type_0) << OP_SF_EBIF_arm_strb_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_strb_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_strb_reg_a1_Rm_0) >> OP_SF_EBII_arm_strb_reg_a1_Rm_0) << OP_SF_EBIF_arm_strb_reg_a1_Rm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_push_a1) != OP_FB_arm_push_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_push_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_push_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_push_a1;
        
            context->decoded_code->code.arm_push_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_push_a1_cond_0) >> OP_SF_EBII_arm_push_a1_cond_0) << OP_SF_EBIF_arm_push_a1_cond_0);
            
        
            context->decoded_code->code.arm_push_a1.register_list =
            
                (((context->code32x1 & OP_SF_MASK_arm_push_a1_register_list_0) >> OP_SF_EBII_arm_push_a1_register_list_0) << OP_SF_EBIF_arm_push_a1_register_list_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_push_a1.cond == 15)
         || (setbit_count(context->decoded_code->code.arm_push_a1.register_list) < 2)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_push_a2 */
    static int op_parse_arm_push_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_push_a2) != OP_FB_arm_push_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_push_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_push_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_push_a2;
        
            context->decoded_code->code.arm_push_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_push_a2_cond_0) >> OP_SF_EBII_arm_push_a2_cond_0) << OP_SF_EBIF_arm_push_a2_cond_0);
            
        
            context->decoded_code->code.arm_push_a2.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_push_a2_Rt_0) >> OP_SF_EBII_arm_push_a2_Rt_0) << OP_SF_EBIF_arm_push_a2_Rt_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_push_a2.cond == 15)
         || (context->decoded_code->code.arm_push_a2.Rt == 13)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_stmfd_a1 */
    static int op_parse_arm_stmfd_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_stmfd_a1) != OP_FB_arm_stmfd_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_stmfd_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_stmfd_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_stmfd_a1;
        
            context->decoded_code->code.arm_stmfd_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_stmfd_a1_cond_0) >> OP_SF_EBII_arm_stmfd_a1_cond_0) << OP_SF_EBIF_arm_stmfd_a1_cond_0);
            
        
            context->decoded_code->code.arm_stmfd_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_stmfd_a1_W_0) >> OP_SF_EBII_arm_stmfd_a1_W_0) << OP_SF_EBIF_arm_stmfd_a1_W_0);
            
        
            context->decoded_code->code.arm_stmfd_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_stmfd_a1_Rn_0) >> OP_SF_EBII_arm_stmfd_a1_Rn_0) << OP_SF_EBIF_arm_stmfd_a1_Rn_0);
            
        
            context->decoded_code->code.arm_stmfd_a1.register_list =
            
                (((context->code32x1 & OP_SF_MASK_arm_stmfd_a1_register_list_0) >> OP_SF_EBII_arm_stmfd_a1_register_list_0) << OP_SF_EBIF_arm_stmfd_a1_register_list_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_stmfd_a1.cond == 15)
         || ((context->decoded_code->code.arm_stmfd_a1.W == 1)
         && (context->decoded_code->code.arm_stmfd_a1.Rn == 13)
         && (setbit_count(context->decoded_code->code.arm_stmfd_a1.register_list) > 1)
        )
         || (context->decoded_code->code.arm_stmfd_a1.Rn == 15)
         || (setbit_count(context->decoded_code->code.arm_stmfd_a1.register_list) < 1)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_stm_a1 */
    static int op_parse_arm_stm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_stm_a1) != OP_FB_arm_stm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_stm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_stm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_stm_a1;
        
            context->decoded_code->code.arm_stm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_stm_a1_cond_0) >> OP_SF_EBII_arm_stm_a1_cond_0) << OP_SF_EBIF_arm_stm_a1_cond_0);
            
        
            context->decoded_code->code.arm_stm_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_stm_a1_W_0) >> OP_SF_EBII_arm_stm_a1_W_0) << OP_SF_EBIF_arm_stm_a1_W_0);
            
        
            context->decoded_code->code.arm_stm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_stm_a1_Rn_0) >> OP_SF_EBII_arm_stm_a1_Rn_0) << OP_SF_EBIF_arm_stm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_stm_a1.register_list =
            
                (((context->code32x1 & OP_SF_MASK_arm_stm_a1_register_list_0) >> OP_SF_EBII_arm_stm_a1_register_list_0) << OP_SF_EBIF_arm_stm_a1_register_list_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_stm_a1.cond == 15)
         || (context->decoded_code->code.arm_stm_a1.Rn == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_ldr_imm_a1 */
    static int op_parse_arm_ldr_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_ldr_imm_a1) != OP_FB_arm_ldr_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_ldr_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldr_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldr_imm_a1;
        
            context->decoded_code->code.arm_ldr_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_imm_a1_cond_0) >> OP_SF_EBII_arm_ldr_imm_a1_cond_0) << OP_SF_EBIF_arm_ldr_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_imm_a1_P_0) >> OP_SF_EBII_arm_ldr_imm_a1_P_0) << OP_SF_EBIF_arm_ldr_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_imm_a1_U_0) >> OP_SF_EBII_arm_ldr_imm_a1_U_0) << OP_SF_EBIF_arm_ldr_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_imm_a1_W_0) >> OP_SF_EBII_arm_ldr_imm_a1_W_0) << OP_SF_EBIF_arm_ldr_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_imm_a1_Rn_0) >> OP_SF_EBII_arm_ldr_imm_a1_Rn_0) << OP_SF_EBIF_arm_ldr_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_imm_a1_Rt_0) >> OP_SF_EBII_arm_ldr_imm_a1_Rt_0) << OP_SF_EBIF_arm_ldr_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldr_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_imm_a1_imm12_0) >> OP_SF_EBII_arm_ldr_imm_a1_imm12_0) << OP_SF_EBIF_arm_ldr_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_ldr_literal_a1) != OP_FB_arm_ldr_literal_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_ldr_literal_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldr_literal_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldr_literal_a1;
        
            context->decoded_code->code.arm_ldr_literal_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_literal_a1_cond_0) >> OP_SF_EBII_arm_ldr_literal_a1_cond_0) << OP_SF_EBIF_arm_ldr_literal_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldr_literal_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_literal_a1_P_0) >> OP_SF_EBII_arm_ldr_literal_a1_P_0) << OP_SF_EBIF_arm_ldr_literal_a1_P_0);
            
        
            context->decoded_code->code.arm_ldr_literal_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_literal_a1_U_0) >> OP_SF_EBII_arm_ldr_literal_a1_U_0) << OP_SF_EBIF_arm_ldr_literal_a1_U_0);
            
        
            context->decoded_code->code.arm_ldr_literal_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_literal_a1_W_0) >> OP_SF_EBII_arm_ldr_literal_a1_W_0) << OP_SF_EBIF_arm_ldr_literal_a1_W_0);
            
        
            context->decoded_code->code.arm_ldr_literal_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_literal_a1_Rt_0) >> OP_SF_EBII_arm_ldr_literal_a1_Rt_0) << OP_SF_EBIF_arm_ldr_literal_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldr_literal_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_literal_a1_imm12_0) >> OP_SF_EBII_arm_ldr_literal_a1_imm12_0) << OP_SF_EBIF_arm_ldr_literal_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_ldrb_imm_a1) != OP_FB_arm_ldrb_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_ldrb_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldrb_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldrb_imm_a1;
        
            context->decoded_code->code.arm_ldrb_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_imm_a1_cond_0) >> OP_SF_EBII_arm_ldrb_imm_a1_cond_0) << OP_SF_EBIF_arm_ldrb_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_imm_a1_P_0) >> OP_SF_EBII_arm_ldrb_imm_a1_P_0) << OP_SF_EBIF_arm_ldrb_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_imm_a1_U_0) >> OP_SF_EBII_arm_ldrb_imm_a1_U_0) << OP_SF_EBIF_arm_ldrb_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_imm_a1_W_0) >> OP_SF_EBII_arm_ldrb_imm_a1_W_0) << OP_SF_EBIF_arm_ldrb_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_imm_a1_Rn_0) >> OP_SF_EBII_arm_ldrb_imm_a1_Rn_0) << OP_SF_EBIF_arm_ldrb_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_imm_a1_Rt_0) >> OP_SF_EBII_arm_ldrb_imm_a1_Rt_0) << OP_SF_EBIF_arm_ldrb_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldrb_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_imm_a1_imm12_0) >> OP_SF_EBII_arm_ldrb_imm_a1_imm12_0) << OP_SF_EBIF_arm_ldrb_imm_a1_imm12_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_ldrb_imm_a1.cond == 15)
         || (context->decoded_code->code.arm_ldrb_imm_a1.Rn == 15)
         || ((context->decoded_code->code.arm_ldrb_imm_a1.P == 0)
         && (context->decoded_code->code.arm_ldrb_imm_a1.W == 1)
        )
         || (context->decoded_code->code.arm_ldrb_imm_a1.Rt == 15)
         || (((context->decoded_code->code.arm_ldrb_imm_a1.P == 0)
         || (context->decoded_code->code.arm_ldrb_imm_a1.W == 1)
        )
         && (context->decoded_code->code.arm_ldrb_imm_a1.Rn == context->decoded_code->code.arm_ldrb_imm_a1.Rt)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_ldrh_imm_a1 */
    static int op_parse_arm_ldrh_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_ldrh_imm_a1) != OP_FB_arm_ldrh_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_ldrh_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldrh_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldrh_imm_a1;
        
            context->decoded_code->code.arm_ldrh_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_imm_a1_cond_0) >> OP_SF_EBII_arm_ldrh_imm_a1_cond_0) << OP_SF_EBIF_arm_ldrh_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_imm_a1_P_0) >> OP_SF_EBII_arm_ldrh_imm_a1_P_0) << OP_SF_EBIF_arm_ldrh_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_imm_a1_U_0) >> OP_SF_EBII_arm_ldrh_imm_a1_U_0) << OP_SF_EBIF_arm_ldrh_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_imm_a1_W_0) >> OP_SF_EBII_arm_ldrh_imm_a1_W_0) << OP_SF_EBIF_arm_ldrh_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_imm_a1_Rn_0) >> OP_SF_EBII_arm_ldrh_imm_a1_Rn_0) << OP_SF_EBIF_arm_ldrh_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_imm_a1_Rt_0) >> OP_SF_EBII_arm_ldrh_imm_a1_Rt_0) << OP_SF_EBIF_arm_ldrh_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldrh_imm_a1.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_imm_a1_imm8_0) >> OP_SF_EBII_arm_ldrh_imm_a1_imm8_0) << OP_SF_EBIF_arm_ldrh_imm_a1_imm8_0)
            
                | (((context->code32x1 & OP_SF_MASK_arm_ldrh_imm_a1_imm8_1) >> OP_SF_EBII_arm_ldrh_imm_a1_imm8_1) << OP_SF_EBIF_arm_ldrh_imm_a1_imm8_1);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_ldrd_imm_a1) != OP_FB_arm_ldrd_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_ldrd_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldrd_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldrd_imm_a1;
        
            context->decoded_code->code.arm_ldrd_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrd_imm_a1_cond_0) >> OP_SF_EBII_arm_ldrd_imm_a1_cond_0) << OP_SF_EBIF_arm_ldrd_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrd_imm_a1_P_0) >> OP_SF_EBII_arm_ldrd_imm_a1_P_0) << OP_SF_EBIF_arm_ldrd_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrd_imm_a1_U_0) >> OP_SF_EBII_arm_ldrd_imm_a1_U_0) << OP_SF_EBIF_arm_ldrd_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrd_imm_a1_W_0) >> OP_SF_EBII_arm_ldrd_imm_a1_W_0) << OP_SF_EBIF_arm_ldrd_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrd_imm_a1_Rn_0) >> OP_SF_EBII_arm_ldrd_imm_a1_Rn_0) << OP_SF_EBIF_arm_ldrd_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrd_imm_a1_Rt_0) >> OP_SF_EBII_arm_ldrd_imm_a1_Rt_0) << OP_SF_EBIF_arm_ldrd_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldrd_imm_a1.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrd_imm_a1_imm8_0) >> OP_SF_EBII_arm_ldrd_imm_a1_imm8_0) << OP_SF_EBIF_arm_ldrd_imm_a1_imm8_0)
            
                | (((context->code32x1 & OP_SF_MASK_arm_ldrd_imm_a1_imm8_1) >> OP_SF_EBII_arm_ldrd_imm_a1_imm8_1) << OP_SF_EBIF_arm_ldrd_imm_a1_imm8_1);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_ldr_reg_a1) != OP_FB_arm_ldr_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_ldr_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldr_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldr_reg_a1;
        
            context->decoded_code->code.arm_ldr_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_reg_a1_cond_0) >> OP_SF_EBII_arm_ldr_reg_a1_cond_0) << OP_SF_EBIF_arm_ldr_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_reg_a1_P_0) >> OP_SF_EBII_arm_ldr_reg_a1_P_0) << OP_SF_EBIF_arm_ldr_reg_a1_P_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_reg_a1_U_0) >> OP_SF_EBII_arm_ldr_reg_a1_U_0) << OP_SF_EBIF_arm_ldr_reg_a1_U_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_reg_a1_W_0) >> OP_SF_EBII_arm_ldr_reg_a1_W_0) << OP_SF_EBIF_arm_ldr_reg_a1_W_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_reg_a1_Rn_0) >> OP_SF_EBII_arm_ldr_reg_a1_Rn_0) << OP_SF_EBIF_arm_ldr_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_reg_a1_Rt_0) >> OP_SF_EBII_arm_ldr_reg_a1_Rt_0) << OP_SF_EBIF_arm_ldr_reg_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_reg_a1_imm5_0) >> OP_SF_EBII_arm_ldr_reg_a1_imm5_0) << OP_SF_EBIF_arm_ldr_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_reg_a1_type_0) >> OP_SF_EBII_arm_ldr_reg_a1_type_0) << OP_SF_EBIF_arm_ldr_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_ldr_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldr_reg_a1_Rm_0) >> OP_SF_EBII_arm_ldr_reg_a1_Rm_0) << OP_SF_EBIF_arm_ldr_reg_a1_Rm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_ldrb_reg_a1) != OP_FB_arm_ldrb_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_ldrb_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldrb_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldrb_reg_a1;
        
            context->decoded_code->code.arm_ldrb_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_reg_a1_cond_0) >> OP_SF_EBII_arm_ldrb_reg_a1_cond_0) << OP_SF_EBIF_arm_ldrb_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_reg_a1_P_0) >> OP_SF_EBII_arm_ldrb_reg_a1_P_0) << OP_SF_EBIF_arm_ldrb_reg_a1_P_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_reg_a1_U_0) >> OP_SF_EBII_arm_ldrb_reg_a1_U_0) << OP_SF_EBIF_arm_ldrb_reg_a1_U_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_reg_a1_W_0) >> OP_SF_EBII_arm_ldrb_reg_a1_W_0) << OP_SF_EBIF_arm_ldrb_reg_a1_W_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_reg_a1_Rn_0) >> OP_SF_EBII_arm_ldrb_reg_a1_Rn_0) << OP_SF_EBIF_arm_ldrb_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_reg_a1_Rt_0) >> OP_SF_EBII_arm_ldrb_reg_a1_Rt_0) << OP_SF_EBIF_arm_ldrb_reg_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_reg_a1_imm5_0) >> OP_SF_EBII_arm_ldrb_reg_a1_imm5_0) << OP_SF_EBIF_arm_ldrb_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_reg_a1_type_0) >> OP_SF_EBII_arm_ldrb_reg_a1_type_0) << OP_SF_EBIF_arm_ldrb_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_ldrb_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrb_reg_a1_Rm_0) >> OP_SF_EBII_arm_ldrb_reg_a1_Rm_0) << OP_SF_EBIF_arm_ldrb_reg_a1_Rm_0);
            
        
        
        
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

    /* arm_ldrsh_imm_a1 */
    static int op_parse_arm_ldrsh_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_ldrsh_imm_a1) != OP_FB_arm_ldrsh_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_ldrsh_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldrsh_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldrsh_imm_a1;
        
            context->decoded_code->code.arm_ldrsh_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrsh_imm_a1_cond_0) >> OP_SF_EBII_arm_ldrsh_imm_a1_cond_0) << OP_SF_EBIF_arm_ldrsh_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldrsh_imm_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrsh_imm_a1_P_0) >> OP_SF_EBII_arm_ldrsh_imm_a1_P_0) << OP_SF_EBIF_arm_ldrsh_imm_a1_P_0);
            
        
            context->decoded_code->code.arm_ldrsh_imm_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrsh_imm_a1_U_0) >> OP_SF_EBII_arm_ldrsh_imm_a1_U_0) << OP_SF_EBIF_arm_ldrsh_imm_a1_U_0);
            
        
            context->decoded_code->code.arm_ldrsh_imm_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrsh_imm_a1_W_0) >> OP_SF_EBII_arm_ldrsh_imm_a1_W_0) << OP_SF_EBIF_arm_ldrsh_imm_a1_W_0);
            
        
            context->decoded_code->code.arm_ldrsh_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrsh_imm_a1_Rn_0) >> OP_SF_EBII_arm_ldrsh_imm_a1_Rn_0) << OP_SF_EBIF_arm_ldrsh_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldrsh_imm_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrsh_imm_a1_Rt_0) >> OP_SF_EBII_arm_ldrsh_imm_a1_Rt_0) << OP_SF_EBIF_arm_ldrsh_imm_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldrsh_imm_a1.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrsh_imm_a1_imm8_0) >> OP_SF_EBII_arm_ldrsh_imm_a1_imm8_0) << OP_SF_EBIF_arm_ldrsh_imm_a1_imm8_0)
            
                | (((context->code32x1 & OP_SF_MASK_arm_ldrsh_imm_a1_imm8_1) >> OP_SF_EBII_arm_ldrsh_imm_a1_imm8_1) << OP_SF_EBIF_arm_ldrsh_imm_a1_imm8_1);
            
        
        
        
            if (
                (context->decoded_code->code.arm_ldrsh_imm_a1.cond == 15)
         || (context->decoded_code->code.arm_ldrsh_imm_a1.Rn == 15)
         || ((context->decoded_code->code.arm_ldrsh_imm_a1.P == 0)
         && (context->decoded_code->code.arm_ldrsh_imm_a1.W == 1)
        )
         || (context->decoded_code->code.arm_ldrsh_imm_a1.Rt == 15)
         || (((context->decoded_code->code.arm_ldrsh_imm_a1.P == 0)
         || (context->decoded_code->code.arm_ldrsh_imm_a1.W == 1)
        )
         && (context->decoded_code->code.arm_ldrsh_imm_a1.Rn == context->decoded_code->code.arm_ldrsh_imm_a1.Rt)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_ldrh_reg_a1 */
    static int op_parse_arm_ldrh_reg_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_ldrh_reg_a1) != OP_FB_arm_ldrh_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_ldrh_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldrh_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldrh_reg_a1;
        
            context->decoded_code->code.arm_ldrh_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_reg_a1_cond_0) >> OP_SF_EBII_arm_ldrh_reg_a1_cond_0) << OP_SF_EBIF_arm_ldrh_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_reg_a1_P_0) >> OP_SF_EBII_arm_ldrh_reg_a1_P_0) << OP_SF_EBIF_arm_ldrh_reg_a1_P_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_reg_a1_U_0) >> OP_SF_EBII_arm_ldrh_reg_a1_U_0) << OP_SF_EBIF_arm_ldrh_reg_a1_U_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_reg_a1_W_0) >> OP_SF_EBII_arm_ldrh_reg_a1_W_0) << OP_SF_EBIF_arm_ldrh_reg_a1_W_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_reg_a1_Rn_0) >> OP_SF_EBII_arm_ldrh_reg_a1_Rn_0) << OP_SF_EBIF_arm_ldrh_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_reg_a1_Rt_0) >> OP_SF_EBII_arm_ldrh_reg_a1_Rt_0) << OP_SF_EBIF_arm_ldrh_reg_a1_Rt_0);
            
        
            context->decoded_code->code.arm_ldrh_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldrh_reg_a1_Rm_0) >> OP_SF_EBII_arm_ldrh_reg_a1_Rm_0) << OP_SF_EBIF_arm_ldrh_reg_a1_Rm_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_ldrh_reg_a1.cond == 15)
         || (context->decoded_code->code.arm_ldrh_reg_a1.Rm == 15)
         || (context->decoded_code->code.arm_ldrh_reg_a1.Rt == 15)
         || (((context->decoded_code->code.arm_ldrh_reg_a1.P == 0)
         || (context->decoded_code->code.arm_ldrh_reg_a1.W == 1)
        )
         && ((context->decoded_code->code.arm_ldrh_reg_a1.Rn == 15)
         || (context->decoded_code->code.arm_ldrh_reg_a1.Rn == context->decoded_code->code.arm_ldrh_reg_a1.Rt)
        )
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_pop_a1 */
    static int op_parse_arm_pop_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_pop_a1) != OP_FB_arm_pop_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_pop_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_pop_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_pop_a1;
        
            context->decoded_code->code.arm_pop_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_pop_a1_cond_0) >> OP_SF_EBII_arm_pop_a1_cond_0) << OP_SF_EBIF_arm_pop_a1_cond_0);
            
        
            context->decoded_code->code.arm_pop_a1.register_list =
            
                (((context->code32x1 & OP_SF_MASK_arm_pop_a1_register_list_0) >> OP_SF_EBII_arm_pop_a1_register_list_0) << OP_SF_EBIF_arm_pop_a1_register_list_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_pop_a1.cond == 15)
         || (setbit_count(context->decoded_code->code.arm_pop_a1.register_list) < 2)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_pop_a2 */
    static int op_parse_arm_pop_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_pop_a2) != OP_FB_arm_pop_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_pop_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_pop_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_pop_a2;
        
            context->decoded_code->code.arm_pop_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_pop_a2_cond_0) >> OP_SF_EBII_arm_pop_a2_cond_0) << OP_SF_EBIF_arm_pop_a2_cond_0);
            
        
            context->decoded_code->code.arm_pop_a2.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_pop_a2_Rt_0) >> OP_SF_EBII_arm_pop_a2_Rt_0) << OP_SF_EBIF_arm_pop_a2_Rt_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_pop_a2.cond == 15)
         || (context->decoded_code->code.arm_pop_a2.Rt == 13)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_ldm_a1 */
    static int op_parse_arm_ldm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_ldm_a1) != OP_FB_arm_ldm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_ldm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_ldm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_ldm_a1;
        
            context->decoded_code->code.arm_ldm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldm_a1_cond_0) >> OP_SF_EBII_arm_ldm_a1_cond_0) << OP_SF_EBIF_arm_ldm_a1_cond_0);
            
        
            context->decoded_code->code.arm_ldm_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldm_a1_W_0) >> OP_SF_EBII_arm_ldm_a1_W_0) << OP_SF_EBIF_arm_ldm_a1_W_0);
            
        
            context->decoded_code->code.arm_ldm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldm_a1_Rn_0) >> OP_SF_EBII_arm_ldm_a1_Rn_0) << OP_SF_EBIF_arm_ldm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_ldm_a1.register_list =
            
                (((context->code32x1 & OP_SF_MASK_arm_ldm_a1_register_list_0) >> OP_SF_EBII_arm_ldm_a1_register_list_0) << OP_SF_EBIF_arm_ldm_a1_register_list_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_ldm_a1.cond == 15)
         || ((context->decoded_code->code.arm_ldm_a1.W == 1)
         && (context->decoded_code->code.arm_ldm_a1.Rn == 13)
         && (setbit_count(context->decoded_code->code.arm_ldm_a1.register_list) > 1)
        )
         || (context->decoded_code->code.arm_ldm_a1.Rn == 15)
         || (setbit_count(context->decoded_code->code.arm_ldm_a1.register_list) < 1)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_nop_a1 */
    static int op_parse_arm_nop_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_nop_a1) != OP_FB_arm_nop_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_nop_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_nop_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_nop_a1;
        
            context->decoded_code->code.arm_nop_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_nop_a1_cond_0) >> OP_SF_EBII_arm_nop_a1_cond_0) << OP_SF_EBIF_arm_nop_a1_cond_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_nop_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_msr_imm_a1 */
    static int op_parse_arm_msr_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_msr_imm_a1) != OP_FB_arm_msr_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_msr_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_msr_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_msr_imm_a1;
        
            context->decoded_code->code.arm_msr_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_msr_imm_a1_cond_0) >> OP_SF_EBII_arm_msr_imm_a1_cond_0) << OP_SF_EBIF_arm_msr_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_msr_imm_a1.mask =
            
                (((context->code32x1 & OP_SF_MASK_arm_msr_imm_a1_mask_0) >> OP_SF_EBII_arm_msr_imm_a1_mask_0) << OP_SF_EBIF_arm_msr_imm_a1_mask_0);
            
        
            context->decoded_code->code.arm_msr_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_msr_imm_a1_imm12_0) >> OP_SF_EBII_arm_msr_imm_a1_imm12_0) << OP_SF_EBIF_arm_msr_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_msr2_imm_a1) != OP_FB_arm_msr2_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_msr2_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_msr2_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_msr2_imm_a1;
        
            context->decoded_code->code.arm_msr2_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_msr2_imm_a1_cond_0) >> OP_SF_EBII_arm_msr2_imm_a1_cond_0) << OP_SF_EBIF_arm_msr2_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_msr2_imm_a1.R =
            
                (((context->code32x1 & OP_SF_MASK_arm_msr2_imm_a1_R_0) >> OP_SF_EBII_arm_msr2_imm_a1_R_0) << OP_SF_EBIF_arm_msr2_imm_a1_R_0);
            
        
            context->decoded_code->code.arm_msr2_imm_a1.mask =
            
                (((context->code32x1 & OP_SF_MASK_arm_msr2_imm_a1_mask_0) >> OP_SF_EBII_arm_msr2_imm_a1_mask_0) << OP_SF_EBIF_arm_msr2_imm_a1_mask_0);
            
        
            context->decoded_code->code.arm_msr2_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_msr2_imm_a1_imm12_0) >> OP_SF_EBII_arm_msr2_imm_a1_imm12_0) << OP_SF_EBIF_arm_msr2_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_mrs_a1) != OP_FB_arm_mrs_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_mrs_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mrs_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mrs_a1;
        
            context->decoded_code->code.arm_mrs_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrs_a1_cond_0) >> OP_SF_EBII_arm_mrs_a1_cond_0) << OP_SF_EBIF_arm_mrs_a1_cond_0);
            
        
            context->decoded_code->code.arm_mrs_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrs_a1_Rd_0) >> OP_SF_EBII_arm_mrs_a1_Rd_0) << OP_SF_EBIF_arm_mrs_a1_Rd_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_msr2_reg_a1) != OP_FB_arm_msr2_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_msr2_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_msr2_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_msr2_reg_a1;
        
            context->decoded_code->code.arm_msr2_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_msr2_reg_a1_cond_0) >> OP_SF_EBII_arm_msr2_reg_a1_cond_0) << OP_SF_EBIF_arm_msr2_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_msr2_reg_a1.R =
            
                (((context->code32x1 & OP_SF_MASK_arm_msr2_reg_a1_R_0) >> OP_SF_EBII_arm_msr2_reg_a1_R_0) << OP_SF_EBIF_arm_msr2_reg_a1_R_0);
            
        
            context->decoded_code->code.arm_msr2_reg_a1.mask =
            
                (((context->code32x1 & OP_SF_MASK_arm_msr2_reg_a1_mask_0) >> OP_SF_EBII_arm_msr2_reg_a1_mask_0) << OP_SF_EBIF_arm_msr2_reg_a1_mask_0);
            
        
            context->decoded_code->code.arm_msr2_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_msr2_reg_a1_Rn_0) >> OP_SF_EBII_arm_msr2_reg_a1_Rn_0) << OP_SF_EBIF_arm_msr2_reg_a1_Rn_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_mcr_a1) != OP_FB_arm_mcr_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_mcr_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mcr_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mcr_a1;
        
            context->decoded_code->code.arm_mcr_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr_a1_cond_0) >> OP_SF_EBII_arm_mcr_a1_cond_0) << OP_SF_EBIF_arm_mcr_a1_cond_0);
            
        
            context->decoded_code->code.arm_mcr_a1.opc1 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr_a1_opc1_0) >> OP_SF_EBII_arm_mcr_a1_opc1_0) << OP_SF_EBIF_arm_mcr_a1_opc1_0);
            
        
            context->decoded_code->code.arm_mcr_a1.CRn =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr_a1_CRn_0) >> OP_SF_EBII_arm_mcr_a1_CRn_0) << OP_SF_EBIF_arm_mcr_a1_CRn_0);
            
        
            context->decoded_code->code.arm_mcr_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr_a1_Rt_0) >> OP_SF_EBII_arm_mcr_a1_Rt_0) << OP_SF_EBIF_arm_mcr_a1_Rt_0);
            
        
            context->decoded_code->code.arm_mcr_a1.coproc =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr_a1_coproc_0) >> OP_SF_EBII_arm_mcr_a1_coproc_0) << OP_SF_EBIF_arm_mcr_a1_coproc_0);
            
        
            context->decoded_code->code.arm_mcr_a1.opc2 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr_a1_opc2_0) >> OP_SF_EBII_arm_mcr_a1_opc2_0) << OP_SF_EBIF_arm_mcr_a1_opc2_0);
            
        
            context->decoded_code->code.arm_mcr_a1.CRm =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr_a1_CRm_0) >> OP_SF_EBII_arm_mcr_a1_CRm_0) << OP_SF_EBIF_arm_mcr_a1_CRm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_mcr2_a2) != OP_FB_arm_mcr2_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_mcr2_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mcr2_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mcr2_a2;
        
            context->decoded_code->code.arm_mcr2_a2.opc1 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr2_a2_opc1_0) >> OP_SF_EBII_arm_mcr2_a2_opc1_0) << OP_SF_EBIF_arm_mcr2_a2_opc1_0);
            
        
            context->decoded_code->code.arm_mcr2_a2.CRn =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr2_a2_CRn_0) >> OP_SF_EBII_arm_mcr2_a2_CRn_0) << OP_SF_EBIF_arm_mcr2_a2_CRn_0);
            
        
            context->decoded_code->code.arm_mcr2_a2.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr2_a2_Rt_0) >> OP_SF_EBII_arm_mcr2_a2_Rt_0) << OP_SF_EBIF_arm_mcr2_a2_Rt_0);
            
        
            context->decoded_code->code.arm_mcr2_a2.coproc =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr2_a2_coproc_0) >> OP_SF_EBII_arm_mcr2_a2_coproc_0) << OP_SF_EBIF_arm_mcr2_a2_coproc_0);
            
        
            context->decoded_code->code.arm_mcr2_a2.opc2 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr2_a2_opc2_0) >> OP_SF_EBII_arm_mcr2_a2_opc2_0) << OP_SF_EBIF_arm_mcr2_a2_opc2_0);
            
        
            context->decoded_code->code.arm_mcr2_a2.CRm =
            
                (((context->code32x1 & OP_SF_MASK_arm_mcr2_a2_CRm_0) >> OP_SF_EBII_arm_mcr2_a2_CRm_0) << OP_SF_EBIF_arm_mcr2_a2_CRm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_mrc_a1) != OP_FB_arm_mrc_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_mrc_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mrc_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mrc_a1;
        
            context->decoded_code->code.arm_mrc_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc_a1_cond_0) >> OP_SF_EBII_arm_mrc_a1_cond_0) << OP_SF_EBIF_arm_mrc_a1_cond_0);
            
        
            context->decoded_code->code.arm_mrc_a1.opc1 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc_a1_opc1_0) >> OP_SF_EBII_arm_mrc_a1_opc1_0) << OP_SF_EBIF_arm_mrc_a1_opc1_0);
            
        
            context->decoded_code->code.arm_mrc_a1.CRn =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc_a1_CRn_0) >> OP_SF_EBII_arm_mrc_a1_CRn_0) << OP_SF_EBIF_arm_mrc_a1_CRn_0);
            
        
            context->decoded_code->code.arm_mrc_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc_a1_Rt_0) >> OP_SF_EBII_arm_mrc_a1_Rt_0) << OP_SF_EBIF_arm_mrc_a1_Rt_0);
            
        
            context->decoded_code->code.arm_mrc_a1.coproc =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc_a1_coproc_0) >> OP_SF_EBII_arm_mrc_a1_coproc_0) << OP_SF_EBIF_arm_mrc_a1_coproc_0);
            
        
            context->decoded_code->code.arm_mrc_a1.opc2 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc_a1_opc2_0) >> OP_SF_EBII_arm_mrc_a1_opc2_0) << OP_SF_EBIF_arm_mrc_a1_opc2_0);
            
        
            context->decoded_code->code.arm_mrc_a1.CRm =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc_a1_CRm_0) >> OP_SF_EBII_arm_mrc_a1_CRm_0) << OP_SF_EBIF_arm_mrc_a1_CRm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_mrc2_a2) != OP_FB_arm_mrc2_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_mrc2_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mrc2_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mrc2_a2;
        
            context->decoded_code->code.arm_mrc2_a2.opc1 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc2_a2_opc1_0) >> OP_SF_EBII_arm_mrc2_a2_opc1_0) << OP_SF_EBIF_arm_mrc2_a2_opc1_0);
            
        
            context->decoded_code->code.arm_mrc2_a2.CRn =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc2_a2_CRn_0) >> OP_SF_EBII_arm_mrc2_a2_CRn_0) << OP_SF_EBIF_arm_mrc2_a2_CRn_0);
            
        
            context->decoded_code->code.arm_mrc2_a2.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc2_a2_Rt_0) >> OP_SF_EBII_arm_mrc2_a2_Rt_0) << OP_SF_EBIF_arm_mrc2_a2_Rt_0);
            
        
            context->decoded_code->code.arm_mrc2_a2.coproc =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc2_a2_coproc_0) >> OP_SF_EBII_arm_mrc2_a2_coproc_0) << OP_SF_EBIF_arm_mrc2_a2_coproc_0);
            
        
            context->decoded_code->code.arm_mrc2_a2.opc2 =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc2_a2_opc2_0) >> OP_SF_EBII_arm_mrc2_a2_opc2_0) << OP_SF_EBIF_arm_mrc2_a2_opc2_0);
            
        
            context->decoded_code->code.arm_mrc2_a2.CRm =
            
                (((context->code32x1 & OP_SF_MASK_arm_mrc2_a2_CRm_0) >> OP_SF_EBII_arm_mrc2_a2_CRm_0) << OP_SF_EBIF_arm_mrc2_a2_CRm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_bic_imm_a1) != OP_FB_arm_bic_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_bic_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_bic_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_bic_imm_a1;
        
            context->decoded_code->code.arm_bic_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_bic_imm_a1_cond_0) >> OP_SF_EBII_arm_bic_imm_a1_cond_0) << OP_SF_EBIF_arm_bic_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_bic_imm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_bic_imm_a1_S_0) >> OP_SF_EBII_arm_bic_imm_a1_S_0) << OP_SF_EBIF_arm_bic_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_bic_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_bic_imm_a1_Rn_0) >> OP_SF_EBII_arm_bic_imm_a1_Rn_0) << OP_SF_EBIF_arm_bic_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_bic_imm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_bic_imm_a1_Rd_0) >> OP_SF_EBII_arm_bic_imm_a1_Rd_0) << OP_SF_EBIF_arm_bic_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_bic_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_bic_imm_a1_imm12_0) >> OP_SF_EBII_arm_bic_imm_a1_imm12_0) << OP_SF_EBIF_arm_bic_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_orr_imm_a1) != OP_FB_arm_orr_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_orr_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_orr_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_orr_imm_a1;
        
            context->decoded_code->code.arm_orr_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_imm_a1_cond_0) >> OP_SF_EBII_arm_orr_imm_a1_cond_0) << OP_SF_EBIF_arm_orr_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_orr_imm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_imm_a1_S_0) >> OP_SF_EBII_arm_orr_imm_a1_S_0) << OP_SF_EBIF_arm_orr_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_orr_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_imm_a1_Rn_0) >> OP_SF_EBII_arm_orr_imm_a1_Rn_0) << OP_SF_EBIF_arm_orr_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_orr_imm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_imm_a1_Rd_0) >> OP_SF_EBII_arm_orr_imm_a1_Rd_0) << OP_SF_EBIF_arm_orr_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_orr_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_imm_a1_imm12_0) >> OP_SF_EBII_arm_orr_imm_a1_imm12_0) << OP_SF_EBIF_arm_orr_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_orr_reg_a1) != OP_FB_arm_orr_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_orr_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_orr_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_orr_reg_a1;
        
            context->decoded_code->code.arm_orr_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_reg_a1_cond_0) >> OP_SF_EBII_arm_orr_reg_a1_cond_0) << OP_SF_EBIF_arm_orr_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_reg_a1_S_0) >> OP_SF_EBII_arm_orr_reg_a1_S_0) << OP_SF_EBIF_arm_orr_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_reg_a1_Rn_0) >> OP_SF_EBII_arm_orr_reg_a1_Rn_0) << OP_SF_EBIF_arm_orr_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_reg_a1_Rd_0) >> OP_SF_EBII_arm_orr_reg_a1_Rd_0) << OP_SF_EBIF_arm_orr_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_reg_a1_imm5_0) >> OP_SF_EBII_arm_orr_reg_a1_imm5_0) << OP_SF_EBIF_arm_orr_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_reg_a1_type_0) >> OP_SF_EBII_arm_orr_reg_a1_type_0) << OP_SF_EBIF_arm_orr_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_orr_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_orr_reg_a1_Rm_0) >> OP_SF_EBII_arm_orr_reg_a1_Rm_0) << OP_SF_EBIF_arm_orr_reg_a1_Rm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_movt_a1) != OP_FB_arm_movt_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_movt_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_movt_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_movt_a1;
        
            context->decoded_code->code.arm_movt_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_movt_a1_cond_0) >> OP_SF_EBII_arm_movt_a1_cond_0) << OP_SF_EBIF_arm_movt_a1_cond_0);
            
        
            context->decoded_code->code.arm_movt_a1.imm16 =
            
                (((context->code32x1 & OP_SF_MASK_arm_movt_a1_imm16_0) >> OP_SF_EBII_arm_movt_a1_imm16_0) << OP_SF_EBIF_arm_movt_a1_imm16_0)
            
                | (((context->code32x1 & OP_SF_MASK_arm_movt_a1_imm16_1) >> OP_SF_EBII_arm_movt_a1_imm16_1) << OP_SF_EBIF_arm_movt_a1_imm16_1);
            
        
            context->decoded_code->code.arm_movt_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_movt_a1_Rd_0) >> OP_SF_EBII_arm_movt_a1_Rd_0) << OP_SF_EBIF_arm_movt_a1_Rd_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_lsl_imm_a1) != OP_FB_arm_lsl_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_lsl_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_lsl_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_lsl_imm_a1;
        
            context->decoded_code->code.arm_lsl_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsl_imm_a1_cond_0) >> OP_SF_EBII_arm_lsl_imm_a1_cond_0) << OP_SF_EBIF_arm_lsl_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_lsl_imm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsl_imm_a1_S_0) >> OP_SF_EBII_arm_lsl_imm_a1_S_0) << OP_SF_EBIF_arm_lsl_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_lsl_imm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsl_imm_a1_Rd_0) >> OP_SF_EBII_arm_lsl_imm_a1_Rd_0) << OP_SF_EBIF_arm_lsl_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_lsl_imm_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsl_imm_a1_imm5_0) >> OP_SF_EBII_arm_lsl_imm_a1_imm5_0) << OP_SF_EBIF_arm_lsl_imm_a1_imm5_0);
            
        
            context->decoded_code->code.arm_lsl_imm_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsl_imm_a1_Rm_0) >> OP_SF_EBII_arm_lsl_imm_a1_Rm_0) << OP_SF_EBIF_arm_lsl_imm_a1_Rm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_lsl_reg_a1) != OP_FB_arm_lsl_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_lsl_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_lsl_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_lsl_reg_a1;
        
            context->decoded_code->code.arm_lsl_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsl_reg_a1_cond_0) >> OP_SF_EBII_arm_lsl_reg_a1_cond_0) << OP_SF_EBIF_arm_lsl_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_lsl_reg_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsl_reg_a1_S_0) >> OP_SF_EBII_arm_lsl_reg_a1_S_0) << OP_SF_EBIF_arm_lsl_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_lsl_reg_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsl_reg_a1_Rd_0) >> OP_SF_EBII_arm_lsl_reg_a1_Rd_0) << OP_SF_EBIF_arm_lsl_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_lsl_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsl_reg_a1_Rm_0) >> OP_SF_EBII_arm_lsl_reg_a1_Rm_0) << OP_SF_EBIF_arm_lsl_reg_a1_Rm_0);
            
        
            context->decoded_code->code.arm_lsl_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsl_reg_a1_Rn_0) >> OP_SF_EBII_arm_lsl_reg_a1_Rn_0) << OP_SF_EBIF_arm_lsl_reg_a1_Rn_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_lsr_imm_a1) != OP_FB_arm_lsr_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_lsr_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_lsr_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_lsr_imm_a1;
        
            context->decoded_code->code.arm_lsr_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsr_imm_a1_cond_0) >> OP_SF_EBII_arm_lsr_imm_a1_cond_0) << OP_SF_EBIF_arm_lsr_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_lsr_imm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsr_imm_a1_S_0) >> OP_SF_EBII_arm_lsr_imm_a1_S_0) << OP_SF_EBIF_arm_lsr_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_lsr_imm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsr_imm_a1_Rd_0) >> OP_SF_EBII_arm_lsr_imm_a1_Rd_0) << OP_SF_EBIF_arm_lsr_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_lsr_imm_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsr_imm_a1_imm5_0) >> OP_SF_EBII_arm_lsr_imm_a1_imm5_0) << OP_SF_EBIF_arm_lsr_imm_a1_imm5_0);
            
        
            context->decoded_code->code.arm_lsr_imm_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsr_imm_a1_Rm_0) >> OP_SF_EBII_arm_lsr_imm_a1_Rm_0) << OP_SF_EBIF_arm_lsr_imm_a1_Rm_0);
            
        
        
        
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

    /* arm_lsr_reg_a1 */
    static int op_parse_arm_lsr_reg_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_lsr_reg_a1) != OP_FB_arm_lsr_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_lsr_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_lsr_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_lsr_reg_a1;
        
            context->decoded_code->code.arm_lsr_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsr_reg_a1_cond_0) >> OP_SF_EBII_arm_lsr_reg_a1_cond_0) << OP_SF_EBIF_arm_lsr_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_lsr_reg_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsr_reg_a1_S_0) >> OP_SF_EBII_arm_lsr_reg_a1_S_0) << OP_SF_EBIF_arm_lsr_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_lsr_reg_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsr_reg_a1_Rd_0) >> OP_SF_EBII_arm_lsr_reg_a1_Rd_0) << OP_SF_EBIF_arm_lsr_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_lsr_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsr_reg_a1_Rm_0) >> OP_SF_EBII_arm_lsr_reg_a1_Rm_0) << OP_SF_EBIF_arm_lsr_reg_a1_Rm_0);
            
        
            context->decoded_code->code.arm_lsr_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_lsr_reg_a1_Rn_0) >> OP_SF_EBII_arm_lsr_reg_a1_Rn_0) << OP_SF_EBIF_arm_lsr_reg_a1_Rn_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_lsr_reg_a1.cond == 15)
         || ((context->decoded_code->code.arm_lsr_reg_a1.Rd == 15)
         || (context->decoded_code->code.arm_lsr_reg_a1.Rm == 15)
         || (context->decoded_code->code.arm_lsr_reg_a1.Rn == 15)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_bfc_a1 */
    static int op_parse_arm_bfc_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_bfc_a1) != OP_FB_arm_bfc_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_bfc_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_bfc_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_bfc_a1;
        
            context->decoded_code->code.arm_bfc_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_bfc_a1_cond_0) >> OP_SF_EBII_arm_bfc_a1_cond_0) << OP_SF_EBIF_arm_bfc_a1_cond_0);
            
        
            context->decoded_code->code.arm_bfc_a1.msb =
            
                (((context->code32x1 & OP_SF_MASK_arm_bfc_a1_msb_0) >> OP_SF_EBII_arm_bfc_a1_msb_0) << OP_SF_EBIF_arm_bfc_a1_msb_0);
            
        
            context->decoded_code->code.arm_bfc_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_bfc_a1_Rd_0) >> OP_SF_EBII_arm_bfc_a1_Rd_0) << OP_SF_EBIF_arm_bfc_a1_Rd_0);
            
        
            context->decoded_code->code.arm_bfc_a1.lsb =
            
                (((context->code32x1 & OP_SF_MASK_arm_bfc_a1_lsb_0) >> OP_SF_EBII_arm_bfc_a1_lsb_0) << OP_SF_EBIF_arm_bfc_a1_lsb_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_and_imm_a1) != OP_FB_arm_and_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_and_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_and_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_and_imm_a1;
        
            context->decoded_code->code.arm_and_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_imm_a1_cond_0) >> OP_SF_EBII_arm_and_imm_a1_cond_0) << OP_SF_EBIF_arm_and_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_and_imm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_imm_a1_S_0) >> OP_SF_EBII_arm_and_imm_a1_S_0) << OP_SF_EBIF_arm_and_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_and_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_imm_a1_Rn_0) >> OP_SF_EBII_arm_and_imm_a1_Rn_0) << OP_SF_EBIF_arm_and_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_and_imm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_imm_a1_Rd_0) >> OP_SF_EBII_arm_and_imm_a1_Rd_0) << OP_SF_EBIF_arm_and_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_and_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_imm_a1_imm12_0) >> OP_SF_EBII_arm_and_imm_a1_imm12_0) << OP_SF_EBIF_arm_and_imm_a1_imm12_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_and_reg_a1) != OP_FB_arm_and_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_and_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_and_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_and_reg_a1;
        
            context->decoded_code->code.arm_and_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_reg_a1_cond_0) >> OP_SF_EBII_arm_and_reg_a1_cond_0) << OP_SF_EBIF_arm_and_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_reg_a1_S_0) >> OP_SF_EBII_arm_and_reg_a1_S_0) << OP_SF_EBIF_arm_and_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_reg_a1_Rn_0) >> OP_SF_EBII_arm_and_reg_a1_Rn_0) << OP_SF_EBIF_arm_and_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_reg_a1_Rd_0) >> OP_SF_EBII_arm_and_reg_a1_Rd_0) << OP_SF_EBIF_arm_and_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_reg_a1_imm5_0) >> OP_SF_EBII_arm_and_reg_a1_imm5_0) << OP_SF_EBIF_arm_and_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_reg_a1_type_0) >> OP_SF_EBII_arm_and_reg_a1_type_0) << OP_SF_EBIF_arm_and_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_and_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_and_reg_a1_Rm_0) >> OP_SF_EBII_arm_and_reg_a1_Rm_0) << OP_SF_EBIF_arm_and_reg_a1_Rm_0);
            
        
        
        
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

    /* arm_uxtb_a1 */
    static int op_parse_arm_uxtb_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_uxtb_a1) != OP_FB_arm_uxtb_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_uxtb_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_uxtb_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_uxtb_a1;
        
            context->decoded_code->code.arm_uxtb_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_uxtb_a1_cond_0) >> OP_SF_EBII_arm_uxtb_a1_cond_0) << OP_SF_EBIF_arm_uxtb_a1_cond_0);
            
        
            context->decoded_code->code.arm_uxtb_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_uxtb_a1_Rd_0) >> OP_SF_EBII_arm_uxtb_a1_Rd_0) << OP_SF_EBIF_arm_uxtb_a1_Rd_0);
            
        
            context->decoded_code->code.arm_uxtb_a1.rotate =
            
                (((context->code32x1 & OP_SF_MASK_arm_uxtb_a1_rotate_0) >> OP_SF_EBII_arm_uxtb_a1_rotate_0) << OP_SF_EBIF_arm_uxtb_a1_rotate_0);
            
        
            context->decoded_code->code.arm_uxtb_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_uxtb_a1_Rm_0) >> OP_SF_EBII_arm_uxtb_a1_Rm_0) << OP_SF_EBIF_arm_uxtb_a1_Rm_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_uxtb_a1.cond == 15)
         || (context->decoded_code->code.arm_uxtb_a1.Rd == 15)
         || (context->decoded_code->code.arm_uxtb_a1.Rm == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_uxth_a1 */
    static int op_parse_arm_uxth_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_uxth_a1) != OP_FB_arm_uxth_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_uxth_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_uxth_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_uxth_a1;
        
            context->decoded_code->code.arm_uxth_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_uxth_a1_cond_0) >> OP_SF_EBII_arm_uxth_a1_cond_0) << OP_SF_EBIF_arm_uxth_a1_cond_0);
            
        
            context->decoded_code->code.arm_uxth_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_uxth_a1_Rd_0) >> OP_SF_EBII_arm_uxth_a1_Rd_0) << OP_SF_EBIF_arm_uxth_a1_Rd_0);
            
        
            context->decoded_code->code.arm_uxth_a1.rotate =
            
                (((context->code32x1 & OP_SF_MASK_arm_uxth_a1_rotate_0) >> OP_SF_EBII_arm_uxth_a1_rotate_0) << OP_SF_EBIF_arm_uxth_a1_rotate_0);
            
        
            context->decoded_code->code.arm_uxth_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_uxth_a1_Rm_0) >> OP_SF_EBII_arm_uxth_a1_Rm_0) << OP_SF_EBIF_arm_uxth_a1_Rm_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_uxth_a1.cond == 15)
         || (context->decoded_code->code.arm_uxth_a1.Rd == 15)
         || (context->decoded_code->code.arm_uxth_a1.Rm == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_rsb_reg_a1 */
    static int op_parse_arm_rsb_reg_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_rsb_reg_a1) != OP_FB_arm_rsb_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_rsb_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_rsb_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_rsb_reg_a1;
        
            context->decoded_code->code.arm_rsb_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_reg_a1_cond_0) >> OP_SF_EBII_arm_rsb_reg_a1_cond_0) << OP_SF_EBIF_arm_rsb_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_reg_a1_S_0) >> OP_SF_EBII_arm_rsb_reg_a1_S_0) << OP_SF_EBIF_arm_rsb_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_reg_a1_Rn_0) >> OP_SF_EBII_arm_rsb_reg_a1_Rn_0) << OP_SF_EBIF_arm_rsb_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_reg_a1_Rd_0) >> OP_SF_EBII_arm_rsb_reg_a1_Rd_0) << OP_SF_EBIF_arm_rsb_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_reg_a1_imm5_0) >> OP_SF_EBII_arm_rsb_reg_a1_imm5_0) << OP_SF_EBIF_arm_rsb_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_reg_a1_type_0) >> OP_SF_EBII_arm_rsb_reg_a1_type_0) << OP_SF_EBIF_arm_rsb_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_rsb_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_reg_a1_Rm_0) >> OP_SF_EBII_arm_rsb_reg_a1_Rm_0) << OP_SF_EBIF_arm_rsb_reg_a1_Rm_0);
            
        
        
        
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

    /* arm_rsb_imm_a1 */
    static int op_parse_arm_rsb_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_rsb_imm_a1) != OP_FB_arm_rsb_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_rsb_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_rsb_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_rsb_imm_a1;
        
            context->decoded_code->code.arm_rsb_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_imm_a1_cond_0) >> OP_SF_EBII_arm_rsb_imm_a1_cond_0) << OP_SF_EBIF_arm_rsb_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_rsb_imm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_imm_a1_S_0) >> OP_SF_EBII_arm_rsb_imm_a1_S_0) << OP_SF_EBIF_arm_rsb_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_rsb_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_imm_a1_Rn_0) >> OP_SF_EBII_arm_rsb_imm_a1_Rn_0) << OP_SF_EBIF_arm_rsb_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_rsb_imm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_imm_a1_Rd_0) >> OP_SF_EBII_arm_rsb_imm_a1_Rd_0) << OP_SF_EBIF_arm_rsb_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_rsb_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_rsb_imm_a1_imm12_0) >> OP_SF_EBII_arm_rsb_imm_a1_imm12_0) << OP_SF_EBIF_arm_rsb_imm_a1_imm12_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_rsb_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_rsb_imm_a1.Rd == 15)
         && (context->decoded_code->code.arm_rsb_imm_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_sbc_reg_a1 */
    static int op_parse_arm_sbc_reg_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_sbc_reg_a1) != OP_FB_arm_sbc_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_sbc_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_sbc_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_sbc_reg_a1;
        
            context->decoded_code->code.arm_sbc_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_sbc_reg_a1_cond_0) >> OP_SF_EBII_arm_sbc_reg_a1_cond_0) << OP_SF_EBIF_arm_sbc_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_sbc_reg_a1_S_0) >> OP_SF_EBII_arm_sbc_reg_a1_S_0) << OP_SF_EBIF_arm_sbc_reg_a1_S_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_sbc_reg_a1_Rn_0) >> OP_SF_EBII_arm_sbc_reg_a1_Rn_0) << OP_SF_EBIF_arm_sbc_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_sbc_reg_a1_Rd_0) >> OP_SF_EBII_arm_sbc_reg_a1_Rd_0) << OP_SF_EBIF_arm_sbc_reg_a1_Rd_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_sbc_reg_a1_imm5_0) >> OP_SF_EBII_arm_sbc_reg_a1_imm5_0) << OP_SF_EBIF_arm_sbc_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_sbc_reg_a1_type_0) >> OP_SF_EBII_arm_sbc_reg_a1_type_0) << OP_SF_EBIF_arm_sbc_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_sbc_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_sbc_reg_a1_Rm_0) >> OP_SF_EBII_arm_sbc_reg_a1_Rm_0) << OP_SF_EBIF_arm_sbc_reg_a1_Rm_0);
            
        
        
        
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
        if ((context->code32x1 & OP_FB_MASK_arm_mul_a1) != OP_FB_arm_mul_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_mul_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_mul_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_mul_a1;
        
            context->decoded_code->code.arm_mul_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_mul_a1_cond_0) >> OP_SF_EBII_arm_mul_a1_cond_0) << OP_SF_EBIF_arm_mul_a1_cond_0);
            
        
            context->decoded_code->code.arm_mul_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_mul_a1_S_0) >> OP_SF_EBII_arm_mul_a1_S_0) << OP_SF_EBIF_arm_mul_a1_S_0);
            
        
            context->decoded_code->code.arm_mul_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_mul_a1_Rd_0) >> OP_SF_EBII_arm_mul_a1_Rd_0) << OP_SF_EBIF_arm_mul_a1_Rd_0);
            
        
            context->decoded_code->code.arm_mul_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_mul_a1_Rm_0) >> OP_SF_EBII_arm_mul_a1_Rm_0) << OP_SF_EBIF_arm_mul_a1_Rm_0);
            
        
            context->decoded_code->code.arm_mul_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_mul_a1_Rn_0) >> OP_SF_EBII_arm_mul_a1_Rn_0) << OP_SF_EBIF_arm_mul_a1_Rn_0);
            
        
        
        
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

    /* arm_smmul_a1 */
    static int op_parse_arm_smmul_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_smmul_a1) != OP_FB_arm_smmul_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_smmul_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_smmul_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_smmul_a1;
        
            context->decoded_code->code.arm_smmul_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_smmul_a1_cond_0) >> OP_SF_EBII_arm_smmul_a1_cond_0) << OP_SF_EBIF_arm_smmul_a1_cond_0);
            
        
            context->decoded_code->code.arm_smmul_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_smmul_a1_Rd_0) >> OP_SF_EBII_arm_smmul_a1_Rd_0) << OP_SF_EBIF_arm_smmul_a1_Rd_0);
            
        
            context->decoded_code->code.arm_smmul_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_smmul_a1_Rm_0) >> OP_SF_EBII_arm_smmul_a1_Rm_0) << OP_SF_EBIF_arm_smmul_a1_Rm_0);
            
        
            context->decoded_code->code.arm_smmul_a1.R =
            
                (((context->code32x1 & OP_SF_MASK_arm_smmul_a1_R_0) >> OP_SF_EBII_arm_smmul_a1_R_0) << OP_SF_EBIF_arm_smmul_a1_R_0);
            
        
            context->decoded_code->code.arm_smmul_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_smmul_a1_Rn_0) >> OP_SF_EBII_arm_smmul_a1_Rn_0) << OP_SF_EBIF_arm_smmul_a1_Rn_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_smmul_a1.cond == 15)
         || (context->decoded_code->code.arm_smmul_a1.Rd == 15)
         || (context->decoded_code->code.arm_smmul_a1.Rm == 15)
         || (context->decoded_code->code.arm_smmul_a1.Rn == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_smull_a1 */
    static int op_parse_arm_smull_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_smull_a1) != OP_FB_arm_smull_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_smull_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_smull_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_smull_a1;
        
            context->decoded_code->code.arm_smull_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_smull_a1_cond_0) >> OP_SF_EBII_arm_smull_a1_cond_0) << OP_SF_EBIF_arm_smull_a1_cond_0);
            
        
            context->decoded_code->code.arm_smull_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_smull_a1_S_0) >> OP_SF_EBII_arm_smull_a1_S_0) << OP_SF_EBIF_arm_smull_a1_S_0);
            
        
            context->decoded_code->code.arm_smull_a1.RdHi =
            
                (((context->code32x1 & OP_SF_MASK_arm_smull_a1_RdHi_0) >> OP_SF_EBII_arm_smull_a1_RdHi_0) << OP_SF_EBIF_arm_smull_a1_RdHi_0);
            
        
            context->decoded_code->code.arm_smull_a1.RdLo =
            
                (((context->code32x1 & OP_SF_MASK_arm_smull_a1_RdLo_0) >> OP_SF_EBII_arm_smull_a1_RdLo_0) << OP_SF_EBIF_arm_smull_a1_RdLo_0);
            
        
            context->decoded_code->code.arm_smull_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_smull_a1_Rm_0) >> OP_SF_EBII_arm_smull_a1_Rm_0) << OP_SF_EBIF_arm_smull_a1_Rm_0);
            
        
            context->decoded_code->code.arm_smull_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_smull_a1_Rn_0) >> OP_SF_EBII_arm_smull_a1_Rn_0) << OP_SF_EBIF_arm_smull_a1_Rn_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_smull_a1.cond == 15)
         || (context->decoded_code->code.arm_smull_a1.RdHi == 15)
         || (context->decoded_code->code.arm_smull_a1.RdLo == 15)
         || (context->decoded_code->code.arm_smull_a1.Rm == 15)
         || (context->decoded_code->code.arm_smull_a1.Rn == 15)
         || (context->decoded_code->code.arm_smull_a1.RdHi == context->decoded_code->code.arm_smull_a1.RdLo)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_tst_imm_a1 */
    static int op_parse_arm_tst_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_tst_imm_a1) != OP_FB_arm_tst_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_tst_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_tst_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_tst_imm_a1;
        
            context->decoded_code->code.arm_tst_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_tst_imm_a1_cond_0) >> OP_SF_EBII_arm_tst_imm_a1_cond_0) << OP_SF_EBIF_arm_tst_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_tst_imm_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_tst_imm_a1_Rn_0) >> OP_SF_EBII_arm_tst_imm_a1_Rn_0) << OP_SF_EBIF_arm_tst_imm_a1_Rn_0);
            
        
            context->decoded_code->code.arm_tst_imm_a1.imm12 =
            
                (((context->code32x1 & OP_SF_MASK_arm_tst_imm_a1_imm12_0) >> OP_SF_EBII_arm_tst_imm_a1_imm12_0) << OP_SF_EBIF_arm_tst_imm_a1_imm12_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_tst_imm_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_tst_reg_a1 */
    static int op_parse_arm_tst_reg_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_tst_reg_a1) != OP_FB_arm_tst_reg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_tst_reg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_tst_reg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_tst_reg_a1;
        
            context->decoded_code->code.arm_tst_reg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_tst_reg_a1_cond_0) >> OP_SF_EBII_arm_tst_reg_a1_cond_0) << OP_SF_EBIF_arm_tst_reg_a1_cond_0);
            
        
            context->decoded_code->code.arm_tst_reg_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_tst_reg_a1_Rn_0) >> OP_SF_EBII_arm_tst_reg_a1_Rn_0) << OP_SF_EBIF_arm_tst_reg_a1_Rn_0);
            
        
            context->decoded_code->code.arm_tst_reg_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_tst_reg_a1_imm5_0) >> OP_SF_EBII_arm_tst_reg_a1_imm5_0) << OP_SF_EBIF_arm_tst_reg_a1_imm5_0);
            
        
            context->decoded_code->code.arm_tst_reg_a1.type =
            
                (((context->code32x1 & OP_SF_MASK_arm_tst_reg_a1_type_0) >> OP_SF_EBII_arm_tst_reg_a1_type_0) << OP_SF_EBIF_arm_tst_reg_a1_type_0);
            
        
            context->decoded_code->code.arm_tst_reg_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_tst_reg_a1_Rm_0) >> OP_SF_EBII_arm_tst_reg_a1_Rm_0) << OP_SF_EBIF_arm_tst_reg_a1_Rm_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_tst_reg_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_sxtb_a1 */
    static int op_parse_arm_sxtb_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_sxtb_a1) != OP_FB_arm_sxtb_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_sxtb_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_sxtb_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_sxtb_a1;
        
            context->decoded_code->code.arm_sxtb_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_sxtb_a1_cond_0) >> OP_SF_EBII_arm_sxtb_a1_cond_0) << OP_SF_EBIF_arm_sxtb_a1_cond_0);
            
        
            context->decoded_code->code.arm_sxtb_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_sxtb_a1_Rd_0) >> OP_SF_EBII_arm_sxtb_a1_Rd_0) << OP_SF_EBIF_arm_sxtb_a1_Rd_0);
            
        
            context->decoded_code->code.arm_sxtb_a1.rotate =
            
                (((context->code32x1 & OP_SF_MASK_arm_sxtb_a1_rotate_0) >> OP_SF_EBII_arm_sxtb_a1_rotate_0) << OP_SF_EBIF_arm_sxtb_a1_rotate_0);
            
        
            context->decoded_code->code.arm_sxtb_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_sxtb_a1_Rm_0) >> OP_SF_EBII_arm_sxtb_a1_Rm_0) << OP_SF_EBIF_arm_sxtb_a1_Rm_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_sxtb_a1.cond == 15)
         || (context->decoded_code->code.arm_sxtb_a1.Rd == 15)
         || (context->decoded_code->code.arm_sxtb_a1.Rm == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_sxth_a1 */
    static int op_parse_arm_sxth_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_sxth_a1) != OP_FB_arm_sxth_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_sxth_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_sxth_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_sxth_a1;
        
            context->decoded_code->code.arm_sxth_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_sxth_a1_cond_0) >> OP_SF_EBII_arm_sxth_a1_cond_0) << OP_SF_EBIF_arm_sxth_a1_cond_0);
            
        
            context->decoded_code->code.arm_sxth_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_sxth_a1_Rd_0) >> OP_SF_EBII_arm_sxth_a1_Rd_0) << OP_SF_EBIF_arm_sxth_a1_Rd_0);
            
        
            context->decoded_code->code.arm_sxth_a1.rotate =
            
                (((context->code32x1 & OP_SF_MASK_arm_sxth_a1_rotate_0) >> OP_SF_EBII_arm_sxth_a1_rotate_0) << OP_SF_EBIF_arm_sxth_a1_rotate_0);
            
        
            context->decoded_code->code.arm_sxth_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_sxth_a1_Rm_0) >> OP_SF_EBII_arm_sxth_a1_Rm_0) << OP_SF_EBIF_arm_sxth_a1_Rm_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_sxth_a1.cond == 15)
         || (context->decoded_code->code.arm_sxth_a1.Rd == 15)
         || (context->decoded_code->code.arm_sxth_a1.Rm == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_asr_imm_a1 */
    static int op_parse_arm_asr_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_asr_imm_a1) != OP_FB_arm_asr_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_asr_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_asr_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_asr_imm_a1;
        
            context->decoded_code->code.arm_asr_imm_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_asr_imm_a1_cond_0) >> OP_SF_EBII_arm_asr_imm_a1_cond_0) << OP_SF_EBIF_arm_asr_imm_a1_cond_0);
            
        
            context->decoded_code->code.arm_asr_imm_a1.S =
            
                (((context->code32x1 & OP_SF_MASK_arm_asr_imm_a1_S_0) >> OP_SF_EBII_arm_asr_imm_a1_S_0) << OP_SF_EBIF_arm_asr_imm_a1_S_0);
            
        
            context->decoded_code->code.arm_asr_imm_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_asr_imm_a1_Rd_0) >> OP_SF_EBII_arm_asr_imm_a1_Rd_0) << OP_SF_EBIF_arm_asr_imm_a1_Rd_0);
            
        
            context->decoded_code->code.arm_asr_imm_a1.imm5 =
            
                (((context->code32x1 & OP_SF_MASK_arm_asr_imm_a1_imm5_0) >> OP_SF_EBII_arm_asr_imm_a1_imm5_0) << OP_SF_EBIF_arm_asr_imm_a1_imm5_0);
            
        
            context->decoded_code->code.arm_asr_imm_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_asr_imm_a1_Rm_0) >> OP_SF_EBII_arm_asr_imm_a1_Rm_0) << OP_SF_EBIF_arm_asr_imm_a1_Rm_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_asr_imm_a1.cond == 15)
         || ((context->decoded_code->code.arm_asr_imm_a1.Rd == 15)
         && (context->decoded_code->code.arm_asr_imm_a1.S == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_srs_a1 */
    static int op_parse_arm_srs_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_srs_a1) != OP_FB_arm_srs_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_srs_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_srs_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_srs_a1;
        
            context->decoded_code->code.arm_srs_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_srs_a1_P_0) >> OP_SF_EBII_arm_srs_a1_P_0) << OP_SF_EBIF_arm_srs_a1_P_0);
            
        
            context->decoded_code->code.arm_srs_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_srs_a1_U_0) >> OP_SF_EBII_arm_srs_a1_U_0) << OP_SF_EBIF_arm_srs_a1_U_0);
            
        
            context->decoded_code->code.arm_srs_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_srs_a1_W_0) >> OP_SF_EBII_arm_srs_a1_W_0) << OP_SF_EBIF_arm_srs_a1_W_0);
            
        
            context->decoded_code->code.arm_srs_a1.mode =
            
                (((context->code32x1 & OP_SF_MASK_arm_srs_a1_mode_0) >> OP_SF_EBII_arm_srs_a1_mode_0) << OP_SF_EBIF_arm_srs_a1_mode_0);
            
        
        
        
        return 0;
    }

    /* arm_clz_a1 */
    static int op_parse_arm_clz_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_clz_a1) != OP_FB_arm_clz_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_clz_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_clz_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_clz_a1;
        
            context->decoded_code->code.arm_clz_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_clz_a1_cond_0) >> OP_SF_EBII_arm_clz_a1_cond_0) << OP_SF_EBIF_arm_clz_a1_cond_0);
            
        
            context->decoded_code->code.arm_clz_a1.Rd =
            
                (((context->code32x1 & OP_SF_MASK_arm_clz_a1_Rd_0) >> OP_SF_EBII_arm_clz_a1_Rd_0) << OP_SF_EBIF_arm_clz_a1_Rd_0);
            
        
            context->decoded_code->code.arm_clz_a1.Rm =
            
                (((context->code32x1 & OP_SF_MASK_arm_clz_a1_Rm_0) >> OP_SF_EBII_arm_clz_a1_Rm_0) << OP_SF_EBIF_arm_clz_a1_Rm_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_clz_a1.cond == 15)
         || (context->decoded_code->code.arm_clz_a1.Rd == 15)
         || (context->decoded_code->code.arm_clz_a1.Rm == 15)
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_rfe_a1 */
    static int op_parse_arm_rfe_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_rfe_a1) != OP_FB_arm_rfe_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_rfe_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_rfe_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_rfe_a1;
        
            context->decoded_code->code.arm_rfe_a1.P =
            
                (((context->code32x1 & OP_SF_MASK_arm_rfe_a1_P_0) >> OP_SF_EBII_arm_rfe_a1_P_0) << OP_SF_EBIF_arm_rfe_a1_P_0);
            
        
            context->decoded_code->code.arm_rfe_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_rfe_a1_U_0) >> OP_SF_EBII_arm_rfe_a1_U_0) << OP_SF_EBIF_arm_rfe_a1_U_0);
            
        
            context->decoded_code->code.arm_rfe_a1.W =
            
                (((context->code32x1 & OP_SF_MASK_arm_rfe_a1_W_0) >> OP_SF_EBII_arm_rfe_a1_W_0) << OP_SF_EBIF_arm_rfe_a1_W_0);
            
        
            context->decoded_code->code.arm_rfe_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_rfe_a1_Rn_0) >> OP_SF_EBII_arm_rfe_a1_Rn_0) << OP_SF_EBIF_arm_rfe_a1_Rn_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_rfe_a1.Rn == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_wfi_a1 */
    static int op_parse_arm_wfi_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_wfi_a1) != OP_FB_arm_wfi_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_wfi_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_wfi_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_wfi_a1;
        
            context->decoded_code->code.arm_wfi_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_wfi_a1_cond_0) >> OP_SF_EBII_arm_wfi_a1_cond_0) << OP_SF_EBIF_arm_wfi_a1_cond_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_wfi_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vadd_freg_a2 */
    static int op_parse_arm_vadd_freg_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vadd_freg_a2) != OP_FB_arm_vadd_freg_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vadd_freg_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vadd_freg_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vadd_freg_a2;
        
            context->decoded_code->code.arm_vadd_freg_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vadd_freg_a2_cond_0) >> OP_SF_EBII_arm_vadd_freg_a2_cond_0) << OP_SF_EBIF_arm_vadd_freg_a2_cond_0);
            
        
            context->decoded_code->code.arm_vadd_freg_a2.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vadd_freg_a2_D_0) >> OP_SF_EBII_arm_vadd_freg_a2_D_0) << OP_SF_EBIF_arm_vadd_freg_a2_D_0);
            
        
            context->decoded_code->code.arm_vadd_freg_a2.Vn =
            
                (((context->code32x1 & OP_SF_MASK_arm_vadd_freg_a2_Vn_0) >> OP_SF_EBII_arm_vadd_freg_a2_Vn_0) << OP_SF_EBIF_arm_vadd_freg_a2_Vn_0);
            
        
            context->decoded_code->code.arm_vadd_freg_a2.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vadd_freg_a2_Vd_0) >> OP_SF_EBII_arm_vadd_freg_a2_Vd_0) << OP_SF_EBIF_arm_vadd_freg_a2_Vd_0);
            
        
            context->decoded_code->code.arm_vadd_freg_a2.sz =
            
                (((context->code32x1 & OP_SF_MASK_arm_vadd_freg_a2_sz_0) >> OP_SF_EBII_arm_vadd_freg_a2_sz_0) << OP_SF_EBIF_arm_vadd_freg_a2_sz_0);
            
        
            context->decoded_code->code.arm_vadd_freg_a2.N =
            
                (((context->code32x1 & OP_SF_MASK_arm_vadd_freg_a2_N_0) >> OP_SF_EBII_arm_vadd_freg_a2_N_0) << OP_SF_EBIF_arm_vadd_freg_a2_N_0);
            
        
            context->decoded_code->code.arm_vadd_freg_a2.M =
            
                (((context->code32x1 & OP_SF_MASK_arm_vadd_freg_a2_M_0) >> OP_SF_EBII_arm_vadd_freg_a2_M_0) << OP_SF_EBIF_arm_vadd_freg_a2_M_0);
            
        
            context->decoded_code->code.arm_vadd_freg_a2.Vm =
            
                (((context->code32x1 & OP_SF_MASK_arm_vadd_freg_a2_Vm_0) >> OP_SF_EBII_arm_vadd_freg_a2_Vm_0) << OP_SF_EBIF_arm_vadd_freg_a2_Vm_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vadd_freg_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vldr_a1 */
    static int op_parse_arm_vldr_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vldr_a1) != OP_FB_arm_vldr_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vldr_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vldr_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vldr_a1;
        
            context->decoded_code->code.arm_vldr_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a1_cond_0) >> OP_SF_EBII_arm_vldr_a1_cond_0) << OP_SF_EBIF_arm_vldr_a1_cond_0);
            
        
            context->decoded_code->code.arm_vldr_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a1_U_0) >> OP_SF_EBII_arm_vldr_a1_U_0) << OP_SF_EBIF_arm_vldr_a1_U_0);
            
        
            context->decoded_code->code.arm_vldr_a1.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a1_D_0) >> OP_SF_EBII_arm_vldr_a1_D_0) << OP_SF_EBIF_arm_vldr_a1_D_0);
            
        
            context->decoded_code->code.arm_vldr_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a1_Rn_0) >> OP_SF_EBII_arm_vldr_a1_Rn_0) << OP_SF_EBIF_arm_vldr_a1_Rn_0);
            
        
            context->decoded_code->code.arm_vldr_a1.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a1_Vd_0) >> OP_SF_EBII_arm_vldr_a1_Vd_0) << OP_SF_EBIF_arm_vldr_a1_Vd_0);
            
        
            context->decoded_code->code.arm_vldr_a1.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a1_imm8_0) >> OP_SF_EBII_arm_vldr_a1_imm8_0) << OP_SF_EBIF_arm_vldr_a1_imm8_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vldr_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vldr_a2 */
    static int op_parse_arm_vldr_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vldr_a2) != OP_FB_arm_vldr_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vldr_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vldr_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vldr_a2;
        
            context->decoded_code->code.arm_vldr_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a2_cond_0) >> OP_SF_EBII_arm_vldr_a2_cond_0) << OP_SF_EBIF_arm_vldr_a2_cond_0);
            
        
            context->decoded_code->code.arm_vldr_a2.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a2_U_0) >> OP_SF_EBII_arm_vldr_a2_U_0) << OP_SF_EBIF_arm_vldr_a2_U_0);
            
        
            context->decoded_code->code.arm_vldr_a2.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a2_D_0) >> OP_SF_EBII_arm_vldr_a2_D_0) << OP_SF_EBIF_arm_vldr_a2_D_0);
            
        
            context->decoded_code->code.arm_vldr_a2.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a2_Rn_0) >> OP_SF_EBII_arm_vldr_a2_Rn_0) << OP_SF_EBIF_arm_vldr_a2_Rn_0);
            
        
            context->decoded_code->code.arm_vldr_a2.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a2_Vd_0) >> OP_SF_EBII_arm_vldr_a2_Vd_0) << OP_SF_EBIF_arm_vldr_a2_Vd_0);
            
        
            context->decoded_code->code.arm_vldr_a2.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_vldr_a2_imm8_0) >> OP_SF_EBII_arm_vldr_a2_imm8_0) << OP_SF_EBIF_arm_vldr_a2_imm8_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vldr_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vcvt_df_a1 */
    static int op_parse_arm_vcvt_df_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vcvt_df_a1) != OP_FB_arm_vcvt_df_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vcvt_df_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vcvt_df_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vcvt_df_a1;
        
            context->decoded_code->code.arm_vcvt_df_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_df_a1_cond_0) >> OP_SF_EBII_arm_vcvt_df_a1_cond_0) << OP_SF_EBIF_arm_vcvt_df_a1_cond_0);
            
        
            context->decoded_code->code.arm_vcvt_df_a1.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_df_a1_D_0) >> OP_SF_EBII_arm_vcvt_df_a1_D_0) << OP_SF_EBIF_arm_vcvt_df_a1_D_0);
            
        
            context->decoded_code->code.arm_vcvt_df_a1.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_df_a1_Vd_0) >> OP_SF_EBII_arm_vcvt_df_a1_Vd_0) << OP_SF_EBIF_arm_vcvt_df_a1_Vd_0);
            
        
            context->decoded_code->code.arm_vcvt_df_a1.sz =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_df_a1_sz_0) >> OP_SF_EBII_arm_vcvt_df_a1_sz_0) << OP_SF_EBIF_arm_vcvt_df_a1_sz_0);
            
        
            context->decoded_code->code.arm_vcvt_df_a1.M =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_df_a1_M_0) >> OP_SF_EBII_arm_vcvt_df_a1_M_0) << OP_SF_EBIF_arm_vcvt_df_a1_M_0);
            
        
            context->decoded_code->code.arm_vcvt_df_a1.Vm =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_df_a1_Vm_0) >> OP_SF_EBII_arm_vcvt_df_a1_Vm_0) << OP_SF_EBIF_arm_vcvt_df_a1_Vm_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vcvt_df_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vcvt_fi_a1 */
    static int op_parse_arm_vcvt_fi_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vcvt_fi_a1) != OP_FB_arm_vcvt_fi_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vcvt_fi_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vcvt_fi_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vcvt_fi_a1;
        
            context->decoded_code->code.arm_vcvt_fi_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_fi_a1_cond_0) >> OP_SF_EBII_arm_vcvt_fi_a1_cond_0) << OP_SF_EBIF_arm_vcvt_fi_a1_cond_0);
            
        
            context->decoded_code->code.arm_vcvt_fi_a1.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_fi_a1_D_0) >> OP_SF_EBII_arm_vcvt_fi_a1_D_0) << OP_SF_EBIF_arm_vcvt_fi_a1_D_0);
            
        
            context->decoded_code->code.arm_vcvt_fi_a1.opc2 =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_fi_a1_opc2_0) >> OP_SF_EBII_arm_vcvt_fi_a1_opc2_0) << OP_SF_EBIF_arm_vcvt_fi_a1_opc2_0);
            
        
            context->decoded_code->code.arm_vcvt_fi_a1.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_fi_a1_Vd_0) >> OP_SF_EBII_arm_vcvt_fi_a1_Vd_0) << OP_SF_EBIF_arm_vcvt_fi_a1_Vd_0);
            
        
            context->decoded_code->code.arm_vcvt_fi_a1.sz =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_fi_a1_sz_0) >> OP_SF_EBII_arm_vcvt_fi_a1_sz_0) << OP_SF_EBIF_arm_vcvt_fi_a1_sz_0);
            
        
            context->decoded_code->code.arm_vcvt_fi_a1.op =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_fi_a1_op_0) >> OP_SF_EBII_arm_vcvt_fi_a1_op_0) << OP_SF_EBIF_arm_vcvt_fi_a1_op_0);
            
        
            context->decoded_code->code.arm_vcvt_fi_a1.M =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_fi_a1_M_0) >> OP_SF_EBII_arm_vcvt_fi_a1_M_0) << OP_SF_EBIF_arm_vcvt_fi_a1_M_0);
            
        
            context->decoded_code->code.arm_vcvt_fi_a1.Vm =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcvt_fi_a1_Vm_0) >> OP_SF_EBII_arm_vcvt_fi_a1_Vm_0) << OP_SF_EBIF_arm_vcvt_fi_a1_Vm_0);
            
        
        
        
            if (
                (context->decoded_code->code.arm_vcvt_fi_a1.cond == 15)
         || ((context->decoded_code->code.arm_vcvt_fi_a1.opc2 != 0)
         && ((context->decoded_code->code.arm_vcvt_fi_a1.opc2 != 5)
         && (context->decoded_code->code.arm_vcvt_fi_a1.opc2 != 4)
        )
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vstr_a1 */
    static int op_parse_arm_vstr_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vstr_a1) != OP_FB_arm_vstr_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vstr_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vstr_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vstr_a1;
        
            context->decoded_code->code.arm_vstr_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a1_cond_0) >> OP_SF_EBII_arm_vstr_a1_cond_0) << OP_SF_EBIF_arm_vstr_a1_cond_0);
            
        
            context->decoded_code->code.arm_vstr_a1.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a1_U_0) >> OP_SF_EBII_arm_vstr_a1_U_0) << OP_SF_EBIF_arm_vstr_a1_U_0);
            
        
            context->decoded_code->code.arm_vstr_a1.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a1_D_0) >> OP_SF_EBII_arm_vstr_a1_D_0) << OP_SF_EBIF_arm_vstr_a1_D_0);
            
        
            context->decoded_code->code.arm_vstr_a1.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a1_Rn_0) >> OP_SF_EBII_arm_vstr_a1_Rn_0) << OP_SF_EBIF_arm_vstr_a1_Rn_0);
            
        
            context->decoded_code->code.arm_vstr_a1.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a1_Vd_0) >> OP_SF_EBII_arm_vstr_a1_Vd_0) << OP_SF_EBIF_arm_vstr_a1_Vd_0);
            
        
            context->decoded_code->code.arm_vstr_a1.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a1_imm8_0) >> OP_SF_EBII_arm_vstr_a1_imm8_0) << OP_SF_EBIF_arm_vstr_a1_imm8_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vstr_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vstr_a2 */
    static int op_parse_arm_vstr_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vstr_a2) != OP_FB_arm_vstr_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vstr_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vstr_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vstr_a2;
        
            context->decoded_code->code.arm_vstr_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a2_cond_0) >> OP_SF_EBII_arm_vstr_a2_cond_0) << OP_SF_EBIF_arm_vstr_a2_cond_0);
            
        
            context->decoded_code->code.arm_vstr_a2.U =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a2_U_0) >> OP_SF_EBII_arm_vstr_a2_U_0) << OP_SF_EBIF_arm_vstr_a2_U_0);
            
        
            context->decoded_code->code.arm_vstr_a2.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a2_D_0) >> OP_SF_EBII_arm_vstr_a2_D_0) << OP_SF_EBIF_arm_vstr_a2_D_0);
            
        
            context->decoded_code->code.arm_vstr_a2.Rn =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a2_Rn_0) >> OP_SF_EBII_arm_vstr_a2_Rn_0) << OP_SF_EBIF_arm_vstr_a2_Rn_0);
            
        
            context->decoded_code->code.arm_vstr_a2.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a2_Vd_0) >> OP_SF_EBII_arm_vstr_a2_Vd_0) << OP_SF_EBIF_arm_vstr_a2_Vd_0);
            
        
            context->decoded_code->code.arm_vstr_a2.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_vstr_a2_imm8_0) >> OP_SF_EBII_arm_vstr_a2_imm8_0) << OP_SF_EBIF_arm_vstr_a2_imm8_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vstr_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vcmp_a1 */
    static int op_parse_arm_vcmp_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vcmp_a1) != OP_FB_arm_vcmp_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vcmp_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vcmp_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vcmp_a1;
        
            context->decoded_code->code.arm_vcmp_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a1_cond_0) >> OP_SF_EBII_arm_vcmp_a1_cond_0) << OP_SF_EBIF_arm_vcmp_a1_cond_0);
            
        
            context->decoded_code->code.arm_vcmp_a1.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a1_D_0) >> OP_SF_EBII_arm_vcmp_a1_D_0) << OP_SF_EBIF_arm_vcmp_a1_D_0);
            
        
            context->decoded_code->code.arm_vcmp_a1.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a1_Vd_0) >> OP_SF_EBII_arm_vcmp_a1_Vd_0) << OP_SF_EBIF_arm_vcmp_a1_Vd_0);
            
        
            context->decoded_code->code.arm_vcmp_a1.sz =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a1_sz_0) >> OP_SF_EBII_arm_vcmp_a1_sz_0) << OP_SF_EBIF_arm_vcmp_a1_sz_0);
            
        
            context->decoded_code->code.arm_vcmp_a1.E =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a1_E_0) >> OP_SF_EBII_arm_vcmp_a1_E_0) << OP_SF_EBIF_arm_vcmp_a1_E_0);
            
        
            context->decoded_code->code.arm_vcmp_a1.M =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a1_M_0) >> OP_SF_EBII_arm_vcmp_a1_M_0) << OP_SF_EBIF_arm_vcmp_a1_M_0);
            
        
            context->decoded_code->code.arm_vcmp_a1.Vm =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a1_Vm_0) >> OP_SF_EBII_arm_vcmp_a1_Vm_0) << OP_SF_EBIF_arm_vcmp_a1_Vm_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vcmp_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vcmp_a2 */
    static int op_parse_arm_vcmp_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vcmp_a2) != OP_FB_arm_vcmp_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vcmp_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vcmp_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vcmp_a2;
        
            context->decoded_code->code.arm_vcmp_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a2_cond_0) >> OP_SF_EBII_arm_vcmp_a2_cond_0) << OP_SF_EBIF_arm_vcmp_a2_cond_0);
            
        
            context->decoded_code->code.arm_vcmp_a2.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a2_D_0) >> OP_SF_EBII_arm_vcmp_a2_D_0) << OP_SF_EBIF_arm_vcmp_a2_D_0);
            
        
            context->decoded_code->code.arm_vcmp_a2.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a2_Vd_0) >> OP_SF_EBII_arm_vcmp_a2_Vd_0) << OP_SF_EBIF_arm_vcmp_a2_Vd_0);
            
        
            context->decoded_code->code.arm_vcmp_a2.sz =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a2_sz_0) >> OP_SF_EBII_arm_vcmp_a2_sz_0) << OP_SF_EBIF_arm_vcmp_a2_sz_0);
            
        
            context->decoded_code->code.arm_vcmp_a2.E =
            
                (((context->code32x1 & OP_SF_MASK_arm_vcmp_a2_E_0) >> OP_SF_EBII_arm_vcmp_a2_E_0) << OP_SF_EBIF_arm_vcmp_a2_E_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vcmp_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vmrs_a1 */
    static int op_parse_arm_vmrs_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vmrs_a1) != OP_FB_arm_vmrs_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vmrs_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vmrs_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vmrs_a1;
        
            context->decoded_code->code.arm_vmrs_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmrs_a1_cond_0) >> OP_SF_EBII_arm_vmrs_a1_cond_0) << OP_SF_EBIF_arm_vmrs_a1_cond_0);
            
        
            context->decoded_code->code.arm_vmrs_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmrs_a1_Rt_0) >> OP_SF_EBII_arm_vmrs_a1_Rt_0) << OP_SF_EBIF_arm_vmrs_a1_Rt_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vmrs_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vmov_imm_a1 */
    static int op_parse_arm_vmov_imm_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vmov_imm_a1) != OP_FB_arm_vmov_imm_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vmov_imm_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vmov_imm_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vmov_imm_a1;
        
            context->decoded_code->code.arm_vmov_imm_a1.i =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a1_i_0) >> OP_SF_EBII_arm_vmov_imm_a1_i_0) << OP_SF_EBIF_arm_vmov_imm_a1_i_0);
            
        
            context->decoded_code->code.arm_vmov_imm_a1.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a1_D_0) >> OP_SF_EBII_arm_vmov_imm_a1_D_0) << OP_SF_EBIF_arm_vmov_imm_a1_D_0);
            
        
            context->decoded_code->code.arm_vmov_imm_a1.imm7 =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a1_imm7_0) >> OP_SF_EBII_arm_vmov_imm_a1_imm7_0) << OP_SF_EBIF_arm_vmov_imm_a1_imm7_0)
            
                | (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a1_imm7_1) >> OP_SF_EBII_arm_vmov_imm_a1_imm7_1) << OP_SF_EBIF_arm_vmov_imm_a1_imm7_1);
            
        
            context->decoded_code->code.arm_vmov_imm_a1.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a1_Vd_0) >> OP_SF_EBII_arm_vmov_imm_a1_Vd_0) << OP_SF_EBIF_arm_vmov_imm_a1_Vd_0);
            
        
            context->decoded_code->code.arm_vmov_imm_a1.cmode =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a1_cmode_0) >> OP_SF_EBII_arm_vmov_imm_a1_cmode_0) << OP_SF_EBIF_arm_vmov_imm_a1_cmode_0);
            
        
            context->decoded_code->code.arm_vmov_imm_a1.Q =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a1_Q_0) >> OP_SF_EBII_arm_vmov_imm_a1_Q_0) << OP_SF_EBIF_arm_vmov_imm_a1_Q_0);
            
        
            context->decoded_code->code.arm_vmov_imm_a1.op =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a1_op_0) >> OP_SF_EBII_arm_vmov_imm_a1_op_0) << OP_SF_EBIF_arm_vmov_imm_a1_op_0);
            
        
        
        
            if (
                ((context->decoded_code->code.arm_vmov_imm_a1.op == 0)
         && (BIT_ELEMENT(context->decoded_code->code.arm_vmov_imm_a1.cmode, 0) == 1)
         && ((BIT_ELEMENT(context->decoded_code->code.arm_vmov_imm_a1.cmode, 3) != 1)
         && (BIT_ELEMENT(context->decoded_code->code.arm_vmov_imm_a1.cmode, 2) != 1)
        )
        )
         || ((context->decoded_code->code.arm_vmov_imm_a1.op == 1)
         && (context->decoded_code->code.arm_vmov_imm_a1.cmode != 14)
        )
         || ((context->decoded_code->code.arm_vmov_imm_a1.Q == 1)
         && (BIT_ELEMENT(context->decoded_code->code.arm_vmov_imm_a1.Vd, 0) == 1)
        )
        
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vmov_imm_a2 */
    static int op_parse_arm_vmov_imm_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vmov_imm_a2) != OP_FB_arm_vmov_imm_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vmov_imm_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vmov_imm_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vmov_imm_a2;
        
            context->decoded_code->code.arm_vmov_imm_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a2_cond_0) >> OP_SF_EBII_arm_vmov_imm_a2_cond_0) << OP_SF_EBIF_arm_vmov_imm_a2_cond_0);
            
        
            context->decoded_code->code.arm_vmov_imm_a2.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a2_D_0) >> OP_SF_EBII_arm_vmov_imm_a2_D_0) << OP_SF_EBIF_arm_vmov_imm_a2_D_0);
            
        
            context->decoded_code->code.arm_vmov_imm_a2.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a2_imm8_0) >> OP_SF_EBII_arm_vmov_imm_a2_imm8_0) << OP_SF_EBIF_arm_vmov_imm_a2_imm8_0)
            
                | (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a2_imm8_1) >> OP_SF_EBII_arm_vmov_imm_a2_imm8_1) << OP_SF_EBIF_arm_vmov_imm_a2_imm8_1);
            
        
            context->decoded_code->code.arm_vmov_imm_a2.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a2_Vd_0) >> OP_SF_EBII_arm_vmov_imm_a2_Vd_0) << OP_SF_EBIF_arm_vmov_imm_a2_Vd_0);
            
        
            context->decoded_code->code.arm_vmov_imm_a2.sz =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_imm_a2_sz_0) >> OP_SF_EBII_arm_vmov_imm_a2_sz_0) << OP_SF_EBIF_arm_vmov_imm_a2_sz_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vmov_imm_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vmov_sreg_a1 */
    static int op_parse_arm_vmov_sreg_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vmov_sreg_a1) != OP_FB_arm_vmov_sreg_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vmov_sreg_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vmov_sreg_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vmov_sreg_a1;
        
            context->decoded_code->code.arm_vmov_sreg_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_sreg_a1_cond_0) >> OP_SF_EBII_arm_vmov_sreg_a1_cond_0) << OP_SF_EBIF_arm_vmov_sreg_a1_cond_0);
            
        
            context->decoded_code->code.arm_vmov_sreg_a1.op =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_sreg_a1_op_0) >> OP_SF_EBII_arm_vmov_sreg_a1_op_0) << OP_SF_EBIF_arm_vmov_sreg_a1_op_0);
            
        
            context->decoded_code->code.arm_vmov_sreg_a1.Vn =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_sreg_a1_Vn_0) >> OP_SF_EBII_arm_vmov_sreg_a1_Vn_0) << OP_SF_EBIF_arm_vmov_sreg_a1_Vn_0);
            
        
            context->decoded_code->code.arm_vmov_sreg_a1.Rt =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_sreg_a1_Rt_0) >> OP_SF_EBII_arm_vmov_sreg_a1_Rt_0) << OP_SF_EBIF_arm_vmov_sreg_a1_Rt_0);
            
        
            context->decoded_code->code.arm_vmov_sreg_a1.N =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmov_sreg_a1_N_0) >> OP_SF_EBII_arm_vmov_sreg_a1_N_0) << OP_SF_EBIF_arm_vmov_sreg_a1_N_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vmov_sreg_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vsub_freg_a2 */
    static int op_parse_arm_vsub_freg_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vsub_freg_a2) != OP_FB_arm_vsub_freg_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vsub_freg_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vsub_freg_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vsub_freg_a2;
        
            context->decoded_code->code.arm_vsub_freg_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vsub_freg_a2_cond_0) >> OP_SF_EBII_arm_vsub_freg_a2_cond_0) << OP_SF_EBIF_arm_vsub_freg_a2_cond_0);
            
        
            context->decoded_code->code.arm_vsub_freg_a2.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vsub_freg_a2_D_0) >> OP_SF_EBII_arm_vsub_freg_a2_D_0) << OP_SF_EBIF_arm_vsub_freg_a2_D_0);
            
        
            context->decoded_code->code.arm_vsub_freg_a2.Vn =
            
                (((context->code32x1 & OP_SF_MASK_arm_vsub_freg_a2_Vn_0) >> OP_SF_EBII_arm_vsub_freg_a2_Vn_0) << OP_SF_EBIF_arm_vsub_freg_a2_Vn_0);
            
        
            context->decoded_code->code.arm_vsub_freg_a2.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vsub_freg_a2_Vd_0) >> OP_SF_EBII_arm_vsub_freg_a2_Vd_0) << OP_SF_EBIF_arm_vsub_freg_a2_Vd_0);
            
        
            context->decoded_code->code.arm_vsub_freg_a2.sz =
            
                (((context->code32x1 & OP_SF_MASK_arm_vsub_freg_a2_sz_0) >> OP_SF_EBII_arm_vsub_freg_a2_sz_0) << OP_SF_EBIF_arm_vsub_freg_a2_sz_0);
            
        
            context->decoded_code->code.arm_vsub_freg_a2.N =
            
                (((context->code32x1 & OP_SF_MASK_arm_vsub_freg_a2_N_0) >> OP_SF_EBII_arm_vsub_freg_a2_N_0) << OP_SF_EBIF_arm_vsub_freg_a2_N_0);
            
        
            context->decoded_code->code.arm_vsub_freg_a2.M =
            
                (((context->code32x1 & OP_SF_MASK_arm_vsub_freg_a2_M_0) >> OP_SF_EBII_arm_vsub_freg_a2_M_0) << OP_SF_EBIF_arm_vsub_freg_a2_M_0);
            
        
            context->decoded_code->code.arm_vsub_freg_a2.Vm =
            
                (((context->code32x1 & OP_SF_MASK_arm_vsub_freg_a2_Vm_0) >> OP_SF_EBII_arm_vsub_freg_a2_Vm_0) << OP_SF_EBIF_arm_vsub_freg_a2_Vm_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vsub_freg_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vmul_freg_a2 */
    static int op_parse_arm_vmul_freg_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vmul_freg_a2) != OP_FB_arm_vmul_freg_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vmul_freg_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vmul_freg_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vmul_freg_a2;
        
            context->decoded_code->code.arm_vmul_freg_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmul_freg_a2_cond_0) >> OP_SF_EBII_arm_vmul_freg_a2_cond_0) << OP_SF_EBIF_arm_vmul_freg_a2_cond_0);
            
        
            context->decoded_code->code.arm_vmul_freg_a2.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmul_freg_a2_D_0) >> OP_SF_EBII_arm_vmul_freg_a2_D_0) << OP_SF_EBIF_arm_vmul_freg_a2_D_0);
            
        
            context->decoded_code->code.arm_vmul_freg_a2.Vn =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmul_freg_a2_Vn_0) >> OP_SF_EBII_arm_vmul_freg_a2_Vn_0) << OP_SF_EBIF_arm_vmul_freg_a2_Vn_0);
            
        
            context->decoded_code->code.arm_vmul_freg_a2.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmul_freg_a2_Vd_0) >> OP_SF_EBII_arm_vmul_freg_a2_Vd_0) << OP_SF_EBIF_arm_vmul_freg_a2_Vd_0);
            
        
            context->decoded_code->code.arm_vmul_freg_a2.sz =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmul_freg_a2_sz_0) >> OP_SF_EBII_arm_vmul_freg_a2_sz_0) << OP_SF_EBIF_arm_vmul_freg_a2_sz_0);
            
        
            context->decoded_code->code.arm_vmul_freg_a2.N =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmul_freg_a2_N_0) >> OP_SF_EBII_arm_vmul_freg_a2_N_0) << OP_SF_EBIF_arm_vmul_freg_a2_N_0);
            
        
            context->decoded_code->code.arm_vmul_freg_a2.M =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmul_freg_a2_M_0) >> OP_SF_EBII_arm_vmul_freg_a2_M_0) << OP_SF_EBIF_arm_vmul_freg_a2_M_0);
            
        
            context->decoded_code->code.arm_vmul_freg_a2.Vm =
            
                (((context->code32x1 & OP_SF_MASK_arm_vmul_freg_a2_Vm_0) >> OP_SF_EBII_arm_vmul_freg_a2_Vm_0) << OP_SF_EBIF_arm_vmul_freg_a2_Vm_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vmul_freg_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vdiv_freg_a2 */
    static int op_parse_arm_vdiv_freg_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vdiv_freg_a2) != OP_FB_arm_vdiv_freg_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vdiv_freg_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vdiv_freg_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vdiv_freg_a2;
        
            context->decoded_code->code.arm_vdiv_freg_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vdiv_freg_a2_cond_0) >> OP_SF_EBII_arm_vdiv_freg_a2_cond_0) << OP_SF_EBIF_arm_vdiv_freg_a2_cond_0);
            
        
            context->decoded_code->code.arm_vdiv_freg_a2.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vdiv_freg_a2_D_0) >> OP_SF_EBII_arm_vdiv_freg_a2_D_0) << OP_SF_EBIF_arm_vdiv_freg_a2_D_0);
            
        
            context->decoded_code->code.arm_vdiv_freg_a2.Vn =
            
                (((context->code32x1 & OP_SF_MASK_arm_vdiv_freg_a2_Vn_0) >> OP_SF_EBII_arm_vdiv_freg_a2_Vn_0) << OP_SF_EBIF_arm_vdiv_freg_a2_Vn_0);
            
        
            context->decoded_code->code.arm_vdiv_freg_a2.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vdiv_freg_a2_Vd_0) >> OP_SF_EBII_arm_vdiv_freg_a2_Vd_0) << OP_SF_EBIF_arm_vdiv_freg_a2_Vd_0);
            
        
            context->decoded_code->code.arm_vdiv_freg_a2.sz =
            
                (((context->code32x1 & OP_SF_MASK_arm_vdiv_freg_a2_sz_0) >> OP_SF_EBII_arm_vdiv_freg_a2_sz_0) << OP_SF_EBIF_arm_vdiv_freg_a2_sz_0);
            
        
            context->decoded_code->code.arm_vdiv_freg_a2.N =
            
                (((context->code32x1 & OP_SF_MASK_arm_vdiv_freg_a2_N_0) >> OP_SF_EBII_arm_vdiv_freg_a2_N_0) << OP_SF_EBIF_arm_vdiv_freg_a2_N_0);
            
        
            context->decoded_code->code.arm_vdiv_freg_a2.M =
            
                (((context->code32x1 & OP_SF_MASK_arm_vdiv_freg_a2_M_0) >> OP_SF_EBII_arm_vdiv_freg_a2_M_0) << OP_SF_EBIF_arm_vdiv_freg_a2_M_0);
            
        
            context->decoded_code->code.arm_vdiv_freg_a2.Vm =
            
                (((context->code32x1 & OP_SF_MASK_arm_vdiv_freg_a2_Vm_0) >> OP_SF_EBII_arm_vdiv_freg_a2_Vm_0) << OP_SF_EBIF_arm_vdiv_freg_a2_Vm_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vdiv_freg_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vpush_a1 */
    static int op_parse_arm_vpush_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vpush_a1) != OP_FB_arm_vpush_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vpush_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vpush_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vpush_a1;
        
            context->decoded_code->code.arm_vpush_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpush_a1_cond_0) >> OP_SF_EBII_arm_vpush_a1_cond_0) << OP_SF_EBIF_arm_vpush_a1_cond_0);
            
        
            context->decoded_code->code.arm_vpush_a1.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpush_a1_D_0) >> OP_SF_EBII_arm_vpush_a1_D_0) << OP_SF_EBIF_arm_vpush_a1_D_0);
            
        
            context->decoded_code->code.arm_vpush_a1.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpush_a1_Vd_0) >> OP_SF_EBII_arm_vpush_a1_Vd_0) << OP_SF_EBIF_arm_vpush_a1_Vd_0);
            
        
            context->decoded_code->code.arm_vpush_a1.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpush_a1_imm8_0) >> OP_SF_EBII_arm_vpush_a1_imm8_0) << OP_SF_EBIF_arm_vpush_a1_imm8_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vpush_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vpush_a2 */
    static int op_parse_arm_vpush_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vpush_a2) != OP_FB_arm_vpush_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vpush_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vpush_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vpush_a2;
        
            context->decoded_code->code.arm_vpush_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpush_a2_cond_0) >> OP_SF_EBII_arm_vpush_a2_cond_0) << OP_SF_EBIF_arm_vpush_a2_cond_0);
            
        
            context->decoded_code->code.arm_vpush_a2.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpush_a2_D_0) >> OP_SF_EBII_arm_vpush_a2_D_0) << OP_SF_EBIF_arm_vpush_a2_D_0);
            
        
            context->decoded_code->code.arm_vpush_a2.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpush_a2_Vd_0) >> OP_SF_EBII_arm_vpush_a2_Vd_0) << OP_SF_EBIF_arm_vpush_a2_Vd_0);
            
        
            context->decoded_code->code.arm_vpush_a2.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpush_a2_imm8_0) >> OP_SF_EBII_arm_vpush_a2_imm8_0) << OP_SF_EBIF_arm_vpush_a2_imm8_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vpush_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vpop_a1 */
    static int op_parse_arm_vpop_a1(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vpop_a1) != OP_FB_arm_vpop_a1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vpop_a1;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vpop_a1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vpop_a1;
        
            context->decoded_code->code.arm_vpop_a1.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpop_a1_cond_0) >> OP_SF_EBII_arm_vpop_a1_cond_0) << OP_SF_EBIF_arm_vpop_a1_cond_0);
            
        
            context->decoded_code->code.arm_vpop_a1.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpop_a1_D_0) >> OP_SF_EBII_arm_vpop_a1_D_0) << OP_SF_EBIF_arm_vpop_a1_D_0);
            
        
            context->decoded_code->code.arm_vpop_a1.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpop_a1_Vd_0) >> OP_SF_EBII_arm_vpop_a1_Vd_0) << OP_SF_EBIF_arm_vpop_a1_Vd_0);
            
        
            context->decoded_code->code.arm_vpop_a1.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpop_a1_imm8_0) >> OP_SF_EBII_arm_vpop_a1_imm8_0) << OP_SF_EBIF_arm_vpop_a1_imm8_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vpop_a1.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }

    /* arm_vpop_a2 */
    static int op_parse_arm_vpop_a2(OpDecodeContext *context) {
        if ((context->code32x1 & OP_FB_MASK_arm_vpop_a2) != OP_FB_arm_vpop_a2) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_arm_vpop_a2;
        context->optype->format_id = arm_OP_CODE_FORMAT_arm_vpop_a2;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_arm_vpop_a2;
        
            context->decoded_code->code.arm_vpop_a2.cond =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpop_a2_cond_0) >> OP_SF_EBII_arm_vpop_a2_cond_0) << OP_SF_EBIF_arm_vpop_a2_cond_0);
            
        
            context->decoded_code->code.arm_vpop_a2.D =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpop_a2_D_0) >> OP_SF_EBII_arm_vpop_a2_D_0) << OP_SF_EBIF_arm_vpop_a2_D_0);
            
        
            context->decoded_code->code.arm_vpop_a2.Vd =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpop_a2_Vd_0) >> OP_SF_EBII_arm_vpop_a2_Vd_0) << OP_SF_EBIF_arm_vpop_a2_Vd_0);
            
        
            context->decoded_code->code.arm_vpop_a2.imm8 =
            
                (((context->code32x1 & OP_SF_MASK_arm_vpop_a2_imm8_0) >> OP_SF_EBII_arm_vpop_a2_imm8_0) << OP_SF_EBIF_arm_vpop_a2_imm8_0);
            
        
        
        
            if (
                context->decoded_code->code.arm_vpop_a2.cond == 15
            ) {
                return 1;
            }
        
        return 0;
    }


/* decision node functions */

        static int decision_node_code32x1_0(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x0e000000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_1(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x02000000:
                            if (decision_node_code32x1_43(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x04000000:
                            if (decision_node_code32x1_77(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x06000000:
                            if (decision_node_code32x1_87(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x08000000:
                            if (decision_node_code32x1_103(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x0a000000:
                            if (decision_node_code32x1_115(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x0c000000:
                            if (decision_node_code32x1_119(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x0e000000:
                            if (decision_node_code32x1_128(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_1(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00000010) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_2(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00000010:
                            if (decision_node_code32x1_25(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_2(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01a00000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_3(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00200000:
                            if (decision_node_code32x1_6(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00800000:
                            if (decision_node_code32x1_7(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00a00000:
                            if (decision_node_code32x1_10(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01000000:
                            if (decision_node_code32x1_11(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01200000:
                            if (decision_node_code32x1_15(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01800000:
                            if (decision_node_code32x1_16(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01a00000:
                            if (decision_node_code32x1_17(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_3(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00400000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_4(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00400000:
                            if (decision_node_code32x1_5(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_4(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_and_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_5(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_sub_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_6(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_rsb_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_7(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00400000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_8(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00400000:
                            if (decision_node_code32x1_9(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_8(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_add_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_9(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_sbc_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_10(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_adc_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_11(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00500000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_12(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00100000:
                            if (decision_node_code32x1_13(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00500000:
                            if (decision_node_code32x1_14(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_12(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_mrs_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_13(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_tst_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_14(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_cmp_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_15(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_msr2_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_16(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_orr_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_17(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x004f0000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_18(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00400000:
                            if (decision_node_code32x1_24(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_18(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00000060) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_19(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00000020:
                            if (decision_node_code32x1_22(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00000040:
                            if (decision_node_code32x1_23(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_19(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00000f80) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_20(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_21(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_20(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_mov_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_21(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_lsl_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_22(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_lsr_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_23(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_asr_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_24(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_mvn_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_25(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x004000e0) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_26(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00000020:
                            if (decision_node_code32x1_29(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00000080:
                            if (decision_node_code32x1_32(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x000000a0:
                            if (decision_node_code32x1_33(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00400000:
                            if (decision_node_code32x1_34(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00400080:
                            if (decision_node_code32x1_35(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x004000a0:
                            if (decision_node_code32x1_36(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x004000c0:
                            if (decision_node_code32x1_39(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x004000e0:
                            if (decision_node_code32x1_40(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_26(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01af0000) {
                    
                        case 0x012f0000:
                            if (decision_node_code32x1_27(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01a00000:
                            if (decision_node_code32x1_28(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_27(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_bx_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_28(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_lsl_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_29(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01af0000) {
                    
                        case 0x012f0000:
                            if (decision_node_code32x1_30(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01a00000:
                            if (decision_node_code32x1_31(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_30(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_blx_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_31(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_lsr_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_32(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_mul_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_33(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_ldrh_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_34(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_clz_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_35(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_smull_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_36(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00100000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_37(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00100000:
                            if (decision_node_code32x1_38(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_37(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_strh_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_38(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_ldrh_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_39(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_ldrd_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_40(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00100000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_41(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00100000:
                            if (decision_node_code32x1_42(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_41(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_strd_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_42(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_ldrsh_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_43(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00a00000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_44(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00200000:
                            if (decision_node_code32x1_55(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00800000:
                            if (decision_node_code32x1_65(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00a00000:
                            if (decision_node_code32x1_73(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_76(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_44(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01400000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_45(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00400000:
                            if (decision_node_code32x1_46(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01000000:
                            if (decision_node_code32x1_49(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01400000:
                            if (decision_node_code32x1_52(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_45(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_and_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_46(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x000f0000) {
                    
                        case 0x000d0000:
                            if (decision_node_code32x1_47(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_48(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_47(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_sub_spimm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_48(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_sub_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_49(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00100000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_50(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00100000:
                            if (decision_node_code32x1_51(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_50(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_mov_imm_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_51(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_tst_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_52(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00100000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_53(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00100000:
                            if (decision_node_code32x1_54(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_53(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_movt_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_54(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_cmp_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_55(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01000000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_56(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01000000:
                            if (decision_node_code32x1_57(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_56(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_rsb_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_57(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x0010f000) {
                    
                        case 0x0000f000:
                            if (decision_node_code32x1_58(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00100000:
                            if (decision_node_code32x1_64(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_58(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x000c0fff) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_59(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00000003:
                            if (decision_node_code32x1_60(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_61(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_59(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_nop_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_60(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_wfi_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_61(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00430000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_62(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_63(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_62(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_msr_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_63(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_msr2_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_64(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_cmn_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_65(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01400000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_66(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01000000:
                            if (decision_node_code32x1_70(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01400000:
                            if (decision_node_code32x1_71(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_72(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_66(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x000f0000) {
                    
                        case 0x000d0000:
                            if (decision_node_code32x1_67(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x000f0000:
                            if (decision_node_code32x1_68(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_69(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_67(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_add_spimm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_68(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_adr_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_69(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_add_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_70(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_orr_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_71(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_bic_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_72(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vmov_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_73(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x014f0000) {
                    
                        case 0x01000000:
                            if (decision_node_code32x1_74(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01400000:
                            if (decision_node_code32x1_75(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_74(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_mov_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_75(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_mvn_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_76(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_subs_pclr_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_77(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00500000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_78(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00100000:
                            if (decision_node_code32x1_81(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00400000:
                            if (decision_node_code32x1_85(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00500000:
                            if (decision_node_code32x1_86(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_78(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01af0fff) {
                    
                        case 0x012d0004:
                            if (decision_node_code32x1_79(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_80(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_79(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_push_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_80(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_str_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_81(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x000f0000) {
                    
                        case 0x000d0000:
                            if (decision_node_code32x1_82(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x000f0000:
                            if (decision_node_code32x1_83(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_84(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_82(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_pop_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_83(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_ldr_literal_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_84(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_ldr_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_85(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_strb_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_86(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_ldrb_imm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_87(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00400010) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_88(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00000010:
                            if (decision_node_code32x1_91(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00400000:
                            if (decision_node_code32x1_94(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00400010:
                            if (decision_node_code32x1_97(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_88(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00100000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_89(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00100000:
                            if (decision_node_code32x1_90(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_89(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_str_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_90(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_ldr_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_91(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01bf03e0) {
                    
                        case 0x00af0060:
                            if (decision_node_code32x1_92(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00bf0060:
                            if (decision_node_code32x1_93(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_92(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_sxtb_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_93(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_sxth_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_94(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00100000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_95(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00100000:
                            if (decision_node_code32x1_96(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_95(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_strb_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_96(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_ldrb_reg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_97(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01a00040) {
                    
                        case 0x00a00040:
                            if (decision_node_code32x1_98(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01000000:
                            if (decision_node_code32x1_101(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01800000:
                            if (decision_node_code32x1_102(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_98(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x001f03a0) {
                    
                        case 0x000f0020:
                            if (decision_node_code32x1_99(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x001f0020:
                            if (decision_node_code32x1_100(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_99(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_uxtb_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_100(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_uxth_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_101(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_smmul_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_102(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_bfc_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_103(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00500000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_104(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00100000:
                            if (decision_node_code32x1_109(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00400000:
                            if (decision_node_code32x1_114(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_104(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01800000) {
                    
                        case 0x00800000:
                            if (decision_node_code32x1_105(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01000000:
                            if (decision_node_code32x1_106(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_105(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_stm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_106(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x002f0000) {
                    
                        case 0x002d0000:
                            if (decision_node_code32x1_107(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_108(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_107(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_push_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_108(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_stmfd_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_109(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01800000) {
                    
                        case 0x00800000:
                            if (decision_node_code32x1_110(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_113(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_110(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x002f0000) {
                    
                        case 0x002d0000:
                            if (decision_node_code32x1_111(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_112(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_111(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_pop_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_112(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_ldm_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_113(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_rfe_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_114(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_srs_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_115(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01000000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_116(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01000000:
                            if (decision_node_code32x1_117(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_118(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_116(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_b_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_117(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_bl_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_118(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_blx_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_119(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01300f00) {
                    
                        case 0x00300a00:
                            if (decision_node_code32x1_120(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00300b00:
                            if (decision_node_code32x1_121(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01000a00:
                            if (decision_node_code32x1_122(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01000b00:
                            if (decision_node_code32x1_123(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01100a00:
                            if (decision_node_code32x1_124(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01100b00:
                            if (decision_node_code32x1_125(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01200a00:
                            if (decision_node_code32x1_126(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x01200b00:
                            if (decision_node_code32x1_127(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_120(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vpop_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_121(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vpop_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_122(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vstr_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_123(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vstr_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_124(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vldr_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_125(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vldr_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_126(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vpush_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_127(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vpush_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_128(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x01000010) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_129(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00000010:
                            if (decision_node_code32x1_141(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_129(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00b00e40) {
                    
                        case 0x00200a00:
                            if (decision_node_code32x1_130(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00300a00:
                            if (decision_node_code32x1_131(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00300a40:
                            if (decision_node_code32x1_132(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00800a00:
                            if (decision_node_code32x1_133(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00b00a00:
                            if (decision_node_code32x1_134(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00b00a40:
                            if (decision_node_code32x1_135(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_130(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vmul_freg_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_131(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vadd_freg_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_132(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vsub_freg_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_133(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vdiv_freg_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_134(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vmov_imm_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_135(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00080000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_136(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00080000:
                            if (decision_node_code32x1_140(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_136(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00070000) {
                    
                        case 0x00040000:
                            if (decision_node_code32x1_137(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00050000:
                            if (decision_node_code32x1_138(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00070000:
                            if (decision_node_code32x1_139(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
            return 1;
        }
        static int decision_node_code32x1_137(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vcmp_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_138(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vcmp_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_139(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vcvt_df_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_140(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vcvt_fi_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_141(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00100000) {
                    
                        case 0x00000000:
                            if (decision_node_code32x1_142(context, code) == 0) {
                                return 0;
                            }
                            break;
                        case 0x00100000:
                            if (decision_node_code32x1_145(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_150(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_142(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0xf0000000) {
                    
                        case 0xf0000000:
                            if (decision_node_code32x1_143(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_144(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_143(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_mcr2_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_144(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_mcr_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_145(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0xf0000000) {
                    
                        case 0xf0000000:
                            if (decision_node_code32x1_146(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_147(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_146(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_mrc2_a2(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_147(OpDecodeContext *context, arm_uint32 code) {
            
            switch (code & 0x00ef0fef) {
                    
                        case 0x00e10a00:
                            if (decision_node_code32x1_148(context, code) == 0) {
                                return 0;
                            }
                            break;
                }
            
                if (decision_node_code32x1_149(context, code) == 0) {
                    return 0;
                }
            return 1;
        }
        static int decision_node_code32x1_148(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vmrs_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_149(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_mrc_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }
        static int decision_node_code32x1_150(OpDecodeContext *context, arm_uint32 code) {
            
                if (op_parse_arm_vmov_sreg_a1(context) == 0) {
                    return 0;
                }
            
            return 1;
        }

/* op parse function */
int arm_op_parse(arm_uint16 code[arm_OP_DECODE_MAX], arm_OpDecodedCodeType *decoded_code, arm_OperationCodeType *optype) {
    

    OpDecodeContext context;
    context.code = &code[0];
    context.decoded_code = decoded_code;
    context.optype = optype;
    
        context.code16x1 = code[0];
        context.code16x2 = (((arm_uint32) code[0]) << 16) | ((arm_uint32) code[1]);
        context.code32x1 = *((arm_uint32 *) &code[0]);
    
    if (decision_node_code32x1_0(&context, context.code32x1) == 0) {
            return 0;
        }
    
    return 1;
}

arm_OpExecType arm_op_exec_table[arm_OpCodeId_Num] = {
    
	{ 1, arm_op_exec_arm_add_imm_a1 },		/* arm_add_imm_a1 */
    
	{ 1, arm_op_exec_arm_add_reg_a1 },		/* arm_add_reg_a1 */
    
	{ 1, arm_op_exec_arm_adc_reg_a1 },		/* arm_adc_reg_a1 */
    
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
    
	{ 1, arm_op_exec_arm_str_reg_a1 },		/* arm_str_reg_a1 */
    
	{ 1, arm_op_exec_arm_strb_reg_a1 },		/* arm_strb_reg_a1 */
    
	{ 1, arm_op_exec_arm_push_a1 },		/* arm_push_a1 */
    
	{ 1, arm_op_exec_arm_push_a2 },		/* arm_push_a2 */
    
	{ 1, arm_op_exec_arm_stmfd_a1 },		/* arm_stmfd_a1 */
    
	{ 1, arm_op_exec_arm_stm_a1 },		/* arm_stm_a1 */
    
	{ 1, arm_op_exec_arm_ldr_imm_a1 },		/* arm_ldr_imm_a1 */
    
	{ 1, arm_op_exec_arm_ldr_literal_a1 },		/* arm_ldr_literal_a1 */
    
	{ 1, arm_op_exec_arm_ldrb_imm_a1 },		/* arm_ldrb_imm_a1 */
    
	{ 1, arm_op_exec_arm_ldrh_imm_a1 },		/* arm_ldrh_imm_a1 */
    
	{ 1, arm_op_exec_arm_ldrd_imm_a1 },		/* arm_ldrd_imm_a1 */
    
	{ 1, arm_op_exec_arm_ldr_reg_a1 },		/* arm_ldr_reg_a1 */
    
	{ 1, arm_op_exec_arm_ldrb_reg_a1 },		/* arm_ldrb_reg_a1 */
    
	{ 1, arm_op_exec_arm_ldrsh_imm_a1 },		/* arm_ldrsh_imm_a1 */
    
	{ 1, arm_op_exec_arm_ldrh_reg_a1 },		/* arm_ldrh_reg_a1 */
    
	{ 1, arm_op_exec_arm_pop_a1 },		/* arm_pop_a1 */
    
	{ 1, arm_op_exec_arm_pop_a2 },		/* arm_pop_a2 */
    
	{ 1, arm_op_exec_arm_ldm_a1 },		/* arm_ldm_a1 */
    
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
    
	{ 1, arm_op_exec_arm_lsr_reg_a1 },		/* arm_lsr_reg_a1 */
    
	{ 1, arm_op_exec_arm_bfc_a1 },		/* arm_bfc_a1 */
    
	{ 1, arm_op_exec_arm_and_imm_a1 },		/* arm_and_imm_a1 */
    
	{ 1, arm_op_exec_arm_and_reg_a1 },		/* arm_and_reg_a1 */
    
	{ 1, arm_op_exec_arm_uxtb_a1 },		/* arm_uxtb_a1 */
    
	{ 1, arm_op_exec_arm_uxth_a1 },		/* arm_uxth_a1 */
    
	{ 1, arm_op_exec_arm_rsb_reg_a1 },		/* arm_rsb_reg_a1 */
    
	{ 1, arm_op_exec_arm_rsb_imm_a1 },		/* arm_rsb_imm_a1 */
    
	{ 1, arm_op_exec_arm_sbc_reg_a1 },		/* arm_sbc_reg_a1 */
    
	{ 1, arm_op_exec_arm_mul_a1 },		/* arm_mul_a1 */
    
	{ 1, arm_op_exec_arm_smmul_a1 },		/* arm_smmul_a1 */
    
	{ 1, arm_op_exec_arm_smull_a1 },		/* arm_smull_a1 */
    
	{ 1, arm_op_exec_arm_tst_imm_a1 },		/* arm_tst_imm_a1 */
    
	{ 1, arm_op_exec_arm_tst_reg_a1 },		/* arm_tst_reg_a1 */
    
	{ 1, arm_op_exec_arm_sxtb_a1 },		/* arm_sxtb_a1 */
    
	{ 1, arm_op_exec_arm_sxth_a1 },		/* arm_sxth_a1 */
    
	{ 1, arm_op_exec_arm_asr_imm_a1 },		/* arm_asr_imm_a1 */
    
	{ 1, arm_op_exec_arm_srs_a1 },		/* arm_srs_a1 */
    
	{ 1, arm_op_exec_arm_clz_a1 },		/* arm_clz_a1 */
    
	{ 1, arm_op_exec_arm_rfe_a1 },		/* arm_rfe_a1 */
    
	{ 1, arm_op_exec_arm_wfi_a1 },		/* arm_wfi_a1 */
    
	{ 1, arm_op_exec_arm_vadd_freg_a2 },		/* arm_vadd_freg_a2 */
    
	{ 1, arm_op_exec_arm_vldr_a1 },		/* arm_vldr_a1 */
    
	{ 1, arm_op_exec_arm_vldr_a2 },		/* arm_vldr_a2 */
    
	{ 1, arm_op_exec_arm_vcvt_df_a1 },		/* arm_vcvt_df_a1 */
    
	{ 1, arm_op_exec_arm_vcvt_fi_a1 },		/* arm_vcvt_fi_a1 */
    
	{ 1, arm_op_exec_arm_vstr_a1 },		/* arm_vstr_a1 */
    
	{ 1, arm_op_exec_arm_vstr_a2 },		/* arm_vstr_a2 */
    
	{ 1, arm_op_exec_arm_vcmp_a1 },		/* arm_vcmp_a1 */
    
	{ 1, arm_op_exec_arm_vcmp_a2 },		/* arm_vcmp_a2 */
    
	{ 1, arm_op_exec_arm_vmrs_a1 },		/* arm_vmrs_a1 */
    
	{ 1, arm_op_exec_arm_vmov_imm_a1 },		/* arm_vmov_imm_a1 */
    
	{ 1, arm_op_exec_arm_vmov_imm_a2 },		/* arm_vmov_imm_a2 */
    
	{ 1, arm_op_exec_arm_vmov_sreg_a1 },		/* arm_vmov_sreg_a1 */
    
	{ 1, arm_op_exec_arm_vsub_freg_a2 },		/* arm_vsub_freg_a2 */
    
	{ 1, arm_op_exec_arm_vmul_freg_a2 },		/* arm_vmul_freg_a2 */
    
	{ 1, arm_op_exec_arm_vdiv_freg_a2 },		/* arm_vdiv_freg_a2 */
    
	{ 1, arm_op_exec_arm_vpush_a1 },		/* arm_vpush_a1 */
    
	{ 1, arm_op_exec_arm_vpush_a2 },		/* arm_vpush_a2 */
    
	{ 1, arm_op_exec_arm_vpop_a1 },		/* arm_vpop_a1 */
    
	{ 1, arm_op_exec_arm_vpop_a2 },		/* arm_vpop_a2 */
    
};