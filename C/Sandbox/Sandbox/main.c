#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <stdalign.h>

int main( void )
{
	char **strings = (void *)0x122311112;

	*strings = "Hello";
	*(strings + 1) = "World";
}
