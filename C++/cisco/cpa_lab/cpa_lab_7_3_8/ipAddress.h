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
        short b1, b2, b3, b4;
public:
        explicit ipAddress(const char* const) throw(std::invalid_argument, std::domain_error);
        std::string print(void) const;
        ostrean& operator<< (ostream& stream, ipAddress) const;
};

class ipAddressRange : public ipAddress {
private:
        short range;
        ipAddress* subnet;
public:
        explicit ipAddressRange(const char* const, short) throw(std::invalid_argument, std::domain_error);
        void print(void) const;
};

#endif /* IPADDRESS_H */
