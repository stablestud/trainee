#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::cerr;

struct STRING_STRUCT {
        char* string;
        unsigned length;
};

void updateStringLength ( STRING_STRUCT* string );
void removeSpaces ( STRING_STRUCT* string );
void printString ( STRING_STRUCT* string );

int main ( void )
{
	STRING_STRUCT inputParam;
	inputParam.string = new char [80];
	cin.getline ( inputParam.string, 80 );
	updateStringLength ( &inputParam );

	removeSpaces ( &inputParam );

	printString ( &inputParam );
        return 0;
}


void updateStringLength ( STRING_STRUCT* string )
{

	if ( string->string == nullptr ) {
		cout << "getStringLength: string is a nullptr, returning " \
			"0 as length" << endl;	
		string->length = 0;
		return;
	}

	int length = 0;

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
	if ( string->string == nullptr || string->length == 0 ) {
		cerr << "removeSpaces: parameter string- or length" \
			" is nullptr / zero" << endl;
			return;
	}

	unsigned newLength = 0;

        /* Let's search for spaces and count them        *
         * so a array with the right size can be created *
	 * string->Length must be be size of the actual  *
	 * string it should not go over it, e.g. should  *
	 * not include '\0',				 */
	for ( int i = 0; i < string->length; i++ )
		if ( string->string[i] != ' ' ) 
			newLength++;

	char* aux = string->string;

	/* Create an array by one greater then the	*
	 * actual array size to save the '\0' sign as	*
	 * 'length' does not scope the end-sign		*/
	string->string = new char[newLength + 1];
	
	for ( int i = 0, k = 0; i < string->length; i++ )
		if ( aux[i] != ' ' )
			string->string[k++] = aux[i];
	
	/* Add the end-string-sign to the last position	*/
	string->string[newLength] = '\0';

	string->length = newLength;

	delete[] aux;
}

void printString ( STRING_STRUCT* string )
{
	if ( string->string == nullptr || string->length == 0 ) {
		cerr << "printString: parameter string- or length" \
			"is nullptr / zero" << endl;
			return;
	}

	for ( int i = 0; i < string->length; i++ )
		cout << "[" << i << "] '" << string->string[i] << "'" << endl;

	cout << "[+1] '" << string->string[string->length] << "' < this must be empty" << endl;
	cout << "[+2] '" << string->string[string->length + 1] << "' < this must be empty" << endl;
	cout << "[+3] '" << string->string[string->length + 2] << "' < this must be empty" << endl;
	cout << "[Length]: " << string->length << endl;
}
