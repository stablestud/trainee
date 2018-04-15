#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

struct STRING {
        char* string;
        unsigned length = 0;
};

unsigned getStringLength ( char** array );

int main ( void )
{
        cout << "Enter parameters: " << endl;

        STRING input { new char[81] };
        unsigned stringLength;

        cin.getline ( input.string, 80 );

        cout << "Length: " << getStringLength ( &input.string ) << endl;
}

unsigned getStringLength ( char** array )
{
        unsigned length = 0U;
        
        for (; (*array)[length] != '\0'; length++ );

        return length;
}

char* charPushBack ( char** array, char character )
{
        unsigned length = getStringLength ( array );

        char* aux = *array; 

}

