#include <iostream>
#include "Draw.h"

void Tree::draw ( pos* position ) const
{
	if ( position -> x <= 2 )
		std::cout << "/";
	else
		std::cout << "\\";
}
