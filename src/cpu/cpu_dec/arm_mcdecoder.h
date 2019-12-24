#ifndef _arm_MC_DECODER_H_
#define _arm_MC_DECODER_H_

#include <stdint.h>

typedef uint8_t arm_uint8;
typedef uint16_t arm_uint16;
typedef uint32_t arm_uint32;

#define arm_OP_CODE_FORMAT_NUM	arm_OP_CODE_FORMAT_UNKNOWN

typedef enum {
	
		arm_OP_CODE_FORMAT_arm_add_imm_a1,
	
		arm_OP_CODE_FORMAT_push_1,
	
		arm_OP_CODE_FORMAT_arm_mov_imm_a1,
	
		arm_OP_CODE_FORMAT_arm_mov_imm_a2,
	
	arm_OP_CODE_FORMAT_UNKNOWN,
} arm_OpCodeFormatId;

typedef enum {
	
		arm_OpCodeId_arm_add_imm_a1,
	
		arm_OpCodeId_push_1,
	
		arm_OpCodeId_arm_mov_imm_a1,
	
		arm_OpCodeId_arm_mov_imm_a2,
	
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
	
		arm_uint16 register_list;	/* 15-0 */
	
} arm_OpCodeFormatType_push_1;

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
	arm_OpCodeFormatId type_id;
    union {
		
        	arm_OpCodeFormatType_arm_add_imm_a1 arm_add_imm_a1;
		
        	arm_OpCodeFormatType_push_1 push_1;
		
        	arm_OpCodeFormatType_arm_mov_imm_a1 arm_mov_imm_a1;
		
        	arm_OpCodeFormatType_arm_mov_imm_a2 arm_mov_imm_a2;
		
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
extern int arm_op_exec_push_1(struct TargetCore *core);
extern int arm_op_exec_arm_mov_imm_a1(struct TargetCore *core);
extern int arm_op_exec_arm_mov_imm_a2(struct TargetCore *core);
#endif /* !_arm_MC_DECODER_H_ */