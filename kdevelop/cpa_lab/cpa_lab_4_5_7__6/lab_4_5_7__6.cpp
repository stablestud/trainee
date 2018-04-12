#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::cerr;

struct BLOCK {
        char type;
        int begin;
        BLOCK* parent;
        BLOCK* child;
        BLOCK* next;
        string content; // Save the exact amount of children starting from 1, not needed if using linked list
        int children;
};

void insertChildren ( BLOCK* current )
{
        // On LINKED_LIST:
        // TODO Instead of array I need to got through the linked list till the last and begin from there (reverse direction)
        // TODO I may need a counter that, when going through the list counts the children
        for ( int i = current -> children; i > 0; i-- ) {
                current -> content.insert ( current -> child[i - 1].begin, current -> child[i - 1].content );
        }
}

BLOCK* searchForBlocks ( string String )
{
        BLOCK* blocks = nullptr, * current = nullptr;
        int amount = 0;

        // TODO find method to get the blocks end.
        // TODO to do this I have to save the parent to the block maybe also the child if possible
        // TODO so after an end of a block I can derefence the parent pointer and continue from there
        for ( int i = 0; i < String.length(); i++ ) {
                if ( String[i] == '*' || String[i] == '_' ) {
                        if ( blocks == nullptr ) {
                                blocks = new BLOCK;
                                blocks -> parent = nullptr;
                        } else {
                                BLOCK* aux = blocks;

                                blocks = new BLOCK [amount + 1];

                                for ( int j = 0; j < amount; j++ )
                                        blocks[j] = aux[j];
                        }

                        blocks[amount].type = String[i];
                        blocks[amount].begin = searched = i;
//                         blocks[amount].      # Add child to block?

                        amount++;
                }
        }
}

int main ( void ) {
        string input;
        getline ( cin, input );

        searchForBlocks ( input );
        return 0;
}
