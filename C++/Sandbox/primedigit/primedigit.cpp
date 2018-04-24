#include <iostream>

/** 
 * @author stablestud
 * @date 24.04.2018
 */

int main ( void )
{
	for ( int i = 0; i <= 100; i++ ) {
		/* Sets the maximum possible divider */
		int bTeiler = i / 2;
		int j = 2;
		bool primedigit = true;

		do {
			/* When i Modulo j equals to 0, then it's a primedigit.
			 * Exception is the 2 */	
			if ( !( i % j ) && i != 2 ) {
				primedigit = false;
				break;
			}
		/* Aslong the maximum possible divider has not been reached
		 * run the loop */
		} while ( j++ <= bTeiler );

		if ( primedigit )
			std::cout << "PRIMEDIGIT: " << i << std::endl;
	}
}

