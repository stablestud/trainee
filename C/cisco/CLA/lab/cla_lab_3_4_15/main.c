#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int input;

	if (scanf("%d", &input) != 1) {
		fputs("Failed to read input.\n", stderr );
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < input+1; i++) {
		for (int j = 0; j < i; j++)
			printf("*#");
		puts("");
	}
}
