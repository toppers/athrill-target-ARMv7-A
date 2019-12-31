#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"
#include <string.h>

int arm_op_exec_arm_add_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_add_imm_a1 *op = &core->decoded_code->code.arm_add_imm_a1;

	arm_add_imm_input_type in;
	arm_add_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ADD";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REG(core, &in, op, Rn);

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = -1;
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	int ret = arm_op_exec_arm_add_imm(core, &in, &out);
	DBG_ARM_ADD_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_add_spimm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_add_spimm_a1 *op = &core->decoded_code->code.arm_add_spimm_a1;

	arm_add_spimm_input_type in;
	arm_add_spimm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ADD";
	in.cond = op->cond;
	in.S = op->S;
	OP_SET_REG(core, &in, op, Rd);
	OP_SET_REGID(core, &in, CpuRegId_SP, SP);

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = -1;
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);
	
	int ret = arm_op_exec_arm_add_spimm(core, &in, &out);
	DBG_ARM_ADD_SPIMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_adr_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_adr_a1 *op = &core->decoded_code->code.arm_adr_a1;

	arm_adr_imm_input_type in;
	arm_adr_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "ADR";
	in.cond = op->cond;
	in.add = TRUE;
	OP_SET_REG(core, &in, op, Rd);

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = -1;
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	int ret = arm_op_exec_arm_adr_imm(core, &in, &out);
	DBG_ARM_ADR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_subs_pclr_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_subs_pclr_a1 *op = &core->decoded_code->code.arm_subs_pclr_a1;

	arm_subs_pclr_input_type in;
	arm_subs_pclr_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "SUBS";
	in.cond = op->cond;
	in.opcode = op->opcode;
	in.register_form = FALSE;
	OP_SET_REG(core, &in, op, Rn);
	OP_INIT_REG(core, &in, Rm);
	in.shift_n = -1;
	in.shift_n = -1;

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = -1;
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = -1;
	
	int ret = arm_op_exec_arm_subs_pclr(core, &in, &out);
	DBG_ARM_SUBS_PCLR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_cmp_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_cmp_imm_a1 *op = &core->decoded_code->code.arm_cmp_imm_a1;

	arm_cmp_imm_input_type in;
	arm_cmp_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "CMP";

	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rn);
	cpu_conv_status_flag(out.status, &out.status_flag);
	in.imm32 = ARMExpandImm(op->imm12, out.status_flag.carry);

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = -1;
	
	int ret = arm_op_exec_arm_cmp_imm(core, &in, &out);
	DBG_ARM_CMP_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_cmp_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_cmp_reg_a1 *op = &core->decoded_code->code.arm_cmp_reg_a1;

	arm_cmp_reg_input_type in;
	arm_cmp_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "CMP";

	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rm);
	DecodeImmShift(op->type, op->imm5, &in.shift_t, &in.shift_n);

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = -1;
	cpu_conv_status_flag(out.status, &out.status_flag);
	
	int ret = arm_op_exec_arm_cmp_reg(core, &in, &out);
	DBG_ARM_CMP_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
