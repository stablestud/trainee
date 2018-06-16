#include <exception>
#include <stdexcept>
#include "IntWithBoundaries.h"

IntWithBoundExcep::IntWithBoundExcep ( int err_code ) : std::logic_error ( "" ), err_code ( err_code ) {}

const char* IntWithBoundExcep::what ( void ) const noexcept
{
	const char* re;

	switch ( err_code ) {
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
		re = "Something went wrong. Please fix.";
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
	validate ( value + v );
	return value = v;
}

int IntWithBoundaries::minus ( int v ) throw ( IntWithBoundExcep )
{
	validate ( value - v );
	return value = v;
}

int IntWithBoundaries::multiply ( int v ) throw ( IntWithBoundExcep )
{
	validate ( v = value * v );
	return value = v;
}

int IntWithBoundaries::divide ( int v ) throw ( IntWithBoundExcep )
{
	validate ( v = value / v );
	return value = v;
}

int IntWithBoundaries::getValue ( void ) const
{
	return value;
}

void IntWithBoundaries::validate ( int v ) const throw ( IntWithBoundExcep )
{
	if ( v < r_min )
		throw IntWithBoundExcep ( 0x2 );

	if ( v > r_max )
		throw IntWithBoundExcep ( 0x3 );
}

int IntWithBoundaries::operator+ ( int v ) const
{
	return value + v;
}

int IntWithBoundaries::operator- ( int v ) const
{
	return value - v;
}

int IntWithBoundaries::operator* ( int v ) const
{
	return value * v;
}

int IntWithBoundaries::operator/ ( int v ) const
{
	return value / v;
}

int IntWithBoundaries::operator+ ( IntWithBoundaries& v ) const
{
	return operator+ ( v.getValue() );
}

int IntWithBoundaries::operator- ( IntWithBoundaries& v ) const
{
	return operator- ( v.getValue() );
}

int IntWithBoundaries::operator* ( IntWithBoundaries& v ) const
{
	return operator* ( v.getValue() );
}

int IntWithBoundaries::operator/ ( IntWithBoundaries& v ) const
{
	return operator/ ( v.getValue() );
}

int IntWithBoundaries::operator+= ( int v ) throw ( IntWithBoundExcep )
{
	return add ( v );
}

int IntWithBoundaries::operator-= ( int v ) throw ( IntWithBoundExcep )
{
	return minus ( v );
}

int IntWithBoundaries::operator*= ( int v ) throw ( IntWithBoundExcep )
{
	return multiply ( v );
}

int IntWithBoundaries::operator/= ( int v ) throw ( IntWithBoundExcep )
{
	return divide ( v );
}

int IntWithBoundaries::operator+= ( IntWithBoundaries& v ) throw ( IntWithBoundExcep )
{
	return operator+= ( v.getValue() );
}

int IntWithBoundaries::operator-= ( IntWithBoundaries& v ) throw ( IntWithBoundExcep )
{
	return operator-= ( v.getValue() );
}

int IntWithBoundaries::operator*= ( IntWithBoundaries& v ) throw ( IntWithBoundExcep )
{
	return operator*= ( v.getValue() );
}

int IntWithBoundaries::operator/= ( IntWithBoundaries& v ) throw ( IntWithBoundExcep )
{
	return operator/= ( v.getValue() );
}
