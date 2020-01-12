#include "arm_gic.h"
#include "target_cpu.h"

/*
 * Transition C
 *  If the interrupt is enabled and of sufficient priority to be signalled to the processor,
 *  occurs when software reads from the ICCIAR.
 */
void CpuInterfaceIntrAck(GicCpuInterfaceType *cpu_inf)
{
	if (cpu_inf->current_irq->state == GicIntrHandlingStateType_Pending) {
		/*
		 * Transition C
		 */
		cpu_inf->current_irq->state = GicIntrHandlingStateType_Active;
	}
	return;
}
void CpuInterfaceIntrEoi(GicCpuInterfaceType *cpu_inf)
{
	if (cpu_inf->current_irq == NULL) {
		return;
	}
	if (cpu_inf->current_irq->state == GicIntrHandlingStateType_Active) {
		/*
		 * Transition E1
		 */
		cpu_inf->current_irq->state = GicIntrHandlingStateType_Inactive;
		cpu_inf->current_irq = NULL;
	}
	else if (cpu_inf->current_irq->state == GicIntrHandlingStateType_ActivePending) {
		/*
		 * Transition E2
		 */
		cpu_inf->current_irq->state = GicIntrHandlingStateType_Pending;
		cpu_inf->current_irq = NULL;
	}
	return;
}
extern void GicInterruptAssertion(uint32 intno)
{
	int i;
	for (i = 0; i < arm_gic_distributor.num; i++) {
		if (arm_gic_distributor.connector[i].intr->enable == FALSE) {
			continue;
		}
		if (arm_gic_distributor.connector[i].intr->intrno != intno) {
			continue;
		}
		if (arm_gic_distributor.connector[i].state == GicIntrHandlingStateType_Inactive) {
			/*
			 * Transition A1
			 */
			arm_gic_distributor.connector[i].state = GicIntrHandlingStateType_Pending;
		}
		else if (arm_gic_distributor.connector[i].state == GicIntrHandlingStateType_Active) {
			/*
			 * Transition A2
			 */
			arm_gic_distributor.connector[i].state = GicIntrHandlingStateType_ActivePending;
		}
	}
	return;
}

static inline bool PriorityIsHigher(uint32 prio1, uint32 prio2)
{
	return prio1 < prio2;
}

static GicIntrCpuConnectorType *arm_gic_get_highest_priority_connector(uint32 coreId)
{
	int i;
	GicIntrCpuConnectorType *connector = NULL;
	for (i = 0; i < arm_gic_distributor.num; i++) {
		if (arm_gic_distributor.connector[i].enable == FALSE) {
			continue;
		}
		if (arm_gic_distributor.connector[i].cpu_inf->id != coreId) {
			continue;
		}
		if (arm_gic_distributor.connector[i].cpu_inf->enable == FALSE) {
			continue;
		}
		if (arm_gic_distributor.connector[i].intr->enable == FALSE) {
			continue;
		}
		if ((arm_gic_distributor.connector[i].state & GicIntrHandlingStateType_Pending) == 0) {
			continue;
		}
		if (connector != NULL) {
			if (PriorityIsHigher(arm_gic_distributor.connector[i].intr->priority, connector->intr->priority)) {
				connector = &arm_gic_distributor.connector[i];
			}
		}
		else {
			connector = &arm_gic_distributor.connector[i];
		}
	}
	return connector;
}

void GIC_GenerateException(void)
{
	uint32 coreId;

	GicIntrCpuConnectorType *asserted_intr_line = NULL;
	if (arm_gic_distributor.enable == FALSE) {
		return;
	}
	if (arm_gic_distributor.enable_cpuinf == FALSE) {
		return;
	}
	for (coreId = 0; coreId < GIC_CPU_NUM; coreId++) {
		asserted_intr_line = arm_gic_get_highest_priority_connector(coreId);
		if (asserted_intr_line == NULL) {
			continue;
		}
		GicCpuInterfaceType *cpu_inf = asserted_intr_line->cpu_inf;
		GicInterruptType *asserted_intr = asserted_intr_line->intr;
		if (!PriorityIsHigher(asserted_intr->priority, cpu_inf->priority_threshold)) {
			continue;
		}
		if (cpu_inf->current_irq == NULL) {
			if (TakePhysicalIRQException(coreId)) {
				cpu_inf->current_irq = asserted_intr_line;
			}
		}
		else if (PriorityIsHigher(asserted_intr->priority, (CpuInterfaceCurrentPriority(cpu_inf) & cpu_inf->priority_mask))) {
			if (TakePhysicalIRQException(coreId)) {
				cpu_inf->current_irq = asserted_intr_line;
			}
		}
	}

	return;
}
