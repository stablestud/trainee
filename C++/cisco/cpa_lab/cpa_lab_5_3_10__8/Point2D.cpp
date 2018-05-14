#include <string>
#include <cmath>
#include "Point2D.h"

Point2D::Point2D ( double x, double y )
{
	this -> x = x;
	this -> y = y;
}

std::string Point2D::toString ( void )
{
	return "";
}

double Point2D::toDouble ( void )
{
	return 0.;
}

double Point2D::distanceTo ( Point2D that )
{
	/* Calculate the length of each side */
	double y = this -> y - that.returnY();
	double x = this -> x - that.returnX();

	return std::sqrt ( y * y + x * x );
}

double Point2D::returnX ( void )
{
	return this -> x;
}

double Point2D::returnY ( void )
{
	return this -> y;
}
