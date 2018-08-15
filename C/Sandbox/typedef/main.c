#include <stdio.h>
#include <stdalign.h>

typedef struct {
	char i, k, o, r, a, w, e, m;
	int L;
} S;

void func( S x )
{

}


typedef int wochen[52];

int main( void )
{
	printf("sizeof S: %zu\n", sizeof(S));
	printf("alignof S: %zu\n", alignof(S));
	wochen (*const jahr)[4];
	func( jahr );
}
