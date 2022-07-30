#include <stdio.h>

#include "extern.h"

void func(char* string)
{
	puts(string);
}

char* storage = "No non no!";

char array[] = {
	[0] = 56,
	[100] = 9,
	[10 * 9] = 90
};

void call( void )
{
	printf("Sizeof array[]: %ld\n", sizeof(array));
}
