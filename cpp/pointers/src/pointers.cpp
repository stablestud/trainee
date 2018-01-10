/*
 * pointers.cpp
 *
 *  Created on: 9 Jan 2018
 *      Author: stablestud
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
        int * p;
        int jk {23};
        p = &jk;
        cout << "jk: " << jk << " &jk: " << &jk << endl;
        cout << " p: " << p  << "  &p: " << &p << endl;
        *p = 783;
        cout << "jk: " << jk << " &jk: " << &jk << endl;
        cout << " p: " << long(p)  << "  &p: " << &p << " *p: " << *p << endl;
        cout << "sizeof  p: " << sizeof(p) << " sizeof  &p: " << sizeof(&p) << " sizeof *p: " << sizeof(*p) << endl;
        cout << "sizeof jk: " << sizeof(jk) << " sizeof &jk: " << sizeof(&jk) << endl;
        return 0;
}
