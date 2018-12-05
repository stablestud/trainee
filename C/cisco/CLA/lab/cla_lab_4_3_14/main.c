#include <stdio.h>
#include <stdbool.h>

int main()
{
	float numbers[10] = {5.6, 4.3, 6.2, 6.4, 7.3, 2.3, 8.3, 9.2, 0.1, 1.9};
	bool changed = false;

	do {
		changed = false;

		for (int i = 0; i < 9; i++) {
			if (numbers[i] > numbers[i + 1]) {
				float aux = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = aux;
				changed = true;
			}
		}

		/* Print */
		for (int i = 0; i < 10; i++)
			printf("%.2f ", numbers[i]);

		puts("");
	} while (changed);

	return 0;
}

