#include <iostream>
#include <stdexcept>

#include "matrices.h"

matrix::matrix(const unsigned x, const unsigned y)
{
        container = new int*[x];

        for (unsigned i = 0; i < x; i++)
                container[i] = new int[y] {};

        matrix::x = x;
        matrix::y = y;
}

void matrix::add_to(const unsigned x, const unsigned y, const int v)
{
        if (x > matrix::x)
                throw std::domain_error("Supplied X position is to big.");

        if (y > matrix::y)
                throw std::domain_error("Supplied Y position is to big.");

        container[x - 1][y - 1] = v;
}

void matrix::combine(matrix& m)
{
        if (m.x != matrix::x)
                throw std::domain_error("Matrices have unequal X size.");

        if (m.y != matrix::y)
                throw std::domain_error("Matrices have unequal Y size.");

        for (unsigned i = 0; i < matrix::x; i++) {
                for (unsigned j = 0; j < matrix::y; j++)
                        matrix::container[i][j] += m.container[i][j];
        }
}

void matrix::print(void)
{
        for (unsigned i = 0; i < matrix::x; i++) {
                for (unsigned j = 0; j < matrix::y; j++)
                        std::cout << container[i][j] << " ";
                std::cout << std::endl;
        }
}
