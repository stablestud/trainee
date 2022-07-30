#include <iostream>
#include "Node.h"

Node::Node ( int value ) : value ( value ), next ( nullptr ), prev ( nullptr )
{
	std::cout << "+Node " << value <<std::endl;
}

Node::~Node ( void )
{
	std::cout << "-Node " << value << std::endl;
}

int Node::getValue ( void )
{
	return this -> value;
}
