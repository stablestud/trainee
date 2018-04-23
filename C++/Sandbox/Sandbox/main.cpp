#include <iostream>

int main ( void )
{
        char street[8];

        for ( int i = 0; i < 8; i++ )
                street[i] = 'X';

        std::cin >> street;

        for ( int i = 0; i < 10; i++ )
                std::cout << "[" << i << "]: '" <<  street[i] << "'" << std::endl;
        return 0;
}
