#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
#include "cpu_exec/op_exec_debug.h"

int arm_op_exec_arm_str_imm_a1(struct TargetCore *core)
{
	uint32 next_address = core->pc + INST_ARM_SIZE;
	arm_OpCodeFormatType_arm_str_imm_a1 *op = &core->decoded_code->code.arm_str_imm_a1;

	if ((op->P == 0) && (op->W != 0)) {
		//if P == ‘0’ && W == ‘1’ then SEE STRT;
		//TODO
		return 0;
	}
	else if ((op->Rn == 0b1101) && (op->P != 0) && (op->U == 0) && (op->W != 0) && (op->imm12 == 0b000000000100)) {
		//if Rn == ‘1101’ && P == ‘1’ && U == ‘0’ && W == ‘1’ && imm12 == ‘000000000100’ then SEE PUSH;
		//TODO
		return 0;
	}
	//t = UInt(Rt); n = UInt(Rn); imm32 = ZeroExtend(imm12, 32);
	//index = (P == ‘1’); add = (U == ‘1’); wback = (P == ‘0’) || (W == ‘1’);
	ArmStoreImmArgType arg;
	arg.index_flag = (op->P != 0);
	arg.add_flag = (op->U != 0);
	arg.wback_flag = ((op->P == 0) || (op->W != 0));

	if (arg.wback_flag && ((op->Rn == CpuRegId_PC) || (op->Rn == op->Rt))) {
		//if wback && (n == 15 || n == t) then UNPREDICTABLE;
		//TODO
		return -1;
	}

	arg.imm32 = op->imm12;
	arg.Rn = op->Rn;
	arg.Rt = op->Rt;
	arg.instrName = "STR";
	arg.cond = op->cond;
	uint32 Rn = cpu_get_reg(core, op->Rn);
	uint32 Rt = cpu_get_reg(core, op->Rt);

	uint32 *status = cpu_get_status(core);
	bool passed = ConditionPassed(arg.cond, *status);
	uint32 data = -1;
	uint32 offset_addr = (arg.add_flag) ? (Rn + arg.imm32) : (Rn - arg.imm32);
	uint32 address = (arg.index_flag) ? offset_addr : Rn;
	if (passed != FALSE) {
		Std_ReturnType err;

		if (op->Rt == CpuRegId_PC) {
			data = PCStoreValue(core);
		}
		else {
			data = Rt;
		}
		err = bus_put_data32(core->core_id, address, data);
		if (err != STD_E_OK) {
			return -1;
		}
		if (arg.wback_flag) {
			cpu_set_reg(core, op->Rn, offset_addr);
		}
	}
	DBG_ARM_STR_IMM(&arg, Rt, Rn, address, data, passed);

	core->pc = next_address;
	return 0;
}

