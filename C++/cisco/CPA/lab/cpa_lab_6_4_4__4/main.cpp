#include <iostream>
#include <string>
#include "Hangman.h"

/*
 * @author stablestud
 * @date   13-06-2018
 */


/*
 * Main Function
 * - - - - - - - -
 * The main function provides a high level view about the program structure.
 */

int main()
{
        std::string word;

        std::cout << "Type in a string that should be guessed: ";
        std::getline(std::cin, word);

        /* Create a new game by creating a new object of type Hangman. *
         * All game related task are handled by the class              */
        Hangman game(word);

        /* Clear screen to obfuscate the entered string */
	for (unsigned i = 0; i < 66; i++)
		std::cout << std::endl;

        /* Print the statistics about the game */
        printHangman(game);

        /* Do aslong lifes are not zero or user has not guessed *
         * the complete string.                                 */
        do {
                char character;
                std::cout << "Type in a character to guess: ";
                std::cin >> character;

                /* Call method responsible for handling a guess operation */
                game.guess(character);

                /* Print the statistics about the game */
                printHangman(game);
        } while (!game.finito());

        if (game.getLifes() > 0) {
                std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "  Y O U  W O N !" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
        } else {
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
                std::cout << "O H . . . N O ,  Y O U  L O S T !" << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        }

        std::cout << std::endl;

        std::cout << "The searched string was:" << std::endl << std::endl << word << std::endl << std::endl;

        return 0;
}
