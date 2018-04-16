#include <iostream>

struct X {
        int pos = 2;
};

void func ( X* damn, int times = 0 )
{
	std::cout << times <<  " Hello ! :" << damn->pos << std::endl;	
	damn->pos += 4;
	times++;

	if ( times < 4 )
		func ( damn, times );
}

int main ( void )
{
        X G;

        func ( &G );

        return 0;
}
