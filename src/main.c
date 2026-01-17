#include "main.h"

void Assemble(const char *in_path, const char *out_path)
{
	Block b;
	fopen_s(&b.in.f, in_path, "rt");
	fopen_s(&b.in.f, out_path, "wb");

	//
}

int main(int argc, char *argv[])
{
}
