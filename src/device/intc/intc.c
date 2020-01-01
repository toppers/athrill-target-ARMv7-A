#include <stdio.h>

#include "intc.h"
#include "device.h"
#include "mpu.h"

IntcControlType intc_control;

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
		if (intc_control.work[coreId].current_intno != -1) {
			dev_clock->intclock++;
			break;
		}
	}

	for (coreId = 0; coreId < core_id_num; coreId++) {
		//TODO intc_raise_pending_intr(&intc_control.cpu->cores[coreId].core);
	}

	return;
}

static void common_raise_intr(uint32 intno, uint32 coreId)
{
	//TODO
	return;
}

void intc_cpu_trigger_interrupt(CoreIdType core_id, int intno)
{
	uint32 triggered_coreId;

	triggered_coreId = (core_id == 0) ? 1 : 0;

	common_raise_intr(intno, triggered_coreId);
	return;
}

int intc_raise_intr(uint32 intno)
{
	uint32 coreId;

	for (coreId = 0; coreId < CPU_CONFIG_GET_CORE_ID_NUM(); coreId++) {
		common_raise_intr(intno, coreId);
	}
	return 0;
}


static Std_ReturnType intc_get_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 *data)
{
	uint32 off = (addr - region->start);
	uint8 *datap = &region->data[off + (core_id * (region->size))];
	*data = *((uint8*)(datap));
	return STD_E_OK;
}
static Std_ReturnType intc_get_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 *data)
{
	uint32 off = (addr - region->start);
	uint8 *datap = &region->data[off + (core_id * (region->size))];
	*data = *((uint16*)(datap));

	return STD_E_OK;
}
static Std_ReturnType intc_get_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 *data)
{
	uint32 off = (addr - region->start);
	uint8 *datap = &region->data[off + (core_id * (region->size))];

	*data = *((uint32*)(datap));
	return STD_E_OK;
}
static Std_ReturnType intc_put_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 data)
{
	uint32 off = (addr - region->start);
	uint8 *datap = &region->data[off + (core_id * (region->size))];

	*((uint8*)(datap)) = data;

	return STD_E_OK;
}
static Std_ReturnType intc_put_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 data)
{
	uint32 off = (addr - region->start);
	uint8 *datap = &region->data[off + (core_id * (region->size))];


	*((uint16*)(datap)) = data;
	return STD_E_OK;
}
static Std_ReturnType intc_put_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 data)
{
	uint32 off = (addr - region->start);
	uint8 *datap = &region->data[off + (core_id * (region->size))];

	*((uint32*)(datap)) = data;
	return STD_E_OK;
}
static Std_ReturnType intc_get_pointer(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 **data)
{
	uint32 off = (addr - region->start);
	uint8 *datap = &region->data[off + (core_id * (region->size))];

	*data = datap;
	return STD_E_OK;
}

