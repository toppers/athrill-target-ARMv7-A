#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"

int arm_op_exec_arm_str_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_str_imm_a1 *op = &core->decoded_code->code.arm_str_imm_a1;

	arm_str_imm_input_type in;
	arm_str_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "STR";
	in.cond = op->cond;
	in.imm32 = (uint32)(op->imm12);
	in.index = (op->P != 0);
	in.add = (op->U != 0);
	in.wback = ((op->P == 0) || (op->W != 0));
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rt);

	if (in.wback && ((op->Rn == CpuRegId_PC) || (op->Rn == op->Rt))) {
		//if wback && (n == 15 || n == t) then UNPREDICTABLE;
		//TODO
		return -1;
	}

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rn);
	
	int ret = arm_op_exec_arm_str_imm(core, &in, &out);
	DBG_ARM_STR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_push_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_push_a1 *op = &core->decoded_code->code.arm_push_a1;

	arm_push_input_type in;
	arm_push_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "PUSH";
	in.cond = op->cond;
	in.bitcount = BitCount(op->register_list);
	in.UnalignedAllowed = FALSE;
	in.registers = op->register_list;
	OP_SET_REGID(core, &in, CpuRegId_SP, SP);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REGID(core, &out, CpuRegId_SP, SP);
	
	int ret = arm_op_exec_arm_push(core, &in, &out);
	DBG_ARM_PUSH(core, &in, &out);

	if (ret == 0) {
		core->pc = out.next_address;
		cpu_set_reg(core, CpuRegId_SP, out.SP.regData);
	}
	return ret;
}

int arm_op_exec_arm_push_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_push_a2 *op = &core->decoded_code->code.arm_push_a2;

	arm_push_input_type in;
	arm_push_output_type out;

	if (op->Rt == 13) {
		//UNPREDICTABLE
		printf("UNPREDICTABLE: arm_op_exec_arm_push_a2¥n");
		return -1;
	}
	out.status = *cpu_get_status(core);

	in.instrName = "PUSH";
	in.cond = op->cond;
	in.bitcount = 1U;
	in.UnalignedAllowed = TRUE;
	in.registers = (1 << (op->Rt));
	OP_SET_REGID(core, &in, CpuRegId_SP, SP);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REGID(core, &out, CpuRegId_SP, SP);

	int ret = arm_op_exec_arm_push(core, &in, &out);
	DBG_ARM_PUSH(core, &in, &out);

	if (ret == 0) {
		core->pc = out.next_address;
		cpu_set_reg(core, CpuRegId_SP, out.SP.regData);
	}
	return ret;
}
