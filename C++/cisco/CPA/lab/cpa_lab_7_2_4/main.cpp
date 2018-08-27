#include <iostream>
#include "myexception.h"

void print ( std::exception& );
float square_area ( float );
float rectangle_area ( float, float );

int main (void)
{
	float a, b;
	std::cin >> a >> b;

	float rsquare;
	try {
		rsquare = square_area ( a );
		std::cout << "square: " << rsquare << std::endl;
	} catch ( std::exception& ex ) {
		print ( ex );
	}

	float rrectangle;
	try {
		rrectangle = rectangle_area ( a, b );
		std::cout << "rectange: " << rrectangle << std::endl;
	} catch ( std::exception& ex ) {
		print ( ex );
	}
}

void print ( std::exception& ex )
{
	std::cout << ex.what() << std::endl;
}

float square_area ( float a )
{
	if ( 0 == a )
		throw MyException ( "zero" );
	if ( 0 > a )
		throw MyException ( "negative" );

	return a * a;
}

float rectangle_area ( float a, float b )
{
	if ( 0 == a || 0 == b )
		throw MyException ( "zero" );
	if ( 0 > a || 0 > b )
		throw MyException ( "negative" );

	return a * b;
}
