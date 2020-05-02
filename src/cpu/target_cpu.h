#ifndef _TARGET_CPU_H_
#define _TARGET_CPU_H_

#include "std_types.h"
#include "cpu_dec/op_dec.h"
#include "object_container.h"
#include "coproc/arm_coproc.h"

#define ATHRILL_TARGET_ARCH	"ARMv7-A"
/*
 * version: X.Y.Z
 *  X: generation
 *  Y: function
 *  Z: bug fix, small changes
 */
#define ATHRILL_TARGET_VERSION "1.0.7"

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
	CpuRegId_PC,
} CpuRegIdType;
#define CpuRegId_NUM	CpuRegId_PC

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

static inline bool CurrentModeIsHyp(uint32 status)
{
	if ((status & CpuSystemLevelEncoding_Mask) == CpuSystemLevelEncoding_Hyp) {
		return TRUE;
	}
	return FALSE;
}
static inline bool CurrentModeIsUserOrSystem(uint32 status)
{
	if ((status & CpuSystemLevelEncoding_Mask) == CpuSystemLevelEncoding_User) {
		return TRUE;
	}
	else if ((status & CpuSystemLevelEncoding_Mask) == CpuSystemLevelEncoding_System) {
		return TRUE;
	}
	return FALSE;
}
static inline bool CurrentModeIsNotUser(uint32 status)
{
	//not supported: if BadMode(CPSR.M) then UNPREDICTABLE;
	if ((status & CpuSystemLevelEncoding_Mask) != CpuSystemLevelEncoding_User) {
		return TRUE;
	}
	return FALSE;
}

typedef struct {
	sint32	r[CpuRegId_NUM];
	uint32	status;
} CpuRegisterType;

typedef struct TargetCore {
	CoreIdType					core_id;
	uint32 						pc;
	CpuRegisterType 			reg[CpuSystemLevel_NUM];
	bool						is_halt;
	uint16 						*current_code;
	OpDecodedCodeType			*decoded_code;
	CoprocRegisterType			coproc;
} TargetCoreType;

static inline uint32 cpu_get_fpscr(TargetCoreType *core)
{
	return core->coproc.cp11.fpscr;
}
static inline bool IsSecure(TargetCoreType *core)
{
	//not supported
	return TRUE;
}
static inline bool HaveSecurityExt(TargetCoreType *core)
{
	//not supported
	return TRUE;
}
static inline bool HaveVirtExt(TargetCoreType *core)
{
	//not supported
	return TRUE;
}
static inline bool IsSCTLR_NMFI(TargetCoreType *core)
{
	//not supported
	return FALSE;
}
static inline bool IsSCR_AW(TargetCoreType *core)
{
	//not supported
	return TRUE;
}
static inline bool IsSCR_FW(TargetCoreType *core)
{
	//not supported
	return TRUE;
}
static inline bool IsNSACR_RFR(TargetCoreType *core)
{
	//not supported
	return TRUE;
}
static inline bool IsSCR_NS(TargetCoreType *core)
{
	//not supported
	return TRUE;
}
#define CPU_STATUS_BITPOS_N		31U
#define CPU_STATUS_BITPOS_Z		30U
#define CPU_STATUS_BITPOS_C		29U
#define CPU_STATUS_BITPOS_V		28U
#define CPU_STATUS_BITPOS_Q		27U
#define CPU_STATUS_BITPOS_J		24U
#define CPU_STATUS_BITPOS_E		 9U
#define CPU_STATUS_BITPOS_A		 8U
#define CPU_STATUS_BITPOS_I		 7U
#define CPU_STATUS_BITPOS_F		 6U
#define CPU_STATUS_BITPOS_T		 5U

#define CPU_STATUS_BIT_IS_SET(status, bitpos)	( ( (status) & (1U << (bitpos)) ) != 0 )
#define CPU_STATUS_BIT_SET(status, bitpos)	\
do {	\
	*(status) |= (1U << (bitpos));	\
} while (0)

