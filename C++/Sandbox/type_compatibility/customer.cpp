#include "customer.h"

customer::customer ( std::string name ) : person ( name ) { }

void customer::meme ( void )
{
	std::cout << person::name << ": I would like to buy something." << std::endl;
}
