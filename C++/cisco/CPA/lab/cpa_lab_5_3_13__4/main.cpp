#include <iostream>
#include "Node.h"
#include "List.h"

void popAll ( List& list );

int main ( void )
{
	{
		List list;

		list.push_top ( 3 );
		list.push_back ( 4 );
		list.push_top ( 2 );
		list.push_back ( 5 );
		list.push_top ( 1 );
		popAll ( list );
	}
	return 0;
}

void popAll ( List& list )
{
	int value;

	while ( list.pop ( value ) )
		std::cout << "Value: " << value << ", size: " << list.getSize() << std::endl;
}
