#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char sptr[20];

	if (1 != scanf("%s", sptr )) {
		fputs("Err couldn't read input.\n", stderr );
		exit( EXIT_FAILURE );
	}

	for (int i = strnlen( sptr, 20 ); i >= 0; i--)
		printf("%c", sptr[i] );

	puts("");

	return 0;
}
