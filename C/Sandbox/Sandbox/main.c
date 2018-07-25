#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>


double calc_circle_area(double radius, double unused1)
{
	return(3.14*radius*radius);
}

calc_any_area(double (*pFunc)(double, double))
{
	double result = (*pFunc)(12.4, 0);     // call using function pointer
	return(result);
}

void calcArea()
{
	double (*calc_area)(double, double)=&calc_circle_area;
	calc_any_area(&calc_area);
}

int main(void)
{
	return 0;
}
