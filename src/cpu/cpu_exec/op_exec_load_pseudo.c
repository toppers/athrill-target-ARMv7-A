#include "bus.h"
#include "arm_pseudo_code_func.h"
#include "cpu_ops.h"

int arm_op_exec_arm_ldr_imm(struct TargetCore *core,  arm_ldr_imm_input_type *in, arm_ldr_imm_output_type *out)
{
	int ret = 0;
	uint32 data = -1;
	uint32 *status = cpu_get_status(core);
	uint32 offset_addr = (in->add) ? (in->Rn.regData + in->imm32) : (in->Rn.regData - in->imm32);
	uint32 address = (in->index) ? offset_addr : in->Rn.regData;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		Std_ReturnType err;

		err = bus_get_data32(core->core_id, address, &data);
		if (err != STD_E_OK) {
			ret = -1;
            goto done;
		}
		out->result = data;
		if (in->wback) {
			cpu_set_reg(core, in->Rn.regId, offset_addr);
		}
		if (in->Rt.regId == CpuRegId_PC) {
			if ((address & 0x3) == 0x0) {
				uint32 pc;
				ret = LoadWritePC(&pc, status, out->result);
                if (ret == 0) {
                    out->next_address = pc;
                }
			}
			else {
				//UNPREDICTABLE
				ret = -1;
			}
		}
		else if (UnalignedSupport() || ((address & 0x3) == 0x00)) {
			cpu_set_reg(core, in->Rt.regId, out->result);
		}
		else {
			out->result = ROR(32, data, 8 * UInt((address & 0x3)) );
			cpu_set_reg(core, in->Rt.regId, out->result);
		}
	}
done:
	out->status = *status;
    return ret;
}
