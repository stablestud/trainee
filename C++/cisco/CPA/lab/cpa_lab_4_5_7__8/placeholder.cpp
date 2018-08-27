/**
 * @author stablestud
 * @date 21.04.2018
 */

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
STRING_STRUCT* replacePlaceholder ( STRING_STRUCT* sentence, PLACEHOLDER* placeholder );
void deleteString ( STRING_STRUCT** structure );
void deleteParam ( PARAM** param );
void deletePlaceH ( PLACEHOLDER** placeholder );


int main ( void )
{
        STRING_STRUCT inputParam;

        inputParam.string = new char [80];
        cout << "Parameters: ";
        cin.getline ( inputParam.string, 80 );
        updateStringLength ( &inputParam );

        /* To remove spaces from parameter input, uncomment this */
        //removeSpaces ( &inputParam );

        PARAM* delimetered = delimeter ( &inputParam );
        delete[] inputParam.string;
        //printDelimeter ( delimetered );

        STRING_STRUCT* sentence = new STRING_STRUCT;
        sentence->string = new char [500];

        cout << "Sentence: ";
        cin.getline ( sentence->string, 500 );
        updateStringLength ( sentence );

        PLACEHOLDER* placeholders = findPlaceholders ( sentence, delimetered );
        /* To print the created placeholder, uncomment this */
        //debugPrintPlaceholder ( placeholders );

        STRING_STRUCT* newSentence = replacePlaceholder ( sentence, placeholders );
        if ( newSentence == nullptr )
                printString ( sentence );
        else
                printString ( newSentence );
        cout << endl;

        deleteParam ( &delimetered );
        deletePlaceH ( &placeholders );
        return 0;
}


/* Get's the string length by looking for termination sign '\0', saving value into structure */
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

        /* Go as long no '\0' has been found, length will be    *
        * the actual size without the '\0’         */
        for (; string->string[length] != '\0'; length++ );

        string->length = length;

}


/* RemoveSpaces() - edits the value that was given  *
 * Remove spaces the effective way, by not adding       *
 * them to the new array, instead of removing from  *
 * the current array                                    */
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
        * not include '\0',                 */
        for ( unsigned i = 0U; i < string->length; i++ )
                if ( string->string[i] != ' ' )
                        newLength++;

        char* aux = string->string;

        /* Create an array by one greater then the  *
        * actual array size to save the '\0' sign as   *
        * 'length' does not scope the end-sign     */
        string->string = new char[newLength + 1U];

        for ( unsigned i = 0U, k = 0U; i < string->length; i++ )
                if ( aux[i] != ' ' )
                        string->string[k++] = aux[i];

        /* Add the end-string-sign to the last position */
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


        if ( string->string == nullptr || string->length == 0U )
                return;

        for ( unsigned i = 0U; i < string->length; i++ )
                cout << "[" << i << "]: '" << string->string[i] << "'" << endl;

        cout << "[+1]: '" << string->string[string->length] << "' <- this should be empty" << endl;
        cout << "[+2]: '" << string->string[string->length + 1] << "'" << endl;
        cout << "[+3]: '" << string->string[string->length + 2] << "'" << endl;
}


/* Extend array by one and append character */
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

        string->string[string->length] = '\0';
}


