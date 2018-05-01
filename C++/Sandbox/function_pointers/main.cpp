#include <iostream>

typedef void* empty;
typedef void (*ptr_to_func)(empty);
enum { one=1, two, three, four };

void func ( empty heap = NULL )
{
	std::cout << "Hello, pointer world!" << four << std::endl;
}

void func2 ( empty code = NULL )
{
	std::cout << "Hmm, hehe progress..." << two << std::endl;
}

int main ( void )
{
	register ptr_to_func funcptr;
	
	funcptr = func;
	int input;
	std::cin >> input;

	if ( input )
		funcptr = &func2;	
	
	funcptr( NULL );

	return 0;
}
