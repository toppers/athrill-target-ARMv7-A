#include "arm_pseudo_code_func.h"


int arm_op_exec_arm_bic_imm(struct TargetCore *core,  arm_bic_imm_input_type *in, arm_bic_imm_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		result = (in->Rn.regData & ~(in->imm32));
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			if (in->S != 0) {
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, out->status_flag.carry);
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
			}
			out->Rd.regData = result;
		}
		else {
			ret = ALUWritePC(&out->next_address, status, result);
			out->Rd.regData = out->next_address;
		}
	}
	out->status = *status;
	return ret;
}


int arm_op_exec_arm_orr_imm(struct TargetCore *core,  arm_orr_imm_input_type *in, arm_orr_imm_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		result = (in->Rn.regData | (in->imm32));
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			if (in->S != 0) {
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, out->status_flag.carry);
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
			}
			out->Rd.regData = result;
		}
		else {
			ret = ALUWritePC(&out->next_address, status, result);
			out->Rd.regData = out->next_address;
		}
	}
	out->status = *status;
	return ret;
}
