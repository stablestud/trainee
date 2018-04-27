#ifndef PERSON
#include "person.h"
#endif

class worker : public person
{
public:
	worker ( std::string name ) : person ( name ) { }
	void meme ( void );
}
