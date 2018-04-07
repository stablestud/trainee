#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::getline;
using std::endl;

struct SPAN {
        int begin = -1;
        int end = -1;
};

string* getStopWords ( void );
bool find ( string, string, struct SPAN** );

int main ( void ) {
        getStopWords();
        return 0;
}

string* getStopWords ( void )
{
        string x = "geh";
        cout << x.length() << endl;
        string input;
        getline ( cin, input );

        struct SPAN* getStopWords = nullptr;

        if ( find ( input, "geh", &getStopWords ) )
                cout << "Yep found" << endl;
        else
                cout << "Not found" << endl;

        if ( getStopWords != nullptr ) {
                cout << "SPAN count: " << getStopWords[0].begin << endl;

                for ( int i = 1; i < getStopWords[0].begin; i++ ) {
                        cout << "begin[" << i << "]: " << getStopWords[i].begin << endl;
                        cout << "end[" << i << "]: " << getStopWords[i].end << endl;
                }
        }

        return &input;
}

bool find ( string input, string searched, struct SPAN** hidder )
{
        bool foundSomething = false;

        for ( int i = 0; i < input.length(); i++ ) {
                /* Check if search is in the span area */
                if ( *hidder != nullptr && i < (*hidder)[(*hidder)[0].begin - 1].end ) {
                        i = (*hidder)[(*hidder)[0].begin - 1].end;
                }

                if ( input[i] == searched[0] )

                        for ( int j = i, k = 0; k < searched.length(); j++, k++ ) {

                                if ( input[j] != searched[k] )
                                        break;

                                if ( k == searched.length() - 1 ) {

                                        if ( *hidder == nullptr ) {
                                                *hidder = new struct SPAN[2];
                                                (*hidder)[0].begin = 2;
                                                (*hidder)[1].begin = i;
                                                (*hidder)[1].end = i + k;
                                        } else {
                                                struct SPAN* aux = *hidder;
                                                *hidder = new struct SPAN [aux[0].begin + 1];

                                                for ( int h = 1; h < aux[0].begin; h++ ) {
                                                       (*hidder)[h].begin = aux[h].begin;
                                                       (*hidder)[h].end = aux[h].end;
                                                }
                                                (*hidder)[0].begin = aux[0].begin + 1;
                                                (*hidder)[(*hidder)[0].begin].begin = i;
                                                (*hidder)[(*hidder)[0].begin].end = i + k;
                                                delete[] aux;
                                        }
                                        foundSomething = true;
                                }
                        }
        }

        if ( foundSomething )
                return true;
        else
                return false;
}
