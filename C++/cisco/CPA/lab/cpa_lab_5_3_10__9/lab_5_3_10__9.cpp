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

	Line2D lineA ( pointA, pointB );
	std::cout << lineA.toString() << std::endl;

	return 0;
}
