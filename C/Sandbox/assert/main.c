#include <assert.h>
#include <limits.h>
#include <stdalign.h>
#include <stdlib.h>
#include <stdio.h>

#define generic _Generic
#define X(X) Q(X)
#define Q(X) #X
//#define NDEBUG

// Set line to 0 and file name to expanded macro X(__STDC__)
#line 0 X(__STDC__)

double func1( int hello )
{
	puts( "func1 (int)" );
	return 2.0;
}

int func2( double g )
{
	printf("Hello"__TIME__" at "__FILE__": %d\n", __LINE__);
	return 7;
}

int main( void )
{
	puts("hello -"X(__STDC_VERSION__));
	alignas(8) int i = 9;

	/* GCC attribute */
	// keyword _Alignas can only align on declaration, not on type definition 
	__attribute__((aligned(8))) struct X {
		char p;
	}; 


	double X = 9;

	printf( "struct X: %ld\n", __alignof__( struct X ));
	printf( "int i: %ld\n", alignof( i ));

	/* Better place _Generic in a macro */
	double value = 	_Generic( X,
				  double: func2(X),
				  long: func1(X),
				  int: func1(X)
			);
	printf( "%f\n", value );

	/* Macro is available as long NDEBUG is not defined */
	assert( sizeof( char ) >= 2 );
}
