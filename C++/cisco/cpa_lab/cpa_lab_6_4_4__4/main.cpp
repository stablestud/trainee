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
                if (game.guess(character))
                        std::cout << "YES, that was RIGHT!" << std::endl;
                else
                        std::cout << "NO, that was wrong... -1 life" << std::endl;

                printHangman(game);
        } while (game.finito());
}
