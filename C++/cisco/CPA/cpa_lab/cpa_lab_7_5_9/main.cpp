#include <iostream>
#include <stdexcept>

#include "ipAddress.h"

const char* iterate(std::string);

int main(void)
{
	std::string source, destination;
	std::cin >> source >> destination;
	ipHeader ipH1(iterate(source), iterate(destination));
	std::cin >> source >> destination;
	ipHeader ipH2(iterate(source), iterate(destination));
}

const char* iterate(std::string s)
{
	while (s[s.length() - 1] == ',')
		s.erase(s.length() - 1);

	char* consti = new char[s.length() + 1];

	for (unsigned i = 0; i < s.length(); i++)
		consti[i] = s[i];

	consti[s.length()] = '\0';
	
	return consti;
}
