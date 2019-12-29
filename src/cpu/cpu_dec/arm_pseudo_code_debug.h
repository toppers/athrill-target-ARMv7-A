#ifndef _ARM_PSEUDO_CODE_DEBUG_H_
#define _ARM_PSEUDO_CODE_DEBUG_H_

#include "dbg_log.h"
#include "cpu_op_types.h"
#include "arm_pseudo_code_type.h"

static inline void DBG_ARM_ADD_IMM(TargetCoreType *core, arm_add_imm_input_type *in, arm_add_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "

		DBG_FMT_sint32

		DBG_FMT_PseudoCodeStatusFlagType

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),


		DBG_ARG_sint32(&out->result),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),

		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_ADR_IMM(TargetCoreType *core, arm_adr_imm_input_type *in, arm_adr_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_bool

		": "

		DBG_FMT_sint32

		DBG_FMT_PseudoCodeStatusFlagType

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_bool(&in->add),


		DBG_ARG_sint32(&out->result),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),

		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_ADD_SPIMM(TargetCoreType *core, arm_add_spimm_input_type *in, arm_add_spimm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "

		DBG_FMT_sint32

		DBG_FMT_PseudoCodeStatusFlagType

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->SP),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),


		DBG_ARG_sint32(&out->result),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),

		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_SUBS_PCLR(TargetCoreType *core, arm_subs_pclr_input_type *in, arm_subs_pclr_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_uint8

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_bool

		DBG_FMT_sint32

		DBG_FMT_sint32

		DBG_FMT_PseudoCodeImmediateData32Type

		": "

		DBG_FMT_sint32

		DBG_FMT_PseudoCodeStatusFlagType

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_uint8(&in->opcode),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_bool(&in->register_form),

		DBG_ARG_sint32(&in->shift_t),

		DBG_ARG_sint32(&in->shift_n),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),


		DBG_ARG_sint32(&out->result),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),

		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MOV_IMM(TargetCoreType *core, arm_mov_imm_input_type *in, arm_mov_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "

		DBG_FMT_sint32

		DBG_FMT_PseudoCodeStatusFlagType

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),


		DBG_ARG_sint32(&out->result),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),

		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MOV_REG(TargetCoreType *core, arm_mov_reg_input_type *in, arm_mov_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "

		DBG_FMT_sint32

		DBG_FMT_PseudoCodeStatusFlagType

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),


		DBG_ARG_sint32(&out->result),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),

		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_BL_IMM(TargetCoreType *core, arm_bl_imm_input_type *in, arm_bl_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_sint32

		": "

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_sint32

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_sint32(&in->type),


		DBG_ARG_PseudoCodeRegisterDataType(&out->LR),

		DBG_ARG_sint32(&out->result),

		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDR_IMM(TargetCoreType *core, arm_ldr_imm_input_type *in, arm_ldr_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_bool

		DBG_FMT_bool

		DBG_FMT_bool

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "

		DBG_FMT_sint32

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_bool(&in->add),

		DBG_ARG_bool(&in->index),

		DBG_ARG_bool(&in->wback),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),


		DBG_ARG_sint32(&out->result),

		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_STR_IMM(TargetCoreType *core, arm_str_imm_input_type *in, arm_str_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_bool

		DBG_FMT_bool

		DBG_FMT_bool

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_bool(&in->add),

		DBG_ARG_bool(&in->index),

		DBG_ARG_bool(&in->wback),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),


		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),

		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

#endif /* !_ARM_PSEUDO_CODE_DEBUG_H_ */