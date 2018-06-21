#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>
#include "ipAddress.h"

ipAddress::ipAddress(const char* const ip) throw (std::invalid_argument, std::domain_error)
{
        short length = 0;
        for (; ip[length] != '\0'; length++);
        --length;

        if (15 < length)
                throw std::invalid_argument("ip is too long!");

        if (7 > length)
                throw std::invalid_argument("ip is too short!");

        short dots = 0;
        for (short i = 0; i < length; i++) {
                if (ip[i] == '.')
                        dots++;
        }

        if (dots != 3)
                throw std::invalid_argument("Invalid count of dots!");

        
}

std::string ipAddress::print(void) const
{
        return std::to_string(b1) + "." + std::to_string(b2) + "." + std::to_string(b3) + "." + std::to_string(b4);
}

ostream& operator<< (ostream& stream, ipAddress) const
{
        return stream << print();
}

ipAddressRange::ipAddressRange(const char* const ip, short range) throw(std::invalid_argument, std::domain_error)
        : ipAddress(ip), range(range)
{
        switch(range) {
                case 1:
                case 2:
                case 4:
                case 8:
                case 16:
                case 32:
                case 64:
                case 128:
                case 256:
                        break;
                default:
                        throw std::domain_error("Invalid range.");
        }

}

void print(void) const
{
        
