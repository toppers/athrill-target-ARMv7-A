#include "../../src/cpu/cpu_exec/op_exec_debug.h"
#include "cpu_dec/arm_mcdecoder.h"
#include "target_cpu.h"
#include "cpu_ops.h"
#include "bus.h"
#include "arm_pseudo_code_func.h"

{% for inst in instruction_decoders -%}

{% set pseudo_code = machine_decoder.extras.pseudo_codes|selectattr('name', 'eq', inst.extras.pseudo_code)|first %}

int arm_op_exec_{{inst.name}}(struct TargetCore *core)
{
	arm_OpCodeFormatType_{{inst.name}} *op = &core->decoded_code->code.{{inst.name}};

	{{inst.extras.pseudo_code}}_input_type in;
	{{inst.extras.pseudo_code}}_output_type out;
	out.status = *cpu_get_status(core);

	//TODO arguments setting..
	in.instrName = "{{inst.name|upper}}";
{% for key, value in pseudo_code.inputs.items() %}
	in.{{key}} = op->{{key}};
{% endfor %}
	out.next_address = core->pc;
	out.passed = FALSE;
{% if pseudo_code.outputs is defined %}
	{% for key, value in pseudo_code.outputs.items() %}
	out.{{key}} = -1;
	{% endfor %}
{% endif %}
	
	int ret = arm_op_exec_{{pseudo_code.name}}(core, &in, &out);
	DBG_{{inst.extras.pseudo_code|upper}}(core, &in, &out);

	core->pc = out.next_address;
	return ret;
}
{% endfor -%}

