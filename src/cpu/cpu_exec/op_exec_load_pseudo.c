#include "bus.h"
#include "arm_pseudo_code_func.h"
#include "cpu_ops.h"

static inline int mem_to_reg(TargetCoreType *core, uint32 address, uint32 size, uint8 *data, uint32 *result)
{
	int ret = 0;
	ret = MemA_R(core, address, size, data);
	if (ret != 0) {
		return -1;
	}
	switch (size) {
		case 1:
			*result = 	(uint32)data[0];
			break;
		case 2:
			*result =	((uint32)data[0] << 0U) |
						((uint32)data[1] << 8U) ;
			break;
		case 4:
			*result =	((uint32)data[0] << 0U)  |
						((uint32)data[1] << 8U)  |
						((uint32)data[2] << 16U) |
						((uint32)data[3] << 24U) ;
			break;
		default:
			ret = -1;
			break;
	}
	return ret;
}

int arm_op_exec_arm_ldr_imm(struct TargetCore *core,  arm_ldr_imm_input_type *in, arm_ldr_imm_output_type *out)
{
	int ret = 0;
	uint8 data[4];
	uint32 *status = cpu_get_status(core);
	uint32 offset_addr = (in->add) ? (in->Rn.regData + in->imm32) : (in->Rn.regData - in->imm32);
	uint32 address = (in->index) ? offset_addr : in->Rn.regData;
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		ret = mem_to_reg(core, address, in->size, data, &out->result);
		if (ret != 0) {
            goto done;
		}
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
			out->result = ROR(32, out->result, 8 * UInt((address & 0x3)) );
			cpu_set_reg(core, in->Rt.regId, out->result);
		}
	}
done:
	out->status = *status;
    return ret;
}


int arm_op_exec_arm_ldr_reg(struct TargetCore *core,  arm_ldr_reg_input_type *in, arm_ldr_reg_output_type *out)
{
	int ret = 0;
	uint8 data[4];
	uint32 *status = cpu_get_status(core);
	uint32 offset = Shift(32, in->Rm.regData, in->shift_t, in->shift_n, CPU_ISSET_CY(status));
	uint32 offset_addr = (in->add) ? (in->Rn.regData + offset) : (in->Rn.regData - offset);
	uint32 address = (in->index) ? offset_addr : in->Rn.regData;
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		ret = mem_to_reg(core, address, in->size, data, &out->result);
		if (ret != 0) {
            goto done;
		}
		cpu_set_reg(core, in->Rt.regId, out->result);
		if (in->wback) {
			cpu_set_reg(core, in->Rn.regId, offset_addr);
		}
	}
done:
	out->status = *status;
    return ret;
}

int arm_op_exec_arm_pop(struct TargetCore *core,  arm_pop_input_type *in, arm_pop_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		int i;
		uint32 address = (uint32)in->SP.regData;
		for (i = 0; i <= CpuRegId_PC; i++) {
			uint32 data;
			if ( ((1U << i) & in->registers) != 0 ) {
				//R[i] = if UnalignedAllowed then MemU[address,4] else MemA[address,4];
				if (in->UnalignedAllowed == TRUE) {
					ret = MemA_R(core, address, 4, (uint8*)&data);
				}
				else {
					ret = MemA_R(core, address, 4, (uint8*)&data);
				}
				if (ret < 0) {
					goto done;
				}
				if (i != CpuRegId_PC) {
					cpu_set_reg(core, i, data);
				}
				else {
					if (in->UnalignedAllowed == TRUE) {
						if ((address & 0x3) == 0) {
							LoadWritePC(&out->next_address, status, data);
						}
						else {
							//UNPREDICTABLE;
							ret = -1;
						}
					}
					else {
						LoadWritePC(&out->next_address, status, data);
					}
				}
				address = address + 4;
			}
		}
		if ( (in->registers & (1U << 13)) == 0 ) {
			out->SP.regData = (in->SP.regData + (4 * (in->bitcount)));		
		}
		else {
			//UNPREDICTABLE;
			ret = -1;
		}
	}
done:
	out->status = *status;
    return ret;
}