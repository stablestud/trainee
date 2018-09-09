#include <stdio.h>

int main( void )
{
	int arr[12] = { 1, 1 };

	for (int i = 0; i < 10; i++) {
		arr[i + 2] = arr[i] + arr[i + 1];
	}

	for (int i = 0; i < 12; i++)
		printf("%d\n", arr[i]);

	for (int i = 0; i < 12; i++)
		if (arr[i] & 1)
			printf("%d\n", arr[i]);

	for (int i = 0; i < 12; i++)
		if ((arr[i] ^ 1) & 1)
			printf("%d\n", arr[i]);


	return 0;
}
