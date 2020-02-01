#include "cpu_dec/arm_mcdecoder.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"
#include <string.h>

int arm_op_exec_arm_vadd_freg_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vadd_freg_a2 *op = &core->decoded_code->code.arm_vadd_freg_a2;

	arm_vadd_freg_input_type in;
	arm_vadd_freg_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);

	in.instrName = "VADD";
	in.cond = op->cond;

	//d = if dp_operation then UInt(D:Vd) else UInt(Vd:D);
	//n = if dp_operation then UInt(N:Vn) else UInt(Vn:N);
	//m = if dp_operation then UInt(M:Vm) else UInt(Vm:M);
	if (op->sz == 1) {
		op->Vd = ( (op->Vd) | (op->D << 4) );
		op->Vn = ( (op->Vd) | (op->N << 4) );
		op->Vm = ( (op->Vd) | (op->M << 4) );
	}
	else {
		op->Vd = ( (op->Vd << 1) | op->D );
		op->Vn = ( (op->Vn << 1) | op->N );
		op->Vm = ( (op->Vm << 1) | op->M );
	}

	OP_SET_FREG(&core->coproc.cp11, (op->sz == 1), &in.Vn, op, Vn);
	OP_SET_FREG(&core->coproc.cp11, (op->sz == 1), &in.Vd, op, Vd);
	OP_SET_FREG(&core->coproc.cp11, (op->sz == 1), &in.Vm, op, Vm);

	in.advsimd = FALSE;
	in.dp_operation = (op->sz == 1);

	out.next_address = core->pc;
	out.passed = FALSE;

	OP_SET_FREG(&core->coproc.cp11, (op->sz == 1),&out.Vd, op, Vd);

	int ret = arm_op_exec_arm_vadd_freg(core, &in, &out);
	DBG_ARM_VADD_FREG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vldr_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vldr_a1 *op = &core->decoded_code->code.arm_vldr_a1;

	arm_vldr_input_type in;
	arm_vldr_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);

	in.instrName = "VLDR";

	in.cond = op->cond;
	in.add = (op->U == 1);
	//d = UInt(D:Vd)
	op->Vd = ((op->Vd) | (op->D << 4));
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_FREG(&core->coproc.cp11, TRUE, &in.Vd, op, Vd);
	in.imm32 = ((uint32)op->imm8) << 2U;

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_FREG(&core->coproc.cp11, TRUE, &out.Vd, op, Vd);

	int ret = arm_op_exec_arm_vldr(core, &in, &out);
	DBG_ARM_VLDR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vldr_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vldr_a2 *op = &core->decoded_code->code.arm_vldr_a2;

	arm_vldr_input_type in;
	arm_vldr_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);

	in.instrName = "VLDR";

	in.cond = op->cond;
	in.add = (op->U == 1);
	//d = UInt(Vd:D)
	op->Vd = ((op->Vd << 1) | op->D);
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_FREG(&core->coproc.cp11, FALSE, &in.Vd, op, Vd);
	in.imm32 = ((uint32)op->imm8) << 2U;

	out.next_address = core->pc;
	out.passed = FALSE;
	OP_SET_FREG(&core->coproc.cp11, FALSE, &out.Vd, op, Vd);

	int ret = arm_op_exec_arm_vldr(core, &in, &out);
	DBG_ARM_VLDR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vcvt_df_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vcvt_df_a1 *op = &core->decoded_code->code.arm_vcvt_df_a1;

	arm_vcvt_df_input_type in;
	arm_vcvt_df_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);

	in.instrName = "VCVT";

	in.cond = op->cond;

	in.double_to_single = (op->sz == 1);
	//d = if double_to_single then UInt(Vd:D) else UInt(D:Vd);
	//m = if double_to_single then UInt(M:Vm) else UInt(Vm:M);
	if (in.double_to_single) {
		op->Vd = ( ((op->Vd) << 1) | op->D );
		op->Vm = ( (op->Vm) | (op->M << 4) );
		OP_SET_FREG(&core->coproc.cp11, FALSE, &in.Vd, op, Vd);
		OP_SET_FREG(&core->coproc.cp11, TRUE, &in.Vm, op, Vm);
		OP_SET_FREG(&core->coproc.cp11, FALSE, &out.Vd, op, Vd);
	}
	else {
		op->Vd = ( (op->Vd) | (op->D << 4) );
		op->Vm = ( ((op->Vm) << 1) | op->M );
		OP_SET_FREG(&core->coproc.cp11, TRUE, &in.Vd, op, Vd);
		OP_SET_FREG(&core->coproc.cp11, FALSE, &in.Vm, op, Vm);
		OP_SET_FREG(&core->coproc.cp11, TRUE, &out.Vd, op, Vd);
	}

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_vcvt_df(core, &in, &out);
	DBG_ARM_VCVT_DF(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vstr_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vstr_a1 *op = &core->decoded_code->code.arm_vstr_a1;

	arm_vstr_input_type in;
	arm_vstr_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);

	in.instrName = "VSTR";
	in.cond = op->cond;
	in.single_reg = FALSE;
	in.add = (op->U == 1);

	in.imm32 = (((uint32)op->imm8) << 2);
	OP_SET_REG(core, &in, op, Rn);
	op->Vd = ( (op->Vd) | (op->D << 4) );
	OP_SET_FREG(&core->coproc.cp11, FALSE, &in.Vd, op, Vd);
	OP_SET_FREG(&core->coproc.cp11, FALSE, &out.Vd, op, Vd);

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_vstr(core, &in, &out);
	DBG_ARM_VSTR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vstr_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vstr_a2 *op = &core->decoded_code->code.arm_vstr_a2;

	arm_vstr_input_type in;
	arm_vstr_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);

	in.instrName = "VSTR";
	in.cond = op->cond;
	in.single_reg = TRUE;
	in.add = (op->U == 1);
	in.imm32 = (((uint32)op->imm8) << 2);
	OP_SET_REG(core, &in, op, Rn);
	op->Vd = ( ((op->Vd) << 1) | op->D );
	OP_SET_FREG(&core->coproc.cp11, FALSE, &in.Vd, op, Vd);
	OP_SET_FREG(&core->coproc.cp11, FALSE, &out.Vd, op, Vd);

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_vstr(core, &in, &out);
	DBG_ARM_VSTR(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vcmp_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vcmp_a1 *op = &core->decoded_code->code.arm_vcmp_a1;

	arm_vcmp_input_type in;
	arm_vcmp_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);

	in.instrName = "VCMP";
	in.cond = op->cond;

	in.dp_operation = (op->sz == 1);
	in.quiet_nan_exc = (op->E == 1);
	in.with_zero = FALSE;
	//d = if dp_operation then UInt(D:Vd) else UInt(Vd:D);
	//m = if dp_operation then UInt(M:Vm) else UInt(Vm:M);
	if (in.dp_operation) {
		op->Vd = ( (op->Vd) | (op->D << 4) );
		op->Vm = ( (op->Vm) | (op->M << 4) );
		OP_SET_FREG(&core->coproc.cp11, TRUE, &in.Vd, op, Vd);
		OP_SET_FREG(&core->coproc.cp11, TRUE, &in.Vm, op, Vm);
	}
	else {
		op->Vd = ( ((op->Vd) << 1) | op->D );
		op->Vm = ( ((op->Vm) << 1) | op->M );
		OP_SET_FREG(&core->coproc.cp11, FALSE, &in.Vd, op, Vd);
		OP_SET_FREG(&core->coproc.cp11, FALSE, &in.Vm, op, Vm);
	}
	out.next_address = core->pc;
	out.passed = FALSE;
	fpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_vcmp(core, &in, &out);
	DBG_ARM_VCMP(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vcmp_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vcmp_a2 *op = &core->decoded_code->code.arm_vcmp_a2;

	arm_vcmp_input_type in;
	arm_vcmp_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);
	memset((void*)&in.Vm, 0, sizeof(PseudoCodeFloatRegisterDataType));

	in.instrName = "VCMP";

	in.cond = op->cond;
	in.dp_operation = (op->sz == 1);
	in.quiet_nan_exc = (op->E == 1);
	in.with_zero = TRUE;
	//d = if dp_operation then UInt(D:Vd) else UInt(Vd:D);
	if (in.dp_operation) {
		op->Vd = ( (op->Vd) | (op->D << 4) );
		OP_SET_FREG(&core->coproc.cp11, TRUE, &in.Vd, op, Vd);
	}
	else {
		op->Vd = ( ((op->Vd) << 1) | op->D );
		OP_SET_FREG(&core->coproc.cp11, FALSE, &in.Vd, op, Vd);
	}
	out.next_address = core->pc;
	out.passed = FALSE;
	fpu_conv_status_flag(out.status, &out.status_flag);

	int ret = arm_op_exec_arm_vcmp(core, &in, &out);
	DBG_ARM_VCMP(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}

int arm_op_exec_arm_vmrs_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vmrs_a1 *op = &core->decoded_code->code.arm_vmrs_a1;

	arm_vmrs_input_type in;
	arm_vmrs_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "VMRS";

	in.cond = op->cond;
	OP_SET_REG(core, &in, op, Rt);
	fpu_conv_status_flag(out.status, &out.status_flag);

	out.next_address = core->pc;
	out.passed = FALSE;

	int ret = arm_op_exec_arm_vmrs(core, &in, &out);
	DBG_ARM_VMRS(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
