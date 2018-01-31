#include <iostream>

using namespace std;

void function ( int, int );

int main ( void )
{
        int *pointer;
        for ( int i = 0; i < 6; i++  ) {
        int elem;

        cin >> elem;

        function ( pointer, elem );


        }

        return 0;
}


void function ( int &pointer, int value )
{

}
