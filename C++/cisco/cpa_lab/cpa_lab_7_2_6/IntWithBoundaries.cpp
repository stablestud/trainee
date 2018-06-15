#include "IntWithBoundaries.h"

IntWithBoundExcep::IntWithBoundExcep ( const int err_code ) : std::logic_error ( "ok" )
{
}

IntWithBoundaries::IntWithBoundaries ( int v, int min, int max )
	: value ( v ), r_min ( min ), r_max ( max )
{
	if ( r_min > r_max )
		throw IntWithBoundExcep ( 0x4 );
}
