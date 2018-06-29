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
	return std::to_string ( this -> x ) + " : " + std::to_string ( this -> y );
}

double Point2D::distanceTo ( Point2D pointB )
{
	double deltaX = this -> x - pointB.getX(), deltaY = this -> y - pointB.getY();

	return std::sqrt ( deltaX * deltaX + deltaY * deltaY );
}

double Point2D::getX ( void )
{
	return this -> x;
}

double Point2D::getY ( void )
{
	return this -> y;
}
