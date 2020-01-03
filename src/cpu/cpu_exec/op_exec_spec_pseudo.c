#include "arm_pseudo_code_func.h"

int arm_op_exec_arm_nop(struct TargetCore *core,  arm_nop_input_type *in, arm_nop_output_type *out)
{
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->status = *status;
    return 0;
}


int arm_op_exec_arm_msr_imm(struct TargetCore *core,  arm_msr_imm_input_type *in, arm_msr_imm_output_type *out)
{
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if (in->write_nzcvq) {
			//APSR.N = imm32<31>;
			//APSR.Z = imm32<30>;
			//APSR.C = imm32<29>;
			//APSR.V = imm32<28>;
			//APSR.Q = imm32<27>;
			user_status_set(status, 0xF8000000, in->imm32);
		}
		if (in->write_g) {
			//APSR.GE = imm32<19:16>;
			user_status_set(status, 0x000F0000, in->imm32);
		}
	}
	out->status = *status;
	return 0;
}

int arm_op_exec_arm_msr2_imm(struct TargetCore *core,  arm_msr2_imm_input_type *in, arm_msr2_imm_output_type *out)
{
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if (in->write_spsr) {
			SPSRWriteByInstr(core, in->imm32, in->mask);
		}
		else {
			CPSRWriteByInstr(core, in->imm32, in->mask, FALSE);
			uint32 cpsr4_0 = (*status) & 0x1F;
			if ((cpsr4_0 == 0b11010) && (CurrentInstrSet(*status) == InstrSet_ThumbEE)) {
				//then UNPREDICTABLE;
				return -1;
			}
		}
	}
	out->status = *status;
	return 0;
}

int arm_op_exec_arm_mrs(struct TargetCore *core,  arm_mrs_input_type *in, arm_mrs_output_type *out)
{
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//R[d] = APSR;
		out->Rd.regData = *status;
		cpu_set_reg(core, in->Rd.regId, out->Rd.regData);
	}
	out->status = *status;
	return 0;
}

