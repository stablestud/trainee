#ifndef STRINGVALIDATOR_H
#define STRINGVALIDATOR_H

#include <string>

/* Pure virtual/abstract class */
class StringValidator {
protected:
        std::string container;
public:
        StringValidator() {};
        StringValidator(std::string input) : container(input) {};
        virtual ~StringValidator() {};
        virtual bool isValid(std::string input) = 0;
};

class ExactValidator : public StringValidator {
public:
	ExactValidator(std::string input) : StringValidator(input) {};
        virtual bool isValid(std::string input);
};

class DummyValidator : public StringValidator {
public:
        DummyValidator() {};
        virtual bool isValid(std::string input);
};

void printValid(StringValidator&, std::string);
#endif
