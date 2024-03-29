#include <string>
#include "Point2D.h"
#include "Line2D.h"

Line2D::Line2D ( Point2D pointA, Point2D pointB )
{
	/* Calculate the slope and y interception ... */
	this -> slope = ( pointB.getY() - pointA.getY()) / ( pointB.getX() - pointA.getX());
	y_intercept = pointA.getY() - this -> slope * pointA.getX();
}

Line2D::Line2D ( double slope, double y_intercept )
{
	this -> slope = slope;
	this -> y_intercept = y_intercept;
}

std::string Line2D::toString ( void )
{
	return "y = " + std::to_string ( this -> slope ) + "x + " + std::to_string ( this -> y_intercept );
}

bool Line2D::contains ( Point2D point )
{
	if (( this -> slope * point.getX() + this -> y_intercept ) == point.getY())
		return true;
	else
		return false;
}
