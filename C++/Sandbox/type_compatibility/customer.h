#ifndef PERSON
#include "person.h"
#endif

class customer : public person
{
private:
        char alias = 'A';
public:
        ~customer ( void );
        customer ( std::string name );
        void meme ( void );
};
