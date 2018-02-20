#include <iostream>
#include <climits>
#include <cinttypes>
#include <stdbool.h>
#include <limits>

using namespace std;

struct f {
        unsigned int flag : 1;
        signed int num : 4;
        signed int : 3;
} baum;

int main ( void )
{
        cout << baum.flag << " " << baum.num << endl;
        baum.flag = 1;
        cout << baum.flag << " " << baum.num << endl;
        return 0;
}



