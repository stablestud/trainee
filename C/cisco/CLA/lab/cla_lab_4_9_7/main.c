#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strtoint(char *string);
void tonextptr(char **ptr);

int main(void)
{
	char string[16];
	char *ptr = string;
	fgets( string, 16, stdin );
	
	int b1, b2, b3, b4;

	b1 = strtoint( ptr );

	tonextptr( &ptr );

	b2 = strtoint( ptr );

	tonextptr( &ptr );

	b3 = strtoint( ptr );

	tonextptr( &ptr );

	b4 = strtoint( ptr );


	if (b1 > 255 || b1 < 0 ||
	    b2 > 255 || b2 < 0 ||
	    b3 > 255 || b3 < 0 ||
	    b4 > 255 || b4 < 0)
	{
		fputs("Invalid IP.\n", stderr );
		exit( EXIT_FAILURE );
	}

	printf("Last 3 parts: %d.%d.%d\n", b2, b3, b4);
	printf("Last 2 parts: %d.%d\n", b3, b4);
	printf("Last 1 part: %d\n", b4);

	return 0;
}

int strtoint(char *string)
{
	int val = 0, i = 0;
	while (string[i] != '.' && string[i] != 0 && string[i] != 0xA) {
		if (string[i] < '0' || string[i] > '9' || i > 2) {
			fputs("Invalid IP.\n", stderr );
			exit( EXIT_FAILURE );
		}

		val = val * 10 + string[i++] - '0';
	}

	return val;
}

void tonextptr(char **ptr)
{
	while(*(*ptr)++ != '.') {
		if (**ptr == 0) {
			fputs("Invalid IP.\n", stderr );
			exit( EXIT_FAILURE );
		}
	}

	return;
}
