#include "arm_pseudo_code_func.h"

static inline int mem_to_reg(TargetCoreType *core, uint32 address, uint32 size, uint32 *result)
{
	int ret = 0;
	uint8 data[4];
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

typedef struct {
	uint32 *status;
	bool wback;
	uint32 size;
	uint32 address;
	uint32 offset_addr;
	PseudoCodeRegisterDataType *Rn;
	PseudoCodeRegisterDataType *Rt_in;
	PseudoCodeRegisterDataType *Rt_out;
	uint32 *next_address;
} ArmOpExecArmLdrArgType;
static int arm_op_exec_arm_ldr(TargetCoreType *core, ArmOpExecArmLdrArgType *arg)
{
	int ret;
	uint32 result = -1;
	ret = mem_to_reg(core, arg->address, arg->size, &result);
	if (ret != 0) {
        return ret;
	}
	if (arg->wback) {
		cpu_set_reg(core, arg->Rn->regId, arg->offset_addr);
	}
	uint32 align_mask;
	if (arg->size == 4) {
		align_mask = 0x3;
	}
	else if (arg->size == 2) {
		align_mask = 0x1;
	}
	else {
		align_mask = 0x0;
	}
	if (arg->Rt_in->regId == CpuRegId_PC) {
		if ((arg->address & 0x3) == 0x0) {
			ret = LoadWritePC(arg->next_address, arg->status, result);
		}
		else {
			//UNPREDICTABLE
			ret = -1;
		}
	}
	else if (UnalignedSupport() || ((arg->address & align_mask) == 0x00)) {
		cpu_set_reg(core, arg->Rt_in->regId, result);
	}
	else {
		if (arg->size == 4) {
			result = ROR(32, result, 8 * UInt((arg->address & 0x3)) );
		}
		cpu_set_reg(core, arg->Rt_in->regId, result);
	}
	arg->Rt_out->regData = result;
	return ret;
}

int arm_op_exec_arm_ldr_imm(struct TargetCore *core,  arm_ldr_imm_input_type *in, arm_ldr_imm_output_type *out)
{
	int ret = 0;
	ArmOpExecArmLdrArgType arg;
	arg.Rn = &in->Rn;
	arg.Rt_in = &in->Rt;
	arg.Rt_out = &out->Rt;
	arg.wback = in->wback;
	arg.size = in->size;
	arg.status = cpu_get_status(core);
	arg.offset_addr = (in->add) ? (in->Rn.regData + in->imm32) : (in->Rn.regData - in->imm32);
	arg.address = (in->index) ? arg.offset_addr : in->Rn.regData;
	arg.next_address = &out->next_address;
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *arg.status);
	if (out->passed != FALSE) {
		ret = arm_op_exec_arm_ldr(core, &arg);
	}
	out->status = *(arg.status);
    return ret;
}

int arm_op_exec_arm_ldr_literal(struct TargetCore *core,  arm_ldr_literal_input_type *in, arm_ldr_literal_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		uint32 base = Align(in->PC.regData, 4);
		uint32 address = (in->add) ? (base + in->imm32) : (base - in->imm32);
		ret = mem_to_reg(core, address, 4, &result);
		if (ret != 0) {
			goto done;
		}
		if (in->Rt.regId == CpuRegId_PC) {
			if ((address & 0x3) == 0x0) {
				ret = LoadWritePC(&out->next_address, status, result);
			}
			else {
				//UNPREDICTABLE
				ret = -1;
			}
		}
		else if (UnalignedSupport() || ((address & 0x3) == 0x00)) {
			cpu_set_reg(core, in->Rt.regId, result);
		}
		else {
			result = ROR(32, result, 8 * UInt((address & 0x3)) );
			cpu_set_reg(core, in->Rt.regId, result);
		}
		out->Rt.regData = result;
	}
done:
	out->status = *status;
	return ret;
}
int arm_op_exec_arm_ldrd_imm(struct TargetCore *core,  arm_ldrd_imm_input_type *in, arm_ldrd_imm_output_type *out)
{
	int ret = 0;
	uint32 result;
	uint32 *status = cpu_get_status(core);
	uint32 offset_addr = (in->add) ? (in->Rn.regData + in->imm32) : (in->Rn.regData - in->imm32);
	uint32 address = (in->index) ? offset_addr : in->Rn.regData;
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		ret = mem_to_reg(core, address, 4, &result);
		if (ret != 0) {
			goto done;
		}
		ret = mem_to_reg(core, address + 4, 4, &result);
		if (ret != 0) {
			goto done;
		}
		if ((ret == 0) && in->wback) {
			cpu_set_reg(core, in->Rn.regId, offset_addr);
        	out->Rn.regData = offset_addr;
		}
	}
done:
	out->status = *status;
	return ret;
}

int arm_op_exec_arm_ldr_reg(struct TargetCore *core,  arm_ldr_reg_input_type *in, arm_ldr_reg_output_type *out)
{
	int ret = 0;
	ArmOpExecArmLdrArgType arg;
	arg.Rn = &in->Rn;
	arg.Rt_in = &in->Rt;
	arg.Rt_out = &out->Rt;
	arg.wback = in->wback;
	arg.size = in->size;
	arg.status = cpu_get_status(core);
	uint32 offset = Shift(32, in->Rm.regData, in->shift_t, in->shift_n, CPU_ISSET_CY(arg.status));
	arg.offset_addr = (in->add) ? (in->Rn.regData + offset) : (in->Rn.regData - offset);
	arg.address = (in->index) ? arg.offset_addr : in->Rn.regData;
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *arg.status);
	if (out->passed != FALSE) {
		ret = arm_op_exec_arm_ldr(core, &arg);
	}
	out->status = *arg.status;
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
			cpu_set_reg(core, out->SP.regId, out->SP.regData);
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


int arm_op_exec_arm_ldm(struct TargetCore *core,  arm_ldm_input_type *in, arm_ldm_output_type *out)
{
	int ret = 0;
	uint32 *status = cpu_get_status(core);
	out->next_address = core->pc + INST_ARM_SIZE;
	out->passed = ConditionPassed(in->cond, *status);
	if (out->passed != FALSE) {
		int i;
		uint32 data;
		uint32 address = (uint32)in->Rn.regData;
		for (i = 0; i < CpuRegId_PC; i++) {
			if ( ((1U << i) & in->registers) != 0 ) {
				ret = MemA_R(core, address, 4, (uint8*)&data);
				if (ret < 0) {
					goto done;
				}
				//R[i] = MemA[address,4]; address = address + 4;
				cpu_set_reg(core, i, data);
				address = address + 4;
			}
		}
		if ( (in->registers & (1U << CpuRegId_PC)) != 0 ) {
			//LoadWritePC(MemA[address,4]);
			ret = MemA_R(core, address, 4, (uint8*)&data);
			if (ret < 0) {
				goto done;
			}
			LoadWritePC(&out->next_address, status, data);
		}
		//if wback && registers<n> == ‘0’ then R[n] = R[n] + 4*BitCount(registers);
		//if wback && registers<n> == ‘1’ then R[n] = bits(32) UNKNOWN
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
