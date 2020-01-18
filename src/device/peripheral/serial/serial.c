#include "inc/serial.h"
#include "device.h"
#include "std_errno.h"
#include "mpu_types.h"
#include "device_ex_serial_ops.h"
#include "cpuemu_ops.h"
#include <stdio.h>

typedef struct {
	uint32					baseaddr;
	uint16 					id;
	uint16 					rx_intno;
	uint16 					tx_intno;
	uint32					flush_count;
	bool   					is_send_data;
	bool					rdf;
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
		SerialDevice[i].rx_intno = -1;
		SerialDevice[i].tx_intno = -1;
		SerialDevice[i].is_send_data = FALSE;
		SerialDevice[i].start_clock = 0;
		SerialDevice[i].flush_count = 0;
		SerialDevice[i].rdf = FALSE;
		SerialDevice[i].ops = NULL;
	}

	SerialDevice[UARTnCH3].baseaddr = UART3_BASE;
	SerialDevice[UARTnCH3].rx_intno = 231;
	SerialDevice[UARTnCH3].tx_intno = 232;
	serial_put_data16(region, 0, (UART3_BASE + REG_SCFSR), SCFSR_TDFE);

	serial_region = region;

	return;
}

static void device_do_serial(SerialDeviceType *serial)
{
	uint8 data;
	bool ret;
	if (serial->ops == NULL) {
		return;
	}
	if (serial->rdf == TRUE) {
		return;
	}
	ret = serial->ops->getchar(0, &data);
	//printf("serial:getchar()=%d\n", ret);
	if (ret == TRUE) {
		uint16 status;
		serial->rdf = TRUE;
		(void)serial_get_data16(serial_region, 0U, (serial->baseaddr + REG_SCFSR), &status);
		//printf("serial: addr=0x%x status=0x%x\n", (serial->baseaddr + REG_SCFSR), status | SCFSR_RDF);
		(void)serial_put_data16(serial_region, 0U, (serial->baseaddr + REG_SCFSR), status | SCFSR_RDF);
		(void)serial_put_data8(serial_region, 0U, (serial->baseaddr + REG_SCFRDR), data);
		device_raise_int(serial->rx_intno);
	}

	return;
}

void device_supply_clock_serial(DeviceClockType *dev_clock)
{
	SerialDevice[UARTnCH3].dev_clock = dev_clock;
	device_do_serial(&SerialDevice[UARTnCH3]);
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
	//printf("get:%c\n", *data);
	return STD_E_OK;
}
static Std_ReturnType serial_get_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 *data)
{
	uint32 off = (addr - region->start);
	*data = *((uint16*)(&region->data[off]));
	//if (addr == (UART3_BASE + REG_SCFSR)) {
	//	printf("read addr=0x%x REG_SCFSR=0x%x\n", addr, *data);
	//}
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
		uint16 *org_data = ((uint16*)(&region->data[off]));
		if ((*org_data & SCFSR_TDFE) != 0) {
			if ((data & SCFSR_TDFE) == 0) {
				data |= SCFSR_TDFE;
			}
		}
		if ((*org_data & SCFSR_RDF) != 0) {
			if ((data & SCFSR_RDF) == 0) {
				SerialDevice[UARTnCH3].rdf = FALSE;
			}
		}
		*org_data = data;
		//printf("write addr=0x%x REG_SCFSR=0x%x\n", addr, *org_data);
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

