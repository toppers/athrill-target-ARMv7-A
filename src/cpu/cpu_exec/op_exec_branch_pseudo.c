#include "arm_pseudo_code_func.h"
#include "cpu_ops.h"

int arm_op_exec_arm_bl_imm(struct TargetCore *core,  arm_bl_imm_input_type *in, arm_bl_imm_output_type *out)
{
    int ret = 0;
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
    		ret = BranchWritePC(core, out->next_address);
        }
		out->next_address = core->pc;
		out->result = core->pc;
	}
	out->status = *status;
	return ret;
}
