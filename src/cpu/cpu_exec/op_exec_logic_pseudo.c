#include "arm_pseudo_code_func.h"
#include "cpu_ops.h"

int arm_op_exec_arm_mov_imm(struct TargetCore *core,  arm_mov_imm_input_type *in, arm_mov_imm_output_type *out)
{
	int ret = -1;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
        out->result = in->imm32;
		cpu_set_reg(core, in->Rd.regId, out->result);
		if (in->Rd.regId != CpuRegId_PC) {
			if (in->S != 0) {
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_C, out->status_flag.carry);
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_Z, (out->result == 0));
				CPU_STATUS_BIT_UPDATE(status, CPU_STATUS_BITPOS_N, ((out->result & (1U << 31U)) != 0));
			}
            ret = 0;
		}
		else {
			uint32 pc;
			ret = ALUWritePC(&pc, status, out->result);
            if (ret == 0) {
                out->next_address = pc;
            }
		}
	}
	out->status = *status;
	return ret;
}
