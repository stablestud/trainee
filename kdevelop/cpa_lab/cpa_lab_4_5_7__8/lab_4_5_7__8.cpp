#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::cerr;

struct STRING_STRUCT {
        char* string = nullptr;
        unsigned length = 0U;
};

struct PARAM {
        STRING_STRUCT* param = new STRING_STRUCT;
        STRING_STRUCT* value = new STRING_STRUCT;
        PARAM* next = nullptr;
};

void updateStringLength ( STRING_STRUCT* string );
void removeSpaces ( STRING_STRUCT* string );
void printString ( STRING_STRUCT* string );
void debugPrintString ( STRING_STRUCT* string );
void charPushBack ( STRING_STRUCT* string, char character );
void eraseFromString ( STRING_STRUCT* string, unsigned position, int scope );
PARAM* appendDelimeter ( PARAM* current );
void printDelimeter ( PARAM* current );
PARAM* delimeter ( STRING_STRUCT* string );


int main ( void )
{/*
	STRING_STRUCT inputParam;
	inputParam.string = new char [80];
	cin.getline ( inputParam.string, 80 );
	updateStringLength ( &inputParam );

	removeSpaces ( &inputParam );

        PARAM* delimetered = delimeter ( &inputParam );

        printDelimeter ( delimetered );
   */
        STRING_STRUCT x;

        x.string = new char[20];
        cin.getline ( x.string, 15 );
        updateStringLength ( &x );
        cout << "Real length: " << x.length << endl;
        cout << "~ " << ~x.length << "\t~cast " << ~static_cast<signed> ( x.length ) + 2 << endl;
        eraseFromString ( &x, x.length - 1, ~static_cast<signed> ( x.length ) + 2 );

        debugPrintString ( &x );
        //printString ( &x );

        return 0;
}


void updateStringLength ( STRING_STRUCT* string )
{
        if ( string == nullptr ) {
                cerr << "updateStringLength: got a nullptr, can't continue" << endl;
                return;
        }

	if ( string->string == nullptr ) {
		cerr << "updateStringLength: string is a nullptr, returning " \
			"0 as length" << endl;
		string->length = 0U;
		return;
	}

	unsigned length = 0U;

	/* Go as long no '\0' has been found, length will be	*
	 * the actual size without the '\0’			*/
	for (; string->string[length] != '\0'; length++ );

	string->length = length;

}


/* RemoveSpaces() - edits the value that was given	*
 * Remove spaces the effective way, by not adding      	*
 * them to the new array, instead of removing from	*
 * the current array                                   	*/
void removeSpaces ( STRING_STRUCT* string )
{
        if ( string == nullptr ) {
                cerr << "removeSpaces: got a nullptr, can't continue" << endl;
                return;
        }

	if ( string->string == nullptr || string->length == 0U ) {
		cerr << "removeSpaces: parameter string- or length" \
			" is nullptr / zero" << endl;
			return;
	}

	unsigned newLength = 0U;

        /* Let's search for spaces and count them        *
         * so a array with the right size can be created *
	 * string->Length must be be size of the actual  *
	 * string it should not go over it, e.g. should  *
	 * not include '\0',				 */
	for ( unsigned i = 0U; i < string->length; i++ )
		if ( string->string[i] != ' ' )
			newLength++;

	char* aux = string->string;

	/* Create an array by one greater then the	*
	 * actual array size to save the '\0' sign as	*
	 * 'length' does not scope the end-sign		*/
	string->string = new char[newLength + 1U];

	for ( unsigned i = 0U, k = 0U; i < string->length; i++ )
		if ( aux[i] != ' ' )
			string->string[k++] = aux[i];

	/* Add the end-string-sign to the last position	*/
	string->string[newLength] = '\0';

	string->length = newLength;

	delete[] aux;
}


void printString ( STRING_STRUCT* string )
{
        if ( string == nullptr ) {
                cerr << "printString: got a nullptr, can't continue" << endl;
                return;
        }

	if ( string->string == nullptr || string->length == 0U )
                return;

	for ( unsigned i = 0U; i < string->length; i++ )
		cout << string->string[i];
}


void debugPrintString ( STRING_STRUCT* string )
{
        if ( string == nullptr ) {
                cerr << "debugPrintString: got a nullptr, can't continue" << endl;
                return;
        }

        for ( unsigned i = 0U; i < string->length; i++ )
                cout << "[" << i << "]: '" << string->string[i] << "'" << endl;

        cout << "[+1]: '" << string->string[string->length] << "' <- this should be empty" << endl;
        cout << "[+2]: '" << string->string[string->length + 1] << "'" << endl;
        cout << "[+3]: '" << string->string[string->length + 2] << "'" << endl;
}


