#include <iostream>
#include <exception>
#include <stdexcept>
#include "draughts.h"

int main ( void )
{

	try {
                Field field1;
		field1.create ( new Knight ( true ), new pos { 1, 1 } );
		field1.printTable();
                field1.move ( new pos { 1, 1 }, new pos { 2, 2 } );
		std::cout << std::endl;
		field1.printTable();
	} catch ( std::exception& err ) {
		std::cout << err.what() << std::endl;
	}
        std::cout << std::endl;

        try {
                Field field2;
                field2.create ( new King ( 1 ), new pos { 1, 1 } );
                field2.printTable();
                field2.move ( new pos { 1, 1 }, new pos { 3, 3 } );
		std::cout << std::endl;
                field2.printTable();
        } catch ( std::exception& err ) {
                std::cout << err.what() << std::endl;
        }
        std::cout << std::endl;

        try {
                Field field3;
                field3.create ( new Knight ( 1 ), new pos { 1, 1 } );
                field3.printTable();
                field3.move ( new pos { 1, 1 }, new pos { 3, 3 } );
		std::cout << std::endl;
                field3.printTable();
        } catch ( std::exception& err ) {
                std::cout << err.what() << std::endl;
        }

	return 0;
}
