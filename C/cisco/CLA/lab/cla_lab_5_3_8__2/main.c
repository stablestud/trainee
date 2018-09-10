#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	printf("Enter a weekdays number: ");

	int day;
	scanf("%d", &day );

	if (day > 7 || day <= 0) {
		fputs("Err, no such day.\n", stderr );
		exit( EXIT_FAILURE );
	}

	char *arr[7] = {
		"Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday",
		"Saturday", "Sunday"
	};

	printf("arr: %s\n", arr[day - 1] );
	printf("ptr: %s\n", *(arr + day - 1 ));

	return 0;
}
