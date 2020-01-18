#ifndef _TIMER_H_
#define _TIMER_H_

#include "device.h"

#define ARM_REG_OSTM0_BASE  0xFCFEC000
#define ARM_REG_OSTM0CMP    (ARM_REG_OSTM0_BASE)            /* OSTM0CMP register (32bit) */
#define ARM_REG_OSTM0CNT    (ARM_REG_OSTM0_BASE + 0x04)     /* OSTM0CNT register (32bit) */
#define ARM_REG_OSTM0TE     (ARM_REG_OSTM0_BASE + 0x10)     /* OSTM0TE register (8bit) */
#define ARM_REG_OSTM0TS     (ARM_REG_OSTM0_BASE + 0x14)     /* OSTM0TS register (8bit) */
#define ARM_REG_OSTM0TT     (ARM_REG_OSTM0_BASE + 0x18)     /* OSTM0TT register (8bit) */
#define ARM_REG_OSTM0CTL    (ARM_REG_OSTM0_BASE + 0x20)     /* OSTM0CTL register (8bit) */

/* OSTMnTS register */
#define ARM_BIT_OSTMTS      0x01    /* OSTMnTS bit - 1:start count */

/* OSTMnTT register */
#define ARM_BIT_OSTMTT      0x01    /* OSTMnTT bit - 1:stop count */

/* OSTMnCTL register */
#define ARM_BIT_OSTMMD0     0x01    /* OSTMnMD0 bit - 1:enable interrupt at start */
#define ARM_BIT_OSTMMD1     0x02    /* OSTMnMD1 bit - 0:interval timer mode */


/*
 *  タイマ割込みハンドラ登録のための定数
 */
#define ARM_TIMER_INTNO_CMP_CH0     134

#define ARM_TIMER_NUM	1U
#define ARM_TIMER_CH0	0U


#endif /* _TIMER_H_ */
