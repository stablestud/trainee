#include <stdio.h>

double getMaxOfThree(double paramA, double paramB, double paramC)
{
	double max = paramA;
	if ( max < paramB )
		max = paramB;
	if ( max < paramC )
		max = paramC;

	return max;
}

int main(void)
{
	double tenValue = getMaxOfThree(5, 9, 10);
	double bigValue = getMaxOfThree(555.4, 555.3, 556.4);

	printf("Ten: %.2f\n", tenValue);
	printf("Bigest value: %.2f\n", bigValue);

	return 0;
}

