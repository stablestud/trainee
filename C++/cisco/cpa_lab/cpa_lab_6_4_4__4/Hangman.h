#ifndef HANGMAN_H
#define HANGMAN_H

#include "CharList.h"
#include <string>

class Hangman {
private:
        unsigned lifes;
        std::string word;
        List characters;
        List guessedChars;
public:
        Hangman(std::string word) : lifes(8), word(word);
        bool guess(char);
        bool finito();
        unsigned getLifes();
};

void printHangman (Hangman&);
#endif
