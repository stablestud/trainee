#include <stdalign.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

int main( int agrc, char *argv[] )
{
	int *mem = malloc( sizeof( int ));

	/* calloc( count, size ) */
	int *cal = calloc( 2, sizeof( int ));

	int *new = realloc( NULL, sizeof( int ));

	/* aligned_alloc( alignment, size )
	 * C11, in my testing it does not obbey the setting, probably because I'm reading
	 * wrongly the alignment of the type */
	int *align = aligned_alloc( 8, sizeof( int )); 

	*mem = INT_MAX;
	*(long *)cal = LONG_MAX;
	*cal = INT_MAX;
	*new = INT_MAX;

	printf("*mem: %d, alignof: %zu\n", *mem, alignof( *mem ));
	printf("*cal: %d, alignof: %zu\n", *cal, alignof( *cal ));
	printf("*(long *)cal: %ld, alignof: %zu\n", *(long *)cal, alignof( *(long *)cal ));
	printf("*new: %p: %d, alignof: %zu\n", new, *new, alignof( *new ));
	printf("*align: %d, alignof: %zu\n", *align, alignof( *align ));

	int *tmp = realloc( new, 28 ); 

	if ( NULL == tmp )
		puts("realloc to new size failed.");
	else if ( new == tmp )
		puts("realloc extended current memory field.");
	else
		puts("realloc had to copy the content to a new memory area.");

	new = tmp;

	free( mem );
	free( cal );

	printf("*new: %p: %d\n", new, *new );

	if ( NULL == realloc( new, 0 ))
		puts("realloc returned NULL after truncating size to zero.");

	if ( NULL == ( tmp = realloc( new, 4 ))) {
		puts("realloc returned NULL while extending from zero.");
		if ( errno )
			printf("%s: %s: %s\n", argv[0], "realloc", strerror( errno ));
	} else if ( tmp == new )
		puts("realloc allocated memory specified by me");
	else
		puts("realloc ignored current memory and allocated a different, new memory space.");

	printf("*new: %p: %d\n", new, *new );

	if ( NULL == ( tmp = realloc( new, 23 )))
		puts("realloc to new size failed.");
	else if ( tmp == new )
		puts("realloc extended current memory field.");
	else
		puts("realloc had to copy the content to a new memory area.");

	printf("*new: %p: %d\n", new, *new );

	free( tmp );

	if ( errno )
		printf("%s: %s: %s\n", argv[0], "realloc", strerror( errno ));

	return 0;
}
