#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char buffer[32] = {};

	for (volatile unsigned i = 0xFFFFFFF; i > 0; i--) {
			//strncpy(buffer, argv[1], 32);
			buffer[0] = strlen(argv[1]);
			__asm__ __volatile__("");
	}

	//puts(buffer);
	printf("%d", buffer[0]);

	return 0;
}