/* Deletes characters from string, not used as reallocating arrays is slow */
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

        /* If scope is zero, delete the rest of the string */
        if ( scope == 0 )
                scope = string->length - position;

        /* + 1 to append the string termination character: '\0' */
        unsigned newLength;
        char* newString;

        if ( scope > 0 ) { /* When scope is positive, delete from postion */
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
        } else { /* When scope is negative, delete in front of position */
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


/* Append a PARAM element to the linked list */
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


/* Read the parameters and group them in a block for each   *
 * parameter with its value                                 */
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

                        if ( inParam )
                                charPushBack ( current->param, string->string[i] );
                        else
                                charPushBack ( current->value, string->string[i] );

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


/* Remove incomplete placeholders, by recursion */
void removeInvPlaceholder ( PLACEHOLDER* current )
{
        if ( current->next == nullptr ) {
                return;
        }

        if ( current->next->replaceWith == nullptr ) {
                delete current->next;
                current->next = nullptr;
        } else
                removeInvPlaceholder ( current->next );
}


/* Find placeholders [xxx] and save their position into a linked list */
PLACEHOLDER* findPlaceholders ( STRING_STRUCT* string, PARAM* parameters )
{
        if ( parameters == nullptr )
                cerr << "findPlaceholders: parameters is a nullptr, can't continue" << endl;

        PLACEHOLDER* placeholder = nullptr;
        PLACEHOLDER** currentPlaceholder = &placeholder;
        bool begin = false;
        bool found = false;
        bool cfound = false;

        for ( unsigned i = 0U; i < string->length; i++ ) {
                if ( string->string[i] == '[' ) {
                        begin = true;

                        if ( *currentPlaceholder == nullptr )
                                *currentPlaceholder = new PLACEHOLDER;

                        (*currentPlaceholder)->beginPos = i + 1U;
                } else if ( string->string[i] == ']' && begin ) {
                        begin = false;

                        (*currentPlaceholder)->length = i - (*currentPlaceholder)->beginPos;

                        if ( (*currentPlaceholder)->length == 0U ) {
                                delete *currentPlaceholder;
                                *currentPlaceholder = nullptr;
                                continue;
                        }

                        PARAM* currentParam = parameters;

                        do {
                                /* Compare with existing parameters (first the length, then the content) */
                                if ( currentParam->param->length == (*currentPlaceholder)->length ) {

                                        for ( unsigned j = 0U; j < (*currentPlaceholder)->length; j++ ) {
                                                if ( string->string[(*currentPlaceholder)->beginPos + j] != currentParam->param->string[j] )
                                                        break;
                                                else if ( j == (*currentPlaceholder)->length - 1U ) {
                                                        (*currentPlaceholder)->replaceWith = currentParam->value;

                                                        currentPlaceholder = &(*currentPlaceholder)->next;

                                                        cfound = true;
                                                        break;
                                                }
                                        }
                                }

                                if ( cfound )
                                        break;

                                currentParam = currentParam->next;

                        } while ( currentParam != nullptr );
                }

                if ( cfound ) {
                        found = true;
                        cfound = false;
                }
        }

        /* If unclosed brace delete it's placeholder, same goes for zero length cases */
        if ( begin == true && cfound == false )
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
                newLength -= placeholder->length + 2U;
                newLength += placeholder->replaceWith->length;

                placeholder = placeholder->next;
        }

        return newLength;
}


/* Instead of erasing existing content from the array and insert new ones,       *
 * create new array of calculated and fixed size and add the characters,         *
 * this should be faster, as it doesn't reallocate the array.                    */
STRING_STRUCT* replacePlaceholder ( STRING_STRUCT* string, PLACEHOLDER* placeholder )
{
        if ( placeholder == nullptr )
                return nullptr;

        /* Get calculated length of the new sentence to create the fixed size array */
        unsigned newLength = calcNewSentenceLength ( string, placeholder );

        /* newLength + 1 for the termination character '\0' */
        STRING_STRUCT* newSentence = new STRING_STRUCT { new char [newLength + 1], newLength };

        /* Copy over character till placeholder occurence */
        for ( unsigned i = 0U, k = 0U; i < string->length; i++ ) {
                if ( placeholder != nullptr ) {
                        /* When 'a wild placeholder appeared!', catch it and add it's string to the new array */
                        if ( i >= placeholder->beginPos - 1U && i <= placeholder->beginPos + placeholder->length + 1U ) {
                                for ( unsigned j = 0U; j < placeholder->replaceWith->length; j++ )
                                        newSentence->string[k++] = placeholder->replaceWith->string[j];

                                i = placeholder->beginPos + placeholder->length;
                                placeholder = placeholder->next;
                        } else
                                /* Not a good way but I wanted to try out the shortcut to the pokecenter */
                                goto normalString;
                } else
                normalString:
                        newSentence->string[k++] = string->string[i];
        }

        newSentence->string[newLength] = '\0';
        return newSentence;
}


void deleteString ( STRING_STRUCT** structure )
{
        if ( *structure == nullptr )
                return;

        if ( (*structure)->string != nullptr )
                delete (*structure)->string;

        delete *structure;

        /* Set to nullptr to avoid redeletion */
        *structure = nullptr;
}


void deleteParam ( PARAM** param )
{
        if ( *param == nullptr )
                return;

        if ( (*param)->param != nullptr ) {
                if ( (*param)->param->string != nullptr ) {
                        deleteString ( &(*param)->param );
                        /* Set to nullptr, as a marker to avoid deletion of the same object */
                        (*param)->param = nullptr;
                }
        }

        if ( (*param)->value != nullptr ) {
                if ( (*param)->value->string != nullptr ) {
                        deleteString ( &(*param)->value );
                        (*param)->param = nullptr;
                }
        }

        if ( (*param)->next != nullptr )
                deleteParam ( &(*param)->next );

        delete *param;
}


/* Delete all dynamically created placeholder structures and its sub variables */
void deletePlaceH ( PLACEHOLDER** placeholder )
{
        if ( *placeholder == nullptr )
                return;

        /* recursive call: enter sub element and run the same function */
        if ( (*placeholder)->next != nullptr ) {
                deletePlaceH ( &(*placeholder)->next );
        }

        delete *placeholder;
}
