#include <stdio.h>

int stringCompare(char *x, char *y)
{
	int i;
	for (i = 0; x[i] != 0 && y[i] != 0 ; i++) {
		if(x[i] > y[i]) {
			return 1;
		} else if (x[i] < y[i]) {
			return -1;
		}
	}

	if (x[i] == 0) {
		if (y[i] == 0)
			return 0;
		else
			return -1;
	} else {
		return 1;
	}
}

int main(void)
{
	int result1 = stringCompare("AAA", "BBB");
	int result2 = stringCompare("AAC", "AAB");
	int result3 = stringCompare("AAC", "AAC");
	int result4 = stringCompare("AAC", "AACC");

	printf("result1: %d\n", result1);
	printf("result2: %d\n", result2);
	printf("result3: %d\n", result3);
	printf("result4: %d\n", result4);

	return 0;
}
