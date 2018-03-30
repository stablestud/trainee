#include <iostream>

using namespace std;

int main ( void )
{
	int x[2] = { 3, 6 };
	cout << *(x + 1) << endl;
	cout << *x << endl;
        return 0;
}
