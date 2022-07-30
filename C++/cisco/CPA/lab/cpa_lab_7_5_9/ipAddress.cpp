#include <stdexcept>
#include <iostream>

#include "ipAddress.h"

ipAddress::ipAddress(const char* const s) : string(s)
{
	/*
	 * First count the length of the string,
	 * Secondly count the number of dots,
	 * Thirdly look for invalid characters 
	 */
	int length = 0;
	int dotsc = 0;

	while (s[length] != '\0') {
		if (s[length] != '.' && (s[length] < '0' || s[length] >= '9'))
			throw std::domain_error("Invalid characters in ip.");
		if (s[length] == '.')
			dotsc++;
		length++;
	}

	//std::cout << "Length of ip: " << length << std::endl;
	if (dotsc != 3)
		throw std::domain_error("Invalid count of dots.");
	if (length < 7 || length > 15)
		throw std::domain_error("Invalid length of ip.");

	/* Now check for each block's value */
	int offset_pos = 0;
	
	do {
		int dots_pos = 0;

		/* Gets the lengths of the block */
		while (s[dots_pos + offset_pos] != '.' && s[dots_pos + offset_pos] != '\0') {
			dots_pos++;
		}
		//std::cout << "Block size: " << dots_pos << std::endl;

		/* Check if block length is invalid */
		if (dots_pos > 3 || dots_pos < 1)
			throw std::domain_error("Invalid block size in ip.");
		
		/* 'Extract' block value */
		int block_val = 0;
		for (int i = 0; i < dots_pos; i++) {
			//std::cout << "Adding: " << s[i + offset_pos] <<
			//" to block_val: " << (s[i + offset_pos] - '0') << std::endl;
			block_val = block_val * 10 + s[i + offset_pos] - '0';
		}

		//std::cout << "Block value: " << block_val << std::endl;
		/* Check if block value is invalid */
		if (block_val > 255 || block_val < 0)
			throw std::domain_error("Invalid block value in ip.");
			
		offset_pos += dots_pos;
	} while (s[offset_pos++] != '\0');

	std::cout << string << " is valid!" << std::endl;
}

ipHeader::ipHeader(const char* const s, const char* const d)
{
	bool error = false;

	try {
		source = new ipAddress(s);
	} catch (std::exception& exc) {
		error = true;
		std::cerr << "Source: " << exc.what() << std::endl;
	}

	try {
		destination = new ipAddress(d);
	} catch (std::exception& exc) {
		error = true;
		std::cerr << "Destination: " << exc.what() << std::endl;
	}
	
	if (error)
		std::cout << "Invalid Ip Header." << std::endl;
	else
		std::cout << "Valid Ip Header." << std::endl;
}
