#include "coproc/cp15/arm_coproc_cp15.h"
#include "target_cpu.h"

bool Coproc_Accepted_CP15(struct TargetCore *core, CoprocOpType *coproc_op)
{
	//not supported...
	//TODO
	uint32 status = *cpu_get_status(core);
	if (!CurrentModeIsNotUser(status)) {
		return FALSE;
	}
	if (coproc_op->CRn >= CP15CRn_Num) {
		return FALSE;
	}
	if (coproc_op->op1 >= CP15Opc1_Num) {
		return FALSE;
	}
	if (coproc_op->op2 >= CP15Opc2_Num) {
		return FALSE;
	}
	return TRUE;
}

uint32 Coproc_GetOneWord_CP15(struct TargetCore *core,  CoprocOpType *coproc_op)
{
	return core->coproc.cp15.r[coproc_op->CRn][coproc_op->op1][coproc_op->CRm][coproc_op->op2];
}

void Coproc_SendOneWord_CP15(struct TargetCore *core, uint32 regId, CoprocOpType *coproc_op)
{
	uint32 value = cpu_get_reg(core, regId);
	core->coproc.cp15.r[coproc_op->CRn][coproc_op->op1][coproc_op->CRm][coproc_op->op2] = value;
	return;
}
