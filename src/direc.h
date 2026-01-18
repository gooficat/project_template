#pragma once

#include "main.h"
#include <stdint.h>

typedef struct
{
	const char *name;
	void (*proc)(Block *b, uint8_t m);
	uint8_t magic;
} Directive;

extern const Directive DIRECTIVES[];
extern const uint8_t N_DIRECTIVES;
