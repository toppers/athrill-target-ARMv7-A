#include "cpu_dec/arm_mcdecoder.h"
#include "arm_pseudo_code_debug.h"
#include "arm_pseudo_code_func.h"
#include <string.h>


static uint64 AdvSIMDExpandImm(uint8 op, uint8 cmode, uint32 imm8)
{
	uint8 cmode3_1 = ( (cmode & 0x0E) >> 1 );
	uint8 cmode0 = (cmode & 0x1);
	bool testimm8 = TRUE;
	uint32 tmp_data;
	union {
		uint8  array8[8];
		uint16 array16[4];
		uint32 array32[2];
		uint64 imm64;
	} data;
	int i;

	data.imm64 = -1;

	switch (cmode3_1) {
	case 0b000:
		//testimm8 = FALSE; imm64 = Replicate(Zeros(24):imm8, 2);
		testimm8 = FALSE;
		data.array32[0] = imm8;
		data.array32[1] = imm8;
		break;
	case 0b001:
		//testimm8 = TRUE; imm64 = Replicate(Zeros(16):imm8:Zeros(8), 2);
		data.array32[0] = imm8 << 8;
		data.array32[1] = imm8 << 8;
		break;
	case 0b010:
		//testimm8 = TRUE; imm64 = Replicate(Zeros(8):imm8:Zeros(16), 2);
		data.array32[0] = imm8 << 16;
		data.array32[1] = imm8 << 16;
		break;
	case 0b011:
		//testimm8 = TRUE; imm64 = Replicate(imm8:Zeros(24), 2);
		data.array32[0] = imm8 << 24;
		data.array32[1] = imm8 << 24;
		break;
	case 0b100:
		//testimm8 = FALSE; imm64 = Replicate(Zeros(8):imm8, 4);
		testimm8 = FALSE;
		data.array16[0] = (uint16)imm8;
		data.array16[1] = (uint16)imm8;
		data.array16[2] = (uint16)imm8;
		data.array16[3] = (uint16)imm8;
		break;
	case 0b101:
		//testimm8 = TRUE; imm64 = Replicate(imm8:Zeros(8), 4);
		data.array16[0] = (uint16)(imm8 << 8);
		data.array16[1] = (uint16)(imm8 << 8);
		data.array16[2] = (uint16)(imm8 << 8);
		data.array16[3] = (uint16)(imm8 << 8);
		break;
	case 0b110:
		//testimm8 = TRUE;
		//if cmode<0> == '0' then
		//imm64 = Replicate(Zeros(16):imm8:Ones(8), 2);
		//else
		//imm64 = Replicate(Zeros(8):imm8:Ones(16), 2);
		if (cmode0 == 0) {
			tmp_data = imm8 << 8;
		}
		else {
			tmp_data = imm8 << 16;
		}
		data.array32[0] = tmp_data;
		data.array32[1] = tmp_data;
		break;
	case 0b111:
		testimm8 = FALSE;
		if ((cmode0 == 0) && (op == 0)) {
			for (i = 0; i < 8; i++) {
				data.array8[i] = (uint8)imm8;
			}
		}
		else if ((cmode0 == 0) && (op == 1)) {
			//imm8a = Replicate(imm8<7>, 8); imm8b = Replicate(imm8<6>, 8);
			//imm8c = Replicate(imm8<5>, 8); imm8d = Replicate(imm8<4>, 8);
			//imm8e = Replicate(imm8<3>, 8); imm8f = Replicate(imm8<2>, 8);
			//imm8g = Replicate(imm8<1>, 8); imm8h = Replicate(imm8<0>, 8);
			//imm64 = imm8a:imm8b:imm8c:imm8d:imm8e:imm8f:imm8g:imm8h;
			for (i = 0; i < 8; i++) {
				if ((imm8 & (1U << i)) != 0) {
					data.array8[i] = 0xFF;
				}
				else {
					data.array8[i] = 0x00;
				}
			}
		}
		else if ((cmode0 == 1) && (op == 0)) {
			//             12:          11:                10-6:5-0
			//imm32 = imm8<7>:NOT(imm8<6>):Replicate(imm8<6>,5):imm8<5:0>:Zeros(19);
			tmp_data = (imm8 & 0x3F);
			if ((imm8 & (0x1 << 6)) != 0) {
				tmp_data |= (0x3F << 6);
			}
			else {
				tmp_data |= (0x1  << 11);
			}
			if ((imm8 & (0x1 << 7)) != 0) {
				tmp_data |= (0x1 << 12);
			}
			tmp_data <<= 19;
			//imm64 = Replicate(imm32, 2);
			data.array32[0] = tmp_data;
			data.array32[1] = tmp_data;
		}
		else if ((cmode0 == 1) && (op == 1)) {
			//UNDEFINED;
			printf("UNPREDICTABLE: %s %d\n", __FUNCTION__, __LINE__);
		}
		break;
	default:
		break;
	}
	if ((testimm8 == TRUE) && (imm8 == 0)) {
		//UNPREDICTABLE;
		printf("UNPREDICTABLE: %s %d\n", __FUNCTION__, __LINE__);
	}

	return data.imm64;
}


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


