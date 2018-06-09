#include <iostream>
#include <string>
#include "StringValidator.h"

void printValid(StringValidator& validator, std::string input)
{
	std::cout << "The string '" << input << "' is " 
	          << (validator.isValid(input) ? "valid" : "invalid") << std::endl;
}

bool ExactValidator::isValid(std::string input)
{
        if ( container.length() == input.length() ) {
                for ( unsigned i = 0; i < container.length(); i++ ) {
                        if ( container[i] != input[i] )
                                return false;
                }

                return true;
        } else {
                return false;
        }
}

bool DummyValidator::isValid(std::string)
{
        return true;
}

bool MinLengthValidator::isValid(std::string input)
{
        if (input.length() >= length)
                return true;
        else    
                return false;
}

bool MaxLengthValidator::isValid(std::string input)
{
        if (input.length() <= length)
                return true;
        else
                return false;
}

bool PatternValidator::isValid(std::string input)
{
        if (input.length() < container.length())
                return false;

        for (unsigned i = 0, j = 0; i < input.length() - container.length() + 1; i++) {
                if (container[j] == 'D') {
                        if (input[i] >= '0' && input[i] <= '9') {
                                j++;
                        } else {
                                i -= j;
                                j = 0;
                        }
                } else if (container[j] == 'A') {
                        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z')) {
                                j++;
                        } else {
                                i -= j;
                                j = 0;
                        }
                } else if (container[j] == '?') {
                        j++;
                } else if (container[j] >= 'a' && container[j] <= 'z') {
                        if (input[i] == container[j] || input[i] == container[j] - 'A' || input[i] == container[j] + 'A') {
                                j++; 
                        } else {
                                i -= j;
                                j = 0;
                        }
                } else if (container[j] == input[i]) {
                        j++;
                } else {
                        i -= j;
                        j = 0;
                }
                        
                if (j == container.length())
                        return true;
        }
        
        return false;
}
