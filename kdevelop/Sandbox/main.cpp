#include <iostream>


using namespace std;

int main ( void )
{
        int pointer[4] { 1, 6, 2, 9 };
        int *pointer2 = new int [4];
        pointer2 = pointer;
        cout << * ( &pointer2 + 1 )/* / 4sizeof ( pointer [ 0 ] )*/ << " elements ... " << endl;
        /*
        delete[] pointer;
        pointer = new int [5];
        pointer = pointer2;
        pointer[4] = 7;*/
        cout << sizeof ( pointer ) / sizeof ( pointer [ 0 ] ) << " elements ... " << endl;
        return 0;
}
