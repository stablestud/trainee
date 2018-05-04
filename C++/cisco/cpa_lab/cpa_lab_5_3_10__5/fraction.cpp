#include <iostream>
#include "fraction.h"

Fraction::Fraction ( int numerator, int denominator )
{
	this -> numerator = numerator;
	this -> denominator = denominator;
}

/*std::string Fraction::toString ( void )
{
	std::string output;

	return output;
}*/

double Fraction::toDouble ( void )
{
	return (double)denominator / numerator;
}
