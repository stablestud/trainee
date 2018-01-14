/*
 * overflow.cpp
 *
 *  Created on: 14 Jan 2018
 *      Author: stablestud
 */
#include <vector>
#include <iostream>

int main(void) {
        std::vector<unsigned long> peep (1);
        unsigned long output { 0 };
        unsigned long previous_output { 0 };

        for(unsigned long i { 0 };;i++) {
                peep.at(i) = { 7322 };
                peep.resize(peep.size() + 1);

                output = { peep.size() / 1024 / 1024 };

                if(output != previous_output) {
                        previous_output = { output };
                        std::cout << output << " Mbytes"<< std::endl;
                }
        }
}


