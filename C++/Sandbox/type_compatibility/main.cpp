#include <iostream>
#include "person.h"
#include "customer.h"
#include "worker.h"

using std::cout;
using std::endl;
using std::cerr;
using std::string;

int main ( void )
{
        person* obj1 = new worker ( "Gustav (worker)" );
        person* obj2 = new customer ( "Hanna (customer)" );
        person* obj3 = new worker ( "Jason (worker)" );
        person* obj4 = new person ( "Rhys (person)" );

        static_cast<person*>(obj1)->meme();
        static_cast<person*>(obj2)->meme();
        static_cast<customer*>(obj3)->meme();
        static_cast<customer*>(obj4)->meme();

        delete obj1;
        delete obj2;
        delete obj3;
        delete obj4;
}
