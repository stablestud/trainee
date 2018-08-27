class Point2D
{
private:
	double x, y;
public:
	Point2D ( double x, double y );
	std::string toString ( void );
	double toDouble ( void );
	double distanceTo ( Point2D that );
	double returnX ( void );
	double returnY ( void );
};
