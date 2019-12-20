#include "concrete_executor/target/dbg_target_cpu.h"
#include "cpu.h"
#include "symbol_ops.h"

#include <stdio.h>


static void print_register(const char* regname, uint32 addr, char* opt)
{
	 uint32 funcaddr;
	 int funcid;
	 uint32 gladdr;
	 int glid;

	 funcid = symbol_pc2funcid(addr, &funcaddr);
	 if (funcid >= 0) {
		printf("%s		0x%x %s(+0x%x)", regname, addr, symbol_funcid2funcname(funcid), addr - funcaddr);
	 }
	 else {
		glid = symbol_addr2glid(addr, &gladdr);
		if (glid >= 0) {
			printf("%s		0x%x %s(+0x%x)", regname, addr, symbol_glid2glname(glid), addr - gladdr);
		}
		else {
			printf("%s		0x%x", regname, addr);
		}
	 }
	 if (opt != NULL) {
		 printf(" %s\n", opt);
	 }
	 else {
		 printf("\n");
	 }
	return;
}

void dbg_target_print_cpu(uint32 coreId)
{
	int i;
	uint32 pc;
	char buffer[128];

	printf("***CPU<%d>***\n", coreId);
	pc = virtual_cpu.cores[coreId].core.pc;

	print_register("PC", pc, NULL);
	for (i = 0; i < CpuRegId_NUM; i++) {
		 char *opt = NULL;
		 sprintf(buffer, "R%d", i);
		 print_register(buffer, cpu_get_reg(&virtual_cpu.cores[coreId].core, i), opt);
	 }
	 printf("CPSR		0x%x\n", *cpu_get_status(&virtual_cpu.cores[coreId].core));
	 return;
}
