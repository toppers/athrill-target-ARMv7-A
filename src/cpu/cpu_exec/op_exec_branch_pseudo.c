#include "arm_pseudo_code_func.h"

int arm_op_exec_arm_bl_imm(struct TargetCore *core,  arm_bl_imm_input_type *in, arm_bl_imm_output_type *out)
{
    int ret = 0;
	uint32 result;
	out->next_address = core->pc + INST_ARM_SIZE;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, out->status);
	if (out->passed != FALSE) {
		InstrSetType type = CurrentInstrSet(out->status);
		uint32 pc = cpu_get_reg(core, CpuRegId_PC);
		if (type == InstrSet_ARM) {
            out->LR.regData = ((sint32)(((sint32)(pc)) - ((sint32)4)));
		}
		else {
            out->LR.regData = pc | 0x1;
		}
		cpu_set_reg(core, CpuRegId_LR, out->LR.regData);
		if (in->type == InstrSet_ARM) {
			out->next_address = ((sint32)Align(pc, 4)) + in->imm32;
		}
		else {
			out->next_address = ((sint32)pc) + in->imm32;
		}
		if (SelectInstrSet(status, in->type) != 0) {
			ret = -1;
		}
        else {
    		ret = BranchWritePC(&result, status, out->next_address);
			if (ret == 0) {
				out->next_address = result;
			}
        }
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_b_imm(struct TargetCore *core,  arm_b_imm_input_type *in, arm_b_imm_output_type *out)
{
    int ret = 0;
	out->next_address = core->pc + INST_ARM_SIZE;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, out->status);
	if (out->passed != FALSE) {
		out->next_address = ((sint32)in->PC.regData) + in->imm32;
    	ret = BranchWritePC(&out->next_address, status, out->next_address);
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_bx_reg(struct TargetCore *core,  arm_bx_reg_input_type *in, arm_bx_reg_output_type *out)
{
    int ret = 0;
	out->next_address = core->pc + INST_ARM_SIZE;
	uint32 *status = cpu_get_status(core);
	out->passed = ConditionPassed(in->cond, out->status);
	if (out->passed != FALSE) {
		out->next_address = ((sint32)in->Rm.regData);
    	ret = BXWritePC(&out->next_address, status, out->next_address);
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_bl_reg(struct TargetCore *core,  arm_bl_reg_input_type *in, arm_bl_reg_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		uint32 target = in->Rm.regData;
		uint32 pc = cpu_get_reg(core, CpuRegId_PC);
		if (CurrentInstrSet(*status) == InstrSet_ARM) {
			//next_instr_addr = PC - 4;
			//LR = next_instr_addr;
			out->LR.regData = pc - 4;
			cpu_set_reg(core, CpuRegId_LR, out->LR.regData);
		}
		else {
			//next_instr_addr = PC - 2;
			//LR = next_instr_addr<31:1> : ‘1’;
			out->LR.regData = pc - 2;
			cpu_set_reg(core, CpuRegId_LR, out->LR.regData);
		}
		//BXWritePC(target);
    	ret = BXWritePC(&out->next_address, status, target);
	}
	out->status = *status;
	return ret;
}
