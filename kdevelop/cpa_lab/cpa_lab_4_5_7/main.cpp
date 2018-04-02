#include <iostream>
#include <string>

std::string reduceWhitespaces ( std::string );
std::string removeDuplicates ( std::string );

int main ( void )
{
        std::string sentence;
        std::getline ( std::cin, sentence );

        sentence = removeDuplicates ( reduceWhitespaces ( sentence ) );

        std::cout << sentence << std::endl;

        return 0;
}

std::string reduceWhitespaces ( std::string oldSentence )
{
        std::string newSentence;
        bool spaceOccured = false;

        for ( int i = 0; i < oldSentence.length(); i++ ) {
                if ( oldSentence.substr ( i, 1 ).compare ( " " ) == 0 ) {
                        if ( spaceOccured ) {
                                /* When space occured again do nothing */
                        } else {
                                spaceOccured = true;
                                newSentence += oldSentence.substr ( i, 1 );
                        }
                } else {
                        spaceOccured = false;
                        newSentence += oldSentence.substr ( i, 1 );
                }
        }

        return newSentence;
}

std::string removeDuplicates ( std::string oldSentence )
{
        std::string newSentence;

        int words = 1;
        for ( int i = 0; i < oldSentence.length(); i++ )
                if ( oldSentence[i] == ' ' )
                        words++;

        bool charOccured = false;
        for ( int i = 0, begin = 0, end = 0; i < oldSentence.length(); i++ ) {
                if ( oldSentence[i] == ' ' ) {
                        end = i;
                        /* Save chars into string */
                }
                else if ( charOccured ) {

                } else {
                        begin = i;
                }
        }

        return newSentence;
}
