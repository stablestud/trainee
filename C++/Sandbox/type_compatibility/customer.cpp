#include "customer.h"

customer::customer ( std::string name ) : person ( name )
{
        std::cout << name << ": customer constructed!" << std::endl;
}

customer::~customer ( void )
{
        std::cout << name << ": customer deconstructed!" << std::endl;
}

void customer::meme ( void )
{
	std::cout << person::name << "[" << customer::alias << "]: I would like to buy something. (customer)" << std::endl;
}
