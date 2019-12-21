#include "cpu.h"
#include "bus.h"
#include "std_cpu_ops.h"
#include <stdio.h>
#include "cpu_common/cpu_ops.h"
#include "cpu_dec/arm_mcdecoder.h"
#include "mpu_types.h"
#include <sys/time.h>
#include "std_device_ops.h"

CpuType virtual_cpu;

void cpu_init(void)
{
	CoreIdType i;
	for (i = 0; i < cpu_config_get_core_id_num(); i++) {
		virtual_cpu.cores[i].core.core_id = i;
		cpu_reset(i);
	}
	return;
}


static void private_cpu_reset(TargetCoreType *cpu)
{
	//TODO
	*cpu_get_status(cpu) = CpuSystemLevelEncoding_System;
	cpu->is_halt = FALSE;
	return;
}

void cpu_reset(CoreIdType core_id)
{
	private_cpu_reset(&virtual_cpu.cores[core_id].core);
	return;
}
bool cpu_is_halt(CoreIdType core_id)
{
	return virtual_cpu.cores[core_id].core.is_halt;
}
void cpu_set_current_core(CoreIdType core_id)
{
	virtual_cpu.current_core = &virtual_cpu.cores[core_id];
	return;
}

bool cpu_has_permission(CoreIdType core_id, MpuAddressRegionEnumType region_type, CpuMemoryAccessType access_type, uint32 addr, uint32 size)
{
	//TODO
	return TRUE;
}
static Std_ReturnType cpu_supply_clock_not_cached(CoreIdType core_id, CachedOperationCodeType *cached_code, uint32 inx)
{
	int ret;
	Std_ReturnType err;
	static arm_OpDecodedCodeType	decoded_code;
	arm_OpDecodedCodeType		*p_decoded_code;
	arm_OperationCodeType optype;
	bool permission;

	if (cached_code != NULL) {
		p_decoded_code = &cached_code->codes[inx].decoded_code;
		virtual_cpu.cores[core_id].core.decoded_code = &cached_code->codes[inx].decoded_code;
	}
	else {
		p_decoded_code = &decoded_code;
		virtual_cpu.cores[core_id].core.decoded_code = &decoded_code;
	}
	/*
	 * 命令取得する
	 */
	err = bus_get_pointer(core_id,
			cpu_get_pc(&virtual_cpu.cores[core_id].core),
				(uint8**)&(virtual_cpu.cores[core_id].core.current_code));
	if (err != STD_E_OK) {
		return err;
	}

	/*
	 * デコード
	 */
	ret = arm_op_parse(virtual_cpu.cores[core_id].core.current_code,
			p_decoded_code, &optype);
	if (ret != 0) {
		printf("Decode Error\n");
		return STD_E_DECODE;
	}

	permission = cpu_has_permission(core_id,
			READONLY_MEMORY,
			CpuMemoryAccess_EXEC,
			cpu_get_pc(&virtual_cpu.cores[core_id].core),
			OpFormatSize[p_decoded_code->type_id]);
	if (permission == FALSE) {
		return STD_E_SEGV;
	}

	if (arm_op_exec_table[optype.code_id].exec == NULL) {
		printf("Not supported code(%d fmt=%d) Error code[0]=0x%x code[1]=0x%x type_id=0x%x\n",
				optype.code_id, optype.format_id,
				virtual_cpu.cores[core_id].core.current_code[0],
				virtual_cpu.cores[core_id].core.current_code[1],
				virtual_cpu.cores[core_id].core.decoded_code->type_id);
		return STD_E_EXEC;
	}

	/*
	 * 命令実行
	 */
	ret = arm_op_exec_table[optype.code_id].exec(&virtual_cpu.cores[core_id].core);
	if (ret < 0) {
		printf("Exec Error code[0]=0x%x code[1]=0x%x type_id=0x%x code_id=%u\n",
				virtual_cpu.cores[core_id].core.current_code[0],
				virtual_cpu.cores[core_id].core.current_code[1],
				virtual_cpu.cores[core_id].core.decoded_code->type_id,
				optype.code_id);
		return STD_E_EXEC;
	}

	if (cached_code != NULL) {
#ifdef CONFIG_STAT_PERF
		cached_code->codes[inx].code_id = optype.code_id;
#endif /* CONFIG_STAT_PERF */
		cached_code->codes[inx].op_exec = arm_op_exec_table[optype.code_id].exec;
	}
	return STD_E_OK;
}

