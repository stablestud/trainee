#include <iostream>
#include <exception>
#include "ipAddress.h"

int main(void)
{
        char ip[14];
        uint8_t range;

        try {
                std::cin >> ip >> range;
                ipAddressRange i0(ip, range);
                i0.print();
        } catch (std::exception& err) {
                std::cout << err.what() << std::endl;
        }

        try {
                std::cin >> ip >> range;
                ipAddressRange i1(ip, range);
                i1.print();
        } catch (std::exception& err) {
                std::cout << err.what() << std::endl;
        }

        try {
                std::cin >> ip >> range;
                ipAddressRange i2(ip, range);
                i2.print();
        } catch (std::exception& err) {
                std::cout << err.what() << std::endl;
        }

        try {
                std::cin >> ip >> range;
                ipAddressRange i3(ip, range);
                i3.print();
        } catch (std::exception& err) {
                std::cout << err.what() << std::endl;
        }

        return 0;
}
