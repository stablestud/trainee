#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{	
	if (argc != 2) {
	fputs("I need exactly one parameter.\n", stderr);
		return 1;
	}

	if (!strcmp(argv[1], "-v")) {
		printf("Compiled on %s at %s\n", __DATE__, __TIME__);
		return 0;
	}

	FILE *fparam = fopen(argv[1],"rt");

	printf("%s: %s [%d]\n", argv[0], strerror(errno), errno);
	if (fparam == NULL || errno)
		return 2;

	printf("Content of %s:\n", argv[1]);
	/* NOT TRUE (equal) -> *//* fgetc() is slower than fgets() */
	//for (char tmp_char; (tmp_char = (char)fgetc(fparam)) != -1 ; printf("%c", tmp_char));
	for (char tmp_str[100]; NULL != fgets(tmp_str, 100, fparam); printf("%s", tmp_str));
	printf("%s: %s [%d]\n", argv[0], strerror(errno), errno);

	while(fclose(fparam));
}