void charPushBack ( STRING_STRUCT* string, char character )
{
        if ( string == nullptr ) {
                cerr << "charPushBack: got a nullptr, can't continue" << endl;
                return;
        }

        char* aux = nullptr;

        if ( string->string != nullptr && string->length != 0U )
                aux = string->string;

        string->string = new char[string->length + 1U];

        for ( unsigned i = 0U; i < string->length; i++ )
                string->string[i] = aux[i];

        if ( aux != nullptr )
                delete[] aux;

        string->string[string->length] = character;

        string->length++;
}


void eraseFromString ( STRING_STRUCT* string, unsigned position, int scope )
{
        if ( string == nullptr ) {
                cerr << "eraseFromString: got a nullptr, can't continue" << endl;
                return;
        }

        if ( string->string == nullptr || string->length == 0U )
                return;

        if ( position >= string->length ) {
                cerr << "eraseFromString: position can't be greater then the " \
                        "string" << endl;
                return;
        }

        /* If scope zero, delete the rest of the string */
        if ( scope == 0 )
                scope = string->length - position;

        /* + 1 to append the string termination character: '\0' */
        unsigned newLength;
        char* newString;

        if ( scope > 0 ) { /* When scope is positive */
                if ( static_cast<unsigned>(scope) > string->length - position ) {
                        cerr << "eraseFromString: positive scope is greater " \
                                "than the available string, can't delete more" \
                                " then the existing string" << endl;
                        return;
                }

                newLength = string->length - static_cast<unsigned>(scope);
                newString = new char [newLength + 1U];

                for ( unsigned i = 0U, k = 0U; i < string->length; i++ ) {
                        if (( i < position ) != ( i >= position + static_cast<unsigned> ( scope )))
                                newString[k++] = string->string[i];
                        if ( k >= newLength )
                                break;
                }
        } else { /* When scope is negative */
                if ( scope + static_cast<int>(position) < 0 ) {
                        cerr << "eraseFromString: negative scope is greater " \
                                "than the position, can't delete more " \
                                "then the existing string" << endl;
                        return;
                }

                newLength = string->length + static_cast<unsigned>(scope);
                newString = new char [newLength + 1U];

                for ( unsigned i = 0U, k = 0U; i < string->length; i++ ) {
                        if (( i >= position ) != ( i < position + static_cast<unsigned> ( scope )))
                                newString[k++] = string->string[i];
                        if ( k >= newLength )
                                break;
                }
        }

        newString[newLength] = '\0';

        delete[] string->string;
        string->string = newString;
        string->length = newLength;
}


PARAM* appendDelimeter ( PARAM* current )
{
        if ( current == nullptr ) {
                cerr << "appendDelimeter: got a nullptr, can't continue" << endl;
                return current;
        }

        if ( current->next != nullptr )
                return appendDelimeter ( current->next );
        else
                return current->next = new PARAM;
}


void printDelimeter ( PARAM* current )
{
        if ( current == nullptr ) {
                cerr << "printDelimeter: got a nullptr, can't continue" << endl;
                return;
        }

        printString ( current->param );
        //debugPrintString ( current->param );
        cout << ": ";

        printString ( current->value );
        //debugPrintString ( current->value );
        cout << endl;

        if ( current->next != nullptr )
                printDelimeter ( current->next );
}


PARAM* delimeter ( STRING_STRUCT* string )
{
        if ( string == nullptr ) {
                cerr << "delimeter: got a nullptr, can't continue" << endl;
                return nullptr;
        }

        PARAM* container = new PARAM;
        PARAM* current = container;
        bool delimeterExtend = false;
        bool gotInput = false;

        for ( unsigned i = 0U, pos = 0U, inParam = 1U; i < string->length; i++ ) {
                if ( string->string[i] == '=' && inParam == true && gotInput == true ) {
                        inParam = false;
                        gotInput = false;
                } else if (( string->string[i] == ';' || string->string[i] == ',' ) && inParam == false && gotInput == true) {
                        inParam = true;
                        pos++;
                        delimeterExtend = true;
                        gotInput = false;
                } else {
                        if ( delimeterExtend ) {
                                current = appendDelimeter ( container );
                                delimeterExtend = false;
                        }

                        if ( inParam ) {
                                charPushBack ( current->param, string->string[i] );
                        } else {
                                charPushBack ( current->value, string->string[i] );
                        }

                        gotInput = true;
                }
        }

        return container;
}
