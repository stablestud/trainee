#ifndef IPADDRESS_H 
#define IPADDRESS_H

#include <iostream>
#include <string>

/* Simple base class that holds the ip and it can print the ip */
class IpAddress {
public:
        std::string ip;
        bool correct;
        void check(void);
public:
	IpAddress() : ip(""), correct(false) {};
        IpAddress(std::string input) : ip(input), correct(false)
	{
		this->check();
	};
        const bool returnCorrect(void) const;
	IpAddress & operator()(std::string input);
};

#endif
