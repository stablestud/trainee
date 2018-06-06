#ifndef IPADDRESS_H 
#define IPADDRESS_H

#include <iostream>
#include <string>

class IpAddress {
private:
        const std::string ip;
public:
        IpAddress(std::string input) : ip(input) {};
        IpAddress(IpAddress& source) : ip(source.returnIp()) {};
        const std::string returnIp(void) const;
        virtual const void print(void) const;
};

class IpAddressChecked : public IpAddress {
private:
        const bool correct;
public:
        IpAddressChecked(std::string ip) : IpAddress(ip), correct(check()) {};
        IpAddressChecked(IpAddressChecked& source) : IpAddress(source.returnIp()), correct(source.returnCorrect()) {};
        const bool returnCorrect(void) const;
        const bool check(void) const;
        const void print(void) const;
};

#endif
