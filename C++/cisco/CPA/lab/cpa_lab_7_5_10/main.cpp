#include <iostream>
#include <stdexcept>
#include "tower_of_hanoi.h"

int main(void)
{
	TOH::game game1;

	do {
		try {
			game1.print();
			int input1, input2;

			if ( std::cin >> input1 )
				std::cin >> input2;
			else
				break;

			game1.move(input1, input2);
		} catch (std::exception& exc) {
			std::cerr << exc.what() << std::endl;
		}
	} while (!game1.finito());
}
