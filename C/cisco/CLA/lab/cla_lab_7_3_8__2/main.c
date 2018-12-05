#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	/* Count whitespaces, tabs, lines, and all lower case characters */

	FILE *count = fopen( "main.c", "rt" );
	if ( NULL == count ) {
		fprintf( stderr, "%s\n", strerror( errno ));
		return 1;
	}

	char buffer[512];

	struct {
		int lines;
		int characters;
		int whitespaces;
		int letters[26];
	} stats = { 1 };

	while ( fgets( buffer, 512, count ) != NULL ) {
		char *pos = buffer;
		stats.lines++;
		while (*pos++) {
			stats.characters++;
			if (*pos == ' ' || *pos == '	')
				stats.whitespaces++;
			else if (*pos >= 'a' && *pos <= 'z')
				stats.letters[*pos - 'a']++;
		}
	}

	if (errno) {
		fputs( strerror( errno ), stderr );
		fputs("\n", stderr );
		return 1;
	}

	printf("Lines: %d\n", stats.lines );
	printf("Characters: %d\n", stats.characters );
	printf("Whitespaces: %d\n", stats.whitespaces );
	printf("a: %d\n", stats.letters[ 0] );
	printf("b: %d\n", stats.letters[ 1] );
	printf("c: %d\n", stats.letters[ 2] );
	printf("d: %d\n", stats.letters[ 3] );
	printf("e: %d\n", stats.letters[ 4] );
	printf("f: %d\n", stats.letters[ 5] );
	printf("g: %d\n", stats.letters[ 6] );
	printf("h: %d\n", stats.letters[ 7] );
	printf("i: %d\n", stats.letters[ 8] );
	printf("j: %d\n", stats.letters[ 9] );
	printf("k: %d\n", stats.letters[10] );
	printf("l: %d\n", stats.letters[11] );
	printf("m: %d\n", stats.letters[12] );
	printf("n: %d\n", stats.letters[13] );
	printf("o: %d\n", stats.letters[14] );
	printf("p: %d\n", stats.letters[15] );
	printf("q: %d\n", stats.letters[16] );
	printf("r: %d\n", stats.letters[17] );
	printf("s: %d\n", stats.letters[18] );
	printf("t: %d\n", stats.letters[19] );
	printf("u: %d\n", stats.letters[20] );
	printf("v: %d\n", stats.letters[21] );
	printf("w: %d\n", stats.letters[22] );
	printf("x: %d\n", stats.letters[23] );
	printf("y: %d\n", stats.letters[24] );
	printf("z: %d\n", stats.letters[25] );

	return 0;
}
