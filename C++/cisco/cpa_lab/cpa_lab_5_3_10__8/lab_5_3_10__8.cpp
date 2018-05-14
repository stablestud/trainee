#include <string>
#include <iostream>
#include "Point2D.h"

std::string cleanString ( std::string input );
unsigned findFirstOf ( std::string input, char character );

int main ( void )
{
	std::string input;
	std::getline ( std::cin, input );	

	input = cleanString ( input );

	double x1, y1;

	x1 = std::stod ( input.substr ( 0, findFirstOf ( input, ' ' )));
	input = input.substr ( findFirstOf ( input, ' ' ) + 1 );

	y1 = std::stod ( input );

	Point2D f1 ( x1, y1 );

	/* Second line */
	std::getline ( std::cin, input );	

	input = cleanString ( input );

	double x2, y2;

	x2 = std::stod ( input.substr ( 0, findFirstOf ( input, ' ' )));
	input = input.substr ( findFirstOf ( input, ' ' ) + 1 );

	y2 = std::stod ( input );

	Point2D f2 ( x2, y2 );

	std::cout << "f1 to f2: " << f1.distanceTo ( f2 ) << std::endl;	
	return 0;
}

std::string cleanString ( std::string input )
{
	/* Remove all unnecessary characters except 0-9 and - and . */
	for ( unsigned i = 0; i < input.length(); i++ )
		if ( ( input[i] < '0' || input[i] > '9' ) && input[i] != '.' && input[i] != '-' )
			input[i] = ' ';
			
	for ( unsigned i = input.length(); i > 0; i-- )
		if ( input[i] == ' ' && input[i - 1] == ' ' && i != 0 )
			input.erase ( i, 1 );

	for (; input[0] == ' ';)
		input.erase ( 0, 1 );

	return input;
}

unsigned findFirstOf ( std::string input, char character )
{
	for ( unsigned i = 0; i < input.length(); i++ )
		if ( input[i] == character )
			return i;

	std::cout << "Nicht gefunden " << input.length() << " " << input << std::endl;
	return 0;
}
