#include <stdio.h>

#include "ntriangle.h"
#include "floyd.h"


int main(void)
{
	printf("%s:%d(%s): Asking for input.\n", __FILE__, __LINE__, __func__ );
	printf("Enter size of traingles (0-20): ");

	int size;

	if( scanf( "%d", &size ) != 1 ) {
		fprintf( stderr, "Invalid size: %d", size );
		return 1;
	}

	ntriangle(size);
	puts("");
	floyd(size);

	return 0;
}
