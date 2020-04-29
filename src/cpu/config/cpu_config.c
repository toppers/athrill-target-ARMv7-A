#include "cpu.h"
#include "bus.h"
#include "std_cpu_ops.h"
#include <stdio.h>
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
	*cpu_get_status(cpu) = CpuSystemLevelEncoding_Supervisor;
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
	InstrSetType type = CurrentInstrSet(*cpu_get_status(&virtual_cpu.cores[core_id].core));
	if (type == InstrSet_ARM) {
		ret = arm_op_parse(virtual_cpu.cores[core_id].core.current_code,
				p_decoded_code, &optype);
	} else if (type == InstrSet_Thumb) {
		printf("ERROR: thumb mode is not supported yet..\n");
		printf("Decode Error\n");
		return STD_E_DECODE;
	}
	else {
		printf("ERROR: %d mode is not supported yet..\n", type);
		printf("Decode Error\n");
		return STD_E_DECODE;
	}
	if (ret != 0) {
		printf("Decode Error\n");
		return STD_E_DECODE;
	}

	permission = cpu_has_permission(core_id,
			READONLY_MEMORY,
			CpuMemoryAccess_EXEC,
			cpu_get_pc(&virtual_cpu.cores[core_id].core),
			0);
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
	uint32 inx = -1;
	CachedOperationCodeType *cached_code;

	if (virtual_cpu.cores[core_id].core.is_halt == TRUE) {
		return STD_E_OK;
	}

	cached_code = virtual_cpu_get_cached_code(cpu_get_pc(&virtual_cpu.cores[core_id].core));
	if (cached_code != NULL) {
		inx = cpu_get_pc(&virtual_cpu.cores[core_id].core) - cached_code->code_start_addr;
	}
	if (inx == -1) {
		return STD_E_SEGV;
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
				0);
		if (permission == FALSE) {
			return STD_E_SEGV;
		}
#endif /* DISABLE_MEMPROTECT */
#if 0 /* for debug */
		if (cpu_get_pc(&virtual_cpu.cores[core_id].core) == 0x1800c838) {
			printf("Exec code[0]=0x%x code[1]=0x%x type_id=0x%x inx=%d func=%p, pc=0x%x\n",
					virtual_cpu.cores[core_id].core.current_code[0],
					virtual_cpu.cores[core_id].core.current_code[1],
					virtual_cpu.cores[core_id].core.decoded_code->type_id, inx, cached_code->codes[inx].op_exec,
					cpu_get_pc(&virtual_cpu.cores[core_id].core));
		}
#endif
		ret = cached_code->codes[inx].op_exec(&virtual_cpu.cores[core_id].core);
#ifdef CONFIG_STAT_PERF
		PROFSTAT_END(&op_exec_stat_table[code_id]);
#endif /* CONFIG_STAT_PERF */
		if (ret < 0) {
			printf("Exec cached_code Error code[0]=0x%x code[1]=0x%x type_id=0x%x, inx=%d func=%p, pc=0x%x\n",
					virtual_cpu.cores[core_id].core.current_code[0],
					virtual_cpu.cores[core_id].core.current_code[1],
					virtual_cpu.cores[core_id].core.decoded_code->type_id, inx, cached_code->codes[inx].op_exec,
					cpu_get_pc(&virtual_cpu.cores[core_id].core));
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


bool TakePhysicalIRQException(uint32 coreId)
{
	TargetCoreType *core = &virtual_cpu.cores[coreId].core;
	uint32 *status = cpu_get_status(core);

	core->is_halt = FALSE;

	if (CPU_STATUS_BIT_IS_SET(*status, CPU_STATUS_BITPOS_I)) {
		return FALSE;
	}
	uint32 new_lr_value = cpu_get_reg(core, CpuRegId_PC);
	if (!CPU_STATUS_BIT_IS_SET(*status, CPU_STATUS_BITPOS_T)) {
		new_lr_value -= 4U;
	}
	uint32 new_spsr_value = *status;
	uint32 vect_offset = 24U;

	*status = ((*status) & ~0x1F) | CpuSystemLevelEncoding_IRQ;
	uint32 *saved_status = cpu_get_saved_status(core);
	*saved_status = new_spsr_value;
	cpu_set_reg(core, CpuRegId_LR, new_lr_value);
	CPU_STATUS_BIT_SET(status, CPU_STATUS_BITPOS_I);

	//CPSR.IT = '00000000';
	//bits[15:10, 26:25]
	*status &= 0xF9FF03FF;

	//CPSR.J = '0'; CPSR.T = SCTLR.TE; // TE=0: ARM, TE=1: Thumb
	CPU_STATUS_BIT_CLR(status, CPU_STATUS_BITPOS_J);

	//CPSR.E = SCTLR.EE; // EE=0: little-endian, EE=1: big-endian
	// Branch to correct IRQ vector.
	//if SCTLR.VE == '1' then
	//IMPLEMENTATION_DEFINED branch to an IRQ vector;
	//else
	//BranchTo(ExcVectorBase() + vect_offset);
	BranchTo(&core->pc, ExcVectorBase() + vect_offset);
	return TRUE;
}
