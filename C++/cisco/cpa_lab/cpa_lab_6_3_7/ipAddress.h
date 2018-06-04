#ifndef IPADDRESS_H 
#define IPADDRESS_H

#include <iostream>
#include <string>

class IpAddress
{
private:
        std::string ip;
public:
        IpAddress(std::string input) : ip(input) {};
        IpAddress(IpAddress& source
};

class IpAddressChecked
{
private:
        bool correct;
public:
        IpAddressChecked(std::string ip) : IpAddress(ip) {};
};
