#include <string>
#include <iostream>
#include <vector>
#include "membership.h"

void printInfo ( std::vector<membership*> storage );
int findId ( unsigned id, std::vector<membership*> storage );
void processInput ( std::string& input );

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
        
        /* 10^POS but caution: can't multiply by 10 here, as 10*0 is not 1 as required, need for research */
        int blockSize = ( input.find_first_of ( " " ) == 0 ) ? input.size() : input.find_first_of ( " " );
        for ( int i = 0; i < blockSize; i++ )
                x.id += 10;
        
        std::cout << input << std::endl;

        if ( x.id == 0 )
                std::cerr << "Id 0 is not valid!" << std::endl;
}
