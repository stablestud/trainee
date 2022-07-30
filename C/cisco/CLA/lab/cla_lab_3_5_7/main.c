#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	printf("Enter year to test for leap: ");

	int year;

	if ( scanf("%d", &year ) != 1 ) {
		fputs("Failed to read input.", stderr );
		exit( EXIT_FAILURE );
	}

	printf("%d is ", year );

	if ( year % 400 == 0 ) {
	} else if ( year % 100 == 0 ) {
not_leap:
		printf("not ");
	} else if ( year % 4 == 0 ) {
	} else {
		goto not_leap;
	}

	puts("a leap year.");
	return 0;
}
