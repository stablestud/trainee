#include <iostream>

namespace banana {
        int apes = 778;

        int do_it ( void ) {
                std::cout << "Mashalla: ";
                std::cout << apes << std::endl;
                return 0;
        }

        struct Structbase {
                int kay = apes;

                int do_it_twice ( void ) {
                        std::cout << kay;
                        return 999;
                }
        } Meh = { 11111 };

        namespace HUND {
                int i = 4;
                int j = 3;
                Structbase man = { 44444 };
        }
}

namespace sort = banana;
namespace piece_of_shit = std;

using namespace piece_of_shit;

int main ( int argc, char **argv )
{
        piece_of_shit::cout << "Hello, world!" << std::endl;
        piece_of_shit::cout << sort::do_it() << ":" << banana::apes << std::endl;
        std::cout << banana::Meh.do_it_twice() << "-" << sort::HUND::j << endl;
        std::cout << sort::HUND::man.do_it_twice() << piece_of_shit::endl;
        return 0;
}
