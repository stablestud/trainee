#include <iostream>
#include <string>

using namespace std;

int main ( void )
{
        /*
        std::string string_one { "Ok, so I'm a variable?" };
        std::string string_two = "I'm Bob";
        std::string string_three ( "\"Savage mode accepted\"" );
        cout << string_one + " Yes, looks like it." << endl;
        cout << string_two + ", what's your name?" << endl;
        cout << "Jeremy said: " + string_three << endl;

        // Create new string with content of another
        string new_one ( string_two );
        cout << "new_one has been declared with string_two: " + new_one << endl;

        // Input full sentences, ignoring whitespaces
        string overwrite_me;
        cout << "Type a sentence: ";
        getline ( cin, overwrite_me );
        cout << "Your input is: " + overwrite_me << endl;

        // Replace new_one's content with the content of overwrite_me
        new_one.assign ( overwrite_me );
        cout << new_one << endl;
        new_one = string_two + " and me";
        cout << new_one << endl;
        */
        
        string str1, str2;
        str1 ( "ABCDEF" );
        str2 ( str1.substr ( 1, 1 ) + str1.substr ( 4 ) + str1.substr() );
        cout << str2 << endl;


        // cout << "Sleeping 4 seconds ..." << endl;
        // system ( "sleep 4s" );
        return 0;
}
