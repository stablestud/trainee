#include <string>
#include "Fraction.h"

Fraction::Fraction ( int numerator, int denominator )
{
	this -> numerator = numerator;
	this -> denominator = denominator;
}

std::string Fraction::toString ( void )
{
	bool minus = false;

	if ( denominator < 0 ) {
		minus = true;
		denominator = ~denominator + 1;
	}

	int rest = numerator % denominator, carry = numerator / denominator;	
	std::string prefix;
	
	if ( carry != 0 && rest < 0 ) {
		rest = ~rest + 1;
		minus = true;
	} else if ( carry == 0 &&  minus == true )
		rest = ~rest - 1;

	if ( carry != 0 ) {
		if ( minus == true )
			carry = ~carry - 1;

		prefix = std::to_string ( carry ) + " ";
	}

	return prefix + std::to_string ( rest ) + "/" + std::to_string ( denominator );
}

double Fraction::toDouble ( void )
{
	return numerator / (double)denominator;
}

Fraction Fraction::plus ( Fraction that )
{
	return that;
}

Fraction Fraction::minus ( Fraction that )
{
	return that;
}

Fraction Fraction::times ( Fraction that )
{
	that.numerator = this -> numerator * that.numerator;
	that.denominator = this -> denominator * that.denominator;

	return that;
}

Fraction Fraction::by ( Fraction that )
{
	return that;
}
