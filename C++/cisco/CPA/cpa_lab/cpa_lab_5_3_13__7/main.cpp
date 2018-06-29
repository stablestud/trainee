#include <iostream>
#include "Node.h"
#include "List.h"

void printList ( List& list );
void popAll ( List& list );

int main ( void )
{
	List list1;
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);
	list1.push_front(4);
	std::cout << "list1" << std::endl;
	printList(list1);
	std::cout << std::endl;
	List list2(list1);
	std::cout << "list2" << std::endl;
	printList(list2);
	std::cout << std::endl;
	list1.insert_at(1, 6);
	list2.remove_at(2);
	std::cout << "list1" << std::endl;
	printList(list1);
	std::cout << "list2" << std::endl;
	printList(list2);
	std::cout << std::endl;

	return 0;
}

void printList ( List& list )
{
	for ( unsigned i = 0; i < list.getSize(); i++ )
		std::cout << "list[" << i << "] = " << list.at ( i ) << std::endl;
}

void popAll ( List& list )
{
	int value;

	while ( list.getSize() ) {
		if ( list.pop_front ( value ) )
			std::cout << "value: " << value << ", size: " << list.getSize() << std::endl;
		
		//if ( list.pop_back ( value ) )
		//	std::cout << "value: " << value << ", size: " << list.getSize() << std::endl;
	}
}
