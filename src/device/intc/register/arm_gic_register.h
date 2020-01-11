#ifndef _ARM_GIC_REGISTER_H_
#define _ARM_GIC_REGISTER_H_

#include "device.h"

/*********************************************
 * Distributor
 *********************************************/
#define ARM_GICD_BASE           0xE8201000
#define ARM_GICD_ICDDCR         (ARM_GICD_BASE)             /* ICDDCR, 32bit */
#define ARM_GICD_ICDICTR        (ARM_GICD_BASE + 0x004)     /* ICDICTR, 32bit */
#define ARM_GICD_ICDIIDR        (ARM_GICD_BASE + 0x008)     /* ICDIIDR, 32bit */
#define ARM_GICD_ICDISRn        (ARM_GICD_BASE + 0x080)     /* ICDISR, offset 0x80 - 0xfc, 32bit */
#define ARM_GICD_ICDISERn       (ARM_GICD_BASE + 0x100)     /* ICDISER, offset 0x100-0x17c, 32bit */
#define ARM_GICD_ICDICERn       (ARM_GICD_BASE + 0x180)     /* ICDICER, offset 0x180-0x1fc, 32bit */
#define ARM_GICD_ICDISPRn       (ARM_GICD_BASE + 0x200)     /* ICDISPR, offset 0x200-0x27c, 32bit */
#define ARM_GICD_ICDICPRn       (ARM_GICD_BASE + 0x280)     /* ICDICPR, offset 0x280-0x2fc, 32bit */
#define ARM_GICD_ICDABRn        (ARM_GICD_BASE + 0x300)     /* ICDABR, offset 0x300-0x37c, 32bit */
#define ARM_GICD_ICDIPRn        (ARM_GICD_BASE + 0x400)     /* ICDIPR, offset 0x400-0x7fb, 8bit */
#define ARM_GICD_ICDIPTRn       (ARM_GICD_BASE + 0x800)     /* ICDIPTR, offset 0x800-0xbfb, 8bit */
#define ARM_GICD_ICDICFRn       (ARM_GICD_BASE + 0xC00)     /* ICDICR, offset 0xc00-0xcfc, 32bit */
#define ARM_GICD_ICDSGIR        (ARM_GICD_BASE + 0xF00)     /* ICDSGIR, 32bit */

/*********************************************
 * CPU interface
 *********************************************/
#define ARM_GICC_BASE           0xE8202000
#define ARM_GICC_ICCICR         (ARM_GICC_BASE)             /* ICCICR, 32bit */
#define ARM_GICC_ICCPMR         (ARM_GICC_BASE + 0x004)     /* ICCPMR, 32bit */
#define ARM_GICC_ICCBPR         (ARM_GICC_BASE + 0x008)     /* ICCBPR, 32bit */
#define ARM_GICC_ICCIAR         (ARM_GICC_BASE + 0x00C)     /* ICCIAR, 32bit */
#define ARM_GICC_ICCEOIR        (ARM_GICC_BASE + 0x010)     /* ICCEOIR, 32bit */
#define ARM_GICC_ICCRPR         (ARM_GICC_BASE + 0x014)     /* ICCRPR, 32bit */
#define ARM_GICC_ICCHPIR        (ARM_GICC_BASE + 0x018)     /* ICCHPIR, 32bit */
#define ARM_GICC_ICCABPR        (ARM_GICC_BASE + 0x01C)     /* ICCABPR, 32bit */
#define ARM_GICC_ICCIIDR        (ARM_GICC_BASE + 0x0FC)     /* ICCIIDR, 32bit */

#endif /* _ARM_GIC_REGISTER_H_ */
