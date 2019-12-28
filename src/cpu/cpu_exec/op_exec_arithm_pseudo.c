#include "arm_pseudo_code_func.h"
#include "cpu_ops.h"

int arm_op_exec_arm_add_imm(struct TargetCore *core,  arm_add_imm_input_type *in, arm_add_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		out->result = AddWithCarry(32, in->Rn.regData, in->imm32, FALSE, &out->status_flag);
		 if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, out->result);
			if (in->S != 0) {
				cpu_update_status_flag(status, out->result, &out->status_flag);
			}
			out->next_address = core->pc + INST_ARM_SIZE;
			ret = 0;
		 }
		 else {
			 uint32 pc;
			ret = ALUWritePC(&pc, status, out->result);
            if (ret == 0) {
                out->next_address = pc;
            }
		 }
	}
	out->status = *status;
	return ret;
}
