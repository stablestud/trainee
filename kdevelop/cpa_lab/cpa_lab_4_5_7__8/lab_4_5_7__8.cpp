#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

struct STRING {
        char* string;
        unsigned length = 0;
};


unsigned getStringLength ( char* array );
void updateStringLength ( STRING** string );
char* charPushBack ( char* array, char character, unsigned = 0 );
void charPushBack ( STRING** string, char character );
void erasePart ( STRING** container, unsigned pos, unsigned scope );
void removeSpaces ( STRING** container );
void printString ( STRING** container );


int main ( void )
{
        cout << "Enter parameters: " << endl;
        
        STRING* input = new STRING { new char[81] };

        cin.getline ( input->string, 80 );

        updateStringLength ( &input );

        removeSpaces ( &input );

        printString ( &input );

        cout << endl;
}


unsigned getStringLength ( char* string )
{
        unsigned length = 0U;
        
        for (; string[length] != '\0'; length++ );

        return length;
}


void updateStringLength ( STRING** string )
{
        (*string)->length = getStringLength ( (*string)->string );
}


char* charPushBack ( char* string, char character, unsigned length )
{
	char* aux = string;

        string = new char [length + 1U];

	if ( aux != nullptr )
		for ( int i = 0; i < length; i++ )
			string[i] = aux[i];

        string[length] = character;

        if ( aux != nullptr )
                delete[] aux;

        return string;
}


void charPushBack ( STRING** container, char character )
{
        (*container)->string = charPushBack ( (*container)->string, character, (*container)->length++);
}


void erasePart ( STRING** container, unsigned pos, unsigned scope )
{
        char* aux = (*container)->string;
         
        /* If scope is zero select the rest of the string */
        if ( scope == 0 )
                scope = (*container)->length - pos;

        (*container)->string = new char [(*container)->length - scope];

        for ( int i = 0, k = 0; i < (*container)->length; i++ )
                if ( !(i >= pos && i < pos + scope) )
                        (*container)->string[k++] = aux[i];

	(*container)->length--;

        if ( aux != nullptr )
                delete[] aux;
}


void removeSpaces ( STRING** container )
{
        for ( int i = (*container)->length - 1; i >= 0; i-- )
                if ( (*container)->string[i] == ' ' )
                        erasePart ( container, i , 1 );
}


void printString ( STRING** container )
{
        for ( int i = 0; i < (*container)->length; i++ )
                cout << (*container)->string[i];
}


