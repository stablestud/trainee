#ifndef STRINGVALIDATOR_H
#define STRINGVALIDATOR_H

#include <string>

/* Pure virtual/abstract class */
class StringValidator {
protected:
        std::string container;
public:
        StringValidator(std::string input = "") : container(input) {};
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
        virtual bool isValid(std::string input);
};

/* Pure virtual/abstract class */
class LengthValidator : public StringValidator {
protected:
        unsigned length;
public:
        LengthValidator(unsigned length = 0) : length(length) {};
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

class RangeValidator : public LengthValidator {
private:
        MinLengthValidator min;
        MaxLengthValidator max;
public:
        RangeValidator(unsigned min, unsigned max) : min(min), max(max) {};
        virtual bool isValid(std::string input);
};

class PatternValidator : public StringValidator {
public:
        PatternValidator(std::string input) : StringValidator(input) {};
        virtual bool isValid(std::string input);
};

class PasswordValidator : public StringValidator {
private:
        RangeValidator range;
        PatternValidator digit;
        PatternValidator lower_case;
        PatternValidator upper_case;
        PatternValidator special_character;
public:
        PasswordValidator(...) : StringValidator(), range(8, 8), digit("D"), lower_case("L"), upper_case("U"), special_character("X") {};
        virtual bool isValid(std::string input);
};

void printValid(StringValidator&, std::string);

#endif
