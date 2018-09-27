#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdnoreturn.h>

bool checkip(char *string);
void invalip(char *string);
void valip(char *string);

int main(void)
{
	char string[20] = {};
	fgets( string, 20, stdin );

	if (!checkip( string ))
		invalip( string );
	else
		valip( string );


	return 0;
}

bool checkip(char *string)
{
	short strln = strlen( string );

	if (string[strln - 1] == '\n')
		string[--strln] = '\0';

	if (strln > 15 || strln < 7) {
		return false;
	}

	short block[4] = {};

	for (int i = 0, bl = 0, slb = 0; i < strln + 1; ++i) {
		if (string[i] == '.') {
			if (slb < 1 || slb > 3) {
				return false;
			} else {
				++bl;
				slb = 0;
			}
		} else if (string[i] == '\0') {
			if (bl != 3 || slb < 1 || slb > 3)
				return false;
			else
				break;
		} else if (string[i] >= '0' && string[i] <= '9') {
			block[bl] = block[bl] * 10 + (string[i] - '0');
			++slb;
		} else {
			return false;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (block[i] > 255 || block[i] < 0)
			return false;
	}

	return true;
}

void invalip(char *string)
{
	printf("%s is not a valid IP address.\n", string );

	return;
}

void valip(char *string)
{
	printf("%s is a valid IP address.\n", string );

	return;
}
