#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::cerr;
using std::string;
using std::getline;
using std::endl;

/* EDIT TO GET DEBUG OUTPUT */
const bool debug = false;

struct SPAN {
        int begin;
        int end;
};

string* getStopWords ( int* );
bool find ( string, string, struct SPAN**, bool = false );

int main ( void )
{
        int countStopWords;
        string* stopWords = getStopWords ( &countStopWords );

        cout << "Input sentence: ";

        string sentence;

        getline ( cin, sentence );

        for ( int i = 0; i < countStopWords ; i++ ) {

                struct SPAN* tmp = nullptr;

                if ( ::debug )
                        cout << ":" << stopWords[i] << ":" << endl;

                if ( find ( sentence, stopWords[i], &tmp, true )) {

                        for ( int j = tmp[0].begin - 1; j > 0; j-- ) {

                                if ( ::debug )
                                        cout << j << ": <" << stopWords[i] << ">\t" << " begin: " << tmp[j].begin << " end: " << tmp[j].end << " ";

                                if ( tmp[j].begin != 0 && tmp[j].end + 1 != sentence.length() ) {

                                        if ( ::debug )
                                                cout << "(STD)";

                                        if ( sentence.substr ( tmp[j].end + 1, 1 ) == " " && sentence.substr ( tmp[j].begin - 1, 1 ) == " " )
                                                sentence.erase ( tmp[j].begin, stopWords[i].length() + 1 );

                                } else if ( tmp[j].begin == 0 && tmp[j].end + 1 != sentence.length() ) {
                                        if ( ::debug )
                                                cout << "(BEGIN)";

                                        if ( sentence.substr ( tmp[j].end + 1, 1 ) == " " )
                                                sentence.erase ( tmp[j].begin, stopWords[i].length() + 1 );

                                } else if ( tmp[j].end + 1 == sentence.length() && tmp[j].begin != 0 ) {

                                        if ( ::debug )
                                                cout << "(ENDE)";

                                        if ( sentence.substr ( tmp[j].begin - 1, 1 ) == " " )
                                                sentence.erase ( tmp[j].begin - 1, stopWords[i].length() + 1 );
                                } else {
                                        if ( ::debug )
                                                cout << "(REST)";
                                        sentence.erase ( tmp[j].begin, stopWords[i].length() );
                                }

                                if ( ::debug )
                                        cout << " [length: " << sentence.length() << "]" << endl;
                        }
                }
                delete[] tmp;
        }

        cout << sentence << endl;
        return 0;
}

string* getStopWords ( int* countStopWords )
{
        cout << "Input stop words (delimter by , (comma)): ";
        string input;
        getline ( cin, input );

        string* delimetered = nullptr;
        struct SPAN* StopWords = nullptr;

        if ( find ( input, ",", &StopWords ) ) {
                /* Create fields to store the delimetered words */
                delimetered = new string [StopWords->begin];
                delimetered[0] = input.substr ( 0, StopWords[1].begin );

                for ( int i = 1; i < StopWords->begin - 1; i++ )
                        delimetered[i] = input.substr ( StopWords[i].end + 1, StopWords[i + 1].begin - StopWords[i].end - 1 );

                delimetered[StopWords->begin - 1] = input.substr ( StopWords[StopWords->begin - 1].end + 1 );
                *countStopWords = StopWords->begin;
        } else {
                delimetered = new string;
                *delimetered = input;
                *countStopWords = 1;
        }

        if ( debug )
                std::cout << endl;

        if ( ::debug )
                if ( StopWords != nullptr ) {
                        cout << "-" << StopWords->begin << "- Stop words: " << endl;

                        for ( int i = 0; i < StopWords->begin; i++ )
                                cout << "[" << i + 1 << "] '"<< delimetered[i] << "' " << ( delimetered[i].length() == 0 ? "\t\t" : "\t" ) << "length: "<< delimetered[i].length() << endl;
                } else
                        cout << "[1] " << *delimetered << endl;

        if ( debug )
                std::cout << endl;

        return delimetered;
}

bool find ( string input, string searched, struct SPAN** hidder, bool ignoreCase )
{
        bool foundSomething = false;

        for ( int i = 0; i < input.length(); i++ ) {
                /* Check if search is in the span area */
                if ( *hidder != nullptr ) {
                        if ( i <= (*hidder)[(*hidder)[0].begin - 1].end )
                                i = (*hidder)[(*hidder)[0].begin - 1].end + 1;
                }

                for ( int j = i, k = 0; k < searched.length(); j++, k++ ) {
                        if ( debug )
                                cout << "j=" << j << " k=" << k << " > " << input[j] << " :: " << searched[k] << endl;

                        if ( input[j] != searched[k] && !ignoreCase ) {
                                break;
                        }
                        else if ( input[j] != searched[k] && ignoreCase ) {
                                if ( searched[k] >= 'A' && searched[k] <= 'Z' && input[j] >= 'a' && input[j] <= 'z' ) {
                                        if ( input[j] - searched[k] != 32 )
                                                break;
                                } else if ( searched[k] >= 'a' && searched[k] <= 'z' && input[j] >= 'A' && input[j] <= 'Z' ) {
                                        if ( searched[k] - input[j] != 32 )
                                                break;
                                } else
                                        break;
                        }

                        if ( k == searched.length() - 1 ) {
                                if ( *hidder == nullptr ) {
                                        *hidder = new struct SPAN[2];
                                        (*hidder)[0].begin = 2;
                                        (*hidder)[1].begin = i;
                                        (*hidder)[1].end = j;
                                } else {
                                        struct SPAN* aux = *hidder;
                                        *hidder = new struct SPAN [aux[0].begin + 1];

                                        for ( int h = 1; h < aux[0].begin; h++ ) {
                                                (*hidder)[h].begin = aux[h].begin;
                                                (*hidder)[h].end = aux[h].end;
                                        }

                                        hidder[0]->begin = aux[0].begin + 1;

                                        (*hidder)[(*hidder)[0].begin - 1].begin = i;
                                        (*hidder)[(*hidder)[0].begin - 1].end = j;

                                        delete[] aux;
                                }

                                i += searched.length() - 1;

                                foundSomething = true;

                                break;
                        }
                }
        }

        if ( foundSomething )
                return true;
        else
                return false;
}
