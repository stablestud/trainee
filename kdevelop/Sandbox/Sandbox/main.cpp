#include <iostream>
using namespace std;

struct s {
        float *f;
};

void make(s *p, float x = 10) {
        float *f = new float;
        *f = sizeof(*f) / sizeof(float) * 10;
        p->f = f;
}

int main() {
        s *ss = new s;
        make(ss);
        cout << sizeof ( float* ) / sizeof (float) * 10 << endl;
        cout << *(*ss).f;
        delete ss->f;
        delete ss;
        return 0;
}
