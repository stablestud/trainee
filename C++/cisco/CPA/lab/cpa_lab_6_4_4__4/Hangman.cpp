#include <iostream>
#include <string>
#include "Hangman.h"


/*
 * @author stablestud
 * @date   13-06-2018
 */



/*
 * Constructor: Hangman - default ctor
 * - - - - - - - - - - - - - - - - - - -
 * Add every character from the supplied word to the
 * to be guessed List (searched_chars), ignore duplicates.
 *
 * word: word or sentence that should be guessed.
 */

Hangman::Hangman(std::string word) : lifes(8), word(word)
{
        /* Add letters to search_list */
        for (unsigned i = 0; i < word.length(); i++) {
                char add_me = word[i];

                /* Convert to lower_case */
                if  (add_me >= 'A' && add_me <= 'Z')
                        add_me += 'a' - 'A';

                if (!searched_chars.find(add_me)) {
                        if (add_me >= 'a' && add_me <= 'z')
                                searched_chars.push_back(add_me);
                }
        }
}



/*
 * Function: guess
 * - - - - - - - - -
 * Check if character is a character from the searched word.
 *
 * character: character that should be checked
 *
 * returns: whether character is correct (true) or wrong/not found (false).
 */

bool Hangman::guess(char character)
{
        char untouched = character;

        std::cout << std::endl << "-> ";

        /* Treat lower or upper_case letters as the same (convert to upper) */
        if (character >= 'a' && character <= 'z')
                character += 'A' - 'a';

        /* Check if supplied character is a literal letter */
        if ( !(character >= 'A' && character <= 'Z')) {
                std::cout << "Only letters are valid!" << std::endl;
                return false;
        }


        /* Check if character has been already tried to guess */
        if (guessed_chars.find(character)) {
                std::cout << untouched << " has been already tried!" << std::endl;
                lifes--;
                return false;
        }

        /* Add character to the list of guessed character */
        guessed_chars.push_back(character);

        unsigned pos;
        char lower = character + 'a' - 'A';;

        /* Search through the characters that have to be found,             *
         * if the supplied character matches a character from the list,     *
         * return true and remove it from the "to-be-found" character list. */
        if (searched_chars.find(lower, pos)) {
                searched_chars.remove_at(pos);
                std::cout << "YES, " << character << " was RIGHT!" << std::endl;
                return true;
        }

        std::cout << "NO, " << character << " was WRONG!" << std::endl;
        lifes--;

        return false;
}



/*
 * Function: finito
 * - - - - - - - - - -
 * Check whether the game has finished, no lifes or no characters
 * left to be guessed.
 *
 * returns: whether game has ended (true) or not (false)
 */

bool Hangman::finito()
{
        if (searched_chars.getSize() == 0 || this->lifes == 0)
                return true;
        else
                return false;
}



/*
 * Function: getLifes
 * - - - - - - - - - - -
 * Return amount of lifes leftover.
 *
 * returns: variable lifes
 */

unsigned Hangman::getLifes()
{
        return this->lifes;
}



/*
 * Function: getGuessed
 * - - - - - - - - - - - -
 * Return List containing guessed characters
 *
 * returns: object reference of class List
 */

List& Hangman::getGuessed()
{
        return this->guessed_chars;
}



/*
 * Function: getSearched
 * - - - - - - - - - - - - 
 * Return List containing searched characters
 *
 * return: object reference of class List
 */

List& Hangman::getSearched()
{
        return this->searched_chars;
}



/*
 * Function: getWord
 * - - - - - - - - - -
 * Return word that should be guessed
 *
 * returns: object reference of class string
 */

std::string& Hangman::getWord()
{
        return this->word;
}



/* 
 * Function: printHangman1
 * - - - - - - - - - - - - -
 * Print statistics about the game,
 * e.g. the guessed characters, remaining lifes, the "to-be-guessed" characters.
 *
 * game: object that holds the information about the game.
 */

void printHangman(Hangman& game)
{
        /* Code snippet that prints the characters to be guessed
	try {
                for (unsigned i = 0; game.getSearched().getSize(); i++)
                        std::cout << game.getSearched()[i];
	} catch (std::out_of_range ) {}
        */

        /* Print the -------- line */
        for (unsigned i = 0; i < 50; i++)
                std::cout << "-";

        std::cout << std::endl;
        std::cout << "You've " << game.getLifes() << " tries left."
                << std::endl;
        std::cout << "Guessed characters: ";

        /* Print out the guessed characters */
        try {
                for (unsigned i = 0; i < game.getGuessed().getSize(); i++)
                        std::cout << game.getGuessed()[i] << " ";
        } catch (std::out_of_range& oor) {
                std::cout << std::endl << oor.what();
        }

        std::cout << std::endl;
        std::cout << "Word: ";

        /* Print the word to be guessed,                           *
         * replacing not guessed characters with an underscore '_' */
        try {
                for (unsigned i = 0; i < game.getWord().length(); i++) {
                        char aux;

                        /* Convert Upper-case character to lower-case */
                        if (game.getWord()[i] >= 'A'
                         && game.getWord()[i] <= 'Z')
                                aux = game.getWord()[i] + 'a' - 'A';
                        else
                                aux = game.getWord()[i];

                        /* Call member method to check whether the character *
                         * has to be guessed                                 */
                        if (game.getSearched().find(aux))
                                std::cout << "_";
                        else
                                std::cout << game.getWord()[i];

                        std::cout << " ";
                }
        } catch (std::out_of_range& oor) {
                std::cout << std::endl << oor.what() << std::endl;
        }

        std::cout << std::endl;

        /* Print the -------- line */
        for (unsigned i = 0; i < 50; i++)
                std::cout << "-";

        std::cout << std::endl << std::endl;
}

