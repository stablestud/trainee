#include <iostream>
#include <string>
#include "ipAddress.h"

void sendForPrint(IpAddress&);

int main(void)
{
        std::string new_ip;

        std::cin >> new_ip;
        IpAddress ip1(new_ip);

        std::cin >> new_ip;
        IpAddressChecked ip2(new_ip);

        std::cin >> new_ip;
        IpAddressChecked ip3(new_ip);

        std::cout << std::endl;
        sendForPrint(ip1);
        sendForPrint(ip2);
        sendForPrint(ip3);
}

void sendForPrint(IpAddress& obj)
{
        obj.print();
}
