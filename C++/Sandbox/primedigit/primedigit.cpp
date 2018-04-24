#include <iostream>

struct PRIMZAHL {
	int zahl;
	PRIMZAHL* next;
};

void printPrimzahl ( PRIMZAHL** current );

int main ( void )
{
	PRIMZAHL* container
       	PRIMZAHL** current = &container;	

	for ( int i = 0; i <= 100; i++ ) {
		int bTeiler = i / 2;
		int j = i;

		do {
			if ( !( i % j )) {
				(*current) = new PRIMZAHL { i, nullptr };
				(*current) = (*current)->next;
				break;
			}

		} while ( j++ <= bTeiler );
	}

	printPrimzahl ( &container );
}

void printPrimzahl ( PRIMZAHL* current )
{
	if ( current == nullptr )
		return;

	if ( current == nullptr )
		return;

	static int count = 1;

	std::cout << "Primzahl [" << count++ << "]: " << current->zahl << std::endl;

	printPrimzahl ( current->next );
}
