#include <iostream>
#include <string>
#include "Network.h"

int main()
{
        std::string ip1;
        std::string ip2;
        std::string ip3;
        std::string ip4;
        std::string ip5;
        
        std::cin >> ip1 >> ip2 >> ip3 >> ip4 >> ip5;
        Network net1(ip1, ip2, ip3);
        Network net2(ip3, ip4, ip5);
        std::cout << "Network 1: " << std::endl;
        net1.printAddress();
        std::cout << "Network 2: " << std::endl;
        net2.printAddress();
        return 0;
}
