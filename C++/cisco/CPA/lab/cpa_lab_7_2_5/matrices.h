#ifndef MATRICES_H
#define MATRICES_H

class matrix {
private:
        unsigned x, y;
        int** container;
public:
        matrix(const unsigned x, const unsigned y);
        matrix(matrix& m) = delete;

        void add_to(const unsigned x, const unsigned y, const int v);
        void combine(matrix& m);
        void print(void);
};

#endif /* MATRICES_H */
