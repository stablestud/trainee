#include "Hangman.h"

Hangman::Hangman(std::string word)
{
        /* Create List of characters which are in the word */
        /* Ignore doubles */
}

void printHangman(Hangman& game)
{
        /* print existing Lives + a drawing with a Hangman */
}

bool Hangman::guess(char character)
{
        /* check if character was in the List */
        /* if not return false, and --lives */
        /* if yes remove the character from the character List */
        /* In every case add the input char to the guessedChar List */
        return true;
}

bool Hangman::finito()
{
        /* List empty or lifes empty? If yes return true */
        return true;
}

unsigned getLifes()
{
        return this->lifes;
}
