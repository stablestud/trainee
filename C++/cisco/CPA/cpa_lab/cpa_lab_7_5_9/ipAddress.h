#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <stdexcept>

class ipAddress {
private:
	const char* const string;
public:
	ipAddress(const char* const s);
};

#endif /* IPADDRESS_H */
