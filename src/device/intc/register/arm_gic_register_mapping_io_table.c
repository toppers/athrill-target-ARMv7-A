#include "arm_gic_register.h"
#include "arm_gic_register_mapping_io.h"

DevRegisterMappingType arm_gic_reigster_mapping_table[ARM_GIC_REGISTER_MAPPING_TABLE_NUM] = {
		{	/* 0 */
				.start_address = ARM_GICD_ICDDCR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICDDCR,
		},
		{	/* 1 */
				.start_address = ARM_GICD_ICDICTR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICDICTR,
		},
		{	/* 2 */
				.start_address = ARM_GICD_ICDIIDR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICDIIDR,
		},
		{	/* 3 */
				.start_address = ARM_GICD_ICDISRn,
				.size = (ARM_GICD_ICDISERn - ARM_GICD_ICDISRn),
				.io = arm_gicd_register_mapping_io_ICDISRn,
		},
		{	/* 4 */
				.start_address = ARM_GICD_ICDISERn,
				.size = (ARM_GICD_ICDICERn - ARM_GICD_ICDISERn),
				.io = arm_gicd_register_mapping_io_ICDISERn,
		},
		{	/* 5 */
				.start_address = ARM_GICD_ICDICERn,
				.size = (ARM_GICD_ICDISPRn - ARM_GICD_ICDICERn),
				.io = arm_gicd_register_mapping_io_ICDICERn,
		},
		{	/* 6 */
				.start_address = ARM_GICD_ICDISPRn,
				.size = (ARM_GICD_ICDICPRn - ARM_GICD_ICDISPRn),
				.io = arm_gicd_register_mapping_io_ICDISPRn,
		},
		{	/* 7 */
				.start_address = ARM_GICD_ICDICPRn,
				.size = (ARM_GICD_ICDABRn - ARM_GICD_ICDICPRn),
				.io = arm_gicd_register_mapping_io_ICDICPRn,
		},
		{	/* 8 */
				.start_address = ARM_GICD_ICDABRn,
				.size = (ARM_GICD_ICDIPRn - ARM_GICD_ICDABRn),
				.io = arm_gicd_register_mapping_io_ICDABRn,
		},
		{	/* 9 */
				.start_address = ARM_GICD_ICDIPRn,
				.size = (ARM_GICD_ICDIPTRn - ARM_GICD_ICDIPRn),
				.io = arm_gicd_register_mapping_io_ICDIPRn,
		},
		{	/* 10 */
				.start_address = ARM_GICD_ICDIPTRn,
				.size = (ARM_GICD_ICDICFRn - ARM_GICD_ICDIPTRn),
				.io = arm_gicd_register_mapping_io_ICDIPTRn,
		},
		{	/* 11 */
				.start_address = ARM_GICD_ICDICFRn,
				.size = (ARM_GICD_ICDSGIR - ARM_GICD_ICDICFRn),
				.io = arm_gicd_register_mapping_io_ICDICFRn,
		},
		{	/* 12 */
				.start_address = ARM_GICD_ICDSGIR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICDSGIR,
		},
		{	/* 13 */
				.start_address = ARM_GICC_ICCICR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICCICR,
		},
		{	/* 14 */
				.start_address = ARM_GICC_ICCPMR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICCPMR,
		},
		{	/* 15 */
				.start_address = ARM_GICC_ICCBPR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICCBPR,
		},
		{	/* 16 */
				.start_address = ARM_GICC_ICCIAR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICCIAR,
		},
		{	/* 17 */
				.start_address = ARM_GICC_ICCEOIR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICCEOIR,
		},
		{	/* 18 */
				.start_address = ARM_GICC_ICCRPR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICCRPR,
		},
		{	/* 19 */
				.start_address = ARM_GICC_ICCHPIR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICCHPIR,
		},
		{	/* 20 */
				.start_address = ARM_GICC_ICCABPR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICCABPR,
		},
		{	/* 21 */
				.start_address = ARM_GICC_ICCIIDR,
				.size = 4U,
				.io = arm_gicd_register_mapping_io_ICCIIDR,
		},
};
