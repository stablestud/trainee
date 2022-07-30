#include <iostream>
#include <string>
#include "FarmAnimal.h"
#include "ConsumptionAccumulator.h"

std::string cleanString ( std::string input );
unsigned findFirstOf ( std::string input, char character );

int main ( void )
{
	ConsumptionAccumulator accumulator;
	char action;

	do {
		std::string input;
		std::getline ( std::cin, input ); 
		action = input[0];
		input = cleanString ( input );
		unsigned value = 0;

		if ( input != "" )
			value = std::stoi ( input );

		if ( input == "" ) {
			std::cout << accumulator.getTotalConsumption() << std::endl;
		} else if ( action == 'h' || action == 'H' ) {
			FarmAnimal animal ( value / 100 * 6.8 );
			accumulator.addConsumption ( animal );
		} else if ( action == 'c' || action == 'C' ) {
			FarmAnimal animal ( value / 100 * 8.6 );
			accumulator.addConsumption ( animal );
		} else if ( action == 's' || action == 'S' ) {
			FarmAnimal animal ( value / 10 * 1.1 );
			accumulator.addConsumption ( animal );
		}

	} while ( action != 'q' );

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

	return 0;
}
