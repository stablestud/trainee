#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::getline;
using std::cerr;
using std::endl;

struct BLOCK {
        char type;
        unsigned int beginInParent;
        /* The actual size of the block is String + 2, as the *
         * two block-delimiter signs are ignored              */
        string String;
        struct BLOCK** subBlockContainer;
        unsigned int subBlockCount;
};

void printBlocks ( struct BLOCK** current, unsigned int offset = 0, bool recursive = true );

unsigned int searchForBlock ( struct BLOCK** current )
{
        /* Check for new blocks or end of this block */
        for ( unsigned int i = 0U; i < (*current)->String.length(); i++ ) {
                if ((*current)->String[i] == (*current)->type ) {
                        /* Cut the rest from the end of the block */
                        (*current)->String.erase ( i );

//                         cout << "End of " << (*current)->type << " block found at " << i << " from begin!" << endl;
                        /* Return the position in the string,  *
                         * to avoid rescanning by parent block */
                        return (*current)->String.length() + 1U;
                } else if ((*current)->String[i] == '_' || (*current)->String[i] == '*' ) {
                        /* If more then one sub-block exist, extend array by *
                         * one to fit the most recent sub-block              */
                        if ((*current)->subBlockCount ) {
                                struct BLOCK aux;
                                aux.subBlockContainer = (*current)->subBlockContainer;

                                (*current)->subBlockContainer = new BLOCK* [(*current)->subBlockCount + 1U];

                                for ( unsigned int j = 0U; j < (*current)->subBlockCount; j++ )
                                        (*current)->subBlockContainer[j] = aux.subBlockContainer[j];

                                delete[] aux.subBlockContainer;
                        }

//                         cout << "Family " << (*current) << ": Creating new block at array " << (*current)->subBlockCount << ", as " << (*current)->String[i] << " block, " << i << " from parent begin, " << (*current)->String.substr ( i + 1 ) + " is the rest" << ", nullptr, 0" << endl;

                        /* If a sub-block appeared, create new block inside the parent. */
                        (*current)->subBlockContainer[(*current)->subBlockCount] = new BLOCK { (*current)->String[i], i, (*current)->String.substr ( i + 1U ), new BLOCK*, 0U };

//                         cout << "Running recursive call..." << endl;
                        /* Recursive call: run searchForBlock in sub-block */
                        int returnValue = searchForBlock ( &(*current)->subBlockContainer[(*current)->subBlockCount] );

                        if ( returnValue == 0 ) {
                                printBlocks ( &(*current)->subBlockContainer[(*current)->subBlockCount], (*current)->beginInParent, false );
                                for ( unsigned int j = 0U; j < (*current)->beginInParent;  j++ )
                                        cerr << " ";
                                cerr << "Couldn't match end of " << (*current)->subBlockContainer[(*current)->subBlockCount]->type << " block." << endl;
                                exit ( EXIT_FAILURE );
                        } else {
                                i += returnValue;
                        }

                        (*current)->subBlockCount++;
                }
        }

        if ((*current)->type == 0U ) {
//                 cout << "End of block search" << endl;
        }
        return 0; // Check if return 0, then means it was not found and delete the not found array_block
}

void printBlocks ( struct BLOCK** current, unsigned int offset, bool recursive )
{
        /* print spaces */
        if ((*current)->type) {
                for ( unsigned int i = 0U; i < (*current)->beginInParent + offset; i++ )
                        cout << " ";
                cout << "^";

                for ( unsigned int i = 0U; i < (*current)->String.length() + 1; i++ )
                        cout << "~";

                cout << endl;


        }

        if ( recursive )
                /* Enter sub-blocks */
                for ( unsigned int i = 0U; i < (*current)->subBlockCount; i++ )
                        printBlocks ( &(*current)->subBlockContainer[i], (*current)->beginInParent + offset );
}

string modifyBlocks ( struct BLOCK** current )
{
        /* Enter last block */
        for ( int i = (*current)->subBlockCount - 1; i >= 0; i-- ) {
                (*current)->String.erase ( (*current)->subBlockContainer[i]->beginInParent, (*current)->subBlockContainer[i]->String.length() + 2);
                (*current)->String.insert ( (*current)->subBlockContainer[i]->beginInParent, modifyBlocks ( &(*current)->subBlockContainer[i] ));
        }

        if ((*current)->type == '*' ) {
                /* UPPERCASE */
                for ( int i = 0; i < (*current)->String.length(); i++ )
                        if ((*current)->String[i] >= 'a' && (*current)->String[i] <= 'z' ) {
                                char Char = (*current)->String[i];
                                (*current)->String.erase ( i, 1 ).insert ( i, " " );
                                (*current)->String[i] = Char - 32;
                        }
        } else if ((*current)->type == '_' ) {
                /* STRETCH */

                (*current)->String.resize ( (*current)->String.length() + 1 );

                for ( int i = (*current)->String.length(); i > 0; i-- ) {
                        if ((*current)->String[i] != ' ' ) {
                                (*current)->String.insert ( i, " " );
                        }
                }

                (*current)->String.insert ( 0, " " );
        }

        return (*current)->String;
}

int main ( void )
{
        string inputString;
        getline ( cin, inputString );

        struct BLOCK* linkedList = new BLOCK { 0U, 0U, inputString, new BLOCK*, 0U };

        searchForBlock ( &linkedList );
        printBlocks ( &linkedList );
        cout << modifyBlocks ( &linkedList ) << endl;

        return 0;
}
