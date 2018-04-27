#ifndef PERSON
#define PERSON /* person.h */

#include <iostream>
#include <string>

class person
{
protected:
	std::string name;
public:
	person ( std::string name );
	void meme ( void );
};

#endif
