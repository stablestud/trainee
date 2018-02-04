#include <iostream>


using namespace std;

int main ( void )
{
        int pointer[4] { 1, 6, 2, 9 };
        int *pointer2 = new int [4];
        pointer2 = pointer;
        cout << sizeof ( &pointer2 + 1 ) / sizeof ( pointer [ 0 ] ) << " elements ... " << endl;
        delete[] pointer2;
        pointe2 = new int [5];
        pointe2 = pointer;
        pointer2[4] = 7;
        cout << sizeof ( pointer ) / sizeof ( pointer [ 0 ] ) << " elements ... " << endl;
        int array[3];
        cout << sizeof ( array ) << " " << sizeof ( array[0] ) << endl;
        delete[] pointer2;
        return 0;
}
