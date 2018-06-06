#include "ipAddress.h"

const std::string IpAddress::returnIp(void) const
{
        return this->ip;
}

const void IpAddress::print(void) const 
{
        std::cout << this->ip << std::endl;
}

const bool IpAddressChecked::returnCorrect(void) const
{
        return this->correct;
}

const void IpAddressChecked::print(void) const
{
        std::cout << this->returnIp() << " - " << (this->correct ? "Correct" : "Not Correct") << std::endl;
}

const bool IpAddressChecked::check(void) const
{
        std::string obj = this->returnIp();
        unsigned commas = 0, digits = 0, octet = 0; 

        for (unsigned i = 0; i < obj.length(); i++) {
                if (obj[i] == '.') {
                        if (octet > 255 || digits == 0)
                                return false;

                        octet = digits = 0;
                        commas++; 
                } else if (obj[i] >= '0' && obj[i] <= '9') {
                        digits++;
                        octet = octet * 10 + obj[i] - '0';
                } else {
                        return false;
                }

                if (digits > 3)
                        return false;
        }

        if (commas != 3)
                return false;

        return true;
}
