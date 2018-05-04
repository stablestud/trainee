#include <iostream>

int main ( void )
{
	int x[1] = { 'X' };
	std::cout << (char)*(x+1);
}
