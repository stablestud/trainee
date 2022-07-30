#include <iostream>
#include <string>

using namespace std;

int main ( void ) {
        std::string TheString;
        std::cout << "Please insert a String and I will count the words: " << std::endl;
        std::getline(std::cin,TheString);
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0, other = 0;
        for ( int _i = 0; _i <= TheString.length(); _i++ ) {
                switch ( *( TheString.substr ( _i, 1 ).c_str())) {
                        case 'a':
                        case 'A':
                                a++;
                                break;
                        case 'b':
                        case 'B':
                                b++;
                                break;
                        case 'c':
                        case 'C':
                                c++;
                                break;
                        case 'd':
                        case 'D':
                                d++;
                                break;
                        case 'e':
                        case 'E':
                                e++;
                                break;
                        case 'f':
                        case 'F':
                                f++;
                                break;
                        case 'g':
                        case 'G':
                                g++;
                                break;
                        case 'h':
                        case 'H':
                                h++;
                                break;
                        case 'i':
                        case 'I':
                                i++;
                                break;
                        case 'j':
                        case 'J':
                                j++;
                                break;
                        case 'k':
                        case 'K':
                                k++;
                                break;
                        case 'l':
                        case 'L':
                                l++;
                                break;
                        case 'm':
                        case 'M':
                                m++;
                                break;
                        case 'n':
                        case 'N':
                                n++;
                                break;
                        case 'o':
                        case 'O':
                                o++;
                                break;
                        case 'p':
                        case 'P':
                                p++;
                                break;
                        case 'q':
                        case 'Q':
                                q++;
                                break;
                        case 'r':
                        case 'R':
                                r++;
                                break;
                        case 's':
                        case 'S':
                                s++;
                                break;
                        case 't':
                        case 'T':
                                t++;
                                break;
                        case 'u':
                        case 'U':
                                u++;
                                break;
                        case 'v':
                        case 'V':
                                v++;
                                break;
                        case 'w':
                        case 'W':
                                w++;
                                break;
                        case 'x':
                        case 'X':
                                x++;
                                break;
                        case 'y':
                        case 'Y':
                                y++;
                                break;
                        case 'z':
                        case 'Z':
                                z++;
                                break;
                        default:
                                other++;
                                break;
                }
        }

        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "c: " << c << endl;
        cout << "d: " << d << endl;
        cout << "e: " << e << endl;
        cout << "f: " << f << endl;
        cout << "g: " << g << endl;
        cout << "h: " << h << endl;
        cout << "i: " << i << endl;
        cout << "j: " << j << endl;
        cout << "k: " << k << endl;
        cout << "l: " << l << endl;
        cout << "m: " << m << endl;
        cout << "n: " << n << endl;
        cout << "o: " << o << endl;
        cout << "p: " << p << endl;
        cout << "r: " << r << endl;
        cout << "s: " << s << endl;
        cout << "t: " << t << endl;
        cout << "u: " << u << endl;
        cout << "v: " << v << endl;
        cout << "w: " << w << endl;
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
        cout << "z: " << z << endl;
        cout << "other: " << other << endl;
}
