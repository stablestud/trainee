#ifndef HANGMAN_H
#define HANGMAN_H

/*
 * @author stablestud
 * @date 2018
 */

#include "CharList.h"
#include <string>

class Hangman {
private:
        unsigned lifes;
        std::string word;
        List searched_chars;
        List guessed_chars;
public:
        Hangman(std::string word);
        bool guess(char);
        bool finito();
        unsigned getLifes();
        List& getGuessed();
        List& getSearched();
        std::string& getWord();
};

void printHangman (Hangman&);

#endif
