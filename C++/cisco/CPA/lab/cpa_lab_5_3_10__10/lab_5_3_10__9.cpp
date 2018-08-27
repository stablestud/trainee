#include <iostream>
#include <string>
#include "Point2D.h"
#include "Line2D.h"

int main ( void )
{
	double x, y;

	std::cin >> x >> y;	
	Point2D pointA ( x, y );

	std::cin >> x >> y;
	Point2D pointB ( x, y );

	std::cin >> x >> y;
	Point2D pointC ( x, y );

	Line2D lineA ( pointA, pointB );

	if ( lineA.contains ( pointC ))
		std::cout << "collinear" << std::endl;
	else
		std::cout << "not collinear" << std::endl;

	return 0;
}
