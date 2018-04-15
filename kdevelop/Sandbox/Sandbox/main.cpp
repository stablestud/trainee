#include <iostream>

struct X {
        int* pos;
};

void func ( X* damn )
{
        int* aux = damn->pos;

//         damn->pos = new int;

        delete[] aux;
}

int main ( void )
{
        X G;

        func ( &G );

        return 0;
}
