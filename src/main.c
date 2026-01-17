#include "main.h"
#include <stdio.h>

void Pass(Block *b)
{
	while (fgets(b->line, LINE_MAX, b->in))
	{
		printf("%s", b->line);
	}
}

void Assemble(const char *in_path, const char *out_path)
{
	Block b;
	fopen_s(&b.in, in_path, "rt");
	b.pass = PASS_LABEL;

	while (b.pass != PASS_WRITE)
	{
		Pass(&b);
		fseek(b.in, 0, SEEK_SET);
		b.offset = 0;
	}
	fopen_s(&b.out, out_path, "wb");
}

int main(int argc, char *argv[])
{
	Assemble("C:/Users/User/Documents/cpp/poem/poem/test.ps", "C:/Users/User/Documents/cpp/poem/poem/test.bin");
}
