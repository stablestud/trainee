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

struct PLACEHOLDER {
	unsigned beginPos;
	unsigned length;
	STRING_STRUCT* replaceWith = nullptr;
	PLACEHOLDER* next = nullptr;
};

void updateStringLength ( STRING_STRUCT* string );
void removeSpaces ( STRING_STRUCT* string );
void printString ( STRING_STRUCT* string );
void debugPrintString ( STRING_STRUCT* string );
void charPushBack ( STRING_STRUCT* string, char character );
void eraseFromString ( STRING_STRUCT* string, unsigned position, int scope );
PARAM* extendDelimeter ( PARAM* current );
void printDelimeter ( PARAM* current );
PARAM* delimeter ( STRING_STRUCT* string );
void debugPrintPlaceholder ( PLACEHOLDER* placeholders );
void removeInvPlaceholder ( PLACEHOLDER* current );
PLACEHOLDER* findPlaceholders ( STRING_STRUCT* string, PARAM* parameters );
unsigned calcNewSentenceLength ( STRING_STRUCT* sentence, PLACEHOLDER* placeholder );
STRING_STRUCT* replacePlaceholder ( STRING_STRUCT* string, PLACEHOLDER* placeholder );


int main ( void )
{
	STRING_STRUCT inputParam;
	inputParam.string = new char [80];
        cout << "Input parameters like so:" << endl;
        cout << "param=value; param2=value2;" << endl;
        cout << "Parameters: ";
	cin.getline ( inputParam.string, 80 );
	updateStringLength ( &inputParam );

	removeSpaces ( &inputParam );

        PARAM* delimetered = delimeter ( &inputParam );

        printDelimeter ( delimetered );

        STRING_STRUCT sentence;
        sentence.string = new char [50];
        cout << "Sentence: ";
        cin.getline ( sentence.string, 50 );
        updateStringLength ( &sentence );

        PLACEHOLDER* placeholders = findPlaceholders ( &sentence, delimetered );
        //debugPrintPlaceholder ( placeholders );
        cout << "Current Sentence length: " << sentence.length << endl;
        cout << "New Sentence length: " << calcNewSentenceLength ( &sentence, placeholders ) << endl;
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
                return; }

        if ( string->string == nullptr || string->length == 0U )
                return;

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
                        if (( i < position ) != ( i >= position + static_cast<unsigned>(scope) ))
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
                        if (( i >= position ) != ( i < position + static_cast<unsigned>(scope) ))
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


PARAM* extendDelimeter ( PARAM* current )
{
        if ( current == nullptr ) {
                cerr << "extendDelimeter: got a nullptr, can't continue" << endl;
                return current;
        }

        if ( current->next != nullptr )
                return extendDelimeter ( current->next );
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
                        gotInput = false;
                        pos++;
                        delimeterExtend = true;
                } else {
                        if ( delimeterExtend ) {
                                current = extendDelimeter ( container );
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


void debugPrintPlaceholder ( PLACEHOLDER* placeholders )
{
        while ( placeholders != nullptr ) {
                static int count = 0;
                cout << "----------------[ " << count++ << " ]-----------------" << endl;
                cout << "beginPos: " << placeholders->beginPos << endl;
                cout << "length: " << placeholders->length << endl;
                
                if ( placeholders->replaceWith != nullptr ) {
                        cout << "Replace with: ";

                        for ( unsigned i = 0U; i < placeholders->replaceWith->length; i++ )
                                cout << placeholders->replaceWith->string[i];

                        cout << endl;
                } else  
                        cerr << "placeholders->replaceWith: is a nullptr!" << endl;
                
                if ( placeholders->next != nullptr )
                        cout << "Next is not a nullptr" << endl;
                else    
                        cout << "Next is a nullptr" << endl;

                if ( placeholders->next != nullptr )
                        cout << "Next address: " << placeholders->next << endl;

                cout << endl;

                placeholders = placeholders->next;
        }
}


void removeInvPlaceholder ( PLACEHOLDER* current )
{
        if ( current->next->replaceWith == nullptr ) {
                delete current->next;
                current->next = nullptr;
        } else
                removeInvPlaceholder ( current->next );
}


PLACEHOLDER* findPlaceholders ( STRING_STRUCT* string, PARAM* parameters )
{
	PLACEHOLDER* placeholder = nullptr;
	PLACEHOLDER** currentPlaceholder = &placeholder;
	bool begin = false;
        bool found = false;

	for ( unsigned i = 0U; i < string->length; i++ ) {
		if ( string->string[i] == '[' && !begin ) {
			begin = true;

			if ( *currentPlaceholder == nullptr )
				*currentPlaceholder = new PLACEHOLDER;
                        
			(*currentPlaceholder)->beginPos = i + 1U;
		} else if ( string->string[i] == ']' && begin ) {
			begin = false;

			(*currentPlaceholder)->length = i - (*currentPlaceholder)->beginPos;

			PARAM* currentParam = parameters;

			do {
                                /* Compare with existing parameters (first the length) */
				if ( currentParam->param->length == (*currentPlaceholder)->length ) {

					for ( unsigned j = 0U; j < (*currentPlaceholder)->length; j++ ) {

						if ( string->string[(*currentPlaceholder)->beginPos + j] != currentParam->param->string[j] )
							break;

						else if ( j == (*currentPlaceholder)->length - 1U ) {
							(*currentPlaceholder)->replaceWith = currentParam->value;
                                                        currentPlaceholder = &(*currentPlaceholder)->next;

                                                        found = true;
                                                        break;
                                                }
					}
                                }

                                if ( found )
                                        break;

				currentParam = currentParam->next;

			} while ( currentParam != nullptr );
		}
	}
        
        if ( begin )
                removeInvPlaceholder ( placeholder ); 

        if ( found ) 
                return placeholder;	
        else {
                delete placeholder;
                return nullptr;
        }
}


unsigned calcNewSentenceLength ( STRING_STRUCT* sentence, PLACEHOLDER* placeholder )
{
        unsigned newLength = sentence->length;

        while ( placeholder != nullptr ) {
                newLength -= placeholder->length + 2;

                newLength += placeholder->replaceWith->length;

                placeholder = placeholder->next;
        }

        return newLength;
}


STRING_STRUCT* replacePlaceholder ( STRING_STRUCT* string, PLACEHOLDER* placeholder )
{       
        unsigned newLength = calcNewSentenceLength ( string, placeholder );
        STRING_STRUCT* newSentence = new STRING_STRUCT { new char [newLength], newLength };        

        return newSentence;
}
