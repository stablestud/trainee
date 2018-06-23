#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
#include "ipAddress.h"

ipAddress& ipAddress::setIp(const char* const ip) throw(std::invalid_argument, std::domain_error)
{
        short length = 0;

        for (; ip[length] != '\0'; length++);

        if (15 < length)
                throw std::invalid_argument("ip is too long!");

        if (7 > length)
                throw std::invalid_argument("ip is too short!");

        short dots = 0;
        short dotsP[3];

        for (short i = 0; i < length; i++) {
                if (ip[i] == '.') {
                        dotsP[dots++] = i;
                        if (dots > 3)
                                throw std::invalid_argument("Too many dots in ip!");
                }
        }

        if (dots != 3)
                throw std::invalid_argument("Invalid count of dots!");


        short ipP = 0;
        
        for (short i = 0; i < 4; i++) {
                for (short j = 0; j < dotsP[i]; j++)
                        block[i] *= 10 + ip[ipP++];
                ipP = dotsP[i] + 1;
                checkIp(block[i]);
        }

        return *this;
}

ipAddress& ipAddress::operator<< (uint8_t b4) throw(std::domain_error)
{
        checkIp(block[3] += b4);
        return *this;
}

void ipAddress::checkIp(short block) throw(std::domain_error)
{
        if (block > 256 || block < 0)
                throw std::domain_error("Invalid Block caught!");
}

std::string ipAddress::print(void) const
{
        return std::to_string(block[0]) + "." + std::to_string(block[1]) + "." + std::to_string(block[2]) + "." + std::to_string(block[3]);
}

std::ostream& operator<< (std::ostream& stream, ipAddress& ip)
{
        return stream << ip.print();
}

ipAddressRange::ipAddressRange(const char* const ip, const uint8_t range) throw(std::invalid_argument, std::domain_error)
        : range(range)
{
        if (1U & range) /* When uneven */
                throw std::domain_error("Invalid range.");

        std::cout << "Range:" << range << std::endl;
        subnet = new ipAddress[range];

        for (short i = 0; i < range; i++) {
                subnet[i].setIp(ip) << i;               
        }
}

void ipAddressRange::print(void) const
{
        for (short i = 0; i < range; i++)
                std::cout << subnet[i] << std::endl;
}
