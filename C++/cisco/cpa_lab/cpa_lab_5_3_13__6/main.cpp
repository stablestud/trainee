#include <iostream>
#include "Node.h"
#include "List.h"

void printList ( List list );
void popAll ( List& list );

int main ( void )
{
	{
		List list;

		list.push_front ( 31 );
		list.push_back ( 4 );
		list.push_back ( 132 );
		list.push_front ( 29 );
		list.push_back ( 50 );
		list.push_front ( 1 );
		list.push_front ( 99 );
		printList ( list );
	}
	return 0;
}

void printList ( List list )
{
	for ( unsigned i = 0; i < list.getSize(); i++ )
		std::cout << "list[" << i << "] = " << list.at ( i ) << std::endl;
}

void popAll ( List& list )
{
	static int count = 0;
	int value;

	while ( list.getSize() ) {
		if ( count % 2 ) {
			if ( list.pop_front ( value ) )
				std::cout << "value: " << value << ", size: " << list.getSize() << std::endl;
		} else
			if ( list.pop_back ( value ) )
				std::cout << "value: " << value << ", size: " << list.getSize() << std::endl;
	}
}
