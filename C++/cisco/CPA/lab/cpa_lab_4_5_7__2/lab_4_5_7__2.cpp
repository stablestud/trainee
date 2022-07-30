#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

struct REPLACED {
        int begin = -1;
        int end = -1;
};

bool find ( string, string, REPLACED**, int& );

int main ( void )
{

        string toBeReplaced;

        cout << "What to replace: ";
        getline ( cin, toBeReplaced );
        int slength = toBeReplaced.length();

        string theReplacer;

        cout << "What instead: ";
        getline ( cin, theReplacer );

        string theActualString;

        cout << "Now tell me where: ";
        getline ( cin, theActualString );

        std::cout << "Working really hard..." << endl;

        REPLACED* arr = nullptr;
        int sREPLACED = 0;

        for (;;) {
                if ( find ( theActualString, toBeReplaced, &arr, sREPLACED ) ) {
                        theActualString = theActualString.erase ( arr[sREPLACED].begin, slength );
                        theActualString = theActualString.insert ( arr[sREPLACED].begin, theReplacer );
                        arr[sREPLACED].end = theReplacer.length() + arr[sREPLACED].begin;
                        sREPLACED++;
                } else {
                        break;
                }
        }


        for ( int x = 0; x < sREPLACED; x++ )
                cout << "[" << x << "]: begin " << arr[x].begin << ", end " << arr[x].end << endl;

        cout << "[" << theActualString << "]" << endl;

        return 0;
}

bool find ( string String, string What, REPLACED** arr, int& sREPLACED )
{
        for ( int i = 0; i < String.length(); i++ ) {
                if ( String[i] == What[0] ) {
                        bool isInside = false;

                        for ( int x = 0; x < sREPLACED; x++ )
                                if ( i >= (*arr)[x].begin && i <= (*arr)[x].end ) {
                                        isInside = true;
                                        break;
                                }
                        if ( !isInside ) {
                                for ( int j = i, k = 0;; j++, k++ ) {
                                        if ( String[j] == What[k] ) {
                                                if ( k == What.length() - 1 ) {
                                                        if ( *arr != nullptr ) {
                                                                REPLACED* aux = *arr;
                                                                *arr = new REPLACED [sREPLACED + 1];

                                                                for ( int l = 0; l < sREPLACED; l++ ) {
                                                                        (*arr)[l].begin = aux[l].begin;
                                                                        (*arr)[l].end = aux[l].end;
                                                                }

                                                                delete[] aux;
                                                        } else {
                                                                *arr = new REPLACED [sREPLACED + 1];
                                                        }

                                                        (*arr)[sREPLACED].begin = i;
                                                        return true;
                                                }
                                        } else {
                                                break;
                                        }
                                }
                        }
                }
        }

        return false;
}
