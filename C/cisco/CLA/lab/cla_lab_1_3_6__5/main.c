#include <stdio.h>

int main()
{
	int daysInCurrentFebruary = 28;
	int daysInJanuary = 31;
	int daysInFebruary = daysInCurrentFebruary;
	int daysInMarch = 31;
	int daysInApril = 30;
	int daysInMay = 31;
	int daysInJune = 30;
	int daysInJuly = 31;
	int daysInAugust = 31;
	int daysInSeptember = 30;
	int daysInOctober = 31;
	int daysInNovember = 30;
	int daysInDecember = 31;

	int daysInFirstQuarter = daysInJanuary
			 + daysInFebruary + daysInMarch;
	int daysInSecondQuarter = daysInApril
			+ daysInMay + daysInJune;

	int daysInThirdQuarter = daysInJuly + daysInAugust
			+ daysInSeptember;
	int daysInFourthQuarter = daysInOctober
			+ daysInNovember + daysInDecember;

	printf("Days in the first  quarter: %d\n", daysInFirstQuarter);
	printf("Days in the second quarter: %d\n", daysInSecondQuarter);
	printf("Days in the third  quarter: %d\n", daysInThirdQuarter);
	printf("Days in the fourth quarter: %d\n", daysInFourthQuarter);
	printf("Days in the current year: %d\n", daysInFirstQuarter + daysInSecondQuarter + daysInThirdQuarter + daysInFourthQuarter);

	return 0;
}
