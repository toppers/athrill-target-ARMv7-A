#include "inc/serial.h"
#include "device.h"
#include "std_errno.h"
#include "mpu_types.h"
#include "device_ex_serial_ops.h"
#include "cpuemu_ops.h"
#include <stdio.h>

typedef struct {
	uint32 					last_raised_counter;
	uint16 					id;
	uint16 					intno;
	uint32					flush_count;
	bool   					is_send_data;
	uint8 					send_data;
	DeviceExSerialOpType 	*ops;
	DeviceClockType 		*dev_clock;
	uint64					start_clock;
} SerialDeviceType;

static SerialDeviceType SerialDevice[UARTChannelNum];

static Std_ReturnType serial_get_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 *data);
static Std_ReturnType serial_get_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 *data);
static Std_ReturnType serial_get_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 *data);
static Std_ReturnType serial_put_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 data);
static Std_ReturnType serial_put_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 data);
static Std_ReturnType serial_put_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 data);
static Std_ReturnType serial_get_pointer(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 **data);

MpuAddressRegionOperationType	serial_memory_operation = {
		.get_data8 		= 	serial_get_data8,
		.get_data16		=	serial_get_data16,
		.get_data32		=	serial_get_data32,

		.put_data8 		= 	serial_put_data8,
		.put_data16		=	serial_put_data16,
		.put_data32		=	serial_put_data32,

		.get_pointer	= serial_get_pointer,
};


static MpuAddressRegionType *serial_region;

void device_init_serial(MpuAddressRegionType *region)
{
	int i = 0;

	for (i = 0; i < UARTChannelNum; i++) {
		SerialDevice[i].id = i;
		SerialDevice[i].intno = -1;
		SerialDevice[i].is_send_data = FALSE;
		SerialDevice[i].start_clock = 0;
		SerialDevice[i].flush_count = 0;
		SerialDevice[i].ops = NULL;
		SerialDevice[i].last_raised_counter = 0;
	}

	SerialDevice[UARTnCH3].intno = 0; //TODO
	serial_put_data16(region, 0, (UART3_BASE + REG_SCFSR), SCFSR_TDFE);

	SerialDevice[UARTnCH4].intno = 0; //TODO
	serial_region = region;

	return;
}

void device_do_serial(SerialDeviceType *serial)
{
	if (serial->ops == NULL) {
		return;
	}

	return;
}

void device_supply_clock_serial(DeviceClockType *dev_clock)
{
	SerialDevice[UARTnCH3].dev_clock = dev_clock;
}


void device_ex_serial_register_ops(uint8 channel, DeviceExSerialOpType *ops)
{
	SerialDevice[channel].ops = ops;
	return;
}


static Std_ReturnType serial_get_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 *data)
{
	uint32 off = (addr - region->start);
	*data = *((uint8*)(&region->data[off]));
	return STD_E_OK;
}
static Std_ReturnType serial_get_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 *data)
{
	uint32 off = (addr - region->start);
	*data = *((uint16*)(&region->data[off]));
	return STD_E_OK;
}
static Std_ReturnType serial_get_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 *data)
{
	uint32 off = (addr - region->start);
	*data = *((uint32*)(&region->data[off]));
	return STD_E_OK;
}
static Std_ReturnType serial_put_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 data)
{
	uint32 off = (addr - region->start);
	*((uint8*)(&region->data[off])) = data;


	if (addr == (UART3_BASE + REG_SCFTDR)) {
		(void)SerialDevice[UARTnCH3].ops->putchar(SerialDevice[UARTnCH3].id, data);
	}
	return STD_E_OK;
}
static Std_ReturnType serial_put_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 data)
{
	uint32 off = (addr - region->start);
	if (addr == (UART3_BASE + REG_SCFSR)) {
		*((uint16*)(&region->data[off])) = SCFSR_TDFE;
	}
	else {
		*((uint16*)(&region->data[off])) = data;
	}
	return STD_E_OK;
}
static Std_ReturnType serial_put_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 data)
{
	uint32 off = (addr - region->start);
	*((uint32*)(&region->data[off])) = data;
	return STD_E_OK;
}
static Std_ReturnType serial_get_pointer(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 **data)
{
	uint32 off = (addr - region->start);
	*data = &region->data[off];
	return STD_E_OK;
}

