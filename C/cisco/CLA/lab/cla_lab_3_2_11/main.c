#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned b1, b2, b3, b4;
	if ( scanf("%u %u %u %u", &b1, &b2, &b3, &b4 ) != 4 ) {
		fprintf( stderr, "Err: Couldn't read input ...\n" );
		exit( EXIT_FAILURE );
	}

	if ( b1 > 255 || b2 > 255 || b3 > 255 || b4 > 255 ) {
		fputs("Invalid IP address.\n", stderr );
		exit( EXIT_FAILURE );
	}

	printf("%u.%u.%u.%u\n", b1, b2, b3, b4 );
	printf("%u\n", b1 * 256 * 256 * 256 + b2 * 256 * 256 + b3 * 256 + b4 );
}
