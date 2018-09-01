#include <stdio.h>
#include <string.h>

volatile char *volatile string = "This is a test string...";

int main(int argc, char *argv[])
{
	char buffer[32] = {};
	
	for (volatile unsigned i = 0xFFFFFFF; i > 0; i--) {
			strncpy(buffer, string, 32);
			__asm__ __volatile__("");
	}

	puts(buffer);

	return 0;
}
