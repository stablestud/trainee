#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

struct STRING {
        char* string;
        unsigned length = 0;
};

struct STRING_CONTAINER {
        STRING* container;
        unsigned length = 0;
};

struct STRING_POS {
        int* pos;
        unsigned length = 0;
};

unsigned getStringLength ( char* array );
void updateStringLength ( STRING** string );
void intPushBack ( STRING_POS* intArray, int number );
char* charPushBack ( char* array, char character, unsigned = 0 );
void charPushBack ( STRING** string, char character );
void stringPushBack ( STRING_CONTAINER* ccontainer, STRING* container );
void erasePart ( STRING** container, unsigned pos, unsigned scope );
void removeSpaces ( STRING** container );
void printString ( STRING** container );

int main ( void )
{
        cout << "Enter parameters: " << endl;
        
        STRING* input = new STRING { new char[81] };

        cin.getline ( input->string, 80 );

        updateStringLength ( &input );
        cout << "Before erasePart in main()" << endl; 
        erasePart ( &input, 0U, 1U );
        cout << "Before printString1 in main()" << endl; 
        printString ( &input );
        cout << "\nBefore removeSpaces in main()" << endl; 
        removeSpaces ( &input );
        cout << "Before printString2 in main()" << endl;
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

/* THIS IS BROKEN I DUNNO WHY ! */
void intPushBack ( STRING_POS* intArray, int number )
{
        int* aux = intArray->pos;
        cout << "Hello1" << endl; 
        intArray->pos = new int [intArray->length + 1U];
        cout << "Hello2" << endl;
        for ( int i = 0; i < intArray->length; i++ )
                intArray->pos[i] = aux[i];
        cout << "Hello3" << endl;
        intArray->pos[intArray->length] = number;
        cout << "Hello4" << endl;
        intArray->length++;
        cout << "Hello5" << endl; 
        if ( aux != nullptr )
                 delete aux;
        cout << "Hello6" << endl;
}

char* charPushBack ( char* string, char character, unsigned length )
{
        if ( !length )
                length = getStringLength ( string );

        char* aux = string;
        
        string = new char [length + 1U];

        for ( int i = 0; i < length; i++ ) {
                string[i] = aux[i];
        }
        
        string[length] = character;

        if ( aux != nullptr )
                delete[] aux;

        return string;
}


void charPushBack ( STRING** container, char character )
{
        (*container)->string = charPushBack ( (*container)->string, character, (*container)->length++);
}


void containerPushBack ( STRING_CONTAINER* ccontainer, STRING* container )
{
        STRING* aux = ccontainer->container;

        ccontainer->container = new STRING [ccontainer->length + 1U];
        
        for ( int i = 0; i < ccontainer->length; i++ )
                ccontainer->container[i] = aux[i];

        ccontainer->container[ccontainer->length] = *container;

        ccontainer->length++;

        if ( aux != nullptr )
                delete[] aux;
}

/* BUG with allocation and removeSpaces() */
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

        updateStringLength ( container );
        cout << "erase length: " << (*container)->length << endl;
        if ( aux != nullptr )
                delete[] aux;
}


void removeSpaces ( STRING** container )
{
        STRING_POS* stringPos;
        cout << "Before for-loop in removeSpaces()" << endl;
        for ( int i = (*container)->length - 1; i >= 0; i-- )
                if ( (*container)->string[i] == ' ' )
                        erasePart ( container, i , 1 );
//        for ( int i = 0; i < (*container)->length; i++ )
//                if ( (*container)->string[i] == ' ' )
//                        intPushBack ( stringPos, i );

//        for ( int i = 0; i < stringPos->length; i++ )
//                cout << stringPos->pos[i] << endl;
}

void printString ( STRING** container )
{
        for ( int i = 0; i < (*container)->length; i++ )
                cout << (*container)->string[i];
}
