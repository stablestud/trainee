#ifndef FRACTION_H
#define FRACTION_H

/* 
 * Fraction
 * - - - - - -
 * reduce operator!
 * operators for addition, subtraction, multiplication, division
 * private helper function that determine the Greatest Common Divisor and Lowest Common Divisor
 * function that convert fraction 3/5 to human readable format "three fifths"
 * into double
 * overloaded stream operator for displaying directly on the stream
 *
 * double var = fraction1 + 8;
 * Fraction f = 9;
 */

class Fraction {
private:
	int numerator, denominator;
public:
	Fraction() : numerator(0), denominator(1) {}
	Fraction(int num) : numerator(num), denominator(1) {}
	Fraction(int num, int denum) : numerator(num), denominator(denum) {}
	Fraction(Fraction& f) : 
	Fraction& add ( Fraction& );
	Fraction& add ( double );
	Fraction& subtract ( Fraction& );
	Fraction& subtract ( double );
	Fraction& multiply ( Fraction& );
	Fraction& multiply ( double );
	Fraction& divide ( Fraction& );
	Fraction& divide ( double ); 
	Fraction& operator! (void);
	Fraction& operator+ (Fraction&);
	Fraction& operator+ (double);
	Fraction& operator- (Fraction&);
	Fraction& operator- (double);
	Fraction& operator* (Fraction&);
	Fraction& operator* (double);
	Fraction& operator/ (Fraction&);
	Fraction& operator/ (double);
	Fraction& operator= (double);
	Fraction& operator+= (Fraction&);
	Fraction& operator+= (double);
	Fraction& operator-= (Fraction&);
	Fraction& operator-= (double);
	Fraction& operator*= (Fraction&);
	Fraction& operator*= (double);
	Fraction& operator/= (Fraction&);
	Fraction& operator/= (double);
};

ostream& operator<< (ostream&, Fraction&);
double operator+ (double, Fraction&);
double operator- (double, Fraction&);
int operator* (int, Fraction&);
int operator/ (int, Fraction&);

#endif /* FRACTION_H */
