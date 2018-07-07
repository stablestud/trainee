#include <stdexcept>
#include <iostream>

#include "ipAddress.h"

ipAddress::ipAddress(const char* const s)
{
	/*
	 * First count the length of the string,
	 * Secondly count the number of dots,
	 * Thirdly look for invalid characters 
	 */
	int length = 0;
	int dotsc = 0;

	for (; s[length] != nullptr; length++) {
		if (s[length] != '.' && (s[length] > '0' && s[length] <= '9')
			throw std::domain_error("Invalid characters in ip.");

		if (s[length] == '.')
			dotsc++;
	}

	if (dotsc != 3)
		throw std::domain_error("Invalid count of dots.");
	if (length < 7 || length > 15)
		throw std::domain_error("Invalid length of ip.");

	/* Now check for each block's value */
}
