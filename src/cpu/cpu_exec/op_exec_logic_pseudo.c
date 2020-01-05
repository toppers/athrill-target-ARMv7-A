#include "arm_pseudo_code_func.h"

int arm_op_exec_arm_mov_imm(struct TargetCore *core,  arm_mov_imm_input_type *in, arm_mov_imm_output_type *out)
{
	int ret = 0;
	uint32 result = -1;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
        result = in->imm32;
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			if (in->S != 0) {
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, out->status_flag.carry);
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
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


int arm_op_exec_arm_mov_reg(struct TargetCore *core,  arm_mov_reg_input_type *in, arm_mov_reg_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
        result = in->Rm.regData;
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			if (in->S != 0) {
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
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

int arm_op_exec_arm_mvn_reg(struct TargetCore *core,  arm_mvn_reg_input_type *in, arm_mvn_reg_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		result = Shift_C(32, in->Rm.regData, SRType_LSL, in->shift_n, out->status_flag.carry, &out->status_flag.carry);
		result = ~result;
		cpu_set_reg(core, in->Rd.regId, result);
		if (in->Rd.regId != CpuRegId_PC) {
			if (in->S != 0) {
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, out->status_flag.carry);
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
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

int arm_op_exec_arm_movt(struct TargetCore *core,  arm_movt_input_type *in, arm_movt_output_type *out)
{
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//R[d]<31:16> = imm16;
		// R[d]<15:0> unchanged
		out->Rd.regData = data32_upper_set(in->Rd.regData, in->imm16);
		cpu_set_reg(core, out->Rd.regId, out->Rd.regData);
	}
	out->status = *status;
	return 0;
}


int arm_op_exec_arm_lsl_imm(struct TargetCore *core,  arm_lsl_imm_input_type *in, arm_lsl_imm_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		result = Shift_C(32, in->Rm.regData, SRType_LSL, in->shift_n, out->status_flag.carry, &out->status_flag.carry);
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			if (in->S != 0) {
				//APSR.N = result<31>;
				//APSR.Z = IsZeroBit(result);
				//APSR.C = carry;
				// APSR.V unchanged
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, out->status_flag.carry);
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
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

int arm_op_exec_arm_lsr_imm(struct TargetCore *core,  arm_lsr_imm_input_type *in, arm_lsr_imm_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		result = Shift_C(32, in->Rm.regData, SRType_LSR, in->shift_n, out->status_flag.carry, &out->status_flag.carry);
		if (in->Rd.regId != CpuRegId_PC) {
			cpu_set_reg(core, in->Rd.regId, result);
			if (in->S != 0) {
				//APSR.N = result<31>;
				//APSR.Z = IsZeroBit(result);
				//APSR.C = carry;
				// APSR.V unchanged
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, out->status_flag.carry);
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
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
int arm_op_exec_arm_lsl_reg(struct TargetCore *core,  arm_lsl_reg_input_type *in, arm_lsl_reg_output_type *out)
{
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		uint32 shift_n = in->Rd.regData & 0xFF;
		result = Shift_C(32, in->Rm.regData, SRType_LSL, shift_n, out->status_flag.carry, &out->status_flag.carry);
		out->Rd.regData = result;
		cpu_set_reg(core, in->Rd.regId, out->Rd.regData);
		if (in->S != 0) {
			//APSR.N = result<31>;
			//APSR.Z = IsZeroBit(result);
			//APSR.C = carry;
			// APSR.V unchanged
			CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, out->status_flag.carry);
			CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (result == 0));
			CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((result & (1U << 31U)) != 0));
		}
	}
	out->status = *status;
	return 0;
}
