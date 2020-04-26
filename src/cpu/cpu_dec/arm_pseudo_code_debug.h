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

static inline void DBG_ARM_MLA(TargetCoreType *core, arm_mla_input_type *in, arm_mla_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

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

		DBG_ARG_PseudoCodeRegisterDataType(&in->Ra),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_ADC_REG(TargetCoreType *core, arm_adc_reg_input_type *in, arm_adc_reg_output_type *out)
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

static inline void DBG_ARM_ADC_IMM(TargetCoreType *core, arm_adc_imm_input_type *in, arm_adc_imm_output_type *out)
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

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeCmpResultType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeCmpResultType(&out->result),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_CMN_IMM(TargetCoreType *core, arm_cmn_imm_input_type *in, arm_cmn_imm_output_type *out)
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

static inline void DBG_ARM_CMN_REG(TargetCoreType *core, arm_cmn_reg_input_type *in, arm_cmn_reg_output_type *out)
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

static inline void DBG_ARM_TEQ_REG(TargetCoreType *core, arm_teq_reg_input_type *in, arm_teq_reg_output_type *out)
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

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_PseudoCodeBoolAddType

		DBG_FMT_PseudoCodeBoolIndexType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

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

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDRB_IMM(TargetCoreType *core, arm_ldrb_imm_input_type *in, arm_ldrb_imm_output_type *out)
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

		": "


		DBG_FMT_PseudoCodeRegisterDataType

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

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDR_LITERAL(TargetCoreType *core, arm_ldr_literal_input_type *in, arm_ldr_literal_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_PseudoCodeBoolAddType

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

		DBG_ARG_PseudoCodeRegisterDataType(&in->PC),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDRH_IMM(TargetCoreType *core, arm_ldrh_imm_input_type *in, arm_ldrh_imm_output_type *out)
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

		": "


		DBG_FMT_PseudoCodeRegisterDataType

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

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDRSH_IMM(TargetCoreType *core, arm_ldrsh_imm_input_type *in, arm_ldrsh_imm_output_type *out)
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

		": "


		DBG_FMT_PseudoCodeRegisterDataType

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

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDRSH_REG(TargetCoreType *core, arm_ldrsh_reg_input_type *in, arm_ldrsh_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

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


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBoolAddType(&in->add),

		DBG_ARG_PseudoCodeBoolIndexType(&in->index),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt),


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

		DBG_FMT_PseudoCodeRegisterDataType

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

		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt1),

		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt2),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDR_REG(TargetCoreType *core, arm_ldr_reg_input_type *in, arm_ldr_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

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


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

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



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDRB_REG(TargetCoreType *core, arm_ldrb_reg_input_type *in, arm_ldrb_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

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


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

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



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDRH_REG(TargetCoreType *core, arm_ldrh_reg_input_type *in, arm_ldrh_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

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


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

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



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt),


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

static inline void DBG_ARM_STMFD(TargetCoreType *core, arm_stmfd_input_type *in, arm_stmfd_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBitCountType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeRegisterListType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBitCountType(&in->bitcount),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeRegisterListType(&in->registers),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_STMIB(TargetCoreType *core, arm_stmib_input_type *in, arm_stmib_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBitCountType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeRegisterListType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBitCountType(&in->bitcount),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeRegisterListType(&in->registers),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_STM(TargetCoreType *core, arm_stm_input_type *in, arm_stm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeBitCountType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterListType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeBitCountType(&in->bitcount),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterListType(&in->registers),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),


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

static inline void DBG_ARM_LDM(TargetCoreType *core, arm_ldm_input_type *in, arm_ldm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeBitCountType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterListType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeBitCountType(&in->bitcount),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterListType(&in->registers),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_LDMIB(TargetCoreType *core, arm_ldmib_input_type *in, arm_ldmib_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeBitCountType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterListType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeBitCountType(&in->bitcount),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterListType(&in->registers),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),


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

static inline void DBG_ARM_BIC_REG(TargetCoreType *core, arm_bic_reg_input_type *in, arm_bic_reg_output_type *out)
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

static inline void DBG_ARM_BIC_SHIFT_REG(TargetCoreType *core, arm_bic_shift_reg_input_type *in, arm_bic_shift_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

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

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rs),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_UBFX(TargetCoreType *core, arm_ubfx_input_type *in, arm_ubfx_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeLsbType

		DBG_FMT_PseudoCodeMsbType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeLsbType(&in->lsb),

		DBG_ARG_PseudoCodeMsbType(&in->msb),



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

static inline void DBG_ARM_EOR_IMM(TargetCoreType *core, arm_eor_imm_input_type *in, arm_eor_imm_output_type *out)
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

static inline void DBG_ARM_EOR_REG(TargetCoreType *core, arm_eor_reg_input_type *in, arm_eor_reg_output_type *out)
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

static inline void DBG_ARM_LSR_REG(TargetCoreType *core, arm_lsr_reg_input_type *in, arm_lsr_reg_output_type *out)
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

static inline void DBG_ARM_BFI(TargetCoreType *core, arm_bfi_input_type *in, arm_bfi_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeMsbitType

		DBG_FMT_PseudoCodeLsbitType

		DBG_FMT_PseudoCodeRegisterDataType

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

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),



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

static inline void DBG_ARM_AND_SHIFT_REG(TargetCoreType *core, arm_and_shift_reg_input_type *in, arm_and_shift_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

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

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rs),

		DBG_ARG_PseudoCodeSRType(&in->shift_t),

		DBG_ARG_PseudoCodeShiftNType(&in->shift_n),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_UXT(TargetCoreType *core, arm_uxt_input_type *in, arm_uxt_output_type *out)
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

static inline void DBG_ARM_RRX(TargetCoreType *core, arm_rrx_input_type *in, arm_rrx_output_type *out)
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

static inline void DBG_ARM_RSB_IMM(TargetCoreType *core, arm_rsb_imm_input_type *in, arm_rsb_imm_output_type *out)
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

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



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

static inline void DBG_ARM_SBC_IMM(TargetCoreType *core, arm_sbc_imm_input_type *in, arm_sbc_imm_output_type *out)
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

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



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

static inline void DBG_ARM_SMMUL(TargetCoreType *core, arm_smmul_input_type *in, arm_smmul_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRoundType

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

		DBG_ARG_PseudoCodeRoundType(&in->round),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_SMULL(TargetCoreType *core, arm_smull_input_type *in, arm_smull_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->RdHi),

		DBG_ARG_PseudoCodeRegisterDataType(&in->RdLo),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),



		DBG_ARG_PseudoCodeRegisterDataType(&out->RdHi),

		DBG_ARG_PseudoCodeRegisterDataType(&out->RdLo),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_UMULL(TargetCoreType *core, arm_umull_input_type *in, arm_umull_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeUpdateStatusFlagType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeUpdateStatusFlagType(&in->S),

		DBG_ARG_PseudoCodeRegisterDataType(&in->RdHi),

		DBG_ARG_PseudoCodeRegisterDataType(&in->RdLo),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),



		DBG_ARG_PseudoCodeRegisterDataType(&out->RdHi),

		DBG_ARG_PseudoCodeRegisterDataType(&out->RdLo),

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


		DBG_FMT_PseudoCodeStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



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

static inline void DBG_ARM_SXTB(TargetCoreType *core, arm_sxtb_input_type *in, arm_sxtb_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRotationType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRotationType(&in->rotate),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_SXTH(TargetCoreType *core, arm_sxth_input_type *in, arm_sxth_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRotationType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRotationType(&in->rotate),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_ASR_IMM(TargetCoreType *core, arm_asr_imm_input_type *in, arm_asr_imm_output_type *out)
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

static inline void DBG_ARM_ASR_REG(TargetCoreType *core, arm_asr_reg_input_type *in, arm_asr_reg_output_type *out)
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

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),

		DBG_ARG_PseudoCodeStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_SRS(TargetCoreType *core, arm_srs_input_type *in, arm_srs_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeModeType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeBoolIncrementType

		DBG_FMT_PseudoCodeBoolWordHigherType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeSPSRType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeModeType(&in->mode),

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeBoolIncrementType(&in->increment),

		DBG_ARG_PseudoCodeBoolWordHigherType(&in->wordhigher),

		DBG_ARG_PseudoCodeRegisterDataType(&in->SP),

		DBG_ARG_PseudoCodeRegisterDataType(&in->LR),

		DBG_ARG_PseudoCodeSPSRType(&in->SPSR),



		DBG_ARG_PseudoCodeRegisterDataType(&out->SP),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_CLZ(TargetCoreType *core, arm_clz_input_type *in, arm_clz_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rd),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rm),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_RFE(TargetCoreType *core, arm_rfe_input_type *in, arm_rfe_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeBoolIncrementType

		DBG_FMT_PseudoCodeBoolWordHigherType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeBoolWbackType(&in->wback),

		DBG_ARG_PseudoCodeBoolIncrementType(&in->increment),

		DBG_ARG_PseudoCodeBoolWordHigherType(&in->wordhigher),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),



		DBG_ARG_PseudoCodeRegisterDataType(&out->Rn),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_WFI(TargetCoreType *core, arm_wfi_input_type *in, arm_wfi_output_type *out)
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

static inline void DBG_ARM_VADD_FREG(TargetCoreType *core, arm_vadd_freg_input_type *in, arm_vadd_freg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeBoolIncrementType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vn),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vm),

		DBG_ARG_PseudoCodeBoolWbackType(&in->advsimd),

		DBG_ARG_PseudoCodeBoolIncrementType(&in->dp_operation),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VSUB_FREG(TargetCoreType *core, arm_vsub_freg_input_type *in, arm_vsub_freg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeBoolIncrementType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vn),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vm),

		DBG_ARG_PseudoCodeBoolWbackType(&in->advsimd),

		DBG_ARG_PseudoCodeBoolIncrementType(&in->dp_operation),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VMUL_FREG(TargetCoreType *core, arm_vmul_freg_input_type *in, arm_vmul_freg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeBoolIncrementType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vn),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vm),

		DBG_ARG_PseudoCodeBoolWbackType(&in->advsimd),

		DBG_ARG_PseudoCodeBoolIncrementType(&in->dp_operation),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VDIV_FREG(TargetCoreType *core, arm_vdiv_freg_input_type *in, arm_vdiv_freg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeBoolIncrementType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vn),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vm),

		DBG_ARG_PseudoCodeBoolWbackType(&in->advsimd),

		DBG_ARG_PseudoCodeBoolIncrementType(&in->dp_operation),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VLDR(TargetCoreType *core, arm_vldr_input_type *in, arm_vldr_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeBoolAddType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeBoolAddType(&in->add),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VCVT_DF(TargetCoreType *core, arm_vcvt_df_input_type *in, arm_vcvt_df_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeDoubleToSingleType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeDoubleToSingleType(&in->double_to_single),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vm),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VCVT_FI(TargetCoreType *core, arm_vcvt_fi_input_type *in, arm_vcvt_fi_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBoolIncrementType

		DBG_FMT_PseudoCodeToIntegerType

		DBG_FMT_PseudoCodeUnsignedCvtType

		DBG_FMT_PseudoCodeRoundZeroType

		DBG_FMT_PseudoCodeRoundNearestType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBoolIncrementType(&in->dp_operation),

		DBG_ARG_PseudoCodeToIntegerType(&in->to_integer),

		DBG_ARG_PseudoCodeUnsignedCvtType(&in->unsigned_cvt),

		DBG_ARG_PseudoCodeRoundZeroType(&in->round_zero),

		DBG_ARG_PseudoCodeRoundNearestType(&in->round_nearest),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vm),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VSTR(TargetCoreType *core, arm_vstr_input_type *in, arm_vstr_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeSingleRegType

		DBG_FMT_PseudoCodeBoolAddType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeSingleRegType(&in->single_reg),

		DBG_ARG_PseudoCodeBoolAddType(&in->add),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rn),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VCMP(TargetCoreType *core, arm_vcmp_input_type *in, arm_vcmp_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBoolIncrementType

		DBG_FMT_PseudoCodeQuietNanExcType

		DBG_FMT_PseudoCodeWithZeroType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		": "


		DBG_FMT_PseudoCodeFloatStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBoolIncrementType(&in->dp_operation),

		DBG_ARG_PseudoCodeQuietNanExcType(&in->quiet_nan_exc),

		DBG_ARG_PseudoCodeWithZeroType(&in->with_zero),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vm),



		DBG_ARG_PseudoCodeFloatStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VMRS(TargetCoreType *core, arm_vmrs_input_type *in, arm_vmrs_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeFloatStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),



		DBG_ARG_PseudoCodeFloatStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VMOV_IMM(TargetCoreType *core, arm_vmov_imm_input_type *in, arm_vmov_imm_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		DBG_FMT_PseudoCodeImmediateData64Type

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeSingleRegType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeRegNumType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),

		DBG_ARG_PseudoCodeImmediateData64Type(&in->imm64),

		DBG_ARG_PseudoCodeBoolWbackType(&in->advsimd),

		DBG_ARG_PseudoCodeSingleRegType(&in->single_reg),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd1),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd2),

		DBG_ARG_PseudoCodeRegNumType(&in->regs),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd1),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd2),

		DBG_ARG_PseudoCodeFloatStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VMOV_REG(TargetCoreType *core, arm_vmov_reg_input_type *in, arm_vmov_reg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeSingleRegType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeRegNumType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeSingleRegType(&in->single_reg),

		DBG_ARG_PseudoCodeBoolWbackType(&in->advsimd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vm),

		DBG_ARG_PseudoCodeRegNumType(&in->regs),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),

		DBG_ARG_PseudoCodeFloatStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VNEG(TargetCoreType *core, arm_vneg_input_type *in, arm_vneg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBoolIncrementType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeRegNumType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBoolIncrementType(&in->dp_operation),

		DBG_ARG_PseudoCodeBoolWbackType(&in->advsimd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vm),

		DBG_ARG_PseudoCodeRegNumType(&in->regs),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),

		DBG_ARG_PseudoCodeFloatStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VMLA(TargetCoreType *core, arm_vmla_input_type *in, arm_vmla_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeBoolIncrementType

		DBG_FMT_PseudoCodeBoolWbackType

		DBG_FMT_PseudoCodeBoolAddType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeRegNumType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeFloatStatusFlagType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeBoolIncrementType(&in->dp_operation),

		DBG_ARG_PseudoCodeBoolWbackType(&in->advsimd),

		DBG_ARG_PseudoCodeBoolAddType(&in->add),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vn),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vm),

		DBG_ARG_PseudoCodeRegNumType(&in->regs),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),

		DBG_ARG_PseudoCodeFloatStatusFlagType(&out->status_flag),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VMOV_SREG(TargetCoreType *core, arm_vmov_sreg_input_type *in, arm_vmov_sreg_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeToArmRegisterType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType

		": "


		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeToArmRegisterType(&in->to_arm_register),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vn),

		DBG_ARG_PseudoCodeRegisterDataType(&in->Rt),



		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vn),

		DBG_ARG_PseudoCodeRegisterDataType(&out->Rt),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VPUSH(TargetCoreType *core, arm_vpush_input_type *in, arm_vpush_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeSingleRegType

		DBG_FMT_PseudoCodeRegNumType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeSingleRegType(&in->single_reg),

		DBG_ARG_PseudoCodeRegNumType(&in->regs),

		DBG_ARG_PseudoCodeRegisterDataType(&in->SP),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->SP),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

static inline void DBG_ARM_VPOP(TargetCoreType *core, arm_vpop_input_type *in, arm_vpop_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR

		DBG_FMT_PseudoCodeConditionDataType

		DBG_FMT_PseudoCodeSingleRegType

		DBG_FMT_PseudoCodeRegNumType

		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType

		DBG_FMT_PseudoCodeImmediateData32Type

		": "


		DBG_FMT_PseudoCodeRegisterDataType

		DBG_FMT_PseudoCodeFloatRegisterDataType


		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,

		DBG_ARG_PseudoCodeConditionDataType(&in->cond),

		DBG_ARG_PseudoCodeSingleRegType(&in->single_reg),

		DBG_ARG_PseudoCodeRegNumType(&in->regs),

		DBG_ARG_PseudoCodeRegisterDataType(&in->SP),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&in->Vd),

		DBG_ARG_PseudoCodeImmediateData32Type(&in->imm32),



		DBG_ARG_PseudoCodeRegisterDataType(&out->SP),

		DBG_ARG_PseudoCodeFloatRegisterDataType(&out->Vd),


		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

#endif /* !_ARM_PSEUDO_CODE_DEBUG_H_ */