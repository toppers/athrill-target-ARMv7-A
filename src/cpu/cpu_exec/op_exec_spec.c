#include "cpu_dec/arm_mcdecoder.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"



int arm_op_exec_arm_nop_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_nop_a1 *op = &core->decoded_code->code.arm_nop_a1;

	arm_nop_input_type in;
	arm_nop_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "NOP";
	in.cond = op->cond;

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_nop(core, &in, &out);
	DBG_ARM_NOP(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_msr_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_msr_imm_a1 *op = &core->decoded_code->code.arm_msr_imm_a1;

	arm_msr_imm_input_type in;
	arm_msr_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MSR";
	in.cond = op->cond;
	in.imm32 = ARMExpandImm(op->imm12, CPU_ISSET_CY(&out.status));
	in.write_nzcvq = ((op->mask & 0x2) == 0x2);
	in.write_g = ((op->mask & 0x1) == 0x1);

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_msr_imm(core, &in, &out);
	DBG_ARM_MSR_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}



int arm_op_exec_arm_msr2_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_msr2_imm_a1 *op = &core->decoded_code->code.arm_msr2_imm_a1;

	arm_msr2_imm_input_type in;
	arm_msr2_imm_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MSR2";
	in.cond = op->cond;
	in.imm32 = ARMExpandImm(op->imm12, CPU_ISSET_CY(&out.status));
	in.mask = op->mask;
	in.write_spsr = (op->R == 1);

	out.next_address = core->pc;
	out.passed = FALSE;


	int ret = arm_op_exec_arm_msr2_imm(core, &in, &out);
	DBG_ARM_MSR2_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_msr2_reg_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_msr2_reg_a1 *op = &core->decoded_code->code.arm_msr2_reg_a1;

	arm_msr2_reg_input_type in;
	arm_msr2_reg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MSR2";
	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rn);
	in.mask = op->mask;
	in.write_spsr = (op->R == 1);

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_msr2_reg(core, &in, &out);
	DBG_ARM_MSR2_REG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_mrs_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mrs_a1 *op = &core->decoded_code->code.arm_mrs_a1;

	arm_mrs_input_type in;
	arm_mrs_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MRS";

	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rd);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rd);

	int ret = arm_op_exec_arm_mrs(core, &in, &out);
	DBG_ARM_MRS(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}



int arm_op_exec_arm_mcr_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mcr_a1 *op = &core->decoded_code->code.arm_mcr_a1;

	arm_mcr_input_type in;
	arm_mcr_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MCR";
	in.cond = op->cond;
	in.cp = op->coproc;
	in.CRn = op->CRn;
	in.op1 = op->opc1;
	in.CRm = op->CRm;
	in.op2 = op->opc2;
	OP_SET_REG(core, &in, op, Rt);

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_mcr(core, &in, &out);
	DBG_ARM_MCR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mcr2_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mcr2_a2 *op = &core->decoded_code->code.arm_mcr2_a2;

	arm_mcr_input_type in;
	arm_mcr_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MCR2";
	in.cond = ConditionAlways;
	in.cp = op->coproc;
	in.CRn = op->CRn;
	in.op1 = op->opc1;
	in.CRm = op->CRm;
	in.op2 = op->opc2;
	OP_SET_REG(core, &in, op, Rt);

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_mcr(core, &in, &out);
	DBG_ARM_MCR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mrc_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mrc_a1 *op = &core->decoded_code->code.arm_mrc_a1;

	arm_mrc_input_type in;
	arm_mrc_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MRC";
	in.cond = op->cond;
	in.cp = op->coproc;
	in.CRn = op->CRn;
	in.op1 = op->opc1;
	in.CRm = op->CRm;
	in.op2 = op->opc2;
	OP_SET_REG(core, &in, op, Rt);

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_mrc(core, &in, &out);
	DBG_ARM_MRC(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_mrc2_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_mrc2_a2 *op = &core->decoded_code->code.arm_mrc2_a2;

	arm_mrc_input_type in;
	arm_mrc_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "MRC2";
	in.cond = ConditionAlways;
	in.cp = op->coproc;
	in.CRn = op->CRn;
	in.op1 = op->opc1;
	in.CRm = op->CRm;
	in.op2 = op->opc2;
	OP_SET_REG(core, &in, op, Rt);

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_mrc(core, &in, &out);
	DBG_ARM_MRC(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_rfe_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_rfe_a1 *op = &core->decoded_code->code.arm_rfe_a1;

	arm_rfe_input_type in;
	arm_rfe_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "RFE";
	//wback = (W == '1'); increment = (U == '1'); wordhigher = (P == U);
	in.wback = (op->W == 1);
	in.increment = (op->U == 1);
	in.wordhigher = (op->P == op->U);
	OP_SET_REG(core, &in, op, Rn);

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_REG(core, &out, op, Rn);

	int ret = arm_op_exec_arm_rfe(core, &in, &out);
	DBG_ARM_RFE(core, &in, &out);
	if (ret == 0) {
		cpu_set_reg(core, out.Rn.regId, out.Rn.regData);
	}

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_wfi_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_wfi_a1 *op = &core->decoded_code->code.arm_wfi_a1;

	arm_wfi_input_type in;
	arm_wfi_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "WFI";
	in.cond = op->cond;

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_wfi(core, &in, &out);
	DBG_ARM_WFI(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
