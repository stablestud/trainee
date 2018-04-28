#ifndef PERSON
#include "person.h"
#endif

class worker : public person
{
private:
        int id = 007;
public:
        ~worker ( void );
	worker ( std::string name );
	void meme ( void );
};
