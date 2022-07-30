#include <iostream>
#include <string>
#include "StringValidator.h"

void printValid(StringValidator& validator, std::string input)
{
	std::cout << "The string '" << input << "' is " 
	          << (validator.isValid(input) ? "valid" : "invalid");
}

bool ExactValidator::isValid(std::string input)
{
        if ( container.length() == input.length() ) {
                for ( unsigned i = 0; i < container.length(); i++ )
                        if ( container[i] != input[i] )
                                return false;
                return true;
        } else {
                return false;
        }
}

bool DummyValidator::isValid(std::string)
{
        return true;
}
