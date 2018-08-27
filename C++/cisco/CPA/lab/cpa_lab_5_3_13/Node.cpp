#include "Node.h"

Node::Node ( int value ) : value ( value ), next ( nullptr ) {}

int Node::getValue ( void )
{
	return this -> value;
}
