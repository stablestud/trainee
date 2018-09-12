#include <stdio.h>

double square(double);

int main(void)
{
	printf("square of %.2f is %.2f\n", 2.00, square( 2.00 ));
	printf("square of %.2f is %.2f\n", 6.00, square( 6.00 ));
	printf("square of %.2f is %.2f\n", 2.50, square( 2.50 ));
	printf("square of %.2f is %.2f\n", 12.12 , square( 12.12  ));
	printf("square of %.2f is %.2f\n", 345.68, square( 345.68 )); 
}

double square(double val)
{
	return val * val;
}
