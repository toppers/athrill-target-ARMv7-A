#ifndef _ARM_PSEUDO_CODE_FUNC_H_
#define _ARM_PSEUDO_CODE_FUNC_H_

#include "cpu_op_types.h"
#include "arm_pseudo_code_type.h"

extern int arm_op_exec_arm_add_imm(struct TargetCore *core,  arm_add_imm_input_type *in, arm_add_imm_output_type *out);
extern int arm_op_exec_arm_sub_imm(struct TargetCore *core,  arm_sub_imm_input_type *in, arm_sub_imm_output_type *out);
extern int arm_op_exec_arm_cmp_imm(struct TargetCore *core,  arm_cmp_imm_input_type *in, arm_cmp_imm_output_type *out);
extern int arm_op_exec_arm_cmp_reg(struct TargetCore *core,  arm_cmp_reg_input_type *in, arm_cmp_reg_output_type *out);
extern int arm_op_exec_arm_adr_imm(struct TargetCore *core,  arm_adr_imm_input_type *in, arm_adr_imm_output_type *out);
extern int arm_op_exec_arm_add_spimm(struct TargetCore *core,  arm_add_spimm_input_type *in, arm_add_spimm_output_type *out);
extern int arm_op_exec_arm_subs_pclr(struct TargetCore *core,  arm_subs_pclr_input_type *in, arm_subs_pclr_output_type *out);
extern int arm_op_exec_arm_mov_imm(struct TargetCore *core,  arm_mov_imm_input_type *in, arm_mov_imm_output_type *out);
extern int arm_op_exec_arm_mov_reg(struct TargetCore *core,  arm_mov_reg_input_type *in, arm_mov_reg_output_type *out);
extern int arm_op_exec_arm_bl_imm(struct TargetCore *core,  arm_bl_imm_input_type *in, arm_bl_imm_output_type *out);
extern int arm_op_exec_arm_b_imm(struct TargetCore *core,  arm_b_imm_input_type *in, arm_b_imm_output_type *out);
extern int arm_op_exec_arm_bx_reg(struct TargetCore *core,  arm_bx_reg_input_type *in, arm_bx_reg_output_type *out);
extern int arm_op_exec_arm_ldr_imm(struct TargetCore *core,  arm_ldr_imm_input_type *in, arm_ldr_imm_output_type *out);
extern int arm_op_exec_arm_ldr_reg(struct TargetCore *core,  arm_ldr_reg_input_type *in, arm_ldr_reg_output_type *out);
extern int arm_op_exec_arm_push(struct TargetCore *core,  arm_push_input_type *in, arm_push_output_type *out);
extern int arm_op_exec_arm_pop(struct TargetCore *core,  arm_pop_input_type *in, arm_pop_output_type *out);
extern int arm_op_exec_arm_str_imm(struct TargetCore *core,  arm_str_imm_input_type *in, arm_str_imm_output_type *out);
extern int arm_op_exec_arm_str_reg(struct TargetCore *core,  arm_str_reg_input_type *in, arm_str_reg_output_type *out);
extern int arm_op_exec_arm_nop(struct TargetCore *core,  arm_nop_input_type *in, arm_nop_output_type *out);
#endif /* !_ARM_PSEUDO_CODE_FUNC_H_ */