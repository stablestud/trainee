#include <iostream>
#include <string>
#include "fraction.h"

Fraction::Fraction ( int numerator, int denominator )
{
	this -> numerator = numerator;
	this -> denominator = denominator;
}

std::string Fraction::toString ( void )
{
        int prefix = numerator / denominator;
        std::string sprefix = ( prefix ) ? std::to_string ( prefix ) + " " : "";
        int suffix = numerator % denominator; 
        std::string ssuffix = ( suffix ) ? std::to_string ( suffix ) + "/" + std::to_string ( denominator ) + " " : "";

	return sprefix + ssuffix + "is " + std::to_string ( this -> toDouble() ) + " in decimal.";
}

double Fraction::toDouble ( void )
{
	return (double)numerator / denominator;
}
