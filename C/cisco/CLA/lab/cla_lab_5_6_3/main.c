#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("Enter number to show mul. table: ");

	int numbr;
	if ( 1 != scanf("%d", &numbr)) {
		fputs("Err: Invalid Input.\n", stderr );
		exit( EXIT_FAILURE );
	}

	if (numbr < 1 || numbr > 20) {
		fputs("Err: Invalid number.\n", stderr );
		exit( EXIT_FAILURE );
	}

	int **arr = malloc(sizeof(void *) * numbr);

	for (int i = 0; i < numbr; i++)
		arr[i] = malloc(sizeof(int) * numbr);

	for (int i = 0; i < numbr; i++) {
		for (int j = 0; j < numbr; j++)
			arr[i][j] = (i + 1) * (j + 1);
	}

	for (int i = 0; i < numbr; i++) {
		for (int j = 0; j < numbr; j++)
			printf("%d	", arr[i][j] );
		puts("");
	}

	return 0;
}
