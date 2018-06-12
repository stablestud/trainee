#include <iostream>
#include <string>
#include "Hangman.h"

int main()
{
        std::string word;

        std::cout << "Type in a word to play with: ";
        std::getline(std::cin, word);

        Hangman game(word);

	for (unsigned i = 0; i < 66; i++)
		std::cout << std::endl;

        printHangman(game);

        do {
                char character;
                std::cout << "Type in a character to guess: ";
                std::cin >> character;
                std::cout << std::endl;

                game.guess(character);

                printHangman(game);
        } while (!game.finito());

        if (game.getLifes() > 0) {
                std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "  Y O U  W O N !" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
        } else {
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "O H . . . N O , Y O U  L O S T !" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        }

        std::cout << std::endl;

        std::cout << "The word was: " << word << std::endl;
        return 0;
}