int arm_op_exec_arm_vsub_freg_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vsub_freg_a2 *op = &core->decoded_code->code.arm_vsub_freg_a2;

	arm_vsub_freg_input_type in;
	arm_vsub_freg_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);

	in.instrName = "VSUB";
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

	int ret = arm_op_exec_arm_vsub_freg(core, &in, &out);
	DBG_ARM_VSUB_FREG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vmul_freg_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vmul_freg_a2 *op = &core->decoded_code->code.arm_vmul_freg_a2;

	arm_vmul_freg_input_type in;
	arm_vmul_freg_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);

	in.instrName = "VMUL";
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

	int ret = arm_op_exec_arm_vmul_freg(core, &in, &out);
	DBG_ARM_VMUL_FREG(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vdiv_freg_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vdiv_freg_a2 *op = &core->decoded_code->code.arm_vdiv_freg_a2;

	arm_vdiv_freg_input_type in;
	arm_vdiv_freg_output_type out;
	out.status = *cpu_get_status(core);

	in.instrName = "VDIV";
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

	int ret = arm_op_exec_arm_vdiv_freg(core, &in, &out);
	DBG_ARM_VDIV_FREG(core, &in, &out);

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
	out.status = *fpu_get_status(&core->coproc.cp11);

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

static void VFPExpandImm(uint32 imm8, CoprocFpuRegisterType *op)
{

	//assert N IN {32,64};
	op->reg.raw64 = 0;
	if (op->size == CoprocFpuDataSize_32) {
		uint32 exp;
		uint32 frac;
		//N = 32;
		//E = 8;
		//F = N - E - 1;
		//sign = imm8<7>;
		//                 7:6-2                   :1-0
		//exp = NOT(imm8<6>):Replicate(imm8<6>,E-3):imm8<5:4>;
		exp = ( (imm8 & 0x30) >> 4 );
		if ((imm8 & (0x1 << 6)) != 0) {
			exp |= (0x1F << 2);
		}
		else {
			exp |= (0x1 << 7);
		}
		frac = (imm8 & 0xF) << 19;
		//frac = imm8<3:0>:Zeros(F-4);
		//sign:exp:frac
		op->reg.raw32 = ((exp << 23) | frac);
		if ((imm8 & (0x1 << 7)) != 0) {
			op->reg.raw32 |= (0x1 << 31);
		}
	}
	else {
		uint32 exp;
		uint32 frac[2];
		//N = 64;
		//E = 11;
		//F = 52;
		//                30:29-22                :21-20
		//                10: 9--2                : 1- 0
		//exp = NOT(imm8<6>):Replicate(imm8<6>,E-3):imm8<5:4>;
		exp = (imm8 & 0x30) >> 4;
		if ((imm8 & (0x1 << 6)) != 0) {
			exp |= (0x1F << 2);
		}
		else {
			exp |= (0x1 << 10);
		}
		//           19-16:15-0:31-0
		//           51-48:47------0
		//frac = imm8<3:0>:Zeros(F-4);
		frac[0] = 0;
		frac[1] = (imm8 & 0xF) << 16;
		//sign:exp:frac
		op->reg.raw32_array[0] = frac[0];
		op->reg.raw32_array[1] = ((exp << 20) | frac[1]);
		if ((imm8 & (0x1 << 7)) != 0) {
			op->reg.raw32_array[1] |= (0x1 << 31);
		}
	}
	return;
}

int arm_op_exec_arm_vmov_imm_a1(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vmov_imm_a1 *op = &core->decoded_code->code.arm_vmov_imm_a1;

	arm_vmov_imm_input_type in;
	arm_vmov_imm_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);
	memset((void*)&in.Vd2, 0, sizeof(PseudoCodeFloatRegisterDataType));

	in.instrName = "VMOV";
	in.cond = ConditionAlways;
	in.imm32 = 0;
	in.imm64 = AdvSIMDExpandImm(op->op, op->cmode, ( (op->i << 7) | op->imm7 ));
	in.advsimd = TRUE;
	in.single_reg = FALSE;
	op->Vd = ( (op->Vd) | (op->D << 4) );
	OP_SET_FREG(&core->coproc.cp11, TRUE, &in.Vd1, op, Vd);
	in.regs = (op->Q == 0) ? 1 : 2;
	if (in.regs == 2) {
		in.Vd2 = in.Vd1;
		in.Vd2.freg.regId += 1;
	}

	out.next_address = core->pc;
	out.passed = FALSE;
	fpu_conv_status_flag(out.status, &out.status_flag);
	out.Vd1 = in.Vd1;
	out.Vd2 = in.Vd2;

	int ret = arm_op_exec_arm_vmov_imm(core, &in, &out);
	DBG_ARM_VMOV_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}


