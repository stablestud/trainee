#ifndef LINE2D_H
#define LINE2D_H

class Line2D
{
private:
	double slope, y_intercept;
public:
	Line2D ( Point2D pointA, Point2D pointB );
	Line2D ( double slope, double y_intercept );
	std::string toString ( void );
};

#endif /* LINE2D_H */
