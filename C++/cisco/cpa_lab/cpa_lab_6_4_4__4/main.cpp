#include <string>
#include <iostream>
#include "Hangman.h"

int main()
{
        std::string word;

        std::cout << "Type in a word to play with: ";
        std::cin >> word;

        Hangman game(word);

        do {
                char character;
                std::cout << "Type in a character to guess: ";
                std::cin >> character;
                std::cout << std::endl;

                game.guess(character);

                printHangman(game);
        } while (!game.finito());

        if (game.getLifes() > 0) {
                std::cout << "You won!" << std::endl;
        } else {
                std::cout << "Oh no, you lost ..." << std::endl;
        }

        std::cout << "The word was: " << word << std::endl;
        return 0;
}
