#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	enum monthse {
		JAN = 31, FEB = 29, MAR = 31,
		APR = 30, MAY = 31, JUN = 30,
		JUL = 31, AUG = 31, SEP = 31,
		OCT = 30, NOV = 30, DEC = 30
	};

	printf("Input month number: ");

	int input;
	scanf("%d", &input );

	int days = 0;

	switch (input) {
	case 12:
		days += NOV;
	case 11:
		days += OCT;
	case 10:
		days += SEP;
	case  9:
		days += AUG;
	case  8:
		days += JUL;
	case  7:
		days += JUN;
	case  6:
		days += MAY;
	case  5:
		days += APR;
	case  4:
		days += MAR;
	case  3:
		days += FEB;
	case  2:
		days += JAN;
	case  1:
		break;
	default:
		fputs("Err: no such month in my calendar.\n", stderr );
		exit( EXIT_FAILURE );
	}

	printf("There a %d days between the given month\n", days );

	return 0;
}
