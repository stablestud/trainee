#include <iostream>
#include "IntWithBoundaries.h"

typedef IntWithBoundaries twb;

int main()
{
	try {
		twb value1 ( 0, 0, 1000 );
		twb value2 ( 9, 5, 150 );
		try {
			std::cout << ( value1 += 19 ) << std::endl;
			std::cout << ( value1 /= value2 ) << std::endl;
			std::cout << ( value1 *= value2 *= value1 ) << std::endl;
			std::cout << "value1: " << value1.getValue() << std::endl;
			std::cout << "value2: " << value2.getValue() << std::endl;

		} catch ( IntWithBoundExcep& iwbe ) {
			std::cout << iwbe.what() << std::endl;
		}

	} catch ( IntWithBoundExcep& iwbe ) {
		std::cout << iwbe.what() << std::endl;
	}
}
