#include "worker.h"

worker::worker ( std::string name ) : person ( name ) { }

void worker::meme ( void )
{
	std::cout << person::name << ": What can I do for you? (worker)" << std::endl;
}
