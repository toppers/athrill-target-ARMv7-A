#include "arm_gic_register_mapping_io.h"
#include "arm_gic.h"
#include "arm_gic_register.h"

#define ARM_GIC_ADDR_ALIGN(addr, align)	( ( (addr) / (align) ) * (align) )

/*********************************************
 * Distributor
 *********************************************/
void arm_gicd_register_mapping_io_ICDDCR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//printf("DBG:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	if (io_type == DevRegisterIo_Write) {
		uint32 data;
		device_io_read32(arm_gic_region, arg->coreId, ARM_GIC_ADDR_ALIGN(arg->address, 4), &data);
		if ((data & 0x1) != 0) {
			arm_gic_distributor.enable = TRUE;
			//printf("ICDDCR:enabled\n");
		}
		else {
			arm_gic_distributor.enable = FALSE;
			//printf("ICDDCR:disabled\n");
		}
	}
	return;
}
void arm_gicd_register_mapping_io_ICDICTR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//not supported.
	//printf("%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICDIIDR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//not supported.
	//printf("%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICDISRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//not supported.
	//printf("NS:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICDISERn(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//printf("DBG:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	uint32 data;
	uint32 addr = ARM_GIC_ADDR_ALIGN(arg->address, 4);
	uint32 n = (addr - ARM_GICD_ICDISERn) / 4;
	uint32 bits;
	if (io_type == DevRegisterIo_Write) {
		device_io_read32(arm_gic_region, arg->coreId, addr, &data);
		for (bits = 0; bits < 32; bits++) {
			uint32 intno = (n * 32) + bits;
			GicInterruptType *intr = arm_gic_get_intr(intno);
			if (intr != NULL) {
				if ((data & (1 << bits)) != 0) {
					//enable
					intr->enable = TRUE;
					//printf("intno=%d enabled\n", intno);
				}
			}
		}
	}
	else { /* READ */
		data = 0;
		for (bits = 0; bits < 32; bits++) {
			uint32 intno = (n * 32) + bits;
			GicInterruptType *intr = arm_gic_get_intr(intno);
			if ((intr != NULL) && (intr->enable == TRUE)) {
				data |= (1U << bits);
			}
		}
		device_io_write32(arm_gic_region, arg->coreId, addr, data);
	}
	return;
}

void arm_gicd_register_mapping_io_ICDICERn(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//printf("DBG:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	uint32 data;
	uint32 addr = ARM_GIC_ADDR_ALIGN(arg->address, 4);
	uint32 n = (addr - ARM_GICD_ICDISERn) / 4;
	uint32 bits;
	if (io_type == DevRegisterIo_Write) {
		device_io_read32(arm_gic_region, arg->coreId, addr, &data);
		for (bits = 0; bits < 32; bits++) {
			uint32 intno = (n * 32) + bits;
			GicInterruptType *intr = arm_gic_get_intr(intno);
			if (intr != NULL) {
				if ((data & (1 << bits)) == 0) {
					//enable
					intr->enable = FALSE;
					//printf("intno=%d disabled\n", intno);
				}
			}
		}
	}
	else { /* READ */
		data = 0;
		for (bits = 0; bits < 32; bits++) {
			uint32 intno = (n * 32) + bits;
			GicInterruptType *intr = arm_gic_get_intr(intno);
			if ((intr != NULL) && (intr->enable == TRUE)) {
				data |= (1U << bits);
			}
		}
		device_io_write32(arm_gic_region, arg->coreId, addr, data);
	}
	return;
}
void arm_gicd_register_mapping_io_ICDISPRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//not support.
	//printf("NS:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICDICPRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//not support.
	//printf("NS:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICDABRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//not support.
	//printf("NS:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICDIPRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//printf("DBG:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	uint32 data;
	uint32 addr = ARM_GIC_ADDR_ALIGN(arg->address, 4);
	uint32 n = (addr - ARM_GICD_ICDIPRn) / 4;
	uint32 bytes;
	if (io_type == DevRegisterIo_Write) {
		device_io_read32(arm_gic_region, arg->coreId, addr, &data);
		for (bytes = 0; bytes < 4; bytes++) {
			uint32 intno = (n * 4) + bytes;
			GicInterruptType *intr = arm_gic_get_intr(intno);
			if (intr != NULL) {
				uint32 priority = ((data >> (8 * bytes)) & 0xFF);
				intr->priority = priority;
				//printf("intno=%d:priority=%d\n", intno, priority);
			}
		}
	}
	else { /* READ */
		//nothing to do.
	}
	return;
}
static void arm_gicd_set_connection(uint32 data, uint32 n, uint32 bytes)
{
	uint32 intno = (n * 4) + bytes;
	GicInterruptType *intr = arm_gic_get_intr(intno);
	if (intr == NULL) {
		return;
	}
	uint32 cpus = ((data >> (8 * bytes)) & 0xFF);
	uint32 coreId;
	for (coreId = 0; coreId < 8U; coreId++) {
		if ( (cpus & (1U << coreId)) != 0) {
			//printf("ON:intno=%d:cpus=0x%x cpu=%d\n", intno, cpus, coreId);
			arm_gic_intr_cpu_set_connection(intno, coreId, TRUE);
		}
		else {
			//printf("OFF:intno=%d:cpus=0x%x cpu=%d\n", intno, cpus, coreId);
			arm_gic_intr_cpu_set_connection(intno, coreId, FALSE);
		}
	}
	return;
}
void arm_gicd_register_mapping_io_ICDIPTRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//printf("DBG:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	uint32 data;
	uint32 addr = ARM_GIC_ADDR_ALIGN(arg->address, 4);
	uint32 n = (addr - ARM_GICD_ICDIPTRn) / 4;
	uint32 bytes;
	if (io_type == DevRegisterIo_Write) {
		device_io_read32(arm_gic_region, arg->coreId, addr, &data);
		for (bytes = 0; bytes < 4; bytes++) {
			arm_gicd_set_connection(data, n, bytes);
		}
	}
	else { /* READ */
		//nothing to do.
	}
	return;
}
void arm_gicd_register_mapping_io_ICDICFRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//TODO
	printf("TODO:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICDSGIR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//TODO
	printf("TODO:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}

/*********************************************
 * CPU interface
 *********************************************/
void arm_gicd_register_mapping_io_ICCICR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//TODO
	printf("TODO:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICCPMR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//TODO
	printf("TODO:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICCBPR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//TODO
	printf("TODO:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICCIAR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//TODO
	printf("TODO:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICCEOIR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//TODO
	printf("TODO:%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICCRPR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//not support.
	//printf("%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICCHPIR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//not support.
	//printf("%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICCABPR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//not support.
	//printf("%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
void arm_gicd_register_mapping_io_ICCIIDR(DevRegisterIoType io_type, DevRegisterIoArgType *arg)
{
	//not support.
	//printf("%s(%s 0x%x %u)\n", __FUNCTION__, (io_type == DevRegisterIo_Read) ? "R" : "W", arg->address, arg->size);
	return;
}
