#include "arm_gic.h"

#define ARM_GIC_INTR_TABLE_INX_TIMER_CMP0	0
#define ARM_GIC_INTR_TABLE_INX_SERIAL_RX0	1

GicInterruptType arm_gic_interrupt_table[GIC_INTR_NUM] = {
		{		/* ARM_GIC_INTR_TABLE_INX_TIMER_CMP0 */
				.name = "timer_cmp0",
				.type = GicIntrType_SPI,
				.enable = FALSE,
				.intrno = TOPPERS_INTID_OSTM0,
				.priority = 6U,
				.dtype = GicIntrDetectType_LevelSensitive,
		},
		{		/* ARM_GIC_INTR_TABLE_INX_SERIAL_RX0 */
				.name = "serial_rx3",
				.type = GicIntrType_SPI,
				.enable = FALSE,
				.intrno = TOPPERS_INTID_SCIF_RXI_3,
				.priority = 7U,
				.dtype = GicIntrDetectType_LevelSensitive,
		},
};

GicCpuInterfaceType	arm_gic_cpu_interface_table[GIC_CPU_NUM] = {
		{
				.id = 0,
				.enable = FALSE,
				.current_priority = 0,
				.priority_mask = 0,				//TODO
				.priority_threshold = 0,		//TODO
		}
};

GicIntrCpuConnectorType	arm_gic_intr_cpu_connector_table[GIC_CONNECTOR_NUM] = {
		{
				.assertion = FALSE,
				.state = GicIntrHandlingStateType_Inactive,
				.cpu_inf = &arm_gic_cpu_interface_table[0],
				.intr = &arm_gic_interrupt_table[ARM_GIC_INTR_TABLE_INX_TIMER_CMP0],
		},
		{
				.assertion = FALSE,
				.state = GicIntrHandlingStateType_Inactive,
				.cpu_inf = &arm_gic_cpu_interface_table[0],
				.intr = &arm_gic_interrupt_table[ARM_GIC_INTR_TABLE_INX_SERIAL_RX0],
		}
};
