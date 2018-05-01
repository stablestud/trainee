#include <iostream>
#include <vector>
#include <string>
#include "membership.h"

int main ( void ) {
	std::string input;
	while ( input != "quit" ) {
		std::getline ( std::cin, input );

		if (( input.find ( "create" ) != std::string::npos ) && ( input.find_first_of ( "create" ) == 0 ))
			std::cout << "Found create!" << std::endl;
	}

        return 0;
}

void create ( void )
{




}
