#include <iostream>
#include <string>
#include "Fraction.h"

int main (void)
{
	int numerator, denominator;
	std::string trash;
	std::cin >> numerator >> trash >> denominator;

	Fraction fraction1 ( numerator, denominator );
	
	std::cin >> numerator >> trash  >> denominator;

	Fraction fraction2 ( numerator, denominator );

	std::cout << fraction1.toString() << " ";
	
	if ( fraction1.isEqual ( fraction2 ))
		std::cout << "=";
	else if ( fraction1.isGreaterThan ( fraction2 ))
		std::cout << ">";
	else if ( fraction1.isLessThan ( fraction2 ))
		std::cout << "<";
	
	std::cout << " " << fraction2.toString() << std::endl;

	return 0;
}
