#include <iostream>

int main( void ) {
        long number = 0;
        long auxNumber = 0;
        std::cout << "Number range: ";
        std::cin >> number;
        for ( long i = 1L; i <= number; i++ )
                auxNumber += i;
        std::cout << "result: " << auxNumber << std::endl;
        return 0;
}
