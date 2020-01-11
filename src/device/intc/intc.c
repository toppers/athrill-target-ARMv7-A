#include <stdio.h>

#include "intc.h"
#include "device.h"
#include "mpu.h"
#include "arm_gic.h"
#include "arm_gic_register_mapping_io.h"

static Std_ReturnType intc_get_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 *data);
static Std_ReturnType intc_get_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 *data);
static Std_ReturnType intc_get_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 *data);
static Std_ReturnType intc_put_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 data);
static Std_ReturnType intc_put_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 data);
static Std_ReturnType intc_put_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 data);
static Std_ReturnType intc_get_pointer(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 **data);

MpuAddressRegionOperationType	intc_memory_operation = {
		.get_data8 		= 	intc_get_data8,
		.get_data16		=	intc_get_data16,
		.get_data32		=	intc_get_data32,

		.put_data8 		= 	intc_put_data8,
		.put_data16		=	intc_put_data16,
		.put_data32		=	intc_put_data32,

		.get_pointer	= 	intc_get_pointer,
};


void device_init_intc(CpuType *cpu, MpuAddressRegionType *region)
{
	//TODO

	return;
}
void device_supply_clock_intc(DeviceClockType *dev_clock)
{
	uint32 coreId;
	int core_id_num = CPU_CONFIG_GET_CORE_ID_NUM();

	dev_clock->clock++;
	for (coreId = 0; coreId < core_id_num; coreId++) {
		if (arm_gic_cpu_interface_table[coreId].current_irq != NULL) {
			dev_clock->intclock++;
			break;
		}
	}

	GIC_GenerateException();
	return;
}

int intc_raise_intr(uint32 intno)
{
	GicInterruptAssertion(intno);
	return 0;
}


static Std_ReturnType intc_get_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 *data)
{
	uint32 off = (addr - region->start);
	dev_register_mapping_read_data(core_id, ARM_GIC_REGISTER_MAPPING_TABLE_NUM, arm_gic_reigster_mapping_table, addr, 1U);
	uint8 *datap = &region->data[off + (core_id * (region->size))];
	*data = *((uint8*)(datap));
	return STD_E_OK;
}
static Std_ReturnType intc_get_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 *data)
{
	uint32 off = (addr - region->start);
	dev_register_mapping_read_data(core_id, ARM_GIC_REGISTER_MAPPING_TABLE_NUM, arm_gic_reigster_mapping_table, addr, 2U);
	uint8 *datap = &region->data[off + (core_id * (region->size))];
	*data = *((uint16*)(datap));

	return STD_E_OK;
}
static Std_ReturnType intc_get_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 *data)
{
	uint32 off = (addr - region->start);
	dev_register_mapping_read_data(core_id, ARM_GIC_REGISTER_MAPPING_TABLE_NUM, arm_gic_reigster_mapping_table, addr, 4U);
	uint8 *datap = &region->data[off + (core_id * (region->size))];

	*data = *((uint32*)(datap));
	return STD_E_OK;
}
static Std_ReturnType intc_put_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 data)
{
	uint32 off = (addr - region->start);
	uint8 *datap = &region->data[off + (core_id * (region->size))];

	*((uint8*)(datap)) = data;
	dev_register_mapping_write_data(core_id, ARM_GIC_REGISTER_MAPPING_TABLE_NUM, arm_gic_reigster_mapping_table, addr, 1U);

	return STD_E_OK;
}
static Std_ReturnType intc_put_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 data)
{
	uint32 off = (addr - region->start);
	uint8 *datap = &region->data[off + (core_id * (region->size))];


	*((uint16*)(datap)) = data;
	dev_register_mapping_write_data(core_id, ARM_GIC_REGISTER_MAPPING_TABLE_NUM, arm_gic_reigster_mapping_table, addr, 2U);
	return STD_E_OK;
}
static Std_ReturnType intc_put_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 data)
{
	uint32 off = (addr - region->start);
	uint8 *datap = &region->data[off + (core_id * (region->size))];

	*((uint32*)(datap)) = data;
	dev_register_mapping_write_data(core_id, ARM_GIC_REGISTER_MAPPING_TABLE_NUM, arm_gic_reigster_mapping_table, addr, 4U);
	return STD_E_OK;
}
static Std_ReturnType intc_get_pointer(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 **data)
{
	uint32 off = (addr - region->start);
	uint8 *datap = &region->data[off + (core_id * (region->size))];

	*data = datap;
	return STD_E_OK;
}

