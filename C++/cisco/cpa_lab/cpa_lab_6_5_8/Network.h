#ifndef NETWORK_H
#define NETWORK_H

#include <string>

class IpAddress {
private:
        std::string ip;
public:
        IpAddress(std::string ip); 
        std::string getIp();
};

class Network {
private:
        IpAddress arr[3];
public:
        Network(IpAddress ip1, IpAddress ip2, IpAddress ip3);
        void printAddress();
};

#endif 
