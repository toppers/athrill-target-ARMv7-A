#ifndef _ARM_GIC_H_
#define _ARM_GIC_H_

#include "std_types.h"
#include "assert.h"
#include "arm_gic_config.h"

typedef enum {
	GicIntrDetectType_LevelSensitive = 0,
	GicIntrDetectType_EdgeTriggered
} GicIntrDetectlType;

typedef enum {
	GicIntrType_PPI = 0,	// Private peripheral interrupt
	GicIntrType_SPI,		// Shared peripheral interrupt
	GicIntrType_SGI,		// Software-generated interrupt
} GicIntrType;

typedef struct {
	const char*					name;
	GicIntrType					type;
	/*
	 * Interrupt ID
	 */
	uint32						intrno;
	bool 						enable;
	uint32						priority;	//TRACE_REG_MAP: ICDIPRn
	GicIntrDetectlType			dtype;
	/*
	 * not support Security Extensions
	 */
} GicInterruptType;

extern GicInterruptType	arm_gic_interrupt_table[GIC_INTR_NUM];
static inline GicInterruptType *arm_gic_get_intr(uint32 intno)
{
	int i;
	for (i = 0; i < GIC_INTR_NUM; i++) {
		if (arm_gic_interrupt_table[i].intrno == intno) {
			return &arm_gic_interrupt_table[i];
		}
	}
	return NULL;
}


struct GicIntrCpuConnector;
typedef struct {
	uint32						id;
	bool						enable;				//TRACE_REG_MAP: ICDISERn, ICDICERn
	struct GicIntrCpuConnector	*current_irq;
	struct GicIntrCpuConnector	*next_irq;
	uint32						priority_threshold;
	uint32						priority_mask;
} GicCpuInterfaceType;

extern GicCpuInterfaceType	arm_gic_cpu_interface_table[GIC_CPU_NUM];

typedef enum {
	GicIntrHandlingStateType_Inactive 		= 0x00,
	GicIntrHandlingStateType_Pending		= 0x01,
	GicIntrHandlingStateType_Active			= 0x02,
	GicIntrHandlingStateType_ActivePending	= 0x03,
} GicIntrHandlingStateType;

typedef struct GicIntrCpuConnector {
	GicIntrHandlingStateType	state;
	bool						enable;		//TRACE_REG_MAP: ICDIPTRn
	GicInterruptType 			*intr;
	GicCpuInterfaceType			*cpu_inf;
} GicIntrCpuConnectorType;
static inline uint32 CpuInterfaceCurrentPriority(GicCpuInterfaceType *cpu_inf)
{
	ASSERT(cpu_inf->current_irq != NULL);
	return cpu_inf->current_irq->intr->priority;
}

extern GicIntrCpuConnectorType	arm_gic_intr_cpu_connector_table[GIC_CONNECTOR_NUM];

static inline void arm_gic_intr_cpu_set_connection(uint32 intno, uint32 coreId, bool add)
{
	int i;
	for (i = 0; i < GIC_CONNECTOR_NUM; i++) {
		if (arm_gic_intr_cpu_connector_table[i].cpu_inf->id != coreId) {
			continue;
		}
		if (arm_gic_intr_cpu_connector_table[i].intr->intrno != intno) {
			continue;
		}
		if (add == TRUE) {
			arm_gic_intr_cpu_connector_table[i].enable = TRUE;
		}
		else {
			arm_gic_intr_cpu_connector_table[i].enable = FALSE;
		}
	}
	return;
}

extern void CpuInterfaceIntrAck(GicCpuInterfaceType *cpu_inf);
extern void CpuInterfaceIntrEoi(GicCpuInterfaceType *cpu_inf);
extern void GicInterruptAssertion(uint32 intno);

typedef struct {
	bool						enable;	//TRACE_REG_MAP: ICDDCR-Enable
	uint32						num;
	GicIntrCpuConnectorType		*connector;
} GicDistributorType;

extern GicDistributorType arm_gic_distributor;

extern void GIC_GenerateException(void);
#endif /* _ARM_GIC_H_ */
