#ifndef STRINGVALIDATOR_H
#define STRINGVALIDATOR_H

#include <string>

/* Pure virtual/abstract class */
class StringValidator {
protected:
        std::string container;
public:
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
        DummyValidator(...) : StringValidator("") {};
        virtual bool isValid(std::string input);
};

class LengthValidator : public StringValidator {
protected:
        unsigned length;
public:
        LengthValidator(unsigned length) : StringValidator(""), length(length) {};
        virtual bool isValid(std::string input) = 0;
};

class MinLengthValidator : public LengthValidator {
public:
        MinLengthValidator(unsigned length) : LengthValidator(length) {};
        virtual bool isValid(std::string input);
};

class MaxLengthValidator : public LengthValidator {
public:
        MaxLengthValidator(unsigned length) : LengthValidator(length) {};
        virtual bool isValid(std::string input);
};

class PatternValidator : public StringValidator {
public:
        PatternValidator(std::string input) : StringValidator(input) {};
        virtual bool isValid(std::string input);
};

void printValid(StringValidator&, std::string);
#endif
