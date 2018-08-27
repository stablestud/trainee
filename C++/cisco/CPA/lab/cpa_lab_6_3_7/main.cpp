/**
 * @author stablestud <dev@stablestud.org>
 * @date XX-XX-XXXX
 * 
 * A small program that checks for validity of an ipv4 address
 **/
#include <iostream>
#include <string>
#include "ipAddress.h"

void sendForPrint(const IpAddress* const);

int main(void)
{
        std::string new_ip;
        /* Uncomment to check up to 3 ip-addresses
        std::cin >> new_ip;
        IpAddress ip1(new_ip);

        std::cin >> new_ip;
        IpAddressChecked ip2(new_ip);
        */
        std::cin >> new_ip;
        IpAddressChecked ip3(new_ip);

        std::cout << std::endl;
        /* 
        sendForPrint(ip1);
        sendForPrint(ip2);
        */
        sendForPrint(&ip3);
}

/* I declared the method print as virtual,  *
 * then why shouldn't I make use of it? :-) */
void sendForPrint(const IpAddress* const obj)
{
        obj->print();
}
