#include <stdio.h>

int main()
{
	char zero = '0';

	/*Your code*/
	for (int i = 1; i <= 9; i++)
		printf("'%d' - '%c' is: %d\n", i, zero, i - 0);

	printf("'%d' - '%c' is: %d\n", 0, zero, 0 - 0);
	return 0;
}

