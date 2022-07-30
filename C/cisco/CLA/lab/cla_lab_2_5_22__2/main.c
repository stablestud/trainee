#include <stdio.h>

int main(void)
{
	float v1, v2;
	scanf("%f %f", &v1, &v2);

	printf("Value A: %f\n", v1);
	printf("Value B: %f\n", v2);
	printf("%f + %f = %f\n", v1, v2, v1 + v2);
	printf("%f - %f = %f\n", v1, v2, v1 - v2);
	printf("%f * %f = %f\n", v1, v2, v1 * v2);
	return 0;
}
