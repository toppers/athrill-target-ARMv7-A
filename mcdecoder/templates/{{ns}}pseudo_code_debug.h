#ifndef _{{ ns }}PSEUDO_CODE_DEBUG_H_
#define _{{ ns }}PSEUDO_CODE_DEBUG_H_

#include "dbg_log.h"
#include "cpu_op_types.h"
#include "arm_pseudo_code_type.h"

{% for inst in machine_decoder.extras.pseudo_codes -%}
static inline void DBG_{{inst.name|upper}}(TargetCoreType *core, {{ inst.name }}_input_type *in, {{ inst.name }}_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
	
{% for key, value in inst.inputs.items() %}
		DBG_FMT_{{value}}
{% endfor %}
{% for key, value in inst.outputs.items() %}
		DBG_FMT_{{value}}
{% endfor %}
		DBG_FMT_PseudoCodeCondPassedType,
{% for key, value in inst.inputs.items() %}
		DBG_ARG_{{value}}(&in->{{key}}),
{% endfor %}
{% for key, value in inst.outputs.items() %}
		DBG_ARG_{{value}}(&out->{{key}}),
{% endfor %}
		DBG_ARG_PseudoCodeStatusType(&out->passed)
	));
}

{% endfor -%}


#endif /* !_{{ ns }}PSEUDO_CODE_DEBUG_H_ */
