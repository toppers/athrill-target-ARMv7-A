#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
#include "op_exec_debug.h"

int arm_op_exec_arm_ldr_imm_a1(struct TargetCore *core)
{
	uint32 next_address = core->pc + INST_ARM_SIZE;
	arm_OpCodeFormatType_arm_ldr_imm_a1 *op = &core->decoded_code->code.arm_ldr_imm_a1;

	if (op->Rn == 0b1111) {
		//if Rn == ‘1111’ then SEE LDR (literal);
		return 0;
	}
	else if ((op->P == 0) && (op->W != 0)) {
		//if P == ‘0’ && W == ‘1’ then SEE LDRT;
		//TODO
		return 0;
	}
	else if ((op->Rn == 0b1101) && (op->P == 0) && (op->U != 0) && (op->W == 0) && (op->imm12 == 0b000000000100)) {
		//if Rn == ‘1101’ && P == ‘0’ && U == ‘1’ && W == ‘0’ && imm12 == ‘000000000100’ then SEE POP;
		//TODO
		return 0;
	}
	//t = UInt(Rt); n = UInt(Rn); imm32 = ZeroExtend(imm12, 32);
	//index = (P == ‘1’); add = (U == ‘1’); wback = (P == ‘0’) || (W == ‘1’);
	ArmLoadImmArgType arg;
	arg.index_flag = (op->P != 0);
	arg.add_flag = (op->U != 0);
	arg.wback_flag = ((op->P == 0) || (op->W != 0));

	if (arg.wback_flag && (op->Rn == op->Rt)) {
		//if wback && n == t then UNPREDICTABLE;
		//TODO
		return -1;
	}

	arg.imm32 = op->imm12;
	arg.Rn = op->Rn;
	arg.Rt = op->Rt;
	arg.instrName = "LDR";
	arg.cond = op->cond;
	uint32 Rn = cpu_get_reg(core, op->Rn);
	uint32 Rt = cpu_get_reg(core, op->Rt);

	uint32 *status = cpu_get_status(core);
	bool passed = ConditionPassed(arg.cond, *status);
	uint32 data = -1;
	uint32 result = -1;
	uint32 offset_addr = (arg.add_flag) ? (Rn + arg.imm32) : (Rn - arg.imm32);
	uint32 address = (arg.index_flag) ? offset_addr : Rn;
	if (passed != FALSE) {
		Std_ReturnType err;

		err = bus_get_data32(core->core_id, address, &data);
		if (err != STD_E_OK) {
			return -1;
		}
		result = data;
		if (arg.wback_flag) {
			cpu_set_reg(core, op->Rn, offset_addr);
		}
		if (op->Rt == CpuRegId_PC) {
			if ((address & 0x3) == 0x0) {
				uint32 pc;
				DBG_ARM_LDR_IMM(&arg, Rt, Rn, address, data, result, passed);
				return LoadWritePC(&pc, status, result);
			}
			else {
				//UNPREDICTABLE
				return -1;
			}
		}
		else if (UnalignedSupport() || ((address & 0x3) == 0x00)) {
			cpu_set_reg(core, arg.Rt, result);
		}
		else {
			result = ROR(32, data, 8 * UInt((address & 0x3)) );
			cpu_set_reg(core, arg.Rt, result);
		}
	}
	DBG_ARM_LDR_IMM(&arg, Rt, Rn, address, data, result, passed);

	core->pc = next_address;
	return 0;
}

