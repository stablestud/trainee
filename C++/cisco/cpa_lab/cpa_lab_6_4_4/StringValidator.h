#ifndef STRINGVALIDATOR_H
#define STRINGVALIDATOR_H

#include <iostream>
#include <string>

/* Pure virtual/abstract class */
class StringValidator {
public:
        virtual ~StringValidator() {};
        virtual bool isValid(std::string input) = 0;
};

// Code apparently here
class ExactValidator {
public:
        virtual bool isValid(std::string input);
};

class DummyValidator {
public;
        virtual bool isValid(std::string input);
};

#endif