Std_ReturnType cpu_supply_clock(CoreIdType core_id)
{
	int ret;
	Std_ReturnType err;
	uint32 inx;
	CachedOperationCodeType *cached_code;

	if (virtual_cpu.cores[core_id].core.is_halt == TRUE) {
		return STD_E_OK;
	}

	cached_code = virtual_cpu_get_cached_code(cpu_get_pc(&virtual_cpu.cores[core_id].core));
	if (cached_code != NULL) {
		inx = cpu_get_pc(&virtual_cpu.cores[core_id].core) - cached_code->code_start_addr;
	}
	if ((cached_code == NULL) || (cached_code->codes[inx].op_exec == NULL)) {
		err = cpu_supply_clock_not_cached(core_id, cached_code, inx);
		if (err != STD_E_OK) {
			return err;
		}
	}
	else {
#ifdef CONFIG_STAT_PERF
		OpCodeId code_id = cached_code->codes[inx].code_id;
		PROFSTAT_START(&op_exec_stat_table[code_id]);
#endif /* CONFIG_STAT_PERF */
		virtual_cpu.cores[core_id].core.decoded_code = &cached_code->codes[inx].decoded_code;
#ifndef DISABLE_MEMPROTECT
		bool permission;
		permission = cpu_has_permission(core_id,
				READONLY_MEMORY,
				CpuMemoryAccess_EXEC,
				cpu_get_pc(&virtual_cpu.cores[core_id].core),
				OpFormatSize[cached_code->codes[inx].decoded_code.type_id]);
		if (permission == FALSE) {
			return STD_E_SEGV;
		}
#endif /* DISABLE_MEMPROTECT */
		ret = cached_code->codes[inx].op_exec(&virtual_cpu.cores[core_id].core);
#ifdef CONFIG_STAT_PERF
		PROFSTAT_END(&op_exec_stat_table[code_id]);
#endif /* CONFIG_STAT_PERF */
		if (ret < 0) {
			printf("Exec Error code[0]=0x%x code[1]=0x%x type_id=0x%x\n",
					virtual_cpu.cores[core_id].core.current_code[0],
					virtual_cpu.cores[core_id].core.current_code[1],
					virtual_cpu.cores[core_id].core.decoded_code->type_id);
			return STD_E_EXEC;
		}
	}
	return STD_E_OK;
}

void cpu_illegal_opcode_trap(CoreIdType core_id)
{
	//TODO
	return;
}
bool cpu_illegal_access(CoreIdType core_id)
{
	//TODO
	return FALSE;
}

CoreIdType cpu_get_core_id(const TargetCoreType *core)
{
	return core->core_id;
}
void cpu_set_core_pc(CoreIdType core_id, uint32 pc)
{
	virtual_cpu.cores[core_id].core.pc = pc;
	return;
}
uint32 cpu_get_return_addr(const TargetCoreType *core)
{
	return cpu_get_lr(core);
}

uint32 cpu_get_current_core_sp(void)
{
	return cpu_get_sp((const TargetCoreType *)virtual_cpu.current_core);
}
uint32 cpu_get_current_core_id(void)
{
	return ((const TargetCoreType *)virtual_cpu.current_core)->core_id;
}
uint32 cpu_get_current_core_pc(void)
{
	return cpu_get_pc((const TargetCoreType *)virtual_cpu.current_core);
}
uint32 cpu_get_current_core_register(uint32 inx)
{
	return (cpu_get_reg((TargetCoreType *)virtual_cpu.current_core, inx));
}

MpuAddressRegionOperationType cpu_register_operation = {
		.get_data8 = NULL,
		.get_data16 = NULL,
		.get_data32 = NULL,
		.put_data8 = NULL,
		.put_data16 = NULL,
		.put_data32 = NULL,
};
