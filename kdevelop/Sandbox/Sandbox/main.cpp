#include <iostream>

using namespace std;

void f ( int** );

int main ( void )
{
        int* creme = nullptr;
        if ( creme == nullptr )
                f(&creme);
        cout << *creme << endl;
}

void f ( int** x )
{
        if ( *x == nullptr )
                cout << "Oh no a nullptr!" << endl;
        *x = new int;
        **x = 3;
}
