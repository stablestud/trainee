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

        int ipP = 0;
        
        for (short j = 0; j < dotsP[0]; j++)
                block[0] = block[0] * 10 + ip[ipP++] - 48;

        checkIp(block[0]);

        ipP++;

        for (short j = 0; j < dotsP[1] - dotsP[0] - 1; j++)
                block[1] = block[1] * 10 + ip[ipP++] - 48;
        
        checkIp(block[1]);

        ipP++;

        for (short j = 0; j < dotsP[2] - dotsP[1] - 1; j++)
                block[2] = block[2] * 10 + ip[ipP++] - 48;

        checkIp(block[2]);

        ipP++;

        for (short j = 0; j < length - dotsP[2] - 1; j++)
                block[3] = block[3] * 10 + ip[ipP++] - 48;

        checkIp(block[3]);

        return *this;
}

ipAddress& ipAddress::operator<< (int b4) throw(std::domain_error)
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

ipAddressRange::ipAddressRange(const char* const ip, const int range) throw(std::invalid_argument, std::domain_error)
        : range(range)
{
        if (1U & range) /* When uneven */
                throw std::domain_error("Invalid range.");

        switch (range) {
                case 1:
                case 2:
                case 4:
                case 8:
                case 16:
                case 32:
                case 64:
                        break;
                default:
                        throw std::domain_error("Invalid range.");
        }

        subnet = new ipAddress[range];

        for (int i = 0; i < range; i++)
                subnet[i].setIp(ip) << (i + 1);               
}

void ipAddressRange::print(void) const
{
        for (int i = 0; i < range; i++)
                std::cout << subnet[i] <<  std::endl;
}
