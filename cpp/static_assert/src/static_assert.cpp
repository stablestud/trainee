/*
 * static_assert.cpp
 *
 *  Created on: 8 Jan 2018
 *      Author: stablestud
 */
#include <iostream>
#include <limits>

int main(void) {
        std::cout << std::numeric_limits<unsigned char>::digits << std::endl;
        static_assert(std::numeric_limits<unsigned char>::digits == 8, "Kaputt");

        static_assert(std::numeric_limits<unsigned int>::digits
                == (sizeof(unsigned int) * 8), "int scaling error!");

        static_assert( sizeof(long double) == 16,
                        "Require 16 byte long double");

        static_assert(
                        (std::numeric_limits<unsigned char>::digits == 8),
                        "!!! unsigned char hat hier keine 8 bits !!!"
                        );
}


