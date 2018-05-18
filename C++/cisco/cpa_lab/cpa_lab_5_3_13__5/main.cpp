#include <iostream>
#include "Node.h"
#include "List.h"

void popAll ( List& list );

int main ( void )
{
	{
		List list;

		list.push_top ( 31 );
		list.push_bot ( 4 );
		list.push_bot ( 132 );
		list.push_top ( 29 );
		list.push_bot ( 50 );
		list.push_top ( 1 );
		list.push_top ( 99 );
		popAll ( list );
	}
	return 0;
}

void popAll ( List& list )
{
	static int count = 0;
	int value;

	while ( list.getSize() ) {
		if ( count % 2 ) {
			if ( list.pop_top ( value ) )
				std::cout << "value: " << value << ", size: " << list.getSize() << std::endl;
		} else
			if ( list.pop_bot ( value ) )
				std::cout << "value: " << value << ", size: " << list.getSize() << std::endl;
	}
}
