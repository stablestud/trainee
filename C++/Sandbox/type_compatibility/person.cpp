#include <person.h>

person::person ( std::string n )
{
	person::name = n;
}

person::meme ( void )
{
	std::cout << person::name << "Hallo." << std::endl;
}
