#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	printf("%s: Number of arguments: %d\n",argv[0],argc - 1);

	if (argc >= 2 && !strcmp(argv[1],"-v")) {
		puts("args v0.0");
		return 0;
	}

	for (int i = 1; i < argc; i++)
		puts(argv[i]);

	return 0;
}
