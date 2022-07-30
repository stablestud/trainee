#include <iostream>
#include <string>

struct BLOCK {
        std::string blockString;

        void setBlock ( std::string input )
        {
                blockString = input;
        }

        std::string getBlock ( void )
        {
                return blockString;
        }

        bool checkTooManyCharacters ( void )
        {
                if ( blockString.length() <= 3 )
                        return false;
                else {
                        std::cout << "Too many characters in block: " << blockString << std::endl;
                        return true;
                }
        }

        bool checkCorrectCharacters ( void )
        {
                for ( int i = 0; i < blockString.length(); i++ ) {
                        if ( blockString.compare("") == 0 ) {
                                /* Does not work */
                                std::cout << "Block is empty!" << std::endl;
                                return true;
                        }
                        if ( blockString.substr(i,1) < "0" || blockString.substr(i,1) > "9" ) {
                                std::cout << "Invalid characters in block: " << blockString << std::endl;
                                return true;
                        }
                }
                return false;
        }

        bool checkCorrectValue ( void )
        {
                if ( std::stoi ( blockString ) <= 255 && std::stoi ( blockString ) >= 0 )
                        return false;
                else {
                        std::cout << "Invalid value in block: " << blockString << std::endl;
                        return true;
                }
        }

        bool check ( void )
        {
                if ( checkTooManyCharacters() || checkCorrectCharacters() )
                        return true;
                else if ( checkCorrectValue() )
                        return true;
                else
                        return false;
        }
};

int main ( void )
{
        std::string ip;
        std::cin >> ip;
        bool error = false;

        if ( std::cin.fail() ) {
                std::cin.ignore();
                std::cin.clear();
                std::cout << "Falsche Eingabe!" << std::endl;
                return 1;
        }

        BLOCK part1 { ip.substr ( 0, ip.find_first_of(".") ) };

        ip = ip.substr ( ip.find_first_of(".") + 1 );

        if ( part1.check() )
                error = true;

        BLOCK part2 { ip.substr ( 0, ip.find_first_of(".") ) };

        ip = ip.substr ( ip.find_first_of(".") + 1 );

        if ( part2.check() )
                error = true;

        BLOCK part3 { ip.substr ( 0, ip.find_first_of(".") ) };

        ip = ip.substr ( ip.find_first_of(".") +1 );

        if ( part3.check() )
                error = true;

        BLOCK part4 { ip.substr ( 0, ip.find_first_of(".") ) };

        ip = ip.substr ( ip.find_first_of(".") +1 );

        if ( part4.check() )
                error = true;

        if ( ip != part4.getBlock() ) {
                std::cout << "Too many blocks!" << std::endl;
                error = true;
        }

        if ( error )
                std::cout << "Ip address is invalid." << std::endl;
        return 0;
}
