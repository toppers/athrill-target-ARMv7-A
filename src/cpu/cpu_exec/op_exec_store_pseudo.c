#include "arm_pseudo_code_func.h"

static inline int reg_to_mem(TargetCoreType *core, uint32 address, uint32 size, uint32 regdata, bool aligned)
{
	struct {
		uint8 array[4];
	} data;
	switch (size) {
		case 1:
			data.array[0] = ((uint8)((regdata >> 0U) & 0xFF));
			break;
		case 2:
			data.array[0] = ((uint8)((regdata >> 0U) & 0xFF));
			data.array[1] = ((uint8)((regdata >> 8U) & 0xFF));
			break;
		case 4:
			data.array[0] = ((uint8)((regdata >>  0U) & 0xFF));
			data.array[1] = ((uint8)((regdata >>  8U) & 0xFF));
			data.array[2] = ((uint8)((regdata >> 16U) & 0xFF));
			data.array[3] = ((uint8)((regdata >> 24U) & 0xFF));
			break;
		default:
			return -1;
	}
	if (aligned) {
		return MemA_W(core, address, size, (uint8*)&data);
	}
	else {
		return MemU_W(core, address, size, (uint8*)&data);
	}
}

int arm_op_exec_arm_str_imm(struct TargetCore *core,  arm_str_imm_input_type *in, arm_str_imm_output_type *out)
{
	int ret = 0;
	uint32 regdata;
	uint32 *status = cpu_get_status(core);
	uint32 offset_addr = (in->add) ? (in->Rn.regData + in->imm32) : (in->Rn.regData - in->imm32);
	uint32 address = (in->index) ? offset_addr : in->Rn.regData;
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if (in->Rt.regId == CpuRegId_PC) {
			regdata = PCStoreValue(core);
		}
		else {
			regdata = in->Rt.regData;
		}
		ret = reg_to_mem(core, address, in->size, regdata, FALSE);
		if ((ret == 0) && in->wback) {
			cpu_set_reg(core, in->Rn.regId, offset_addr);
        	out->Rn.regData = offset_addr;
		}
		else if (ret != 0) {
			printf("ERROR:arm_op_exec_arm_str_imm():ret=%d size=%d addr=0x%x data=0x%x\n",
					ret, in->size, address, regdata);
		}
	}
	out->status = *status;
    return ret;
}

int arm_op_exec_arm_strd_imm(struct TargetCore *core,  arm_strd_imm_input_type *in, arm_strd_imm_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	uint32 offset_addr = (in->add) ? (in->Rn.regData + in->imm32) : (in->Rn.regData - in->imm32);
	uint32 address = (in->index) ? offset_addr : in->Rn.regData;
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		ret = reg_to_mem(core, address, 4, in->Rt1.regData, TRUE);
		if (ret != 0) {
			goto done;
		}
		ret = reg_to_mem(core, address + 4, 4, in->Rt2.regData, TRUE);
		if (ret != 0) {
			goto done;
		}
		if ((ret == 0) && in->wback) {
			cpu_set_reg(core, in->Rn.regId, offset_addr);
        	out->Rn.regData = offset_addr;
		}
	}
done:
	if (ret != 0) {
		printf("ERROR:arm_op_exec_arm_strd_imm():ret=%d addr=0x%x\n",
				ret, address);
	}
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_str_reg(struct TargetCore *core,  arm_str_reg_input_type *in, arm_str_reg_output_type *out)
{
	int ret = 0;
	uint32 regdata;
	uint32 *status = cpu_get_status(core);
	uint32 offset = Shift(32, in->Rm.regData, in->shift_t, in->shift_n, CPU_ISSET_CY(status));
	uint32 offset_addr = (in->add) ? (in->Rn.regData + offset) : (in->Rn.regData - offset);
	uint32 address = (in->index) ? offset_addr : in->Rn.regData;
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		if ((in->size == 4) && (in->Rt.regId == CpuRegId_PC)) {
			regdata = PCStoreValue(core);
		}
		else {
			regdata = cpu_get_reg(core, in->Rt.regId);
		}
		ret = reg_to_mem(core, address, in->size, regdata, FALSE);
		if ((ret == 0) && in->wback) {
			cpu_set_reg(core, in->Rn.regId, offset_addr);
		}
	}
	out->status = *status;
    return ret;
}


