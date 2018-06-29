#include <iostream>
#include <string>

std::string reduceWhitespaces ( std::string );
std::string removeDuplicates ( std::string );

int main ( void )
{
        std::string sentence;
        std::getline ( std::cin, sentence );

        sentence = removeDuplicates ( sentence );

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
        oldSentence += " ";
        /* Counts words in the sentence */
        int wordCount = 0;
        int word = 0;
        for ( int i = 0; i < oldSentence.length(); i++ )
                if ( oldSentence[i] == ' ' && oldSentence[i - 1] != ' ')
                        wordCount++;

        std::cout << "Number of words: " << wordCount << std::endl;
        std::string* words = new std::string [wordCount];

        bool prevWasaChar = false;

        for ( int i = 0, begin = 0, end = 0; i < oldSentence.length(); i++ ) {
                if ( oldSentence[i] == ' ' ) {

                        if ( prevWasaChar ) {
                                end = i - 1;
                                for ( int j = begin; j <= end; j++ )
                                        words[word] += oldSentence[j];
                                word++;
                        }

                        prevWasaChar = false;

                } else {
                        if ( !prevWasaChar )
                                begin = i;

                        prevWasaChar = true;
                }
        }

        std::string newSentence;

        for ( int i = 0; i < wordCount; i++ ) {
                if (((i == wordCount ) ? 0 : ( words[i] != words[i + 1] )))
                        newSentence += words[i] + " ";

        }


        return newSentence;
}
