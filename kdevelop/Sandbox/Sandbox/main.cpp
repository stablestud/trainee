#include <iostream>

using namespace std;

struct X {
        static int i;
};


int X::i = 10;

int main ( void )
{
        X tree;
        return 0;
}
