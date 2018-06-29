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
        Network(std::string ip1, std::string ip2, std::string ip3);
        void printAddress();
};

#endif 
