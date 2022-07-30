#include <iostream>

int main ( void )
{
        int x;
        std::cout << (unsigned char)x << (unsigned char)*(&x + 3);
}
