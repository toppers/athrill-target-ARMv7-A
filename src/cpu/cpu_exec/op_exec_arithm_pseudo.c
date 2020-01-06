#include "arm_pseudo_code_func.h"

int arm_op_exec_arm_add_imm(struct TargetCore *core,  arm_add_imm_input_type *in, arm_add_imm_output_type *out)
{
	int ret = 0;
	sint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		result = AddWithCarry(32, in->Rn.regData, in->imm32, FALSE, &out->status_flag);
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			if (in->S != 0) {
				cpu_update_status_flag(status, result, &out->status_flag);
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


int arm_op_exec_arm_add_reg(struct TargetCore *core,  arm_add_reg_input_type *in, arm_add_reg_output_type *out)
{
	int ret = 0;
	sint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//shifted = Shift(R[m], shift_t, shift_n, APSR.C);
		uint32 shifted = Shift(32, in->Rm.regData, in->shift_t, in->shift_n, CPU_ISSET_CY(status));
		//(result, carry, overflow) = AddWithCarry(R[n], shifted, ‘0’);
		result = AddWithCarry(32, in->Rn.regData, shifted, FALSE, &out->status_flag);
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			cpu_update_status_flag(status, result, &out->status_flag);		
			out->Rd.regData = result;
		}
		else {
			//ALUWritePC(result); // setflags is always FALSE here
			ret = ALUWritePC(&out->next_address, status, result);
			out->Rd.regData = out->next_address;
		}
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_adr_imm(struct TargetCore *core,  arm_adr_imm_input_type *in, arm_adr_imm_output_type *out)
{
	int ret = 0;
	sint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		uint32 pc = cpu_get_reg(core, CpuRegId_PC);
		result = (in->add != 0) ? Align(pc, 4) + in->imm32 : Align(pc, 4) - in->imm32;
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
		}
		else {
			ret = ALUWritePC(&out->next_address, status, result);
			out->Rd.regData = out->next_address;
		}
	}
	out->status = *status;
	return ret;
}
int arm_op_exec_arm_add_spimm(struct TargetCore *core,  arm_add_spimm_input_type *in, arm_add_spimm_output_type *out)
{
	int ret = 0;
	sint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		result = AddWithCarry(32, in->SP.regData, in->imm32, FALSE, &out->status_flag);
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			if (in->S != 0) {
				cpu_update_status_flag(status, result, &out->status_flag);
			}
		}
		else {
			ret = ALUWritePC(&out->next_address, status, result);
		}
		out->Rd.regData = result;
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_subs_pclr(struct TargetCore *core,  arm_subs_pclr_input_type *in, arm_subs_pclr_output_type *out)
{
	int ret = 0;
	sint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if (CurrentModeIsHyp(*status)) {
			//UNDEFINED;
			return -1;
		}
		else if (CurrentModeIsUserOrSystem(*status)) {
			//UNPREDICTABLE;
			return -1;
		}
		else {
			uint32 operand2 = (in->register_form) ? 
								Shift(32, in->Rm.regData, in->shift_t, in->shift_n, out->status_flag.carry)
								: in->imm32;
			switch (in->opcode) {
				case 0b0000:
					result = in->Rn.regData & operand2; // AND
					break;
				case 0b0001:
					result = in->Rn.regData ^ operand2; // EOR
					break;
				case 0b0010:
					result = AddWithCarry(32, in->Rn.regData, ~operand2, TRUE, NULL); // SUB
					break;
				case 0b0011:
					result = AddWithCarry(32, ~in->Rn.regData, operand2, TRUE, NULL); // RSB
					break;
				case 0b0100:
					result = AddWithCarry(32, in->Rn.regData, operand2, FALSE, NULL); // ADD
					break;
				case 0b0101:
					result = AddWithCarry(32, in->Rn.regData, operand2, out->status_flag.carry, NULL); // ADC
					break;
				case 0b0110:
					result = AddWithCarry(32, in->Rn.regData, ~operand2, out->status_flag.carry, NULL); // SBC
					break;
				case 0b0111:
					result = AddWithCarry(32, ~in->Rn.regData, operand2, out->status_flag.carry, NULL); // RSC
					break;
				case 0b1100:
					result = in->Rn.regData | operand2; // ORR
					break;
				case 0b1101:
					result = operand2;
					break;
				case 0b1110:
					result = in->Rn.regData & ~operand2; // BIC
					break;
				case 0b1111:
					result = ~operand2; // MVN
					break;
				default:
					ret = -1;
					goto done;
			}
			uint32 *saved_status = cpu_get_saved_status(core);
			CPSRWriteByInstr(core, *saved_status, 0x0F, TRUE);
			uint32 cpsr4_0 = (*status) & 0x1F;
			//// Return to Hyp mode in ThumbEE is UNPREDICTABLE
			if ((cpsr4_0 == 0b11010) && (CurrentInstrSet(*status) == InstrSet_ThumbEE)) {
				//UNPREDICTABLE;
				return -1;
			}
			else {
				ret = BranchWritePC(&out->next_address, status, result);
				out->PC.regData = out->next_address;
			}
		}
	}
