#include <stdio.h>

int main()
{
	int day, month, year, total = 0;

	scanf("%d %d %d", &day, &month, &year);

	int month_tbl[12] = {
		 [0] = 0,
		 [1] = 31,
		 [2] = 31 + 28,
		 [3] = 31 + 28 + 31,
		 [4] = 31 + 28 + 31 + 30,
		 [5] = 31 + 28 + 31 + 30 + 31,
		 [6] = 31 + 28 + 31 + 30 + 31 + 30,
		 [7] = 31 + 28 + 31 + 30 + 31 + 30 + 31,
		 [8] = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31,
		 [9] = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
		[10] = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
		[11] = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
	};


	/* because you may not know the else instruction yet,
	this simple formula will help you to check if a year is a leap year */
	if (year % 400 == 0) {
		if (month > 2)
			++total;
	} else if (year % 100 == 0) {}
	else if (year % 4 == 0) {
		if (month > 2)
			++total;
	}

	total += day + month_tbl[month - 1];

	printf("The day of the year: %d\n", total);

	return 0;
}
