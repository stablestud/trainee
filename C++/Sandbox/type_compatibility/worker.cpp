#include "worker.h"

worker::worker ( std::string name ) : person ( name )
{
        std::cout << name << ": worker constructed!" << std::endl; 
}

worker::~worker ( void )
{
        std::cout << person::name << ": worker deconstructed!" << std::endl; 
}

void worker::meme ( void )
{
	std::cout << person::name << "[" << worker::id << "]: What can I do for you? (worker)" << std::endl;
}
