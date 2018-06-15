#include <exception>
#include <stdexcept>
#include "IntWithBoundaries.h"

IntWithBoundExcep::IntWithBoundExcep ( int err_code ) : std::logic_error ( "ok" )
{
}

const char* IntWithBoundExcep::what ( void ) const noexcept
{
	const char* c = std::logic_error::what();
	const char* re;

	switch ( *c ) {
	case 0x1:
		re = "Min is greater than Max.";
		break;
	case 0x2:
		re = "Value can't be smaller than Min.";
		break;
	case 0x3:
		re = "Value can't be greater than Max.";
		break;
	default:
		re = "Something went wrong. Please try again now.";
		break;
	}

	return re;
}

IntWithBoundaries::IntWithBoundaries ( int v, int min, int max )
	throw ( IntWithBoundExcep )
	: value ( v ), r_min ( min ), r_max ( max )
{
	if ( r_min > r_max )
		throw IntWithBoundExcep ( 0x1 );

	if ( value < r_min )
		throw IntWithBoundExcep ( 0x2 );
	
	if ( value > r_max )
		throw IntWithBoundExcep ( 0x3 );
}

int IntWithBoundaries::add ( int v ) throw ( IntWithBoundExcep )
{
	int tmp = value;
	tmp =+ v;

	validate ( tmp );

	return value = tmp;
}

int IntWithBoundaries::minus ( int v ) throw ( IntWithBoundExcep )
{
	int tmp = value;
	tmp =- v;

	validate ( tmp );

	return value = tmp;
}

int IntWithBoundaries::multiply ( int v ) throw ( IntWithBoundExcep )
{
	int tmp = value;
	tmp =* v;

	validate ( tmp );

	return value = tmp;
}

int IntWithBoundaries::divide ( int v ) throw ( IntWithBoundExcep )
{
	int tmp = value;
	tmp =/ v;

	validate ( tmp );

	return value = tmp;
}

int IntWithBoundaries::getValue ( void ) const
{
	return value;
}

void IntWithBoundaries::validate ( int tmp ) const throw ( IntWithBoundExcep )
{
	if ( tmp < r_min )
		throw IntWithBoundExcep ( 0x2 );

	if ( tmp > r_max )
		throw IntWithBoundExcep ( 0x3 );
}
