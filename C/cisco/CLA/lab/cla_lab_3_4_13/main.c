#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main( void )
{
	int input, total = 0;
	bool exitv = false;

	while ( scanf("%d", &input ) == 1 ) {
		total += input;

		if ( exitv && input == 0 ) {
			puts("Finish.");
			exit( EXIT_SUCCESS );
		}

		if ( input == 0 )
			break;
		else if ( input == 99 )
			exitv = true;
	}

	printf("%d\n", total );
}
