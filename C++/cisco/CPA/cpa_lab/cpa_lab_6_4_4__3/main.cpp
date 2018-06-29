#include <iostream>
#include <string>
#include "StringValidator.h"

int main()
{
        std::cout << "DummyValidator" << std::endl;
        DummyValidator dummy;
        printValid(dummy, "hello");
        std::cout << std::endl;
        std::cout << "ExactValidator" << std::endl;
        ExactValidator exact("secret");
        printValid(exact, "hello");
        printValid(exact, "secret");
        std::cout << std::endl;
        std::cout << "MinLengthValidator" << std::endl;
        MinLengthValidator min(6);
        printValid(min, "hello");
        printValid(min, "welcome");
        std::cout << std::endl;
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
        std::cout << "RangeValidator" << std::endl;
        RangeValidator range(5, 8);
        printValid(range, "cheese");
        printValid(range, "Agnuskanaraless");
        printValid(range, "010");
        std::cout << std::endl;
        std::cout << "PasswordValidator" << std::endl;
        PasswordValidator password;
        printValid(password, "Cheki/a8");
        printValid(password, "oklolSss");
        printValid(password, "Chek/0");
        printValid(password, "che[]KSS");
        printValid(password, "assaS88j");
        printValid(password, "6{]HJKHH");
        printValid(password, "82/(asds");
        return 0;
}
