#ifndef _ARM_PSEUDO_CODE_DEBUG_H_
#define _ARM_PSEUDO_CODE_DEBUG_H_

#include "dbg_log.h"
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


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_ADD_REG(TargetCoreType *core, arm_add_reg_input_type *in, arm_add_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_SUB_IMM(TargetCoreType *core, arm_sub_imm_input_type *in, arm_sub_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_SUB_REG(TargetCoreType *core, arm_sub_reg_input_type *in, arm_sub_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_CMP_IMM(TargetCoreType *core, arm_cmp_imm_input_type *in, arm_cmp_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeSignType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeCmpResultType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeSignType(&in->sign),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeCmpResultType(&out->result),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_CMP_REG(TargetCoreType *core, arm_cmp_reg_input_type *in, arm_cmp_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		": "


		DBG_FMT_PseudoCodeCmpResultType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),



		DBG_ARG_PseudoCodeCmpResultType(&out->result),

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

		DBG_FMT_PseudoCodeBitCountType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_PseudoCodeBitCountType(&in->add),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

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


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->SP),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

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

		DBG_FMT_PseudoCodeOpcodeType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterFormType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeOpcodeType(&in->opcode),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_PseudoCodeRegisterFormType(&in->register_form),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->PC),

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


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MVN_IMM(TargetCoreType *core, arm_mvn_imm_input_type *in, arm_mvn_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

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


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MVN_REG(TargetCoreType *core, arm_mvn_reg_input_type *in, arm_mvn_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

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

		DBG_FMT_PseudoCodeInstrSetType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_PseudoCodeInstrSetType(&in->type),



		DBG_ARG_PseudoCodeRegisterDataType(&out->LR),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_B_IMM(TargetCoreType *core, arm_b_imm_input_type *in, arm_b_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_PseudoCodeRegisterDataType

		": "

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_PseudoCodeRegisterDataType(&in->PC),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_BX_REG(TargetCoreType *core, arm_bx_reg_input_type *in, arm_bx_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_BL_REG(TargetCoreType *core, arm_bl_reg_input_type *in, arm_bl_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->LR),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDR_IMM(TargetCoreType *core, arm_ldr_imm_input_type *in, arm_ldr_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeSizeType

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_PseudoCodeBoolAddType

		DBG_FMT_PseudoCodeBoolIndexType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeSizeType(&in->size),

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_PseudoCodeBoolAddType(&in->add),

		DBG_ARG_PseudoCodeBoolIndexType(&in->index),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDRD_IMM(TargetCoreType *core, arm_ldrd_imm_input_type *in, arm_ldrd_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_PseudoCodeBoolAddType

		DBG_FMT_PseudoCodeBoolIndexType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_PseudoCodeBoolAddType(&in->add),

		DBG_ARG_PseudoCodeBoolIndexType(&in->index),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt1),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt2),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDR_REG(TargetCoreType *core, arm_ldr_reg_input_type *in, arm_ldr_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeSizeType

		DBG_FMT_PseudoCodeSignType

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBoolAddType

		DBG_FMT_PseudoCodeBoolIndexType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeSizeType(&in->size),

		DBG_ARG_PseudoCodeSignType(&in->sign),

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBoolAddType(&in->add),

		DBG_ARG_PseudoCodeBoolIndexType(&in->index),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_PUSH(TargetCoreType *core, arm_push_input_type *in, arm_push_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBitCountType

		DBG_FMT_PseudoCodeUnalignedAllowedType

		DBG_FMT_PseudoCodeRegisterListType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBitCountType(&in->bitcount),

		DBG_ARG_PseudoCodeUnalignedAllowedType(&in->UnalignedAllowed),

		DBG_ARG_PseudoCodeRegisterListType(&in->registers),

		DBG_ARG_PseudoCodeRegisterDataType(&in->SP),



		DBG_ARG_PseudoCodeRegisterDataType(&out->SP),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_POP(TargetCoreType *core, arm_pop_input_type *in, arm_pop_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBitCountType

		DBG_FMT_PseudoCodeUnalignedAllowedType

		DBG_FMT_PseudoCodeRegisterListType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBitCountType(&in->bitcount),

		DBG_ARG_PseudoCodeUnalignedAllowedType(&in->UnalignedAllowed),

		DBG_ARG_PseudoCodeRegisterListType(&in->registers),

		DBG_ARG_PseudoCodeRegisterDataType(&in->SP),



		DBG_ARG_PseudoCodeRegisterDataType(&out->SP),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_STR_IMM(TargetCoreType *core, arm_str_imm_input_type *in, arm_str_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeSizeType

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_PseudoCodeBoolAddType

		DBG_FMT_PseudoCodeBoolIndexType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeSizeType(&in->size),

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_PseudoCodeBoolAddType(&in->add),

		DBG_ARG_PseudoCodeBoolIndexType(&in->index),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_STRD_IMM(TargetCoreType *core, arm_strd_imm_input_type *in, arm_strd_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_PseudoCodeBoolAddType

		DBG_FMT_PseudoCodeBoolIndexType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_PseudoCodeBoolAddType(&in->add),

		DBG_ARG_PseudoCodeBoolIndexType(&in->index),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt1),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt2),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_STR_REG(TargetCoreType *core, arm_str_reg_input_type *in, arm_str_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeSizeType

		DBG_FMT_PseudoCodeSignType

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBoolAddType

		DBG_FMT_PseudoCodeBoolIndexType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeSizeType(&in->size),

		DBG_ARG_PseudoCodeSignType(&in->sign),

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBoolAddType(&in->add),

		DBG_ARG_PseudoCodeBoolIndexType(&in->index),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_NOP(TargetCoreType *core, arm_nop_input_type *in, arm_nop_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		": "

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MSR_IMM(TargetCoreType *core, arm_msr_imm_input_type *in, arm_msr_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_PseudoCodeWriteNZCVQType

		DBG_FMT_PseudoCodeWriteGType

		": "

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_PseudoCodeWriteNZCVQType(&in->write_nzcvq),

		DBG_ARG_PseudoCodeWriteGType(&in->write_g),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MSR2_IMM(TargetCoreType *core, arm_msr2_imm_input_type *in, arm_msr2_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_PseudoCodeMaskType

		DBG_FMT_PseudoCodeWriteSpsrType

		": "

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_PseudoCodeMaskType(&in->mask),

		DBG_ARG_PseudoCodeWriteSpsrType(&in->write_spsr),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MSR2_REG(TargetCoreType *core, arm_msr2_reg_input_type *in, arm_msr2_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeMaskType

		DBG_FMT_PseudoCodeWriteSpsrType

		": "

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeMaskType(&in->mask),

		DBG_ARG_PseudoCodeWriteSpsrType(&in->write_spsr),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MRS(TargetCoreType *core, arm_mrs_input_type *in, arm_mrs_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MCR(TargetCoreType *core, arm_mcr_input_type *in, arm_mcr_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeCoprocType

		DBG_FMT_PseudoCodeCoprocCRnType

		DBG_FMT_PseudoCodeCoprocOp1Type

		DBG_FMT_PseudoCodeCoprocCRmType

		DBG_FMT_PseudoCodeCoprocOp2Type

		DBG_FMT_PseudoCodeRegisterDataType

		": "

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeCoprocType(&in->cp),

		DBG_ARG_PseudoCodeCoprocCRnType(&in->CRn),

		DBG_ARG_PseudoCodeCoprocOp1Type(&in->op1),

		DBG_ARG_PseudoCodeCoprocCRmType(&in->CRm),

		DBG_ARG_PseudoCodeCoprocOp2Type(&in->op2),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MRC(TargetCoreType *core, arm_mrc_input_type *in, arm_mrc_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeCoprocType

		DBG_FMT_PseudoCodeCoprocCRnType

		DBG_FMT_PseudoCodeCoprocOp1Type

		DBG_FMT_PseudoCodeCoprocCRmType

		DBG_FMT_PseudoCodeCoprocOp2Type

		DBG_FMT_PseudoCodeRegisterDataType

		": "

		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeCoprocType(&in->cp),

		DBG_ARG_PseudoCodeCoprocCRnType(&in->CRn),

		DBG_ARG_PseudoCodeCoprocOp1Type(&in->op1),

		DBG_ARG_PseudoCodeCoprocCRmType(&in->CRm),

		DBG_ARG_PseudoCodeCoprocOp2Type(&in->op2),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_BIC_IMM(TargetCoreType *core, arm_bic_imm_input_type *in, arm_bic_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_ORR_IMM(TargetCoreType *core, arm_orr_imm_input_type *in, arm_orr_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_ORR_REG(TargetCoreType *core, arm_orr_reg_input_type *in, arm_orr_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MOVT(TargetCoreType *core, arm_movt_input_type *in, arm_movt_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData16Type

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeImmediateData16Type(&in->imm16),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LSL_IMM(TargetCoreType *core, arm_lsl_imm_input_type *in, arm_lsl_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LSL_REG(TargetCoreType *core, arm_lsl_reg_input_type *in, arm_lsl_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LSR_IMM(TargetCoreType *core, arm_lsr_imm_input_type *in, arm_lsr_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_BFC(TargetCoreType *core, arm_bfc_input_type *in, arm_bfc_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeMsbitType

		DBG_FMT_PseudoCodeLsbitType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeMsbitType(&in->msbit),

		DBG_ARG_PseudoCodeLsbitType(&in->lsbit),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_AND_IMM(TargetCoreType *core, arm_and_imm_input_type *in, arm_and_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_AND_REG(TargetCoreType *core, arm_and_reg_input_type *in, arm_and_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_UTX(TargetCoreType *core, arm_utx_input_type *in, arm_utx_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeSizeType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRotationType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeSizeType(&in->size),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRotationType(&in->rotate),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_RSB_REG(TargetCoreType *core, arm_rsb_reg_input_type *in, arm_rsb_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_SBC_REG(TargetCoreType *core, arm_sbc_reg_input_type *in, arm_sbc_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_MUL(TargetCoreType *core, arm_mul_input_type *in, arm_mul_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_TST_IMM(TargetCoreType *core, arm_tst_imm_input_type *in, arm_tst_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_TST_REG(TargetCoreType *core, arm_tst_reg_input_type *in, arm_tst_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSRType

		DBG_FMT_PseudoCodeShiftNType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

#endif /* !_ARM_PSEUDO_CODE_DEBUG_H_ */