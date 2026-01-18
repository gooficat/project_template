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
	PASS_LABEL = 0b01,
	PASS_ALIGN = 0b10,
	PASS_WRITE = 0b11,
};

typedef struct
{
	FILE *in, *out;
	enum Pass pass;
	char line[LINE_MAX];
	char *s;
	uint64_t offset;
} Block;

void WriteBytes(Block *b, const void *bytes, size_t n);
