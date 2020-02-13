#include <iostream>
#include <string>
#include "ipAddress.h"

const bool IpAddress::returnCorrect(void) const
{
        return this->correct;
}

/* Check if the supplied string is correct  *           
 * by counting the amount of dots,          *
 * checking the size of the numbers,        *
 * and invalid characters.                  */
void IpAddress::check(void)
{
        unsigned delim = 0, digits = 0, octet = 0; 
        std::string obj = ip;

        for (unsigned i = 0; i < obj.length(); i++) {
                if (obj[i] == '.') {
                        if (octet > 255 || digits == 0) {
				this->correct = false;
                                return;
			}

                        octet = digits = 0;
                        delim++; 
                } else if (obj[i] >= '0' && obj[i] <= '9') {
                        digits++;
                        octet = octet * 10 + obj[i] - '0';
                } else {
			this->correct = false;
                        return;
                }

                if (digits > 3) {
			this->correct = false;
                        return;
		}
        }

        if (delim != 3) {
		this->correct = false;
	}

	this->correct = true;
}

IpAddress & IpAddress::operator()(std::string input)
{
	ip = input;
	this->check();
	return *this;
}
