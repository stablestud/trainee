#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	FILE *read = fopen("main.c", "rt");
	if (NULL == read) {
		fprintf( stderr, "main.c: %s\n", strerror( errno ));
		return 1;
	}
	char writeTo[] = "copy_main";

	FILE *write;
	int fails = 0;
	while (!(write = fopen( writeTo, "wt" ))) {
		if (fails > 9) {
			fputs("File limit reached.\n", stderr );
			return 1;
		}

		fprintf( stderr, "Failed to open %s,",
			writeTo );

		writeTo[strlen( writeTo ) - 1] = fails++ + '0';
		fprintf( stderr, " trying %s.\n", writeTo );
	}

	clearerr(write);
	char buffer[512];

	while (fgets( buffer, 512, read ) != NULL) {
		if (fputs( buffer, write ) == EOF)
			break;
	}

	if (ferror( write )) {
		fputs( strerror( errno ), stderr );
		fputs("\n", stderr );
		return 1;
	}

	return 0;
}
