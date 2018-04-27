#ifndef PERSON
#include "person.h"
#endif

class worker : public person
{
private:
        int id = 007;
        ~worker ( void );
public:
	worker ( std::string name );
	void meme ( void );
};
