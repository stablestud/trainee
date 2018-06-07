#include <iostream>
#include <string>
#include "StringValidator.h"

printValid(StringValidator& validator, std::string input)
{
	std::cout << "The string '" << input << "' is " 
	          << (validator.isValid("hello") ? "valid" : "invalid");
}
