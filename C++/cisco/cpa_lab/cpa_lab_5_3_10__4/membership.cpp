#include <string>
#include "membership.h"

membership::membership ( unsigned id, std::string name )
{
        membership::id = id;
        membership::name = name;
}

void membership::extend ( int months )
{
        membership::months += months;
}

void membership::cancel ( void )
{
        membership::months = 0;
}
