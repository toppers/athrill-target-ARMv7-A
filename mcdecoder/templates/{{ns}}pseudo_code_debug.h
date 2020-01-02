#ifndef _{{ ns|upper }}PSEUDO_CODE_DEBUG_H_
#define _{{ ns|upper }}PSEUDO_CODE_DEBUG_H_

#include "dbg_log.h"
#include "arm_pseudo_code_type.h"

{% for inst in machine_decoder.extras.pseudo_codes -%}
static inline void DBG_{{inst.name|upper}}(TargetCoreType *core, {{ inst.name }}_input_type *in, {{ inst.name }}_output_type *out)
{
	DBG_PRINT((DBG_EXEC_OP_BUF(), DBG_EXEC_OP_BUF_LEN(),
		DBG_FMT_STR
{% for key, value in inst.inputs.items() %}
		DBG_FMT_{{value}}
{% endfor %}
		": "
{% if inst.outputs is defined %}
{% for key, value in inst.outputs.items() %}
		DBG_FMT_{{value}}
{% endfor %}
{% endif %}
		DBG_FMT_PseudoCodeStatusType 
		DBG_FMT_PseudoCodeCondPassedType "\n",
		in->instrName,
{% for key, value in inst.inputs.items() %}
		DBG_ARG_{{value}}(&in->{{key}}),
{% endfor %}
{% if inst.outputs is defined %}
{% for key, value in inst.outputs.items() %}
		DBG_ARG_{{value}}(&out->{{key}}),
{% endfor %}
{% endif %}
		DBG_ARG_PseudoCodeStatusType(&out->status),
		DBG_ARG_PseudoCodeCondPassedType(&out->passed)
	));
}

{% endfor -%}


#endif /* !_{{ ns|upper }}PSEUDO_CODE_DEBUG_H_ */
