#include "arm_pseudo_code_func.h"

int arm_op_exec_arm_add_imm(struct TargetCore *core,  arm_add_imm_input_type *in, arm_add_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
int arm_op_exec_arm_adr_imm(struct TargetCore *core,  arm_adr_imm_input_type *in, arm_adr_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
int arm_op_exec_arm_add_spimm(struct TargetCore *core,  arm_add_spimm_input_type *in, arm_add_spimm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
int arm_op_exec_arm_subs_pclr(struct TargetCore *core,  arm_subs_pclr_input_type *in, arm_subs_pclr_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
int arm_op_exec_arm_mov_imm(struct TargetCore *core,  arm_mov_imm_input_type *in, arm_mov_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
int arm_op_exec_arm_mov_reg(struct TargetCore *core,  arm_mov_reg_input_type *in, arm_mov_reg_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
int arm_op_exec_arm_bl_imm(struct TargetCore *core,  arm_bl_imm_input_type *in, arm_bl_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
int arm_op_exec_arm_b_imm(struct TargetCore *core,  arm_b_imm_input_type *in, arm_b_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
int arm_op_exec_arm_ldr_imm(struct TargetCore *core,  arm_ldr_imm_input_type *in, arm_ldr_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
int arm_op_exec_arm_str_imm(struct TargetCore *core,  arm_str_imm_input_type *in, arm_str_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//TODO
	}
	out->status = *status;
}
