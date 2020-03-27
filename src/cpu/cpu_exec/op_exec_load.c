#include "cpu_dec/arm_mcdecoder.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"


int arm_op_exec_arm_ldr_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldr_imm_a1 *op = &core->decoded_code->code.arm_ldr_imm_a1;

	arm_ldr_imm_input_type in;
	arm_ldr_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LDR";
	in.cond = op->cond;
	in.imm32 = (uint32)(op->imm12);
	in.index = (op->P != 0);
	in.add = (op->U != 0);
	in.wback = ((op->P == 0) || (op->W != 0));
	in.size = 4;

	if (in.wback && (op->Rn == op->Rt)) {
		//if wback && n == t then UNPREDICTABLE;
		//TODO
		return -1;
	}
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rt);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rt);
	
	int ret = arm_op_exec_arm_ldr_imm(core, &in, &out);
	DBG_ARM_LDR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldr_literal_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldr_literal_a1 *op = &core->decoded_code->code.arm_ldr_literal_a1;

	arm_ldr_literal_input_type in;
	arm_ldr_literal_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LDR";
	in.cond = op->cond;
	in.imm32 = (uint32)(op->imm12);
	in.add = (op->U != 0);

	if (op->P == op->W) {
		//if P == W then UNPREDICTABLE;
		//TODO
		return -1;
	}
	OP_SET_REG(core, &in, op, Rt);
	OP_SET_REGID(core, &in, CpuRegId_PC, PC);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rt);
	
	int ret = arm_op_exec_arm_ldr_literal(core, &in, &out);
	DBG_ARM_LDR_LITERAL(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_ldrb_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldrb_imm_a1 *op = &core->decoded_code->code.arm_ldrb_imm_a1;

	arm_ldr_imm_input_type in;
	arm_ldr_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LDRB";
	in.cond = op->cond;
	in.imm32 = (uint32)(op->imm12);
	in.index = (op->P != 0);
	in.add = (op->U != 0);
	in.wback = ((op->P == 0) || (op->W != 0));
	in.size = 1;

	if ((op->Rt == CpuRegId_PC) || (in.wback && (op->Rn == op->Rt))) {
		//if t == 15 || (wback && n == t) then UNPREDICTABLE;
		//TODO
		return -1;
	}

	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rt);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rt);
	
	int ret = arm_op_exec_arm_ldr_imm(core, &in, &out);
	DBG_ARM_LDR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_ldrh_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldrh_imm_a1 *op = &core->decoded_code->code.arm_ldrh_imm_a1;

	arm_ldrh_imm_input_type in;
	arm_ldrh_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LDRH";
	in.cond = op->cond;
	in.imm32 = (uint32)(op->imm8);
	in.index = (op->P != 0);
	in.add = (op->U != 0);
	in.wback = ((op->P == 0) || (op->W != 0));

	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rt);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rt);
	OP_SET_REG(core, &out, op, Rn);

	int ret = arm_op_exec_arm_ldrh_imm(core, &in, &out);
	DBG_ARM_LDRH_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_ldrsh_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldrsh_imm_a1 *op = &core->decoded_code->code.arm_ldrsh_imm_a1;

	arm_ldrsh_imm_input_type in;
	arm_ldrsh_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LDRSH";
	out.status = *cpu_get_status(core);

	in.instrName = "LDRH";
	in.cond = op->cond;
	in.imm32 = (uint32)(op->imm8);
	in.index = (op->P != 0);
	in.add = (op->U != 0);
	in.wback = ((op->P == 0) || (op->W != 0));

	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rt);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rt);
	OP_SET_REG(core, &out, op, Rn);

	int ret = arm_op_exec_arm_ldrsh_imm(core, &in, &out);
	DBG_ARM_LDRSH_IMM(core, &in, &out);

	core->pc = out.next_address;

	return ret;
}

