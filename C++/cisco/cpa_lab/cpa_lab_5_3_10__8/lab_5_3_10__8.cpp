#include <string>
#include <iostream>
#include "Point2D.h"

std::string cleanString ( std::string input );

int main ( void )
{
	std::string input;
	std::getline ( std::cin, input );	

	input = cleanString ( input );

	std::cout << input << std::endl;

	return 0;
}

/* Read & filter input, allow to be delimetered by comma and space */
void readInput ( void )
{
	
}

std::string cleanString ( std::string input )
{
	for ( unsigned i = 0; i < input.length(); i++ )
		if ( input[i] < '0' || input[i] > '9' )
			input[i] = ' ';
			
	for ( unsigned i = input.length(); i > 0; i-- )
		if ( input[i] == ' ' && input[i - 1] == ' ' && i != 0 )
			input.erase ( i, 1 );

	for (; input[0] == ' ';)
		input.erase ( 0, 1 );

	return input;
}
