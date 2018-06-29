#include <exception>
#include <stdexcept>
#include <iostream>
#include "draughts.h"

Figure* Figure::move ( Figure &m ) const
{
        return new Figure ( m.getTeam() );
}

Knight* Knight::move ( Figure &m ) const
{
        return new Knight ( m.getTeam() );
}

King* King::move ( Figure &m ) const
{
        return new King ( m.getTeam() );
}

const unsigned Figure::getLevel ( void ) const
{
        return 0U;
}

const unsigned Knight::getLevel ( void ) const
{
        return 1U;
}

const unsigned King::getLevel ( void ) const
{
        return 2U;
}

const char* Figure::getCharacter ( void ) const
{
        return "? ";
}

const char* Knight::getCharacter ( void ) const
{
        return "K ";
}

const char* King::getCharacter ( void ) const
{
        return "M ";
}

const bool Figure::getTeam ( void ) const
{
        return this -> team;
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
	
        switch ( table [ from -> x ][ from -> y ] -> getLevel() ) {
        case 1:
                if ((((int)from->x - (int)to->x) * ((int)from->x - (int)to->x) != 1 ) || (((int)from->y - (int)to->y) * ((int)from->y - (int)to->y) != 1))
                        throw std::logic_error("Knight: Invalid move!");
                break;
        case 2:
                if ((from->x - (int)to->x) * (from->x - (int)to->x) != (from->y - (int)to->y) * (from->y - (int)to->y))
                        throw std::logic_error("King: Invalid move!");
                break;
        default:
                throw std::logic_error ( "Piece is of no type" );
        }

	table[to->x][to->y] = table[from->x][from->y]->move(*table[from->x][from->y]);
        delete table[from->x][from->y];
	table[from->x][from->y] = nullptr;
	delete from;
	delete to;
}

void Field::printTable ( void ) const
{
        std::cout << "  ";
        for ( int i = 1; i <= 8; i++ )
                std::cout << i << " ";
        std::cout << std::endl;
	for (int i = 0, j = 'A'; i < 8; i++, j++ ) {
                std::cout << (char)j << " ";
		for ( int j = 0; j < 8; j++ )
			std::cout << (( table[i][j] == nullptr ) ? "0 " : table[i][j]->getCharacter() );
		std::cout << std::endl;
	}
}
