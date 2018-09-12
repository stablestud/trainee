#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	FILE *main_c = fopen("main.c", "rt");  
	if ( NULL == main_c ) {
		fprintf( stderr, "main.c: %s\n", strerror( errno ));
		return 1;
	}

	FILE *copy_main_c = fopen("copy_main.c", "wt");
	if ( NULL == copy_main_c ) {
		fprintf( stderr, "copy_main.c: %s\n", strerror( errno ));
		return 1;
	}

	char buffer[512];
	int line = 0;

	while (fgets( buffer, 512, main_c ) != NULL) {
		if (fprintf( copy_main_c, "%2d: ", ++line ) == EOF) {
			fprintf( stderr, "copy_main_c: Couldn't write "
					"line number %2d.\n", line );
			break;
		}

		if (fputs(buffer, copy_main_c ) == EOF) {
			fprintf( stderr, "copy_main_c: Couldn't write string "
					"'%s'.\n", buffer );
			break;
		}
	}

	if (errno) {
		fputs( strerror( errno ), stderr );
		fputs("\n", stderr );
		return 1;
	}

	return 0;
}
