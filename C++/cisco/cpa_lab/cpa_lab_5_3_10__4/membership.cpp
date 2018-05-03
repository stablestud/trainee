#include <string>
#include <iostream>
#include "membership.h"

membership::membership ( unsigned id, std::string name )
{
        this -> id = id;
        this -> name = name;
	this -> months = 0;
}

void membership::extend ( int months )
{
        this -> months += months;
}

void membership::cancel ( void )
{
        this -> months = 0;
}

void membership::print ( void )
{
        std::cout << "[" << this -> id << "] " << this -> name << ": " << this -> months << std::endl;
}
