#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define LINE_MAX 1024

typedef struct
{
	char *name;
	uint64_t offset;
	bool global;
} Label;

enum Pass
{
	PASS_LABEL,
	PASS_ALIGN,
	PASS_WRITE,
};

typedef struct
{
	FILE *in, *out;
	enum Pass pass;
	char line[LINE_MAX];
	char **s;
	uint64_t offset;
} Block;
