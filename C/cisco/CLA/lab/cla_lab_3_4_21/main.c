#include <stdlib.h>
#include <stdio.h>

int main( void )
{
	puts("Enter size of structure: ");

	int size;

	if ( scanf("%d", &size ) != 1 ) {
		fputs("Err: reading input.\n", stderr );
		exit( EXIT_FAILURE );
	}

	{
		for ( int i = 0; i < size; i++ ) {
			printf("*");
			for ( int j = 0; j < i; j++ )
			       printf(" ");	
			puts("*");
		}
	}

	{
		for ( int i = size - 1; i >= 0; i-- ) {
			printf("*");
			for ( int j = i; j > 0; j-- )
			       printf(" ");	
			puts("*");
		}
	}

	return 0;
}
