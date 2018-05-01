#include <iostream>

int main ( void )
{
        int mai[3] { 1, 2, 3 };

        for ( int i = 0; i < 3; i++) {
                std::cout << "&(mai + " << i << ") hat die addresse: " << &mai + i << std::endl;
                std::cout << "mai + " << i << " zeight auf: " << mai + i << std::endl;
                std::cout << std::endl;
        }
}
