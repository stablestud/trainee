#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *convval(char *v1, char *v2);

int main(int argc, char *argv[])
{
	if (argc != 4) {
		fputs("Invalid amount of paramters.\n", stderr );
		exit( EXIT_FAILURE );
	}

	if (strlen(argv[1]) != 3) {
		fprintf( stderr, "Invalid operation '%s'.\n", argv[1] );
		exit( EXIT_FAILURE );
	}

	int *var;

	if (!(var = convval( argv[2], argv[3] ))) {
		fputs("Invalid numbers.\n", stderr );
		exit( EXIT_FAILURE );
	}

	if (!strncmp( argv[1], "add", 3 )) {
		printf("add: %d + %d = %d\n", var[0], var[1],
			      	var[0] + var[1] );
	} else if (!strncmp( argv[1], "sub", 3 )) {
		printf("sub: %d - %d = %d\n", var[0], var[1],
			      	var[0] - var[1] );
	} else if (!strncmp( argv[1], "mul", 3 )) {
		printf("mul: %d * %d = %d\n", var[0], var[1],
				var[0] * var[1] );
	} else if (!strncmp( argv[1], "div", 3 )) {
		printf("div: %d / %d = %d\n", var[0], var[1],
			       	var[0] / var[1] );
	} else {
		fputs("Unknown operation.\n", stderr );
		exit( EXIT_FAILURE );
	}

	return 0;
}

int *convval(char *v1, char *v2)
{
	static int val[2] = {};

	if (sscanf( v1, "%d", val ) != 1)
		return NULL;
	else if (sscanf( v2, "%d", val + 1 ) != 1)
		return NULL;
	else
		return val;
}
