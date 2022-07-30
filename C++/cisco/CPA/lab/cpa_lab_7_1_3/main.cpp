#include <iostream>

using namespace std;

int main(void)
{
        int a = 0, b = 0, c = 0;
        try {
                cin >> a;
                cin >> b;
                if (!b)
                        throw string("Can't divide by ZERO!");
                c = a / b;
                cout << c << endl;
        } catch (string s) {
                cout << s << std::endl;
        }

        return 0;
}
