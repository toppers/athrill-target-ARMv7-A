#include "inc/timer.h"
#include "cpuemu_ops.h"
#include <stdio.h>

typedef enum {
	TIMER_STATE_STOP,
	TIMER_STATE_READY,
	TIMER_STATE_RUNNING
} TimerStateType;

typedef enum {
	TIMER_MODE_FREERUN,
	TIMER_MODE_INTERVAL
} TimerModeType;

typedef struct {
	uint16 				cnt;
	TimerStateType 		state;
	TimerModeType 		mode;
	bool				enable;
	uint16 				compare0;
	uint16 				compare0_intno;
	uint64 				start_clock;
	uint16 				fd;
} TimerDeviceType;

static Std_ReturnType timer_get_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 *data);
static Std_ReturnType timer_get_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 *data);
static Std_ReturnType timer_get_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 *data);
static Std_ReturnType timer_put_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 data);
static Std_ReturnType timer_put_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 data);
static Std_ReturnType timer_put_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 data);
static Std_ReturnType timer_get_pointer(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 **data);

MpuAddressRegionOperationType	timer_memory_operation = {
		.get_data8 		= 	timer_get_data8,
		.get_data16		=	timer_get_data16,
		.get_data32		=	timer_get_data32,

		.put_data8 		= 	timer_put_data8,
		.put_data16		=	timer_put_data16,
		.put_data32		=	timer_put_data32,

		.get_pointer	= timer_get_pointer,
};
static TimerDeviceType TimerDevice[ARM_TIMER_NUM];
static MpuAddressRegionType *timer_region;

void device_init_timer(MpuAddressRegionType *region)
{
	int i = 0;
	uint32 value = 50000;

	(void)cpuemu_get_devcfg_value("DEVICE_CONFIG_TIMER_FD", &value);
	//printf("timer value=%d\n", value);

	timer_region = region;

	for (i = 0; i < ARM_TIMER_NUM; i++) {
		TimerDevice[i].cnt = 0;
		TimerDevice[i].state = TIMER_STATE_STOP;
		TimerDevice[i].mode = TIMER_MODE_FREERUN;
		TimerDevice[i].enable = FALSE;
		TimerDevice[i].compare0 = 0;
		TimerDevice[i].fd = value;
		TimerDevice[i].start_clock = 0;
	}
	TimerDevice[ARM_TIMER_CH0].mode = TIMER_MODE_INTERVAL;
	TimerDevice[ARM_TIMER_CH0].compare0_intno = ARM_TIMER_INTNO_CMP_CH0;
	return;
}

static void device_timer_do_update(DeviceClockType *device, int ch)
{
	TimerDeviceType *timer = &(TimerDevice[ch]);

	if (timer->state == TIMER_STATE_STOP) {
		 if (timer->mode == TIMER_MODE_FREERUN) {
			if (timer->start_clock != 0U) {
				timer->start_clock += (uint64)timer->fd;
			}
		}
	}
	else if (timer->state == TIMER_STATE_READY) {
		timer->state = TIMER_STATE_RUNNING;
		if ((timer->start_clock == 0U) || (timer->mode == TIMER_MODE_INTERVAL)) {
			timer->start_clock = device->clock;
		}
		//printf("device_timer_do_update:ch=%d compare=%d\n", ch, timer->compare0);
	}

	timer->cnt = (uint16)((device->clock - timer->start_clock) / (uint64)timer->fd);
	if (timer->mode == TIMER_MODE_INTERVAL) {
		if (timer->enable == TRUE) {
			if (timer->cnt == timer->compare0) {
				//printf("raise INT:ch=%d cnt=%d\n", ch, timer->cnt);
				device_raise_int(timer->compare0_intno);
				timer->state = TIMER_STATE_READY;
			}
		}
	}
	return;
}


static void device_timer_do_calc_min_interval(DeviceClockType *device, int ch)
{
	TimerDeviceType *timer = &(TimerDevice[ch]);
	uint64 interval;

	if (device->can_skip_clock == FALSE) {
		return;
	}
	if (timer->cnt >= timer->compare0) {
		return;
	}

	interval = (timer->compare0 - timer->cnt) * timer->fd;

	if ((interval > 0) && (interval < device->min_intr_interval)) {
		device->min_intr_interval = interval;
		//printf("TIMER clock=%llu min=%llu\n", device->clock, device->min_intr_interval);
	}
	return;
}

