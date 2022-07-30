#include <stdio.h>
#include <stdlib.h>

#include "ntriangle.h"

#define MODULE "ntriangle"

int ntriangle(int size)
{
	if (size < 0 || size > 20) {
		fprintf( stderr, MODULE": Can't print triangle of size %d.\n",
			size );
		return 1;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (i + 1); j++)
			printf("\\");
		puts("");
	}

	return 0;
}
