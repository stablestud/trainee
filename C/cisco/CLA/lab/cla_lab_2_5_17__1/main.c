#include <stdio.h>
int main()
{
	int day = 20;
	int month = 2;
	int year = 2016;
	printf("%04d-%02d-%02d - YYYY-MM-DD format - ISO 8601\n",
		year, month, day);
	printf("%02d-%02d-%04d - MM-DD-YYYY format\n",
		month, day, year);
	printf("%02d-%02d-%04d - DD-MM-YYYY format\n",
		day, month, year);
	printf("%d-%d-%d - D-M-Y format\n",
		day, month, year);
	return 0;
}

