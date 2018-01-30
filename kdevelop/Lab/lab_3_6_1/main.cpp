#include <iostream>

void increment ( int &, int by = 10 );

int main ( void )
{
        int var = 0;
        for ( int i = 0; i < 10; i++ )
                if ( i % 2 )
                        increment ( var );
                else
                        increment ( var, i );
        std::cout << var << std::endl;
        return 0;
}

void increment ( int &value, int by )
{
        value *= by;
}
