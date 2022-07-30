#include <stdio.h>

enum month_enum {
	JAN=31, FEB=29,
       	MAR=31, APR=30,
       	MAY=31, JUN=30,
       	JUL=31, AUG=31,
       	SEP=30, OCT=31,
       	NOV=30, DEC=31
};

int months_days[] = {
	0,
	JAN,
       	JAN + FEB,
	JAN + FEB + MAR,
	JAN + FEB + MAR + APR,
	JAN + FEB + MAR + APR + MAY,
	JAN + FEB + MAR + APR + MAY + JUN,
	JAN + FEB + MAR + APR + MAY + JUN + JUL,
	JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG,
	JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG + SEP,
	JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG + SEP + OCT,
	JAN + FEB + MAR + APR + MAY + JUN + JUL + AUG + SEP + OCT + NOV,
};

int main(void)
{
	int day, month;
	scanf("%d %d", &day, &month);
	printf("The day of the year: %d\n", months_days[month - 1] + day);

	return 0;
}