done:
	out->status = *status;
	return ret;
}


int arm_op_exec_arm_cmp_imm(struct TargetCore *core,  arm_cmp_imm_input_type *in, arm_cmp_imm_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		uint32 value;
		if (in->sign == FALSE) {
			value = ~(in->imm32);
		}
		else {
			value = in->imm32;
		}
		out->result = AddWithCarry(32, in->Rn.regData, value, TRUE, &out->status_flag);
		cpu_update_status_flag(status, out->result, &out->status_flag);
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_cmp_reg(struct TargetCore *core,  arm_cmp_reg_input_type *in, arm_cmp_reg_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//shifted = Shift(R[m], shift_t, shift_n, APSR.C);
		uint32 shifted = Shift(32, in->Rm.regData, in->shift_t, in->shift_n, CPU_ISSET_CY(status));
		//(result, carry, overflow) = AddWithCarry(R[n], NOT(shifted), ‘1’);
		out->result = AddWithCarry(32, in->Rn.regData, ~(shifted), TRUE, &out->status_flag);
		cpu_update_status_flag(status, out->result, &out->status_flag);
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_sub_imm(struct TargetCore *core,  arm_sub_imm_input_type *in, arm_sub_imm_output_type *out)
{
	int ret = 0;
	sint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		result = AddWithCarry(32, in->Rn.regData, ~(in->imm32), TRUE, &out->status_flag);
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			if (in->S != 0) {
				cpu_update_status_flag(status, result, &out->status_flag);
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

int arm_op_exec_arm_rsb_reg(struct TargetCore *core,  arm_rsb_reg_input_type *in, arm_rsb_reg_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		uint32 shifted = Shift_C(32, in->Rm.regData, in->shift_t, in->shift_n, out->status_flag.carry, &out->status_flag.carry);
		result = AddWithCarry(32, ~(in->Rn.regData), shifted, TRUE, &out->status_flag);
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			if (in->S != 0) {
				cpu_update_status_flag(status, result, &out->status_flag);
			}
			out->Rd.regData = result;
		}
		else {
			ret = ALUWritePC(&out->next_address, status, result);
			out->Rd.regData = out->next_address;
		}
		out->Rd.regData = result;
	}
	out->status = *status;
	return ret;
}


int arm_op_exec_arm_sbc_reg(struct TargetCore *core,  arm_sbc_reg_input_type *in, arm_sbc_reg_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		uint32 shifted = Shift_C(32, in->Rm.regData, in->shift_t, in->shift_n, out->status_flag.carry, &out->status_flag.carry);
		result = AddWithCarry(32, ~(in->Rn.regData), ~shifted, TRUE, &out->status_flag);
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			if (in->S != 0) {
				cpu_update_status_flag(status, result, &out->status_flag);
			}
			out->Rd.regData = result;
		}
		else {
			ret = ALUWritePC(&out->next_address, status, result);
			out->Rd.regData = out->next_address;
		}
		out->Rd.regData = result;
	}
	out->status = *status;
	return ret;
}


int arm_op_exec_arm_mul(struct TargetCore *core,  arm_mul_input_type *in, arm_mul_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		sint32 operand1 = SInt(in->Rn.regData); // operand1 = UInt(R[n]) produces the same final results
		sint32 operand2 = SInt(in->Rm.regData); // operand2 = UInt(R[m]) produces the same final results
		sint32 result = operand1 * operand2;
		out->Rd.regData = result;
		cpu_set_reg(core, out->Rd.regId, result);
		if (in->S != 0) {
			CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
			CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
		}
	}
	out->status = *status;
	return ret;
}
