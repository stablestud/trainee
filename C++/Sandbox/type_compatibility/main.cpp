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
        worker* obj1 = new worker ( "Gustav (worker)" );
        customer* obj2 = new customer ( "Hanna (customer)" );
        person* obj3 = new worker ( "Jason (worker)" );
        person* obj4 = new person ( "Rhys (person)" );

        obj1 -> meme();
        obj2 -> meme();
        obj3 -> meme();
        obj4 -> meme();

        delete obj1;
        delete obj2;
        delete obj3;
        delete obj4;
}
