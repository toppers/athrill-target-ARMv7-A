#ifndef _OP_DEC_TYPES_H_
#define _OP_DEC_TYPES_H_

#include "cpu_dec/arm_mcdecoder.h"
typedef arm_OpDecodedCodeType OpDecodedCodeType;
typedef arm_OpCodeId OpCodeId;

#define OP_DECODE_MAX	arm_OP_DECODE_MAX
#define OP_CODE_FORMAT_NUM arm_OP_CODE_FORMAT_NUM

#define INST_ARM_SIZE	4U
#define INST_THUMB_SIZE	2U

#endif /* _OP_DEC_TYPES_H_ */
