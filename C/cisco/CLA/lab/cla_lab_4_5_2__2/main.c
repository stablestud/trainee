#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	puts("Enter 4 ip blocks.");

	char blocks[4][4];
	if (scanf("%s %s %s %s", blocks[0], blocks[1], blocks[2], blocks[3] ) != 4 )
		exit( EXIT_FAILURE );

	char string[16];

	sprintf(string, "%s.%s.%s.%s", blocks[0], blocks[1], blocks[2], blocks[3] );

	puts(string);

	return 0;
}
