#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void err(void);
char *nextdot(char *string);

int main(void)
{
	printf("Enter IP address to check: ");

	char ip[16];

	scanf("%s", ip);

	char *s = ip;
	int dots = 0;

	do {
		if (*s == '.')
			dots++;
		else if ((*s < '0') || (*s > '9'))
			err();
	} while (*++s);

	if (dots != 3)
		err();

	s = ip;
	int b1, b2, b3, b4;

	sscanf(s, "%d", &b1);
	s = nextdot(s);

	sscanf(s, "%d", &b2);
	s = nextdot(s);

	sscanf(s, "%d", &b3);
	s = nextdot(s);

	sscanf(s, "%d", &b4);

	if (	b1 < 0 || b1 > 255
	     || b2 < 0 || b2 > 255
	     || b3 < 0 || b2 > 255
	     || b4 < 0 || b4 > 255)
	{
		printf("%d.%d.%d.%d is not a valid IP.\n", b1, b2, b3, b4);
		exit( EXIT_FAILURE );
	} else {
		printf("%d.%d.%d.%d is a valid IP.\n", b1, b2, b3, b4);
	}

	return 0;
}

_Noreturn void err(void) 
{
	fputs("Invalid IP.\n", stderr );
	exit( EXIT_FAILURE );
}

char *nextdot(char *string)
{
	while (*string) {
		if (*string++ == '.')	
			return string;
	}
	
	err();
}
