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

bool RangeValidator::isValid(std::string input)
{
        if (min.isValid(input) && max.isValid(input))
                return true;
        else
                return false; 
}

bool PatternValidator::isValid(std::string input)
{
        if (input.length() < container.length())
                return false;

        bool reset = false;

        for (unsigned i = 0, j = 0; i < input.length() - container.length() + 1; i++) {
                if (container[j] == 'D') {
                        if (input[i] >= '0' && input[i] <= '9')
                                j++;
                        else
                                reset = true;
                } else if (container[j] == 'A') {
                        if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
                                j++;
                        else
                                reset = true;
                } else if (container[j] == '?') {
                        j++;
                } else if (container[j] == 'U') {
                        if (input[i] >= 'A' && input[i] <= 'Z')
                                j++;
                        else
                                reset = true;
                } else if (container[j] == 'L') { 
                        if (input[i] >= 'a' && input[i] <= 'z')
                                j++;
                        else
                                reset = true;
                } else if (container[j] == 'X') {
                        if ((input[i] >= '!' && input[i] <= '/') || (input[i] >= ':' && input[i] <= '@') || (input[i] >= '[' && input[i] <= '`') || (input[i] >= '{' && input[i] <= '~'))
                        {
                                std::cout << "x true = " << input[i] << std::endl;
                                j++;
                        }
                        else
                                reset = true;
                } else if (container[j] >= 'a' && container[j] <= 'z') {
                        if (input[i] == container[j] || input[i] == container[j] - 'A' || input[i] == container[j] + 'A')
                                j++; 
                        else 
                                reset = true;
                } else if (container[j] == input[i]) {
                        j++;
                } else {
                        reset = true;
                }
                        
                if (reset) {
                        i -= j;
                        j = 0;
                        reset = false;
                }

                if (j == container.length())
                        return true;
        }
        
        return false;
}

bool PasswordValidator::isValid(std::string input)
{
        if (range.isValid(input) && digit.isValid(input) && lower_case.isValid(input) && upper_case.isValid(input) && special_character.isValid(input))
                return true;
        else
                return false;
}
