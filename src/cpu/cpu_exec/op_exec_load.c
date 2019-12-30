#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
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

	if (in.wback && (op->Rn == op->Rt)) {
		//if wback && n == t then UNPREDICTABLE;
		//TODO
		return -1;
	}
	OP_SET_REG(core, &in, op, Rn);
	OP_SET_REG(core, &in, op, Rt);

	out.next_address = core->pc;
	out.passed = FALSE;
	out.result = -1;
	
	int ret = arm_op_exec_arm_ldr_imm(core, &in, &out);
	DBG_ARM_LDR_IMM(core, &in, &out);

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

	if (ret == 0) {
		core->pc = out.next_address;
		cpu_set_reg(core, CpuRegId_SP, out.SP.regData);
	}
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