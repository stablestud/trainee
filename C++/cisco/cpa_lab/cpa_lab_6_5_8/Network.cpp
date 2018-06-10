#include <string>
#include <iostream>
#include "Network.h"

IpAddress::IpAddress(std::string ip) : ip(ip) {};

std::string IpAddress::getIp()
{
        return this->ip;
}


Network::Network(std::string ip1, std::string ip2, std::string ip3) : arr{ip1, ip2, ip3} {};

void Network::printAddress()
{
        std::cout << arr[0].getIp() << std::endl;
        std::cout << arr[1].getIp() << std::endl;
        std::cout << arr[2].getIp() << std::endl;
}