int arm_op_exec_arm_vmov_imm_a2(struct TargetCore *core)
{
	arm_OpCodeFormatType_arm_vmov_imm_a2 *op = &core->decoded_code->code.arm_vmov_imm_a2;

	arm_vmov_imm_input_type in;
	arm_vmov_imm_output_type out;
	out.status = *fpu_get_status(&core->coproc.cp11);
	memset((void*)&in.Vd2, 0, sizeof(PseudoCodeFloatRegisterDataType));

	//TODO if FPSCR.Len != ‘000’ || FPSCR.Stride != ‘00’ then SEE “VFP vectors”;
	in.instrName = "VMOV";
	in.cond = op->cond;
	in.advsimd = FALSE;
	in.single_reg = (op->sz == 0);
	if (in.single_reg) {
		CoprocFpuRegisterType imm;
		op->Vd = ( (op->Vd << 1) | op->D );
		OP_SET_FREG(&core->coproc.cp11, FALSE, &in.Vd1, op, Vd);
		imm.size = CoprocFpuDataSize_32;
		VFPExpandImm(op->imm8, &imm);
		in.imm32 = imm.reg.raw32;
		in.imm64 = 0;
	}
	else {
		CoprocFpuRegisterType imm;
		op->Vd = ( (op->Vd) | (op->D << 4) );
		OP_SET_FREG(&core->coproc.cp11, TRUE, &in.Vd1, op, Vd);
		in.imm32 = 0;
		imm.size = CoprocFpuDataSize_64;
		VFPExpandImm(op->imm8, &imm);
		in.imm64 = imm.reg.raw64;
	}
	in.regs = 1;

	out.next_address = core->pc;
	out.passed = FALSE;
	fpu_conv_status_flag(out.status, &out.status_flag);
	out.Vd1 = in.Vd1;
	out.Vd2 = in.Vd2;

	int ret = arm_op_exec_arm_vmov_imm(core, &in, &out);
	DBG_ARM_VMOV_IMM(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
