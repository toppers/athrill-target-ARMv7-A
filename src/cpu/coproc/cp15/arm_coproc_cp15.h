#ifndef _ARM_COPROC_CP15_H_
#define _ARM_COPROC_CP15_H_

#include "coproc/arm_coproc_op.h"

typedef enum {
	CP15CRn_0 = 0,
	CP15CRn_1,
	CP15CRn_2,
	CP15CRn_3,
	CP15CRn_4,
	CP15CRn_5,
	CP15CRn_6,
	CP15CRn_7,
	CP15CRn_8,
	CP15CRn_9,
	CP15CRn_10,
	CP15CRn_11,
	CP15CRn_12,
	CP15CRn_13,
	CP15CRn_14,
	CP15CRn_15,
	CP15CRn_Num,
} CP15CRnType;

typedef enum {
	CP15Opc1_0 = 0,
	CP15Opc1_1,
	CP15Opc1_2,
	CP15Opc1_Num,
} CP15COpc1Type;

typedef enum {
	CP15CRm_0 = 0,
	CP15CRm_1,
	CP15CRm_2,
	CP15CRm_3,
	CP15CRm_Num,
} CP15CRmType;


typedef enum {
	CP15Opc2_0 = 0,
	CP15Opc2_1,
	CP15Opc2_2,
	CP15Opc2_3,
	CP15Opc2_4,
	CP15Opc2_5,
	CP15Opc2_6,
	CP15Opc2_7,
	CP15Opc2_8,
	CP15Opc2_9,
	CP15Opc2_Num,
} CP15COpc2Type;

typedef struct {
	uint32	r[CP15CRn_Num][CP15Opc1_Num][CP15CRm_Num][CP15Opc2_Num];
} CoprocCP15RegisterType;

struct TargetCore;
extern bool Coproc_Accepted_CP15(struct TargetCore *core, CoprocOpType *coproc_op);
extern uint32 Coproc_GetOneWord_CP15(struct TargetCore *core,  CoprocOpType *coproc_op);
extern void Coproc_SendOneWord_CP15(struct TargetCore *core, uint32 regId, CoprocOpType *coproc_op);

#endif /* _ARM_COPROC_CP15_H_ */
