#include <iostream>
#include <stdexcept>

using namespace std;

int main(void)
{
        int a = 8, b = 0, c = 0;
        cin >> b;
        try {
                if (!b)
                        throw logic_error("Can't divide by ZERO! IDIOT...");

                c = a / b;
        } catch (logic_error& err) {
                cout << err.what() << endl;
        }

        cout << c << endl;
        return 0;
}
