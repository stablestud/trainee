#include <iostream>
#include "IntWithBoundaries.h"

typedef IntWithBoundaries twb;
int operator+ ( int, twb& );
int operator- ( int, twb& );
int operator* ( int, twb& );
int operator/ ( int, twb& );

int main()
{
	try {
		twb value1 ( 5, 0, 10 );
		twb value2 ( 9, 0, 100 );
		try {
			std::cout << ( value1 += 15 ).getValue() << std::endl;
		} catch ( IntWithBoundExcep& iwbe ) {
			std::cout << iwbe.what() << std::endl;
		}

		try {
			std::cout << ( value2 += 15 ).getValue() << std::endl;
		} catch ( IntWithBoundExcep& iwbe ) {
			std::cout << iwbe.what() << std::endl;
		}

		try {
			std::cout << ( value1 += 90 ).getValue() << std::endl;
		} catch ( IntWithBoundExcep& iwbe ) {
			std::cout << iwbe.what() << std::endl;
		}

		try {
			std::cout << ( value2 += 90 ).getValue() << std::endl;
		} catch ( IntWithBoundExcep& iwbe ) {
			std::cout << iwbe.what() << std::endl;
		}

		std::cout << "value1 = " << value1.getValue() << std::endl;
		std::cout << "value2 = " << value2.getValue() << std::endl;

	} catch ( IntWithBoundExcep& iwbe ) {
		std::cout << iwbe.what() << std::endl;
	}
}

int operator+ ( int v, twb& obj )
{
	return v + obj.getValue();
}

int operator- ( int v, twb& obj )
{
	return v - obj.getValue();
}

int operator* ( int v, twb& obj )
{
	return v * obj.getValue();
}

int operator/ ( int v, twb& obj )
{
	return v / obj.getValue();
}
