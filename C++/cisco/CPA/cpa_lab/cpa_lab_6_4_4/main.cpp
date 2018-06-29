#include <iostream>
#include <string>
#include "StringValidator.h"

int main()
{
        DummyValidator dummy;
        printValid(dummy, "hello");
        std::cout << std::endl;
        ExactValidator exact("secret");
        printValid(exact, "hello");
        std::cout << std::endl;
        printValid(exact, "secret");
        std::cout << std::endl;

        return 0;
}
