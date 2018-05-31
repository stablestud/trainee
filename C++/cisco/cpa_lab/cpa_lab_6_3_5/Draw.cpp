#include <iostream>
#include "Draw.h"

void Tree::draw ( pos* position ) const
{
	if ( position -> y == 0 && ( position -> x == 0 || position -> x == 3 ))
		std::cout << ' ';
	else if (( position -> y == 0 && position -> x == 1 ) || ( position -> y == 1 && position -> x == 0 ))
		std::cout << '/';
	else if (( position -> y == 0 && position -> x == 2 ) || ( position -> y == 1 && position -> x == 3 ))
		std::cout << '\\';
}

void Pinetree::draw ( pos* position ) const
{
	Tree::draw ( position );

	if ( position -> y == 1 ) {
		if ( position -> x == 1 )
			std::cout << '/';
		else if ( position -> x == 2 )
			std::cout << '\\';
	}
}

void Oaktree::draw ( pos* position ) const
{
	Tree::draw ( position );

	if ( position -> y == 1 )
		if ( position -> x == 1 || position -> x == 2 )
			std::cout << '*';
}

void Birchtree::draw ( pos* position ) const
{
	Tree::draw ( position );

	if ( position -> y == 1 )
		if ( position -> x == 1 || position -> x == 2 )
			std::cout << '+';
}
