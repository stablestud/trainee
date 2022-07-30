#include <stdio.h>

int main()
{
	float studentAYear1 = 4.2;
	float studentAYear2 = 4.5;
	float studentAYear3 = 4.2;

	float studentBYear1 = 4.3;
	float studentBYear2 = 4.4;
	float studentBYear3 = 4.7;

	float studentCYear1 = 4.3;
	float studentCYear2 = 4.8;
	float studentCYear3 = 4.9;

	/* your code */
	puts("Student name	Year 1	Year 2	Year 3	Average");
	printf("StudentA:	%.2f	%.2f	%.2f	%.2f\n",
		studentAYear1,
		studentAYear2,
		studentAYear3,
		(studentAYear1 + studentAYear2 + studentAYear3) / 3);
	printf("StudentB:	%.2f	%.2f	%.2f	%.2f\n",
		studentBYear1,
		studentBYear2,
		studentBYear3,
		(studentBYear1 + studentBYear2 + studentBYear3) / 3);
	printf("StudentC:	%.2f	%.2f	%.2f	%.2f\n",
		studentCYear1,
		studentCYear2,
		studentCYear3,
		(studentCYear1 + studentCYear2 + studentCYear3) / 3);

	return 0;
}

