#include "main.h"
#include <stdio.h>

void HandleDirective(Block *b)
{
	char tok[32];
	int i;
	sscanf_s(b->s, " .%s %n", tok, 32, &i);
	b->s += i;
	printf("%s %s\n", tok, b->s);

	// for
}

void Pass(Block *b)
{
	while (fgets(b->line, LINE_MAX, b->in))
	{
		b->s = &b->line[0];
		// printf("%s", b->s);
		if (*b->s == '.')
		{
			HandleDirective(b);
		}
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

void WriteBytes(Block *b, const void *bytes, size_t n)
{
	if (b->pass == PASS_WRITE)
		fwrite(bytes, 1, n, b->out);
	b->offset += n;
}
