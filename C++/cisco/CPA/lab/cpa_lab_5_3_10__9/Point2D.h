#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
private:
	double x, y;
public:
	Point2D ( double x, double y );
	std::string toString ( void );
	double distanceTo ( Point2D pointB );
	double getX ( void );
	double getY ( void );
};

#endif /* POINT2D_H */
