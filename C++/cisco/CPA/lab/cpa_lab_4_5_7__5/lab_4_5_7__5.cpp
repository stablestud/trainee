#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::getline;
using std::endl;

namespace mask
{
namespace
{

/* * * * * * * * * * *
 *  Digit mask (D)   *
 * * * * * * * * * * */
struct DIGIT {
        bool check ( char character )
        {
		/* Only digits are allowed */
                if ( character >= '0' && character <= '9')
                        return true;
                else
                        return false;
        }
};

/* * * * * * * * * * * * * * * *
 *  Latein alphabet mask (A)   *
 * * * * * * * * * * * * * * * */
struct ALPHABET {
        bool check ( char character )
        {
		/* Only characters from the Latein alphabet are allowed */
                if (( character >= 'A' && character <= 'Z' ) || ( character >= 'a' && character <= 'z' )) {
			return true;
                } else {
                        return false;
                }
        }
};

/* * * * * * * * * * * * * * *
 *  Any character mask (?)   *
 * * * * * * * * * * * * * * */
struct ANY {
        bool check ( void )
        {
                return true;
        }
};

/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Upper-/Lowercase match (any lowercase letter)  *
 * * * * * * * * * * * * * * * * * * * * * * * * * */
struct CASE {
        char literal;

        bool check ( char character )
	{
		/* If uppercase, check if fits with lowercase */
                if ( character >= 'A' && character <= 'Z' ) {
                        if ( character + 32 == literal || character == literal )
				return true;
			else return false;

		/* If lowercase, check if fits with uppercase */
                } else if ( character >= 'a' && character <= 'z' ) {
			if ( character - 32 == literal || character == literal )
				return true;
			else return false;

		} else return false;
        }
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Punctuation character mask (any punctuation character)   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct PUNCTUATION {
        char literal;

	bool check ( char character )
        {
		/* Only punctuation characters are allowed !"#$%&'()*+,-./:;<=>?@[\]^_` */
		if (( character >= ' ' && character <= '/' ) || ( character >= ':' && character <= '@' && character != '?' ) || ( character >= '[' && character <= '`' ))
			/* Character has to be equal to the specified one */
			if ( character == literal )
				return true;
			else return false;
                else return false;
        }
};

}

struct OPERATION {
	int type = 0;

	struct DIGIT* sDigit = nullptr;
	struct ALPHABET* sAlphabet = nullptr;
	struct ANY* sAny = nullptr;
	struct CASE* sCase = nullptr;
	struct PUNCTUATION* sPunctuation = nullptr;

	void setup ( char character )
	{
		/* ALPHABET mask */
		if ( character == 'A' ) {
			type = 1;
			sAlphabet = new ALPHABET;
		/* DIGIT mask */
		} else if ( character == 'D' ) {
			type = 2;
			sDigit = new DIGIT;
		/* ANY mask */
		} else if ( character == '?' ) {
			type = 3;
			sAny = new ANY;
		/* CASE match */
		} else if ( character >= 'a' && character <= 'z' ) {
			type = 4;
			sCase = new CASE { character };
		/* PUNCTUATION match */
		} else if (( character >= ' ' && character <= '/' ) || ( character >= ':' && character <= '@' && character != '?' ) || ( character >= '[' && character <= '`' )) {
			type = 5;
			sPunctuation = new PUNCTUATION { character };
		}
	}

	bool check ( char character )
	{
		switch ( type ) {
			case 1:
				return sAlphabet->check ( character );
			case 2:
				return sDigit->check ( character );
			case 3:
				return sAny->check();
			case 4:
				return sCase->check ( character );
			case 5:
				return sPunctuation->check ( character );
			default:
				return false;
		}
	}
};

}


int main ( void )
{
        cout << "A - any Latein letter" << endl;
        cout << "D - any digit" << endl;
        cout << "? - any character" << endl;
        cout << "/ - or !\"#$%&'()*+,-./:;<=>@[\\]^_` will search for the specified one" << endl;
        cout << "c - or any other Latein letter, will look for 'c' and 'C'" << endl;
        cout << "pattern: ";

        string Spattern;
        getline ( cin, Spattern );

        struct mask::OPERATION* pattern = new mask::OPERATION[Spattern.length()];

        for ( int i = 0; i < Spattern.length(); i++ )
                pattern[i].setup(Spattern[i]);

        cout << "text: ";

        string text;
        getline ( cin, text );

        if ( text.length() < Spattern.length()) {
                cerr << "Pattern is longer then the supplied text!" << endl;
                return 1;
        }

        for ( int i = 0; i < text.length(); i++ ) {
                if ( text.length() - i < Spattern.length() )
                        return 1;
                for ( int j = i, k = 0; k < Spattern.length(); j++, k++ ) {
                        if ( !(pattern[k].check ( text[j] )))
                                break;
                        if ( k == Spattern.length() - 1 ) {
                                for ( int l = i; l <= j; l++ ) {
                                        cout << text[l];
                                }

                                cout << endl;
                                break;
                        }
                }
        }


        return 0;
}
