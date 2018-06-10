#ifndef HANGMAN_H
#define HANGMAN_H

#include "CharList.h"
#include <string>

class Hangman {
private:
        unsigned lifes;
        std::string word;
        List characters;
        List guessed;
public:
        Hangman(std::string word);
        bool guess(char);
        bool finito();
        unsigned getLifes();
        List getGuessed();
        List getCharacters();
        std::string getWord();
};

void printHangman (Hangman&);
#endif
