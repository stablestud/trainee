#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	printf("How much memory should I allocate?: ");
	int mem;
	scanf("%d", &mem );

	if (mem > 1024*1024) {
		fputs("Too much memory requested.\n", stderr );
		exit( EXIT_FAILURE );
	}

	char *memv = malloc(mem);

	for (int i = 0, j = 0; i < mem; i++, j++) {
		memv[i] = 'A' + j;
		if (24 < j)
			j = -1;
	}

	int i = 0;
	do {
		for (int j = 0; j < 40; j++) {
			if (i + j > mem)
				exit( EXIT_SUCCESS );

			printf("%c", memv[i + j] );
		}

		puts("");

		i += 40;
	} while (i < mem);


	return 0;
}
