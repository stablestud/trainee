#include <string>
#include <iostream>
#include <vector>
#include "membership.h"

void printInfo ( std::vector<membership*> storage );
int findId ( unsigned id, std::vector<membership*> storage );
void processInput ( std::string& input );
int charToInt ( char& character );
int exponentiation ( int exponent );

struct PROC_INPUT
{
        std::string action;
        std::string name;
        unsigned id;
        int extend;
} x;

int main ( void )
{
        std::string input;
         
	std::vector<membership*> storage (0);	

	while ( true ) {
                std::cout << "[action] [id] <name/months>" << std::endl;
                std::getline ( std::cin, input );
                
                processInput ( input );
                
                if ( x.action == "quit" || x.action == "q" )
                        break;

                if ( !x.id )
                        continue;

		if ( x.action == "create" ) 
                        storage.push_back ( new membership ( x.id, x.name ) );
                else if ( x.action == "delete" ) 
                        storage.erase ( storage.begin() + findId ( x.id, storage ) );
                else if ( x.action == "extend" )
                        storage.at ( findId ( x.id, storage ) ) -> extend ( x.extend );
                 
                printInfo ( storage );
        }
}

void printInfo ( std::vector<membership*> storage )
{
        if ( storage.empty() )
                return;

        for ( membership* toPrint : storage )
                toPrint->print();
}

int findId ( unsigned id, std::vector<membership*> storage )
{
        if ( !storage.empty() )
                for ( unsigned i = 0; i < storage.size(); i++ )
                        if ( storage.at ( i ) -> id == id )
                                return i;

        std::cerr << "User with id " << id << " was not found." << std::endl;

        return -1;
}

void processInput ( std::string& input )
{
        x.action = "";
        x.name = "";
        x.id = 0;
        x.extend = 0;

        /* Remove duplicate whitespaces */
        for ( int i = input.length(); i >= 0; i-- )
                if ( input[i] == ' ' && ( input[i + 1] == ' ' || input[i - 1] == ' ' || i == 0 ) )
                        input.erase ( i, 1 );

        x.action = input.substr ( 0, input.find_first_of ( " " ) );

        input = input.substr ( input.find_first_of ( " " ) + 1 );
        
        int blockSize = ( input.find_first_of ( " " ) == 0 ) ? input.size() : input.find_first_of ( " " );

	/* Process each digit one by one *
	 * 10^pos * digit 		 */
        for ( int i = 0, j = blockSize - 1; i < blockSize; i++, j-- )
                x.id += exponentiation ( j ) * charToInt ( input[i] );

        if ( x.id == 0 )
                std::cerr << "Id 0 is not valid!" << std::endl;
	
	/* Name */
	if ( action == "create" )	
		x.name = input.substr ( blockSize );

	std::cout << "action: " << x.action << std::endl;
	std::cout << "id: " << x.id << std::endl;
	std::cout << "name: " << x.name << std::endl;
}

int charToInt ( char& character )
{
	switch ( character ) {
		case '1':
			return 1;
		case '2':
			return 2;	
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		default:
			return 0;
	}
}

int exponentiation ( int exponent )
{
	int value = 1;

	for ( int i = 0; i < exponent; i++ )
		value *= 10;
	
	return value;
}