int arm_op_exec_arm_push(struct TargetCore *core,  arm_push_input_type *in, arm_push_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		int i;
		uint32 address = (uint32)in->SP.regData - (4 * (in->bitcount));
		for (i = 0; i <= CpuRegId_PC; i++) {
			if ( ((1U << i) & in->registers) != 0 ) {
				uint32 data;
				if (i != CpuRegId_PC) {
					data = cpu_get_reg(core, i);
				}
				else {
					data = PCStoreValue(core);
				}
				ret = MemA_W(core, address, 4, (uint8*)&data);
				if (ret < 0) {
					goto done;
				}
				address = address + 4;
			}
		}
		out->SP.regData = (in->SP.regData - (4 * (in->bitcount)));		
	}
done:
	out->status = *status;
    return ret;
}

int arm_op_exec_arm_stmfd(struct TargetCore *core,  arm_stmfd_input_type *in, arm_stmfd_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//address = R[n] - 4*BitCount(registers);
		uint32 address = in->Rn.regData - (4 * in->bitcount);
		int i;
		for (i = 0; i <= CpuRegId_PC; i++) {
			if ( ((1U << i) & in->registers) != 0 ) {
				uint32 data;
				if (i != CpuRegId_PC) {
					data = cpu_get_reg(core, i);
				}
				else {
					data = PCStoreValue(core);
				}
				ret = MemA_W(core, address, 4, (uint8*)&data);
				if (ret < 0) {
					goto done;
				}
				address = address + 4;
			}
		}
		if (in->wback) {
			//if wback then R[n] = R[n] - 4*BitCount(registers);
			out->Rn.regData = (in->Rn.regData - (4 * (in->bitcount)));
		}
	}
done:
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_stmib(struct TargetCore *core,  arm_stmib_input_type *in, arm_stmib_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		//address = R[n] + 4;
		uint32 address = in->Rn.regData + 4;
		int i;
		for (i = 0; i <= CpuRegId_PC; i++) {
			if ( ((1U << i) & in->registers) != 0 ) {
				uint32 data;
				if (i != CpuRegId_PC) {
					data = cpu_get_reg(core, i);
				}
				else {
					data = PCStoreValue(core);
				}
				ret = MemA_W(core, address, 4, (uint8*)&data);
				if (ret < 0) {
					goto done;
				}
				address = address + 4;
			}
		}
		if (in->wback) {
			//if wback then R[n] = R[n] + 4*BitCount(registers);
			out->Rn.regData = (in->Rn.regData + (4 * (in->bitcount)));
		}
	}
done:
	out->status = *status;
	return ret;
}
int arm_op_exec_arm_stm(struct TargetCore *core,  arm_stm_input_type *in, arm_stm_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		int i;
		uint32 address = (uint32)in->Rn.regData;
		uint32 data;
		for (i = 0; i < CpuRegId_PC; i++) {
			data = cpu_get_reg(core, i);
			if ( ((1U << i) & in->registers) != 0 ) {
				//MemA[address,4] = R[i];
				ret = MemA_W(core, address, 4, (uint8*)&data);
				if (ret < 0) {
					goto done;
				}
				address = address + 4;
			}
		}
		if ( (in->registers & (1U << CpuRegId_PC)) != 0 ) {
			//MemA[address,4] = PCStoreValue();
			data = PCStoreValue(core);
			ret = MemA_W(core, address, 4, (uint8*)&data);
			if (ret < 0) {
				goto done;
			}
		}
		//if wback then R[n] = R[n] + 4*BitCount(registers);
		if (in->wback && ((in->registers & (1U << in->Rn.regId)) != 0 )) {
			//R[n] = R[n] + 4*BitCount(registers);
			out->Rn.regData += 4 * in->bitcount;
			cpu_set_reg(core, out->Rn.regId, out->Rn.regData);
		}
	}
done:
	out->status = *status;
    return ret;
}

int arm_op_exec_arm_srs(struct TargetCore *core,  arm_srs_input_type *in, arm_srs_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = TRUE;
	if (out->passed != FALSE) {
		//base = Rmode[13,mode];
		uint32 base = in->SP.regData;
		//address = if increment then base else base-8;
		uint32 address = (in->increment) ? base : base - 8;
		//if wordhigher then address = address+4;
		if (in->wordhigher) {
			address += 4;
		}
		//MemA[address,4] = LR;
		ret = MemA_W(core, address, 4, (uint8*)&in->LR.regData);
		if (ret != 0) {
			goto done;
		}

		//MemA[address+4,4] = SPSR[];
		ret = MemA_W(core, address + 4, 4, (uint8*)&in->SPSR);
		if (ret != 0) {
			goto done;
		}
		//if wback then Rmode[13,mode] = if increment then base+8 else base-8;
		if (in->wback) {
			uint32 data;
			if (in->increment) {
				data = base + 8;
			}
			else {
				data = base - 8;
			}
			cpu_set_reg_mode(core, CpuRegId_SP, in->mode, data);
		}
	}
done:
	out->status = *status;
	return ret;
}

