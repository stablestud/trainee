#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <stdexcept>

class ipAddress {
private:
	const char* const string;
public:
	ipAddress(const char* const s);
};

class ipHeader {
private:
	ipAddress* source, *destination;
public:
	ipHeader(const char* const, const char* const);
};

#endif /* IPADDRESS_H */
