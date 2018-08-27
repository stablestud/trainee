#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char buffer[32] = {};

	for (unsigned i = 0xFFFFFFF; i > 0; i--) {
		strncpy(buffer, argv[1], 32);
		__asm__ __volatile__("");
	}

	puts(buffer);

	return 0;
}
