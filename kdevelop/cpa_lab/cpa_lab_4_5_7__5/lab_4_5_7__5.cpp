#include <iostream>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::getline;
using std::endl;

struct DIGIT {
        // check digit
        bool check ( char character )
        {
                if ( character ) // TODO check if character in range of digits in ASCI/ANSI code
                        return true;
                else
                        return false;
        }
};

struct ALPHABET {
        // Look for char from ALPHABET
        bool check ( char character )
        {
                if ( character ) // TODO check if in ALPHABET
                        return true;
                else
                        return false;
        }
};

struct JOKER {
        // Every character but empty
        // Maybe return always true?
        // Maybe I dont need this structure then?
        bool check ( char character )
        {
                return character;
        }
};

struct CASE {
        u_char literal; // TODO compare with character
        // Check if lower/Upper-case character exists
        bool check ( char character ) {
                if ( character ) // TODO check if character in ALPHABET
                        if ( character ) // TODO check if Upper/lower case & compare with literal
                                return true;
                        else    return false;
                else return false;
        }
};

struct REST {
        u_char literal;
        // Check if char equals this character
        bool check ( char character )
        {
                if ( character == literal )
                        return true;
                else    return false;
        }
};

int main(int argc, char **argv) {
        string pattern;
        getline ( cin, pattern );



        string text;
        getline ( cin, text );
        return 0;
}

