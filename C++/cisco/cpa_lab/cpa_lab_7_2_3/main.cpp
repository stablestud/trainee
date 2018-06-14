#include <iostream>
#include <exception>
#include <stdexcept>

float divKidd ( float v1, float v2 );
float divZero ( float v1, float v2 ) throw ( std::logic_error );

static const float DIVISION_BY_ZERO = 111;

int main()
{
	float a, b;
	while ( std::cin >> a ) {
		std::cin >> b;
		try { 
			std::cout << divZero ( a, b ) << std::endl;
		} catch ( std::logic_error& le ) {
			std::cerr << le.what() << std::endl;
		}

		try {
			std::cout << divKidd ( a, b ) << std::endl;
		} catch ( ... ) {
			std::cerr << "Are you kidding?" << std::endl;
		}
	}
}

float divZero ( float v1, float v2 ) throw ( std::logic_error )
{
	if ( 0 == v2 )
		throw std::logic_error ( "Division by Zero!" );
	
	return v1 / v2;
}

float divKidd ( float v1, float v2 )
{
	if ( 0 == v2 )
		throw DIVISION_BY_ZERO;

	return v1 / v2;
}
