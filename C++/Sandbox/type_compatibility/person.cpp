#include "person.h"

person::person ( std::string name )
{
	person::name = name;
        std::cout << name << ": person constructed!" << std::endl;
}

person::~person ( void )
{
        std::cout << person::name << ": person deconstructed!" << std::endl;
}

void person::meme ( void )
{
	std::cout << person::name << ": Hello. (person)" << std::endl;
}
