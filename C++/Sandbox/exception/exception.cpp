#include <iostream>
#include <exception>

int func ( int, int );

int main ( void )
{
        int a, b;

        try {
        std::cin >> a >> b;
        if ( std::cin.fail() )
                throw float(33 & 12);
        throw func ( a, b );
        std::cout << "Hello World!" << std::endl;
        std::cout << a / b << std::endl;
        } catch ( float a ) {
                std::cout << "!" << a << std::endl;
        } catch ( int excep ) {
                std::cout << "damn " << excep << std::endl;
        }
        
        return 0;
}

int func ( int a, int b ) {
        return a / b;
};