int arm_op_exec_arm_ldrd_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldrd_imm_a1 *op = &core->decoded_code->code.arm_ldrd_imm_a1;

	arm_ldrd_imm_input_type in;
	arm_ldrd_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LDRD";

	in.cond = op->cond;
	in.imm32 = op->imm8;
	in.index = (op->P != 0);
	in.add = (op->U != 0);
	in.wback = ((op->P == 0) || (op->W != 0));

	//if Rt<0> == ‘1’ then UNPREDICTABLE;
	if ((op->Rt & 0x1) != 0) {
		//UNPREDICTABLE
		return -1;
	}
	//if P == ‘0’ && W == ‘1’ then UNPREDICTABLE;
	if ((op->P == 0) && (op->W != 0)) {
		//TODO
		return -1;
	}
	//if wback && (n == t || n == t2) then UNPREDICTABLE;
	if (in.wback && ((op->Rn == op->Rt) || (op->Rn == (op->Rt + 1)))) {
		//TODO
		return -1;
	}
	//if t2 == 15 then UNPREDICTABLE;
	if ((op->Rt + 1)== CpuRegId_PC) {
		//UNPREDICTABLE
		return -1;
	}
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REGID(core, &in, op->Rt, Rt1);
	OP_SET_REGID(core, &in, op->Rt + 1, Rt2);

	OP_SET_REG(core, &out, op, Rn);
	OP_SET_REGID(core, &out, op->Rt, Rt1);
	OP_SET_REGID(core, &out, op->Rt + 1, Rt2);
	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_ldrd_imm(core, &in, &out);
	DBG_ARM_LDRD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldr_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldr_reg_a1 *op = &core->decoded_code->code.arm_ldr_reg_a1;

	arm_ldr_reg_input_type in;
	arm_ldr_reg_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "LDR";
	in.cond = op->cond;
	in.index = (op->P != 0);
	in.add = (op->U != 0);
	in.wback = ((op->P == 0) || (op->W != 0));
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);

	in.size = 4U;
	in.sign = FALSE;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rt);
	OP_SET_REG(core, &in, op, Rm);
	//if wback && (n == 15 || n == t) then UNPREDICTABLE;
	if (in.wback && ((op->Rn == CpuRegId_PC) || (op->Rn == op->Rt))) {
		return -1;
	}
	//not supported following condition
	//if ArchVersion() < 6 && wback && m == n then UNPREDICTABLE;

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rt);

	int ret = arm_op_exec_arm_ldr_reg(core, &in, &out);
	DBG_ARM_LDR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_ldrb_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldrb_reg_a1 *op = &core->decoded_code->code.arm_ldrb_reg_a1;

	arm_ldr_reg_input_type in;
	arm_ldr_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LDRB";
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
	OP_SET_REG(core, &out, op, Rt);

	int ret = arm_op_exec_arm_ldr_reg(core, &in, &out);
	DBG_ARM_LDR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldrh_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldrh_reg_a1 *op = &core->decoded_code->code.arm_ldrh_reg_a1;

	arm_ldr_reg_input_type in;
	arm_ldr_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LDRH";
	in.cond = op->cond;
	in.index = (op->P != 0);
	in.add = (op->U != 0);
	in.wback = ((op->P == 0) || (op->W != 0));
	in.shift_t = SRType_LSL;
	in.shift_n = 0;

	in.size = 2U;
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
	OP_SET_REG(core, &out, op, Rt);

	int ret = arm_op_exec_arm_ldr_reg(core, &in, &out);
	DBG_ARM_LDR_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_pop_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_pop_a1 *op = &core->decoded_code->code.arm_pop_a1;

	arm_pop_input_type in;
	arm_pop_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "POP";
	in.cond = op->cond;
	in.bitcount = BitCount(op->register_list);
	in.UnalignedAllowed = FALSE;
	in.registers = op->register_list;
	OP_SET_REGID(core, &in, CpuRegId_SP, SP);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REGID(core, &out, CpuRegId_SP, SP);

	if (in.bitcount < 2) {
		// TODO SEE LDM / LDMIA / LDMFD;
		printf("Unsupported code: LDM / LDMIA / LDMFD¥n");
		return -1;
	}
	
	int ret = arm_op_exec_arm_pop(core, &in, &out);
	DBG_ARM_POP(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_pop_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_pop_a2 *op = &core->decoded_code->code.arm_pop_a2;

	arm_pop_input_type in;
	arm_pop_output_type out;
	out.status = *cpu_get_status(core);

	if (op->Rt == 13) {
		//UNPREDICTABLE
		printf("UNPREDICTABLE: arm_op_exec_arm_pop_a2");
		return -1;
	}

	in.instrName = "POP";
	in.cond = op->cond;
	in.bitcount = 1U;
	in.UnalignedAllowed = TRUE;
	in.registers = (1 << (op->Rt));
	OP_SET_REGID(core, &in, CpuRegId_SP, SP);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REGID(core, &out, CpuRegId_SP, SP);
	
	int ret = arm_op_exec_arm_pop(core, &in, &out);
	DBG_ARM_POP(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_ldm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldm_a1 *op = &core->decoded_code->code.arm_ldm_a1;

	arm_ldm_input_type in;
	arm_ldm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LDM";
	in.cond = op->cond;
	in.wback = (op->W != 0);
	in.bitcount = BitCount(op->register_list);
	in.registers = op->register_list;
	OP_SET_REG(core, &in, op, Rn);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rn);

	int ret = arm_op_exec_arm_ldm(core, &in, &out);
	DBG_ARM_LDM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_ldmib_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_ldmib_a1 *op = &core->decoded_code->code.arm_ldmib_a1;

	arm_ldmib_input_type in;
	arm_ldmib_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "LDMIB";
	in.cond = op->cond;
	in.wback = (op->W != 0);
	in.bitcount = BitCount(op->register_list);
	in.registers = op->register_list;
	OP_SET_REG(core, &in, op, Rn);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rn);

	int ret = arm_op_exec_arm_ldmib(core, &in, &out);
	DBG_ARM_LDMIB(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
