#include <iostream>
#include <string>
#include "fraction.h"

int main ( void )
{
        int numerator, denominator;
        std::string rest;

        std::cin >> numerator >> rest >> denominator;

        Fraction x ( numerator, denominator );
        std::cout << x.toString() << std::endl;

        return 0;
}
