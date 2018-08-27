#include <string>
#include <iostream>
#include "Fraction.h"

Fraction::Fraction ( int numerator, int denominator )
{
	this -> numerator = numerator;
	this -> denominator = denominator;
}

double Fraction::toDouble ( void )
{
	return (double) this -> numerator / this -> denominator;
}

std::string Fraction::toString ( void )
{
	if ( denominator < 0 ) {
		this -> numerator = ~this -> numerator + 1;
		this -> denominator = ~this -> denominator + 1;
	}
	reduce();

	std::string suffix, prefix;
	int carry = this -> numerator / this -> denominator;
	int rest = this -> numerator % this -> denominator;

	if ( carry ) {
		prefix = std::to_string ( carry );

		if ( rest < 0 )
			rest = ~rest + 1;

	} else if ( !carry && !rest )
		prefix = "0";
		

	if ( rest )
		suffix = std::to_string ( rest ) + "/" + std::to_string ( this -> denominator );	

	if ( carry && rest )
		prefix += " ";

	return prefix + suffix;
}
	
void Fraction::reduce ( void )
{
	int n = this -> numerator, m = this -> denominator, r;

	while (( r =  m % n )) {
		m = n;
		n = r;
	}
	
	if ( n < 0 )
		n = ~n + 1;
	
	this -> numerator /= n;
	this -> denominator /= n;
}

Fraction Fraction::plus ( Fraction that )
{
	Fraction one ( this -> numerator, this -> denominator ), two ( that.numerator, that.denominator );

	that.denominator = one.denominator * two.denominator;

	one.numerator *= two.denominator;
	two.numerator *= one.denominator;

	that.numerator = one.numerator + two.numerator;

	return that;
}

Fraction Fraction::minus ( Fraction that )
{
	Fraction one ( this -> numerator, this -> denominator ), two ( that.numerator, that.denominator );

	that.denominator = one.denominator * two.denominator;

	one.numerator *= two.denominator;
	two.numerator *= one.denominator;

	that.numerator = one.numerator - two.numerator;

	return that;
}

Fraction Fraction::times ( Fraction that )
{
	that.numerator *= this -> numerator;
	that.denominator *= this -> denominator;
		
	return that;
}
 
Fraction Fraction::by ( Fraction that )
{
	int aux = that.denominator;
	that.denominator = that.numerator * this -> denominator;
	that.numerator = aux * this -> numerator;
	
	return that;
}
