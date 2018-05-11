#include <iostream>
#include <string>
#include "Fraction.h"

int main (void)
{
	int numerator, denominator;
	std::string trash;
	std::cin >> numerator >> trash >> denominator;

	Fraction fraction ( numerator, denominator );

	std::cout << fraction.toString() << " is in decimal: " << fraction.toDouble() << std::endl;

	return 0;
}
