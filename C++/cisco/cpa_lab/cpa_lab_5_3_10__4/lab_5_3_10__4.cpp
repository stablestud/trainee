#include <string>
#include <iostream>
#include <vector>
#include "membership.h"

int main ( void )
{
	std::string input;
	std::vector<membership*> array (1) = { NULL };	

	while ( input != "quit" && input != "q" ) {
		std::getline ( std::cin, input );
		
		if ( input.find ( "create" ) != std::string::npos && input.find_first_of ( "create" ) == 0 ) {
				
	}
}
