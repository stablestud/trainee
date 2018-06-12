#include <iostream>
#include <string>
#include "Hangman.h"

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

bool Hangman::guess(char character)
{
        char untouched = character;

        /* Treat lower or upper_case letters as the same (convert to upper) */
        if (character >= 'a' && character <= 'z')
                character += 'A' - 'a';

        if ( !(character >= 'A' && character <= 'Z')) {
                std::cout << "Only letters are valid!" << std::endl;
                return false;
        }


        if (guessed_chars.find(character)) {
                std::cout << untouched << " has been already tried!" << std::endl;
                lifes--;
                return false;
        }

        guessed_chars.push_back(character);

        unsigned pos;
        char lower = character + 'a' - 'A';;

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
 * Check whether the game has finished, no lifes or all characters
 * have been correctly guessed.
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

void printHangman(Hangman& game)
{
        /*
	try {
                for (unsigned i = 0; game.getSearched().getSize(); i++)
                        std::cout << game.getSearched().at(i)->getValue();
	} catch (std::out_of_range ) {}
        */

        std::cout << std::endl << "-----------------------------------------------" << std::endl;
        std::cout << "You've " << game.getLifes() << " tries left." << std::endl;
        std::cout << "Guessed characters: ";

        try {
                for (unsigned i = 0; i < game.getGuessed().getSize(); i++)
                        std::cout << game.getGuessed()[i]->getValue() << " ";
        } catch (std::out_of_range& oor) {
                std::cout << std::endl << oor.what();
        }

        std::cout << std::endl;
        std::cout << "Word: ";

        try {
                for (unsigned i = 0; i < game.getWord().length(); i++) {
                        char aux;

                        if (game.getWord()[i] >= 'A' && game.getWord()[i] <= 'Z')
                                aux = game.getWord()[i] + 'a' - 'A';
                        else
                                aux = game.getWord()[i];

                        if (game.getSearched().find(aux))
                                std::cout << "_";
                        else
                                std::cout << game.getWord()[i];

                        std::cout << " ";
                }
        } catch (std::out_of_range& oor) {
                std::cout << std::endl << oor.what() << std::endl;
        }

        std::cout << std::endl << "-----------------------------------------------" << std::endl << std::endl;
}

