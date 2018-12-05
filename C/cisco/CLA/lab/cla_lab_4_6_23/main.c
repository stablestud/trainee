#include <stdio.h>

int main( void )
{
	printf("%ld byte for chars.\n", sizeof( char ));
	char c;
	printf("%ld byte for char variables.\n", sizeof c );
	printf("%ld bytes for shorts.\n", sizeof( short ));
	short s;
	printf("%ld bytes for short variables.\n", sizeof s );
	printf("%ld bytes for ints.\n", sizeof( int ));
	int i;
	printf("%ld bytes for int variables.\n", sizeof i );
	printf("%ld bytes for longs.\n", sizeof( long ));
	long l;
	printf("%ld bytes for long variables.\n", sizeof l );
	printf("%ld bytes for long longs.\n", sizeof( long long ));
	long long ll;
	printf("%ld bytes for long long variables.\n", sizeof ll );
	printf("%ld bytes for floats.\n", sizeof( float ));
	float f;
	printf("%ld bytes for float variables.\n", sizeof f );
	printf("%ld bytes for doubles.\n", sizeof( double ));
	double d;
	printf("%ld bytes for double variables.\n", sizeof d );
	printf("%ld bytes for long doubles.\n", sizeof( long double ));
	long double ld;
	printf("%ld bytes for long double variables.\n", sizeof ld );
	printf("%ld bytes for pointers.\n", sizeof( void * ));
	void *p;
	printf("%ld bytes for pointer variables.\n", sizeof p );
	printf("%ld bytes for address of char variable.\n", sizeof &c );
	char *cp = &c;
	printf("%ld bytes for pointer to char variable.\n", sizeof cp );
	printf("%ld byte got value stored by pointer to char variable.\n", sizeof *cp );

	return 0;
}
