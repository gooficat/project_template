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

typedef struct
{
	FILE *f;
	int C;
} Stream;

typedef struct
{
	Stream in;
	FILE *out;
	char line[LINE_MAX];
	char **s;
	uint64_t offset;
} Block;
