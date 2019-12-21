#include "arm_mcdecoder.h"

typedef struct {
    arm_uint16 *code;
    arm_OpDecodedCodeType *decoded_code;
    arm_OperationCodeType *optype;
    arm_uint16 code16;
    arm_uint32 code32;
} OpDecodeContext;

/* op constants */

    /* add_1 */
    #define OP_FB_MASK_add_1 (0x0fe00000l) /* fixed bits mask */
    #define OP_FB_add_1 (0x02800000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_add_1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_add_1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_add_1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'S' */
            #define OP_SF_MASK_add_1_S_0 (0x00100000l) /* subfield mask */
            #define OP_SF_EBII_add_1_S_0 (20) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_add_1_S_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rn' */
            #define OP_SF_MASK_add_1_Rn_0 (0x000f0000l) /* subfield mask */
            #define OP_SF_EBII_add_1_Rn_0 (16) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_add_1_Rn_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'Rd' */
            #define OP_SF_MASK_add_1_Rd_0 (0x0000f000l) /* subfield mask */
            #define OP_SF_EBII_add_1_Rd_0 (12) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_add_1_Rd_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'imm12' */
            #define OP_SF_MASK_add_1_imm12_0 (0x00000fffl) /* subfield mask */
            #define OP_SF_EBII_add_1_imm12_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_add_1_imm12_0 (0) /* subfield end bit position in field */
        
    

    /* push_1 */
    #define OP_FB_MASK_push_1 (0x0fff0000l) /* fixed bits mask */
    #define OP_FB_push_1 (0x092d0000l) /* fixed bits */
    
        
            /* 0th subfield of the field 'cond' */
            #define OP_SF_MASK_push_1_cond_0 (0xf0000000l) /* subfield mask */
            #define OP_SF_EBII_push_1_cond_0 (28) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_push_1_cond_0 (0) /* subfield end bit position in field */
        
    
        
            /* 0th subfield of the field 'register_list' */
            #define OP_SF_MASK_push_1_register_list_0 (0x0000ffffl) /* subfield mask */
            #define OP_SF_EBII_push_1_register_list_0 (0) /* subfield end bit position in instruction */
            #define OP_SF_EBIF_push_1_register_list_0 (0) /* subfield end bit position in field */
        
    


/* individual op parse functions */

    /* add_1 */
    static int op_parse_add_1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_add_1) != OP_FB_add_1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_add_1;
        context->optype->format_id = arm_OP_CODE_FORMAT_add_1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_add_1;
        
            context->decoded_code->code.add_1.cond =
            
                (((context->code32 & OP_SF_MASK_add_1_cond_0) >> OP_SF_EBII_add_1_cond_0) << OP_SF_EBIF_add_1_cond_0);
            
        
            context->decoded_code->code.add_1.S =
            
                (((context->code32 & OP_SF_MASK_add_1_S_0) >> OP_SF_EBII_add_1_S_0) << OP_SF_EBIF_add_1_S_0);
            
        
            context->decoded_code->code.add_1.Rn =
            
                (((context->code32 & OP_SF_MASK_add_1_Rn_0) >> OP_SF_EBII_add_1_Rn_0) << OP_SF_EBIF_add_1_Rn_0);
            
        
            context->decoded_code->code.add_1.Rd =
            
                (((context->code32 & OP_SF_MASK_add_1_Rd_0) >> OP_SF_EBII_add_1_Rd_0) << OP_SF_EBIF_add_1_Rd_0);
            
        
            context->decoded_code->code.add_1.imm12 =
            
                (((context->code32 & OP_SF_MASK_add_1_imm12_0) >> OP_SF_EBII_add_1_imm12_0) << OP_SF_EBIF_add_1_imm12_0);
            
        
        return 0;
    }

    /* push_1 */
    static int op_parse_push_1(OpDecodeContext *context) {
        if ((context->code32 & OP_FB_MASK_push_1) != OP_FB_push_1) {
            return 1;
        }

        context->optype->code_id = arm_OpCodeId_push_1;
        context->optype->format_id = arm_OP_CODE_FORMAT_push_1;
        context->decoded_code->type_id = arm_OP_CODE_FORMAT_push_1;
        
            context->decoded_code->code.push_1.cond =
            
                (((context->code32 & OP_SF_MASK_push_1_cond_0) >> OP_SF_EBII_push_1_cond_0) << OP_SF_EBIF_push_1_cond_0);
            
        
            context->decoded_code->code.push_1.register_list =
            
                (((context->code32 & OP_SF_MASK_push_1_register_list_0) >> OP_SF_EBII_push_1_register_list_0) << OP_SF_EBIF_push_1_register_list_0);
            
        
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

    
        if (op_parse_add_1(&context) == 0) {
            return 0;
        }
    
        if (op_parse_push_1(&context) == 0) {
            return 0;
        }
    

    return 1;
}