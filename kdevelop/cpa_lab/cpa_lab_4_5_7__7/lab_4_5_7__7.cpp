#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::getline;

int main ( int argc, char **argv ) {
        cout << "Password - at least 8 characters long" << endl;
        cout << "         - at least one uppercase character" << endl;
        cout << "         - at least one lowercase character" << endl;
        cout << "         - at least one didit" << endl;
        cout << "         - at least one special character" << endl;

        char* password = new char[9];

        cout << "Enter password of length 8: ";
        cin >> password;

        int passwordLength = 0;

        for ( int i = 0; i <= 9; i++ ) {
                if ( password[i] == '\0' ) {
                        passwordLength = i;
                        break;
                }
        }

        if ( passwordLength == 0 ) {
                cerr << "Password is too long! You'll cause a buffer-overflow!" << endl;
                exit ( EXIT_FAILURE );
        } else if ( passwordLength < 8 ) {
                cerr << "Password is too short (" << passwordLength << ")" << endl;
                exit ( EXIT_FAILURE );
        }

        bool hasDigit = false, uppercase = false, lowercase = false, specialCharacter = false;

        for ( int i = 0; i < 8; i++ ) {
                if ( password[i] >= '0' && password[i] <= '9' )
                        hasDigit = true;
                else if ( password[i] >= 'a' && password[i] <= 'z' )
                        lowercase = true;
                else if ( password[i] >= 'A' && password[i] <= 'Z' )
                        uppercase = true;
                else if ( (password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') )
                        specialCharacter = true;
        }

        if ( !hasDigit )
                cerr << "Password does not have a digit!" << endl;
        if ( !uppercase )
                cerr << "Password does not have a uppercase letter!" << endl;
        if ( !lowercase )
                cerr << "Password does not have a lowercase letter!" << endl;
        if ( !specialCharacter )
                cerr << "Password does not have a specialCharacter!" << endl;
        if ( hasDigit && uppercase && lowercase && specialCharacter )
                cout << "Password is valid!" << endl;
        return 0;
}
