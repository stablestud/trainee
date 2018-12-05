#include <stdio.h>

int main(void)
{
	int day;
	char *sday;

	printf("Please input the weekdays number: ");
	scanf("%d", &day);

	if (day & 7 && !(day & -8)) {
		char *csday[7] = { 
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday",
			"Sunday"
		};

		printf("The day is: %s\n", csday[day - 1]);
	} else {
		printf("No such day with number %d, "
			"valid range from 1 to 7!\n", day);
	}
}	
