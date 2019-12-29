#include "bus.h"
#include "arm_pseudo_code_func.h"
#include "cpu_ops.h"


int arm_op_exec_arm_str_imm(struct TargetCore *core,  arm_str_imm_input_type *in, arm_str_imm_output_type *out)
{
	int ret = 0;
	uint32 data = -1;
	uint32 *status = cpu_get_status(core);
	uint32 offset_addr = (in->add) ? (in->Rn.regData + in->imm32) : (in->Rn.regData - in->imm32);
	uint32 address = (in->index) ? offset_addr : in->Rn.regData;
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		Std_ReturnType err;

		if (in->Rt.regId == CpuRegId_PC) {
			data = PCStoreValue(core);
		}
		else {
			data = in->Rt.regData;
		}
		err = bus_put_data32(core->core_id, address, data);
		if (err != STD_E_OK) {
			ret = -1;
		}
        else if (in->wback) {
			cpu_set_reg(core, in->Rn.regId, offset_addr);
        	out->Rn.regData = offset_addr;
		}
	}
	out->status = *status;
    return ret;
}