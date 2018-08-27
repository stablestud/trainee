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

	std::cout << fraction1.toString() << "  +  " << fraction2.toString() << "  =  " << fraction1.plus ( fraction2 ).toString() << std::endl;
	std::cout << fraction1.toString() << "  -  " << fraction2.toString() << "  =  " << fraction1.minus ( fraction2 ).toString() << std::endl;
	std::cout << fraction1.toString() << "  *  " << fraction2.toString() << "  =  " << fraction1.times ( fraction2 ).toString() << std::endl;
	std::cout << fraction1.toString() << "  /  " << fraction2.toString() << "  =  " << fraction1.by ( fraction2 ).toString() << std::endl;

	return 0;
}
