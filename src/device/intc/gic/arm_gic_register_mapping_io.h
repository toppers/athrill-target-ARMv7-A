#ifndef _ARM_GIC_REGISTER_MAPPING_IO_H_
#define _ARM_GIC_REGISTER_MAPPING_IO_H_

#include "device.h"

/*********************************************
 * Distributor
 *********************************************/
extern void arm_gicd_register_mapping_io_ICDDCR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDICTR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDIIDR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDISRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDISERn(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDICERn(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDISPRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDICPRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDABRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDIPRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDIPTRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDICFRn(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICDSGIR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);

/*********************************************
 * CPU interface
 *********************************************/
extern void arm_gicd_register_mapping_io_ICCICR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICCPMR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICCBPR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICCIAR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICCEOIR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICCRPR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICCHPIR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICCABPR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);
extern void arm_gicd_register_mapping_io_ICCIIDR(DevRegisterIoType io_type, DevRegisterIoArgType *arg);


/*********************************************
 * table
 *********************************************/
#define ARM_GIC_REGISTER_MAPPING_TABLE_NUM		22U
extern DevRegisterMappingType arm_gic_reigster_mapping_table[ARM_GIC_REGISTER_MAPPING_TABLE_NUM];

extern MpuAddressRegionType *arm_gic_region;

#endif /* _ARM_GIC_REGISTER_MAPPING_IO_H_ */
