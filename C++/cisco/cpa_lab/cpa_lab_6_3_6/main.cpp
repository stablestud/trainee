#include <iostream>
#include <exception>
#include <stdexcept>
#include "draughts.h"

int main ( void )
{
	try {
		Field field1;
		field1.create ( new Figure ( true ), new pos { 1, 1 } );
		field1.printTable();
		field1.move ( new pos { 1, 1 }, new pos { 7, 7 } );
		std::cout << std::endl;
		field1.printTable();
	} catch ( std::exception& err ) {
		std::cout << err.what() << std::endl;
	}

	return 0;
}
