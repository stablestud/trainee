#include <stdio.h>

#include "floyd.h"

#define MODULE "floyd"

int floyd(int size)
{
	if (size < 0 || size > 20) {
		fprintf( stderr, MODULE": Can't print triangle of size %d.\n",
			size );
		return 1;
	}

	int floyd = 1;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (i + 1); j++, floyd++)
			printf( "%4d", floyd );
		puts("");
	}

	return 0;
}
