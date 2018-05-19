#include <iostream>
#include "Node.h"
#include "List.h"

void printList ( List& list );
void popAll ( List& list );

int main ( void )
{
	{
		List list;

		list.remove_at ( 0 );
		list.push_front ( 0 );
		list.push_back ( 1 );
		list.push_back ( 2 );
		list.push_back ( 3 );
		list.push_front ( -1 );
		list.insert_at ( 0, 999 );
		list.remove_at ( 0 );
		list.push_back ( 4 );
		list.insert_at ( 1, 888 );
		list.push_back ( 5 );
		list.remove_at ( 5 );
		list.insert_at ( list.getSize(), 444 );
		list.push_front ( -2 );
		list.remove_at ( list.getSize() - 1 );
		list.insert_at ( list.getSize() - 1, 666 );
		printList ( list );
		popAll ( list );
	}
	return 0;
}

void printList ( List& list )
{
	for ( unsigned i = 0; i < list.getSize(); i++ )
		std::cout << "list[" << i << "] = " << list.at ( i ) << std::endl;
}

void popAll ( List& list )
{
	static int count = 0;
	int value;

	while ( list.getSize() ) {
		if ( count++ % 2 ) {
			if ( list.pop_front ( value ) )
				std::cout << "value: " << value << ", size: " << list.getSize() << std::endl;
		} else
			if ( list.pop_back ( value ) )
				std::cout << "value: " << value << ", size: " << list.getSize() << std::endl;
	}
}
