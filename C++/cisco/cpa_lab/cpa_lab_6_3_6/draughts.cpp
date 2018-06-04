#include <exception>
#include <stdexcept>
#include <iostream>
#include "draughts.h"

Figure::Figure ( Figure &m )
{
	this -> team = m.team;
	delete &m;
}

void Field::create ( Figure* figure, pos* pos_ptr ) throw ( std::logic_error, std::range_error )
{
	if ( pos_ptr -> y <  0
	  || pos_ptr -> y >= 8
	  || pos_ptr -> x <  0  
	  || pos_ptr -> x >= 8  )
		throw std::range_error ( "Position out of range" );

	if ( table [ pos_ptr -> x ][ pos_ptr -> y ] != nullptr )
		throw std::logic_error ( "Already occupied" );

	table [ pos_ptr -> x ][ pos_ptr -> y ] = figure;
	delete pos_ptr;
}

void Field::remove ( pos* pos_ptr ) throw ( std::logic_error, std::range_error )
{
	if ( pos_ptr -> y <  0
	  || pos_ptr -> y >= 8
	  || pos_ptr -> x <  0
	  || pos_ptr -> x >= 8 )
	  	throw std::range_error ( "Position out of range" );
	
	if ( table [ pos_ptr -> x ][ pos_ptr -> y ] == nullptr )
		throw std::logic_error ( "Already deleted" );
	
	delete table [ pos_ptr -> x ][ pos_ptr -> y ];
	table [ pos_ptr -> x ][ pos_ptr -> y ] = nullptr;
	delete pos_ptr;
}

/* TODO: check if a move to the position is valid */
void Field::move ( pos* from, pos* to ) throw ( std::logic_error, std::range_error )
{
	if ( from -> y <  0
	  || from -> y >= 8
	  || from -> x <  0
	  || from -> x >= 8 )
	  	throw std::range_error ( "'from' position out of range" );

	if ( to -> y <  0
	  || to -> y >= 8
	  || to -> x <  0
	  || to -> x >= 8 )
	  	throw std::range_error ( "'to' position out of range" );
	
	if ( table [ from -> x ][ from -> y ] == nullptr )
		throw std::logic_error ( "'from' is empty" );

	if ( table [ to -> x ][ to -> y ] != nullptr )
		throw std::logic_error ( "'to' is not empty" );
	
	table[to->x][to->y] = new Figure ( *table[from->x][from->y] );
	table[from ->x][from->y] = nullptr;
	delete from;
	delete to;
}

void Field::printTable ( void ) const
{
	for ( int i = 0; i < 8; i++ ) {
		for ( int j = 0; j < 8; j++ )
			std::cout << (( table[i][j] == nullptr ) ? "0 " : "X " );
		std::cout << std::endl;
	}
}
