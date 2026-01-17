#pragma once

#include <stdint.h>

#define MAX_OPS 4
#define MNEM_MAX 12
#define MAX_ARG 4

typedef enum
{
	REG_BYTE,
	REG_WORD,
	REG_DWOR,
	REG_QWOR,
	REX_EBYT,
	REG_EWOR,
	REG_EDWD
} RegType;

typedef struct
{
	const char *name;
	RegType type : 5;
	uint8_t code : 3;
} Reg;

typedef enum
{
	ARG_NON,
	ARG_MEM,
	ARG_IMM,
	ARG_REG
} ArgType;

typedef struct
{
	Reg *base;
	Reg *indx;
	uint8_t scal;
	int64_t disp;
} MemArg;

typedef struct
{
	ArgType type : 2;
	union {
		Reg *reg;
		uint64_t imm;
		MemArg mem;
	};
} Arg;

typedef struct
{
	char mnem[MNEM_MAX];
} Ins;

typedef enum
{
	PRM_MEM = 1,
	PRM_REG = 1 << 1,
	PRM_SRG = 1 << 2,
	PRM_IMM = 1 << 3,
	PRM_REL = 1 << 4,
	PRM_ABS = 1 << 5,
} ParamType;
typedef enum
{
	PRM_BYT = 1,
	PRM_WOR = 1 << 1,
	PRM_DWO = 1 << 2,
	PRM_QWO = 1 << 3,
} ParamSize;
typedef enum
{
	FLD_OPC,
	FLD_REG,
	FLD_RM,
	FLD_DISP,
} ParamField;

typedef struct
{
	ParamType type : 5;
	ParamSize size : 3;
	ParamField field : 8;
} Param;

typedef struct
{
	uint8_t opcodes[MAX_OPS];
	Param params[MAX_ARG];
} Opcode;

typedef struct
{
	const char *mnemonic;
	uint16_t idx;
	uint8_t num;
} OpClass;
