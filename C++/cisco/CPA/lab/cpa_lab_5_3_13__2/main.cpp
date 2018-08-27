#include <iostream>
#include "Node.h"
#include "List.h"

int main ( void )
{
	{
		int value;
		List list;
		
		list.push ( 4 );
		list.push ( 88 );
		if ( list.pop ( value ) )
			std::cout << value << std::endl;

		list.push ( 328 );
		list.push ( 9989 );
		
		//for (; list.pop ( value ) ;)
			//std::cout << value << std::endl;
	}
	std::cout << "Left scope" << std::endl;
		
}
