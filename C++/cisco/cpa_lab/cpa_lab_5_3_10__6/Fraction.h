class Fraction
{
private:
	int numerator, denominator;
	void reduce ( void );
public:
	Fraction ( int numerator, int denominator );
	std::string toString ( void );
	double toDouble ( void );

	Fraction plus ( Fraction that );
	Fraction minus ( Fraction that );
	Fraction times ( Fraction that );
	Fraction by ( Fraction that );
};
