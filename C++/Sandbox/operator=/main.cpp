#include <iostream>

struct X {
public:
	int value;
	X ( int v ) : value ( v ) {};
	~X ()
	{
		std::cout << "Goodbye X!" << std::endl;
	}

	int operator+= ( int v )
	{
		return ( value += v );
	}
};

int main()
{
	int o = 9;
	X i ( o );
	std::cout << "1. i = " << i.value << std::endl;
	std::cout << ( i += 1 ) << std::endl;
	std::cout << "2. i = " << i.value << std::endl;
	std::cout << ( o+= 7 ) << std::endl;
	std::cout << o << std::endl;
}
