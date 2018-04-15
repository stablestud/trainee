#include <iostream>
#include <string>

using std::endl;
using std::cerr;
using std::cout;
using std::cin;
using std::getline;
using std::string;

struct PARAM {
        char* param;
        char* value;
};

PARAM* readValues ( char*, int, int& );
void readSentence ( PARAM*, int, char*, int );

int main ( void ) {
        char values [56];

        cin.getline( values, 55);

        int length = 0;

        for ( int i = 0; i < 56; i++ )
                if ( values[i] != '\0' && values[i+1] == '\0' ) {
                        length = i + 1;
                        break;
                }
        if ( !length ) {
                cerr << "Values are too long, max string length: 20 characters!" << endl;
                exit ( EXIT_FAILURE );
        }

        int delimPos = 0;
        PARAM* holder = readValues ( values, length, delimPos );

        for ( int i = 0; i <= delimPos; i++ )
                cout << holder[i].param << ": " << holder[i].value << endl;

        char sentence [251];

        cin.getline( sentence, 250);

        length = 0;

        for ( int i = 0; i < 251; i++ )
                if ( sentence[i] != '\0' && values[i+1] == '\0' ) {
                        length = i + 1;
                        break;
                }

        if ( !length ) {
                cerr << "Sentence is too long,! " << endl;
                exit ( EXIT_FAILURE );
        }

        readSentence ( holder, delimPos, sentence, length );
        return 0;
}

void readSentence(PARAM* list, int size, char* sentence, int length )
{
        bool inThing = false;
        int position;
        int howLong;

        for ( int i = length; i > 0; i-- ) {
                if ( sentence[i] == '[' || sentence[i] == ']' ) {
                        if ( sentence[i] == ']' ) {
                                position = i;
                                inThing = true;
                        } else if ( sentence[i] == '[' ) {
                                howLong = position - i;
                                inThing = false;

                                /* check if fits to set */
                                for ( int i = 0; i < size; i++) {
                                        for ( i )
                                }
                        }
                }
        }
}


char* reallocateChar ( char* String, int charPos )
{
        char* aux = new char [charPos + 1];

        for ( int i = 0; i < charPos; i++ )
                aux[i] = String[i];

        delete[] String;

        return aux;
}

PARAM* reallocatePARAM ( PARAM* param, int pos )
{
        PARAM* aux = new PARAM [pos + 1];

        for ( int i = 0; i < pos; i++ )
                aux[i] = param[i];

        delete[] param;

        return aux;
}

PARAM* readValues ( char* value, int length, int& delimPos )
{
        PARAM* delimetered = new PARAM;
        int whereAreTheSpaces[55];
        int numberOfSpaces = 0;
        /* Removing spaces from values */
        for ( int i = 0; i < length; i++ ) {
                if ( value[i] == ' ' ) {
                        whereAreTheSpaces[numberOfSpaces++] = i;
                }
        }

        for ( int i = 0, spacePos = 0, saveMode = 0, charPos = 0; i < length; i++ ) {
                if ( whereAreTheSpaces[spacePos] != i ) {
                        if ( value[i] == '=' ) {
                                saveMode = 1;
                                charPos = 0;
                        } else if ( value[i] == ',' || value[i] == ';' ) {
                                saveMode = charPos = 0;
                                delimPos++;
                                delimetered = reallocatePARAM ( delimetered, delimPos );
                        } else {
                                if ( saveMode ) {
                                        /* value */
                                        if ( delimetered[delimPos].value == nullptr )
                                                delimetered[delimPos].value = new char[1];
                                        else
                                                delimetered[delimPos].value = reallocateChar ( delimetered[delimPos].value, charPos );
                                        delimetered[delimPos].value[charPos] = value[i];
                                } else {
                                        /* value */
                                        if ( delimetered[delimPos].param == nullptr )
                                                delimetered[delimPos].param = new char[1];
                                        else
                                                delimetered[delimPos].param = reallocateChar ( delimetered[delimPos].param, charPos );

                                        delimetered[delimPos].param[charPos] = value[i];
                                }
                                charPos++;
                        }
                } else {
                        spacePos++;
                }

        }

        length = numberOfSpaces;

        return delimetered;
}
