#include <stdio.h>

int main()
{
	char zero = '0';

	/*Your code*/
	for (char i = '1'; i <= '9'; i++)
		printf("'%c' - '%c' is: %d\n", i, zero, i - '0');

	printf("'%c' - '%c' is: %c\n", zero, zero, zero);
	return 0;
}

