#include "arm_pseudo_code_func.h"
#include "cpu_ops.h"

int arm_op_exec_arm_add_imm(struct TargetCore *core,  arm_add_imm_input_type *in, arm_add_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		out->result = AddWithCarry(32, in->Rn.regData, in->imm32, FALSE, &out->status_flag);
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, out->result);
			if (in->S != 0) {
				cpu_update_status_flag(status, out->result, &out->status_flag);
			}
			ret = 0;
		}
		else {
			ret = ALUWritePC(&out->next_address, status, out->result);
		}
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_adr_imm(struct TargetCore *core,  arm_adr_imm_input_type *in, arm_adr_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		uint32 pc = cpu_get_reg(core, CpuRegId_PC);
		out->result = (in->add != 0) ? Align(pc, 4) + in->imm32 : Align(pc, 4) - in->imm32;
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, out->result);
			ret = 0;
		}
		else {
			ret = ALUWritePC(&out->next_address, status, out->result);
		}
	}
	out->status = *status;
	return ret;
}
int arm_op_exec_arm_add_spimm(struct TargetCore *core,  arm_add_spimm_input_type *in, arm_add_spimm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		out->result = AddWithCarry(32, in->SP.regData, in->imm32, FALSE, &out->status_flag);
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, out->result);
			if (in->S != 0) {
				cpu_update_status_flag(status, out->result, &out->status_flag);
			}
			ret = 0;
		}
		else {
			ret = ALUWritePC(&out->next_address, status, out->result);
		}
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_subs_pclr(struct TargetCore *core,  arm_subs_pclr_input_type *in, arm_subs_pclr_output_type *out)
{
	int ret = -1;
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
					out->result = in->Rn.regData & operand2; // AND
					break;
				case 0b0001:
					out->result = in->Rn.regData ^ operand2; // EOR
					break;
				case 0b0010:
					out->result = AddWithCarry(32, in->Rn.regData, ~operand2, TRUE, NULL); // SUB
					break;
				case 0b0011:
					out->result = AddWithCarry(32, ~in->Rn.regData, operand2, TRUE, NULL); // RSB
					break;
				case 0b0100:
					out->result = AddWithCarry(32, in->Rn.regData, operand2, FALSE, NULL); // ADD
					break;
				case 0b0101:
					out->result = AddWithCarry(32, in->Rn.regData, operand2, out->status_flag.carry, NULL); // ADC
					break;
				case 0b0110:
					out->result = AddWithCarry(32, in->Rn.regData, ~operand2, out->status_flag.carry, NULL); // SBC
					break;
				case 0b0111:
					out->result = AddWithCarry(32, ~in->Rn.regData, operand2, out->status_flag.carry, NULL); // RSC
					break;
				case 0b1100:
					out->result = in->Rn.regData | operand2; // ORR
					break;
				case 0b1101:
					out->result = operand2;
				case 0b1110:
					out->result = in->Rn.regData & ~operand2; // BIC
					break;
				case 0b1111:
					out->result = ~operand2; // MVN
					break;
				default:
					break;
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
				ret = BranchWritePC(&out->next_address, status, out->result);
			}
		}
	}
	out->status = *status;
	return ret;
}