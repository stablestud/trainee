#include "myexception.h"

const char* MyException::what ( void ) const noexcept
{
	static const char negative[] = "negative";
	for ( unsigned i = 0; std::logic_error::what()[i] != '\0'; i++ ) {
		if ( std::logic_error::what()[i] == negative[i] ) {
			if ( 7 <= i )
				return "Value can't be negative!";
		}
	}

	static const char zero[] = "zero";
	for ( unsigned i = 0; std::logic_error::what()[i] != '\0'; i++ ) {
		if ( std::logic_error::what()[i] == zero[i] ) {
			if ( 3 <= i )
				return "Value can't be zero!";
		}
	}

	return "Couldn't assign error";
}
