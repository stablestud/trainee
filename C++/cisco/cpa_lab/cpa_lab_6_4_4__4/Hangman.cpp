#include <iostream>
#include <string>
#include "Hangman.h"

Hangman::Hangman(std::string word) : lifes(8), word(word)
{
        for (unsigned i = 0; i < word.length(); i++) {
                if (!characters.find(word[i])) {
                        if (word[i] >= 'A' && word[i] <= 'Z')
                                characters.push_back(word[i] + 'a' - 'A');
                        else if (word[i] >= 'a' && word[i] <= 'z')
                                characters.push_back(word[i]);
                }
        }
}

bool Hangman::guess(char character)
{
        /* Treat lower or upper_case letters as the same */
        if (character >= 'A' && character <= 'Z')
                character += 'a' - 'A';

        if ( !(character >= 'a' && character <= 'z')) {
                std::cout << "Only letters are valid!" << std::endl;
                return false;
        }


        if (guessed.find(character)) {
                std::cout << character << " has been already tried!" << std::endl;
                lifes--;
                return false;
        }

        guessed.push_back(character);

        unsigned pos;
        if (characters.find(character, pos)) {
                characters.remove_at(pos);
                std::cout << "YES, " << character << " was RIGHT!" << std::endl;
                return true;
        }

        std::cout << "NO, " << character << " was WRONG!" << std::endl;
        lifes--;

        return false;
}

bool Hangman::finito()
{
        if (characters.getSize() == 0 || this->lifes == 0)
                return true;
        else
                return false;
}

unsigned Hangman::getLifes()
{
        return this->lifes;
}

List& Hangman::getGuessed()
{
        return this->guessed;
}

List& Hangman::getCharacters()
{
        return this->characters;
}

std::string& Hangman::getWord()
{
        return this->word;
}

void printHangman(Hangman& game)
{
        std::cout << std::endl << "-----------------------------------------------" << std::endl;
        std::cout << "You've " << game.getLifes() << " tries left." << std::endl;
        std::cout << "Guessed characters: ";

        for (unsigned i = 0; i < game.getGuessed().getSize(); i++)
                std::cout << game.getGuessed().at(i)->getValue() << " ";

        std::cout << std::endl;
        std::cout << "Word: ";

        for (unsigned i = 0; i < game.getWord().length(); i++) {
                char aux;
                if (game.getWord()[i] >= 'A' && game.getWord()[i] <= 'Z')
                        aux = game.getWord()[i] + 'a' - 'A';
                else
                        aux = game.getWord()[i];

                if (game.getCharacters().find(aux))
                        std::cout << "_";
                else
                        std::cout << game.getWord()[i];

                std::cout << " ";
        }

        std::cout << std::endl << "-----------------------------------------------" << std::endl << std::endl;
        /* print string with __a___h__ e.g. */
}

