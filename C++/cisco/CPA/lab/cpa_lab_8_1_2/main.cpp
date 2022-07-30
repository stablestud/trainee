#include <iostream>

#include "stack.h"

int main(void)
{
	try {
		stack s;
		std::cout << "Input data to stack" << std::endl;
		type var;
		while(std::cin >> var)
			s << var;
		std::cout << s;
	} catch (std::exception& exc) {
		std::cout << exc.what() << std::endl;
	}
}
