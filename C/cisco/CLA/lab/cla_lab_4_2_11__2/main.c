#include <stdio.h>

int main( void )
{
	char arr[26];

	for (char i = 'a'; i <= 'z'; i++)
		arr[i - 'a'] = i;

	for (int i = 25; i >= 0; i--)
		printf("%c\n", arr[i]);

	char *find = "great";

	do {
		int i = 0;
		for (; arr[i] != *find; i++);
		printf("%c", arr[i]);
	} while (*(++find));

	puts("");

	return 0;
}
