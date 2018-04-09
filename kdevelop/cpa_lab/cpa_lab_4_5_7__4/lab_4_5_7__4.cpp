#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::getline;
using std::cerr;
using std::string;
using std::cin;

struct CHARACTER_TABLE {
        uint8_t a = 0;
        uint8_t b = 0;
        uint8_t c = 0;
        uint8_t d = 0;
        uint8_t e = 0;
        uint8_t f = 0;
        uint8_t g = 0;
        uint8_t h = 0;
        uint8_t i = 0;
        uint8_t j = 0;
        uint8_t k = 0;
        uint8_t l = 0;
        uint8_t m = 0;
        uint8_t n = 0;
        uint8_t o = 0;
        uint8_t p = 0;
        uint8_t q = 0;
        uint8_t r = 0;
        uint8_t s = 0;
        uint8_t t = 0;
        uint8_t u = 0;
        uint8_t v = 0;
        uint8_t w = 0;
        uint8_t x = 0;
        uint8_t y = 0;
        uint8_t z = 0;

        int out ( int pos ) {
                switch ( pos ) {
                        case 0:
                                return a;
                                break;
                        case 1:
                                return b;
                                break;
                        case 2:
                                return c;
                                break;
                        case 3:
                                return d;
                                break;
                        case 4:
                                return e;
                                break;
                        case 5:
                                return f;
                                break;
                        case 6:
                                return g;
                                break;
                        case 7:
                                return h;
                                break;
                        case 8:
                                return i;
                                break;
                        case 9:
                                return j;
                                break;
                        case 10:
                                return k;
                                break;
                        case 11:
                                return l;
                                break;
                        case 12:
                                return m;
                                break;
                        case 13:
                                return n;
                                break;
                        case 14:
                                return o;
                                break;
                        case 15:
                                return p;
                                break;
                        case 16:
                                return q;
                                break;
                        case 17:
                                return r;
                                break;
                        case 18:
                                return s;
                                break;
                        case 19:
                                return t;
                                break;
                        case 20:
                                return u;
                                break;
                        case 21:
                                return v;
                                break;
                        case 22:
                                return w;
                                break;
                        case 23:
                                return x;
                                break;
                        case 24:
                                return y;
                                break;
                        case 25:
                                return z;
                                break;
                }
        }
};

struct CHARACTER_TABLE* countCharacters ( string );

int main ( void ) {

        string input;
        getline ( cin, input );

        if ( input.find ( " " ) == string::npos ) {
                cerr << "Invalid input" << endl;
                return 1;
        }

        string firstAnagram ( input.substr ( 0, input.find_first_of ( " " ) ) );

        string secondAnagram ( input.substr ( input.find_first_of ( " " ) + 1 ) );

        if ( firstAnagram.length() != secondAnagram.length() ) {
                cerr << "Words don't have the same length!" << endl;
                return 1;
        }

        struct CHARACTER_TABLE* firstCharTable = countCharacters ( firstAnagram );
        struct CHARACTER_TABLE* secondCharTable = countCharacters ( secondAnagram );

        for ( int i = 0; i < 26; i++ )
                if ( firstCharTable->out(i) != secondCharTable->out(i) ) {
                        cout << "not anagrams" << endl;
                        return 1;
                } else if ( i == 25 )
                        cout << "anagrams" << endl;

        return 0;
}

struct CHARACTER_TABLE* countCharacters ( string word )
{
        struct CHARACTER_TABLE* charTable = new CHARACTER_TABLE;
        for ( int i = 0; i < word.length(); i++ )
                switch ( word[i] ) {
                        case 'A':
                        case 'a':
                                charTable->a++;
                                break;
                        case 'B':
                        case 'b':
                                charTable->b++;
                                break;
                        case 'C':
                        case 'c':
                                charTable->c++;
                                break;
                        case 'D':
                        case 'd':
                                charTable->d++;
                                break;
                        case 'E':
                        case 'e':
                                charTable->e++;
                                break;
                        case 'F':
                        case 'f':
                                charTable->f++;
                                break;
                        case 'G':
                        case 'g':
                                charTable->g++;
                                break;
                        case 'H':
                        case 'h':
                                charTable->h++;
                                break;
                        case 'I':
                        case 'i':
                                charTable->i++;
                                break;
                        case 'J':
                        case 'j':
                                charTable->j++;
                                break;
                        case 'K':
                        case 'k':
                                charTable->k++;
                                break;
                        case 'L':
                        case 'l':
                                charTable->l++;
                                break;
                        case 'M':
                        case 'm':
                                charTable->m++;
                                break;
                        case 'N':
                        case 'n':
                                charTable->n++;
                                break;
                        case 'O':
                        case 'o':
                                charTable->o++;
                                break;
                        case 'P':
                        case 'p':
                                charTable->p++;
                                break;
                        case 'Q':
                        case 'q':
                                charTable->q++;
                                break;
                        case 'R':
                        case 'r':
                                charTable->r++;
                                break;
                        case 'S':
                        case 's':
                                charTable->s++;
                                break;
                        case 'T':
                        case 't':
                                charTable->t++;
                                break;
                        case 'U':
                        case 'u':
                                charTable->u++;
                                break;
                        case 'V':
                        case 'v':
                                charTable->v++;
                                break;
                        case 'W':
                        case 'w':
                                charTable->w++;
                                break;
                        case 'X':
                        case 'x':
                                charTable->x++;
                                break;
                        case 'Y':
                        case 'y':
                                charTable->y++;
                                break;
                        case 'Z':
                        case 'z':
                                charTable->z++;
                                break;
                }
        return charTable;
}
