#include <stdio.h>

int main(void)
{
	int dayOfWeek = 1;
	char *day;

	/* your code */
	switch (dayOfWeek) {
	case 1:
		day = "Monday";
		break;
	case 2:
		day = "Tuesday";
		break;
	case 3:
		day = "Wednesday";
		break;
	case 4:
		day = "Thursday";
		break;
	case 5:
		day = "Friday";
		break;
	case 6:
		day = "Saturday";
		break;
	case 7:
		day = "Sunday";
		break;
	default:
		day = "Unspecified";
		break;
	}
			
	printf("The day of the week is %s\n", day);
	return 0;
}

