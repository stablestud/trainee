#ifndef IPADDRESS_H 
#define IPADDRESS_H

#include <iostream>
#include <string>

class IpAddress
{
private:
        std::string ip;
public:
        IpAddress ( std::string ip ) : this -> ip ( ip ) const = 0;
        IpAddress ( IpAddress& copyOf ) : this -> ip ( copyOf.getIp() ) const = 0;
        std::string getIp ( void );
        void print ( void );
};

class IpAddressChecked
{
private:
        bool correct;
public:
        IpAddressChecked ( std::string ip ) : 1
