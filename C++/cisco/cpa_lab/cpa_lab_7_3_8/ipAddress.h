#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <exception>
#include <stdexcept>
#include <string>

/*
 * ipAddress
 * - - - - - -
 * get a const char*, split each block (dot is the divider)
 * (3dots must be present, no less, no more, else throw an error)
 * Range variable as derived class, 
 *
 * invalid_argument:    invalid characters, string is in general wrong
 * domain_error:        block/range exceeds permissable range
 *
 * create an array of length range and type ipAddress to store the addresses
 */

class ipAddress {
private:
        short block[4] {};
public:
        ipAddress& setIp(const char* const) throw(std::invalid_argument, std::domain_error);
        std::string print(void) const;
        ipAddress& operator<< (int) throw(std::domain_error);
        void checkIp(short block) throw(std::domain_error);
};

class ipAddressRange : public ipAddress {
private:
        const int range;
        ipAddress* subnet;
public:
        explicit ipAddressRange(const char* const, const int) throw(std::invalid_argument, std::domain_error);
        void print(void) const;
};

std::ostream& operator<< (std::ostream&, ipAddress&);
#endif /* IPADDRESS_H */