#define CPU_STATUS_BIT_CLR(status, bitpos)	\
do {	\
	*(status) &= ~(1U << (bitpos));	\
} while (0)

#define CPU_STATUS_BIT_UPDATE(status, bitpos, flag)	\
do {	\
	if ((flag) != FALSE) {	\
		CPU_STATUS_BIT_SET(status, bitpos);	\
	}	\
	else {	\
		CPU_STATUS_BIT_CLR(status, bitpos);	\
	}	\
} while (0)

typedef enum {
	InstrSet_ARM = 0,
	InstrSet_Thumb,
	InstrSet_Jazelle, /* not supported */
	InstrSet_ThumbEE, /* not supported */
} InstrSetType;


static inline InstrSetType CurrentInstrSet(uint32 status)
{
	if (CPU_STATUS_BIT_IS_SET(status, CPU_STATUS_BITPOS_J)) {
		if (CPU_STATUS_BIT_IS_SET(status, CPU_STATUS_BITPOS_T)) {
			return InstrSet_ThumbEE;
		}
		else {
			return InstrSet_Jazelle;
		}
	}
	else {
		if (CPU_STATUS_BIT_IS_SET(status, CPU_STATUS_BITPOS_T)) {
			return InstrSet_Thumb;
		}
		else {
			return InstrSet_ARM;
		}
	}
}
static inline int SelectInstrSet(uint32 *status, InstrSetType type)
{
	InstrSetType current_type = CurrentInstrSet(*status);
	if (type == InstrSet_ARM) {
		if (current_type == InstrSet_ThumbEE) {
			//UNPREDICTABLE
			return -1;
		}
		CPU_STATUS_BIT_CLR(status, CPU_STATUS_BITPOS_J);
		CPU_STATUS_BIT_CLR(status, CPU_STATUS_BITPOS_T);
	}
	else if (type == InstrSet_Thumb) {
		CPU_STATUS_BIT_CLR(status, CPU_STATUS_BITPOS_J);
		CPU_STATUS_BIT_SET(status, CPU_STATUS_BITPOS_T);
	}
	else {
		// not supported
		return -1;
	}
	return 0;
}

static inline uint32 *cpu_get_status(const TargetCoreType *core)
{
	return &(((TargetCoreType *)core)->reg[0].status);
}

