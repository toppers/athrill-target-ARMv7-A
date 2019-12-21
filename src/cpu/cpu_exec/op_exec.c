#include "op_exec.h"

OpExecType op_exec_table[arm_OpCodeId_Num] = {
	{ 7, NULL },		/* add */
	{ 1, NULL },		/* push */
};