#define INLINE_device_supply_clock_timer(dev_clock, ch)	\
do {	\
	if ((dev_clock->clock % TimerDevice[ch].fd) == 0) {	\
		device_timer_do_update(dev_clock, ch);	\
		device_timer_do_calc_min_interval(dev_clock, ch);	\
	}	\
	else {	\
		dev_clock->can_skip_clock = FALSE;	\
	}	\
} while(0)

void device_supply_clock_timer(DeviceClockType *dev_clock)
{
	INLINE_device_supply_clock_timer(dev_clock, ARM_TIMER_CH0);
	return;
}


static Std_ReturnType timer_get_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 *data)
{
	uint32 off = (addr - region->start);
	*data = *((uint8*)(&region->data[off]));
	return STD_E_OK;
}
static Std_ReturnType timer_get_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 *data)
{
	uint32 off = (addr - region->start);
	*data = *((uint16*)(&region->data[off]));
	return STD_E_SEGV;
}
static Std_ReturnType timer_get_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 *data)
{
	uint32 off = (addr - region->start);
	uint32 *datap = ((uint32*)(&region->data[off]));

	if (addr == ARM_REG_OSTM0CNT) {
		*datap = TimerDevice[ARM_TIMER_CH0].cnt;
	}
	*data = *datap;

	return STD_E_OK;
}
static Std_ReturnType timer_put_data8(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 data)
{
	uint32 off = (addr - region->start);

	//printf("timer_put_data8 core=%d addr=0x%x data=0x%x\n", core_id, addr, data);

	if (addr == ARM_REG_OSTM0CTL) {
		if ((data & ARM_BIT_OSTMMD1) == 0) {
			TimerDevice[ARM_TIMER_CH0].mode = TIMER_MODE_INTERVAL;
			//printf("timer:mode=interval\n");
		}
		if ((data & ARM_BIT_OSTMMD0) == 0) {
			TimerDevice[ARM_TIMER_CH0].enable = TRUE;
			//printf("timer:enable=true\n");
		}
		else {
			TimerDevice[ARM_TIMER_CH0].enable = FALSE;
		}
	}
	else if (addr == ARM_REG_OSTM0TS) {
		if ((data & ARM_BIT_OSTMTS) != 0) {
			//printf("timer:READY\n");
			TimerDevice[ARM_TIMER_CH0].state = TIMER_STATE_READY;
		}
	}
	else if (addr == ARM_REG_OSTM0TT) {
		if ((data & ARM_BIT_OSTMTT) != 0) {
			//printf("timer:STOP\n");
			TimerDevice[ARM_TIMER_CH0].state = TIMER_STATE_STOP;
		}
	}
	*((uint8*)(&region->data[off])) = data;


	return STD_E_OK;
}
static Std_ReturnType timer_put_data16(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint16 data)
{
	uint32 off = (addr - region->start);
	*((uint16*)(&region->data[off])) = data;
	return STD_E_OK;
}
static Std_ReturnType timer_put_data32(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint32 data)
{
	uint32 off = (addr - region->start);
	if (addr == ARM_REG_OSTM0CMP) {
		TimerDevice[ARM_TIMER_CH0].compare0 = data;
	}
	*((uint32*)(&region->data[off])) = data;
	return STD_E_OK;
}
static Std_ReturnType timer_get_pointer(MpuAddressRegionType *region, CoreIdType core_id, uint32 addr, uint8 **data)
{
	uint32 off = (addr - region->start);
	uint8 ch;
	uint32 *cntp;

	for (ch = 0; ch < ARM_TIMER_NUM; ch++) {
		if (addr == (ARM_REG_OSTM0CNT)) {
			cntp = (uint32*)&region->data[off];
			*cntp = TimerDevice[ch].cnt;
			break;
		}
	}
	*data = &region->data[off];
	return STD_E_OK;
}
