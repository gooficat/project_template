#include "direc.h"
#include "main.h"
#include <stdint.h>
#include <stdlib.h>

void ProcPutBytes(Block *b, uint8_t m)
{
	uint64_t v = strtoll(b->s, &b->s, 0);
	WriteBytes(b, &v, m);
};

const Directive DIRECTIVES[] = {
	{"byte", ProcPutBytes, 1},
	{"word", ProcPutBytes, 2},
	{"dword", ProcPutBytes, 4},
	{"qword", ProcPutBytes, 8},

};

const uint8_t N_DIRECTIVES = sizeof(DIRECTIVES) / sizeof(*DIRECTIVES);
