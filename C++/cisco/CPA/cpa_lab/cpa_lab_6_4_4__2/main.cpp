#include <iostream>
#include <string>
#include "StringValidator.h"

int main()
{
        DummyValidator dummy;
        printValid(dummy, "hello");
        ExactValidator exact("secret");
        printValid(exact, "hello");
        printValid(exact, "secret");
        std::cout << std::endl;
        std::cout << "MinLengthValidator" << std::endl;
        MinLengthValidator min(6);
        printValid(min, "hello");
        printValid(min, "welcome");
        std::cout << "MaxLengthValidator" << std::endl;
        MaxLengthValidator max(6);
        printValid(max, "hello");
        printValid(max, "welcome");
        std::cout << std::endl;
        std::cout << "PatternValidator" << std::endl;
        PatternValidator digit("D");
        printValid(digit, "there are 2 types of sentences in the world");
        printValid(digit, "valid and invalid ones");
        std::cout << std::endl;

        return 0;
}
