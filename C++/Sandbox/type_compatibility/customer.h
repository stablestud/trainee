#ifndef PERSON
#include "person.h"
#endif

class customer : public person
{
private:
        char alias = 'A';
        ~customer ( void );
public:
		customer ( std::string name );
		void meme ( void );
};
