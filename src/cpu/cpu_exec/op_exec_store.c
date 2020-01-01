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
	in.size = 4U;
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


int arm_op_exec_arm_strb_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_strb_imm_a1 *op = &core->decoded_code->code.arm_strb_imm_a1;

	arm_str_imm_input_type in;
	arm_str_imm_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "STRB";

	in.cond = op->cond;
	in.imm32 = (uint32)(op->imm12);
	in.index = (op->P != 0);
	in.add = (op->U != 0);
	in.wback = ((op->P == 0) || (op->W != 0));
	in.size = 1U;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rt);

	//if P == ‘0’ && W == ‘1’ then SEE STRBT;
	if ((op->P == 0) && (op->W != 0)) {
		//TODO
		return -1;
	}
	if (op->Rt == CpuRegId_PC) {
		//UNPREDICTABLE
		return -1;
	}

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


int arm_op_exec_arm_strb_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_strb_reg_a1 *op = &core->decoded_code->code.arm_strb_reg_a1;

	arm_str_reg_input_type in;
	arm_str_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "STRB";
	in.cond = op->cond;
	in.index = (op->P != 0);
	in.add = (op->U != 0);
	in.wback = ((op->P == 0) || (op->W != 0));
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);
	in.size = 1U;
	in.sign = FALSE;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rt);
	OP_SET_REG(core, &in, op, Rm);
	//if t == 15 || m == 15 then UNPREDICTABLE;
	if ((op->Rt == CpuRegId_PC) || (op->Rm == CpuRegId_PC)) {
		return -1;
	}
	//if wback && (n == 15 || n == t) then UNPREDICTABLE;
	else if (in.wback && ((op->Rn == CpuRegId_PC) || (op->Rn == op->Rt))) {
		return -1;
	}
	//not supported following condition
	//if ArchVersion() < 6 && wback && m == n then UNPREDICTABLE;

	out.next_address = core->pc;
	out.passed = FALSE;
	
	int ret = arm_op_exec_arm_str_reg(core, &in, &out);
	DBG_ARM_STR_REG(core, &in, &out);

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

	if (in.bitcount < 2) {
		// TODO SEE STMDB / STMFD;
		printf("Unsupported code: STMDB / STMFD¥n");
		return -1;
	}
	
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
