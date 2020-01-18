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

int arm_op_exec_arm_msr2_reg(struct TargetCore *core,  arm_msr2_reg_input_type *in, arm_msr2_reg_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if (in->write_spsr) {
			//SPSRWriteByInstr(R[n], mask);
			SPSRWriteByInstr(core, in->Rn.regData, in->mask);
		}
		else {
			//CPSRWriteByInstr(R[n], mask, FALSE);
			CPSRWriteByInstr(core, in->Rn.regData, in->mask, FALSE);
			uint32 cpsr4_0 = (*status) & 0x1F;
			//if CPSR<4:0> == '11010' && CPSR.J == '1' && CPSR.T == '1' then UNPREDICTABLE;
			if ((cpsr4_0 == 0b11010) && (CurrentInstrSet(*status) == InstrSet_ThumbEE)) {
				//then UNPREDICTABLE;
				return -1;
			}
		}
	}
	out->status = *status;
	return ret;
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


int arm_op_exec_arm_mcr(struct TargetCore *core,  arm_mcr_input_type *in, arm_mcr_output_type *out)
{
	CoprocOpType coproc_op;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		coproc_op.CRm = in->CRm;
		coproc_op.CRn = in->CRn;
		coproc_op.cp = in->cp;
		coproc_op.op1 = in->op1;
		coproc_op.op2 = in->op2;
		if (!Coproc_Accepted(core, in->cp, &coproc_op)) {
			GenerateCoprocessorException(core);
			return -1;
		}
		else {
			//Coproc_SendOneWord(R[t], cp, ThisInstr());

		}
	}
	out->status = *status;
	return 0;
}
int arm_op_exec_arm_mrc(struct TargetCore *core,  arm_mrc_input_type *in, arm_mrc_output_type *out)
{
	CoprocOpType coproc_op;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		coproc_op.CRm = in->CRm;
		coproc_op.CRn = in->CRn;
		coproc_op.cp = in->cp;
		coproc_op.op1 = in->op1;
		coproc_op.op2 = in->op2;
		uint32 value;
		if (!Coproc_Accepted(core, in->cp, &coproc_op)) {
			GenerateCoprocessorException(core);
			return -1;
		}
		else {
			value = Coproc_GetOneWord(core, in->cp, &coproc_op);
		}
		if (in->Rt.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rt.regId, value);
		}
		else {
			// Note: not all coprocessors support assignment to the APSR
			//APSR.N = value<31>;
			//APSR.Z = value<30>;
			//APSR.C = value<29>;
			//APSR.V = value<28>;
			// value<27:0> are not used.
			user_status_set(status, 0xF0000000, value);
		}
	}
	out->status = *status;
	return 0;
}


int arm_op_exec_arm_rfe(struct TargetCore *core,  arm_rfe_input_type *in, arm_rfe_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = TRUE;
	if (out->passed != FALSE) {
		//address = if increment then R[n] else R[n]-8;
		uint32 address = (in->increment) ? in->Rn.regData : in->Rn.regData - 8;

		//if wordhigher then address = address+4;
		if (in->wordhigher) {
			address += 4;
		}
		//new_pc_value = MemA[address,4];
		uint32 new_pc_value;
		ret = MemA_R(core, address, 4, (uint8*)&new_pc_value);
		if (ret != 0) {
			goto done;
		}
		//spsr_value = MemA[address+4,4];
		uint32 spsr_value;
		ret = MemA_R(core, address + 4, 4, (uint8*)&spsr_value);
		if (ret != 0) {
			goto done;
		}
		//if wback then R[n] = if increment then R[n]+8 else R[n]-8;
		if (in->wback) {
			out->Rn.regData = (in->increment) ? in->Rn.regData + 8 : in->Rn.regData - 8;
		}
		//CPSRWriteByInstr(spsr_value, '1111', TRUE);
		ret = CPSRWriteByInstr(core, spsr_value, 0b1111, TRUE);
		if (ret != 0) {
			goto done;
		}
		//BranchWritePC(new_pc_value);
		ret = BranchWritePC(&out->next_address, status, new_pc_value);
		if (ret != 0) {
			goto done;
		}
	}
done:
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_wfi(struct TargetCore *core,  arm_wfi_input_type *in, arm_wfi_output_type *out)
{
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		core->is_halt = TRUE;
	}
	out->status = *status;
	return 0;
}

