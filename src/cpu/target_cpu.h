#ifndef _TARGET_CPU_H_
#define _TARGET_CPU_H_

#include "std_types.h"
#include "cpu_dec/op_dec.h"
#include "object_container.h"

#define CPU_REG_UINT_MAX	0xFFFFFFFFULL
#define CPU_REG_PLUS_MAX	2147483647LL
#define CPU_REG_MINUS_MAX	-2147483648LL

typedef enum {
	CpuRegId_0 = 0,
	CpuRegId_1,
	CpuRegId_2,
	CpuRegId_3,
	CpuRegId_4,
	CpuRegId_5,
	CpuRegId_6,
	CpuRegId_7,
	CpuRegId_8,
	CpuRegId_9,
	CpuRegId_10,
	CpuRegId_11,
	CpuRegId_12,
	CpuRegId_SP,
	CpuRegId_LR,
	CpuRegId_NUM,
} CpuRegIdType;

typedef enum {
	CpuSystemLevel_User = 0,
	CpuSystemLevel_System,
	CpuSystemLevel_Hyp,
	CpuSystemLevel_Supervisor,
	CpuSystemLevel_Abort,
	CpuSystemLevel_Undefined,
	CpuSystemLevel_Monitor,
	CpuSystemLevel_IRQ,
	CpuSystemLevel_FIQ,
	CpuSystemLevel_NUM
} CpuSystemLevelType;

#define CpuSystemLevelEncoding_User				0b10000
#define CpuSystemLevelEncoding_FIQ				0b10001
#define CpuSystemLevelEncoding_IRQ				0b10010
#define CpuSystemLevelEncoding_Supervisor		0b10011
#define CpuSystemLevelEncoding_Monitor			0b10110
#define CpuSystemLevelEncoding_Abort			0b10111
#define CpuSystemLevelEncoding_Hyp				0b11010
#define CpuSystemLevelEncoding_Undefined		0b11011
#define CpuSystemLevelEncoding_System			0b11111
#define CpuSystemLevelEncoding_Mask				0x0000001F

typedef struct {
	sint32	r[CpuRegId_NUM];
	uint32	status;
} CpuRegisterType;

typedef struct {
	CoreIdType					core_id;
	uint32 						pc;
	CpuRegisterType 			reg[CpuSystemLevel_NUM];
	bool						is_halt;
	uint16 						*current_code;
	OpDecodedCodeType			*decoded_code;
} TargetCoreType;

static inline uint32 cpu_get_pc(const TargetCoreType *core)
{
	return core->pc;
}
static inline uint32 *cpu_get_status(const TargetCoreType *core)
{
	return &(((TargetCoreType *)core)->reg[0].status);
}

static inline uint32 cpu_get_reg(const TargetCoreType *core, uint32 regid)
{
	if (regid <= CpuRegId_7) {
		return core->reg[0].r[regid];
	}
	else if (regid <= CpuRegId_12) {
		if (((*cpu_get_status(core)) & CpuSystemLevelEncoding_Mask) != CpuSystemLevelEncoding_FIQ) {
			return core->reg[0].r[regid];
		}
		else {
			return core->reg[CpuSystemLevel_FIQ].r[regid];
		}
	}
	switch ((*cpu_get_status(core)) & CpuSystemLevelEncoding_Mask) {
	case CpuSystemLevelEncoding_User:
	case CpuSystemLevelEncoding_System:
		return core->reg[0].r[regid];
	case CpuSystemLevelEncoding_FIQ:
		return core->reg[CpuSystemLevel_FIQ].r[regid];
	case CpuSystemLevelEncoding_IRQ:
		return core->reg[CpuSystemLevel_IRQ].r[regid];
	case CpuSystemLevelEncoding_Supervisor:
		return core->reg[CpuSystemLevel_Supervisor].r[regid];
	case CpuSystemLevelEncoding_Monitor:
		return core->reg[CpuSystemLevel_Monitor].r[regid];
	case CpuSystemLevelEncoding_Abort:
		return core->reg[CpuSystemLevel_Abort].r[regid];
	case CpuSystemLevelEncoding_Hyp:
		return core->reg[CpuSystemLevel_Hyp].r[regid];
	case CpuSystemLevelEncoding_Undefined:
		return core->reg[CpuSystemLevel_Undefined].r[regid];
	default:
		//TODO ERROR
		return -1;
	}
}

static inline uint32 cpu_get_sp(const TargetCoreType *core)
{
	return cpu_get_reg(core, CpuRegId_SP);
}
static inline uint32 cpu_get_lr(const TargetCoreType *core)
{
	return cpu_get_reg(core, CpuRegId_LR);
}
static inline uint32 *cpu_get_saved_status(const TargetCoreType *core)
{
	switch ((*cpu_get_status(core)) & CpuSystemLevelEncoding_Mask) {
	case CpuSystemLevelEncoding_FIQ:
		return &(((TargetCoreType *)core)->reg[CpuSystemLevel_FIQ].status);
	case CpuSystemLevelEncoding_IRQ:
		return &(((TargetCoreType *)core)->reg[CpuSystemLevel_IRQ].status);
	case CpuSystemLevelEncoding_Supervisor:
		return &(((TargetCoreType *)core)->reg[CpuSystemLevel_Supervisor].status);
	case CpuSystemLevelEncoding_Monitor:
		return &(((TargetCoreType *)core)->reg[CpuSystemLevel_Monitor].status);
	case CpuSystemLevelEncoding_Abort:
		return &(((TargetCoreType *)core)->reg[CpuSystemLevel_Abort].status);
	case CpuSystemLevelEncoding_Hyp:
		return &(((TargetCoreType *)core)->reg[CpuSystemLevel_Hyp].status);
	case CpuSystemLevelEncoding_Undefined:
		return &(((TargetCoreType *)core)->reg[CpuSystemLevel_Undefined].status);
	case CpuSystemLevelEncoding_User:
	case CpuSystemLevelEncoding_System:
	default:
		//TODO ERROR
		return NULL;
	}
}

typedef enum {
	CpuMemoryAccess_NONE = 0,
	CpuMemoryAccess_READ,
	CpuMemoryAccess_WRITE,
	CpuMemoryAccess_EXEC,
} CpuMemoryAccessType;

#endif /* _TARGET_CPU_H_ */
