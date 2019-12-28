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
