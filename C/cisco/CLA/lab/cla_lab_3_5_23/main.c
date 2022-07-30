#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	printf("Input number to get nibbles: ");

	int input;
	scanf("%d", &input );

	printf("lower nibble: %d\n", input & 0xF );
	printf("upper nibble: %d\n", ( input & 0xF0 ) >> 4 );

	return 0;
}
