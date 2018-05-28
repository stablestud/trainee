#include <iostream>
#include <exception>

int func ( int, int ) throw ( int, float );
void handler ( void );

int main ( void )
{
        std::set_unexpected ( handler );
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
        try {
                throw 'a';
        } catch ( const char* all ) {}

        return 0;
}

int func ( int a, int b ) throw ( int, float ) {
        throw 333;
        try {
        if ( a / b == 0 )
                throw float(b);
        else throw a / b;
        } catch ( int bae) {
                std::cout << bae << " got caugth! " << std::endl;
        }
        std::cout << "no more excep. " << std::endl;
        return a / b;
};

void handler ( void )
{
        std::cout << "Upps!" << std::endl;
}
