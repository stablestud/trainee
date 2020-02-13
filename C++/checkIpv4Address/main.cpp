/**
 * @author stablestud <dev@stablestud.org>
 * @date 06-06-2018
 *
 * A small program that checks for validity of an ipv4 address
 **/
#include <iostream>
#include <string>
#include "ipAddress.h"

int main(int argc, char * argv[])
{
	IpAddress ip;

	if (argc < 2) {
		std::string input;
		std::cin >> input;
		ip(input);
	} else {
		ip(argv[1]);
	}

	return !ip.returnCorrect();
}
