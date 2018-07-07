#include <iostream>
#include <stdexcept>

#include "ipAddress.h"

int main(void)
{
	try {
		ipAddress ip1("1.1.1.1");
		ipAddress ip2("111.111.111.111");
		ipAddress ip3("255.255.2l.251");
		ipAddress ip4(".12.12.12");
	} catch (std::exception &exc) {
		std::cout << exc.what() << std::endl;
	}
}
