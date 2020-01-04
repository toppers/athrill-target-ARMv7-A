#ifndef _ARM_COPROC_H_
#define _ARM_COPROC_H_

#include "coproc/cp15/arm_coproc_cp15.h"

typedef struct {
	CoprocCP15RegisterType cp15;
} CoprocRegisterType;

struct TargetCore;

static inline bool Coproc_Accepted(struct TargetCore *core, uint32 cp, CoprocOpType *coproc_op)
{
	switch (cp) {
	case 15:
		return Coproc_Accepted_CP15(core, coproc_op);
	default:
		//not supported...
		return FALSE;
	}
}
static inline uint32 Coproc_GetOneWord(struct TargetCore *core, uint32 cp, CoprocOpType *coproc_op)
{
	uint32 value = -1;
	switch (cp) {
	case 15:
		value = Coproc_GetOneWord_CP15(core, coproc_op);
		break;
	default:
		//not supported...
		break;
	}
	return value;
}

static inline void Coproc_SendOneWord(struct TargetCore *core, uint32 regId, uint32 cp, CoprocOpType *coproc_op)
{
	switch (cp) {
	case 15:
		Coproc_SendOneWord_CP15(core, regId, coproc_op);
		break;
	default:
		//not supported...
		break;
	}
	return;
}

#endif /* _ARM_COPROC_H_ */
