#include <stdio.h>
#include <stdlib.h>

int main()
{
	char names[4][20];

	if (scanf("%s %s %s %s", names, names + 1, names + 2, names + 3) != 4) {
		fputs("Err: reading input.", stderr );
		exit( EXIT_FAILURE );
	}

	for (int i = 3; i >= 0; i--)
		puts(names[i]);

	return 0;
}
