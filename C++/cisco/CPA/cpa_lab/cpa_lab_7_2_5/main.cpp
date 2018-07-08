#include <iostream>

#include "matrices.h"

int main(void)
{
        matrix m1(2, 2);
        m1.add_to(1, 1, 3);
        m1.add_to(2, 1, 9);
        matrix m2(2, 2);
        m2.add_to(1, 1, 1);
        m2.add_to(2, 2, 8);
        matrix m3(3, 3);
        try {
                m1.print();
                m1.combine(m2);
                m1.print();
        } catch (std::domain_error& dme) {
                std::cout << dme.what() << std::endl;
        }

        try {
                m2.combine(m3);
        } catch (std::domain_error& dme) {
                std::cout << dme.what() << std::endl;
        }
}
