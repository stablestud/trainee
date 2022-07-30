#include <stddef.h>
#include <stdio.h>

ptrdiff_t function( int *const volatile restrict, int *const restrict, size_t );

int main( void )
{
	int variable1, variable2;
	ptrdiff_t ptrdiff = function( &variable1, &variable2, sizeof( ptrdiff_t ));
	printf("Pointer difference is: %td\n", ptrdiff);
	printf("Sizeof ptrdiff_t:      %zu\n", sizeof( ptrdiff_t ));
	printf("Sizeof size_t:         %zu\n", sizeof( size_t ));
}

ptrdiff_t function( int *const volatile restrict var1, int *const restrict var2, size_t length )
{
	return var2 - var1;
}
