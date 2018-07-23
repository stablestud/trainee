#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>


int main(int argc, char* argv[])
{
	if (argc != 2) {
		fputs("I require exactly one filename"
		"as parameter where I should write to.\n", stderr);
		return 1;
	}

	FILE* outp = fopen(argv[1], "wb");

	if (NULL == outp) {
		fprintf(stderr, "sandbox: %s: %s\n", argv[1], strerror(errno));
		return 1;
	}

	fprintf(outp, "%s %s %s", __TIME__, argv[1], "on"__DATE__);

	char* input = malloc(sizeof(char) * 256);
	while (!feof(stdin)) {
		input[0] = '\0';
		fgets(input, 256, stdin);
		fwrite(input, 1, strlen(input), outp);
	}
	fclose(outp);
}
