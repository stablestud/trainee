#include <iostream>
#include <string>

<<<<<<< HEAD
int main ( void ) {
        return 0;
}
=======
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::getline;
using std::endl;


/*
struct DIGIT {
        bool check ( char character )
        {
                if ( character >= '0' && character <= '9')
                        return true;
                else
                        return false;
        }
};


/* * * * * * * * * * * * * * * * 
 *  Latein alpahbet mask (A)   *
 * * * * * * * * * * * * * * * */
struct ALPHABET {
        bool check ( char character )
        {
                if (( character >= 'A' && character <= 'Z' ) || ( character >= 'a' && character <= 'z' ))
			return true;
                else
                        return false;
        }
};


/* * * * * * * * * * * * * * *
 *  Any character mask (?)   *
 * * * * * * * * * * * * * * */ 
struci JOKER {
        bool check ( char character )
        {
                return character;
        }
};


/* * * * * * * * * * * * * * * * * * * * * * * * * * 
 *   Upper-/Lowercase mask (any lowercase letter)  *
 * * * * * * * * * * * * * * * * * * * * * * * * * */
struct CASE {
        char literal;

        bool check ( char character ) {
		/* If uppercase, check if fits with lowercase */
                if ( character >= 'A' && character <= 'Z' ) {
                        if ( character + 32 == literal )
				return true;
			else return false;

		/* If lowercase, check if fits with uppercase */
		} else if ( character >= 'a' && character <= 'z' ) { 
			if ( character - 32 == literal )
				return true;
			else return false;

		} else return false;
        }
};

struct REST {
        char literal;
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

>>>>>>> 4f0147a96f56d637e597f8d844b183bee5c95ab3
