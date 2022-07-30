#include <iostream>

/**
 * @author stablestud
 * @date 24.04.2018
 */

int main ( void )
{
	int first, second;
	std::cout << "Input first digit: ";
	std::cin >> first;
	std::cout << "Input second digit: ";
	std::cin >> second;
	
	if ( !second ) {
		std::cerr << "Second can't be zero!" << std::endl;
		return 1;
	}	

	int product = 0;
	int i = 1;

	do {
		product += first;	

	} while ( i++ < second );
	
	std::cout << product << std::endl;

	return 0;
}
