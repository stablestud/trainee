#include <iostream>
#include "Draw.h"

int main ( void )
{
	Tree* trees[3] = { new Pinetree, new Oaktree, new Birchtree };

	for ( int i = 0; i < 3; i++ ) {
		pos position;

		for ( int y = 0; y < 2; y++ ) {
			position.y = y;
			position.x = 0;

			for ( int x = 0; x < 4; x++ ) {
				position.x = x;
				trees[i]->draw ( &position );
			}

			std::cout << std::endl;
		}

		std::cout << std::endl;
	}
}