static inline uint32 cpu_get_reg(const TargetCoreType *core, uint32 regid)
{
	uint32 *status = cpu_get_status(core);
	if (regid <= CpuRegId_7) {
		return core->reg[0].r[regid];
	}
	else if (regid <= CpuRegId_12) {
		if (((*status) & CpuSystemLevelEncoding_Mask) != CpuSystemLevelEncoding_FIQ) {
			return core->reg[0].r[regid];
		}
		else {
			return core->reg[CpuSystemLevel_FIQ].r[regid];
		}
	}
	else if (regid == CpuRegId_PC) {
		if (CurrentInstrSet(*status) == InstrSet_ARM) {
			return (core->pc + 8);
		}
		else {
			return (core->pc + 4);
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
		printf("ERROR: invalid status:0x%x\n", (*cpu_get_status(core)));
		return -1;
	}
}

static inline uint32 cpu_get_reg_mode(const TargetCoreType *core, uint32 regid, uint32 mode)
{
	uint32 *status = cpu_get_status(core);
	if (regid <= CpuRegId_7) {
		return core->reg[0].r[regid];
	}
	else if (regid <= CpuRegId_12) {
		if (mode != CpuSystemLevelEncoding_FIQ) {
			return core->reg[0].r[regid];
		}
		else {
			return core->reg[CpuSystemLevel_FIQ].r[regid];
		}
	}
	else if (regid == CpuRegId_PC) {
		if (CurrentInstrSet(*status) == InstrSet_ARM) {
			return (core->pc + 8);
		}
		else {
			return (core->pc + 4);
		}
	}
	switch (mode) {
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
		printf("ERROR: invalid mode:0x%x\n", mode);
		return -1;
	}
}

static inline void cpu_set_reg_mode(TargetCoreType *core, uint32 regid, uint32 mode, uint32 data)
{
	if (regid <= CpuRegId_7) {
		core->reg[0].r[regid] = data;
		return;
	}
	else if (regid <= CpuRegId_12) {
		if (mode != CpuSystemLevelEncoding_FIQ) {
			core->reg[0].r[regid] = data;
			return;
		}
		else {
			core->reg[CpuSystemLevel_FIQ].r[regid] = data;
			return;
		}
	}
	else if (regid == CpuRegId_PC) {
		core->pc = data;
		return;
	}
	switch (mode) {
	case CpuSystemLevelEncoding_User:
	case CpuSystemLevelEncoding_System:
		core->reg[0].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_FIQ:
		core->reg[CpuSystemLevel_FIQ].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_IRQ:
		core->reg[CpuSystemLevel_IRQ].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_Supervisor:
		core->reg[CpuSystemLevel_Supervisor].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_Monitor:
		core->reg[CpuSystemLevel_Monitor].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_Abort:
		core->reg[CpuSystemLevel_Abort].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_Hyp:
		core->reg[CpuSystemLevel_Hyp].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_Undefined:
		core->reg[CpuSystemLevel_Undefined].r[regid] = data;
		break;
	default:
		//TODO ERROR
		printf("ERROR: invalid mode:0x%x\n", mode);
		break;
	}
	return;
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
static inline uint32 cpu_get_pc(const TargetCoreType *core)
{
	return core->pc;
}
static inline uint32 PCStoreValue(const TargetCoreType *core)
{
	return cpu_get_pc(core);
}

static inline void cpu_set_reg(TargetCoreType *core, uint32 regid, uint32 data)
{
	if (regid <= CpuRegId_7) {
		core->reg[0].r[regid] = data;
	}
	else if (regid <= CpuRegId_12) {
		if (((*cpu_get_status(core)) & CpuSystemLevelEncoding_Mask) != CpuSystemLevelEncoding_FIQ) {
			core->reg[0].r[regid] = data;
		}
		else {
			core->reg[CpuSystemLevel_FIQ].r[regid] = data;
		}
	}
	else if (regid == CpuRegId_PC) {
		core->pc = data;
	}
	switch ((*cpu_get_status(core)) & CpuSystemLevelEncoding_Mask) {
	case CpuSystemLevelEncoding_User:
	case CpuSystemLevelEncoding_System:
		core->reg[0].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_FIQ:
		core->reg[CpuSystemLevel_FIQ].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_IRQ:
		core->reg[CpuSystemLevel_IRQ].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_Supervisor:
		core->reg[CpuSystemLevel_Supervisor].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_Monitor:
		core->reg[CpuSystemLevel_Monitor].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_Abort:
		core->reg[CpuSystemLevel_Abort].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_Hyp:
		core->reg[CpuSystemLevel_Hyp].r[regid] = data;
		break;
	case CpuSystemLevelEncoding_Undefined:
		core->reg[CpuSystemLevel_Undefined].r[regid] = data;
		break;
	default:
		//TODO ERROR
		printf("ERROR: invalid status:0x%x\n", (*cpu_get_status(core)));
		return;
	}
}
static inline void BranchTo(uint32 *pc, uint32 address)
{
	*pc = address;
	return;
}
extern uint32 arm_exc_vector_base_addr;
static inline uint32 ExcVectorBase(void)
{
	return arm_exc_vector_base_addr;
}
extern bool TakePhysicalIRQException(uint32 coreId);


typedef enum {
	CpuMemoryAccess_NONE = 0,
	CpuMemoryAccess_READ,
	CpuMemoryAccess_WRITE,
	CpuMemoryAccess_EXEC,
} CpuMemoryAccessType;

#endif /* _TARGET_CPU_H_ */
