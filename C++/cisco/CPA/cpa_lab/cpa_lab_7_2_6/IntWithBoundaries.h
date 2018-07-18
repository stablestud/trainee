#ifndef INTWITHBOUNDARIES_H
#define INTWITHBOUNDARIES_H

#include <exception>
#include <stdexcept>


class IntWithBoundExcep : public std::logic_error {
private:
	int err_code;
public:
	IntWithBoundExcep ( int );
	const char* what ( void ) const noexcept;
};

class IntWithBoundaries;

typedef IntWithBoundaries twb;

class IntWithBoundaries {
private:
	int value;
	const int r_min;
	const int r_max;
	void validate ( int ) const throw ( IntWithBoundExcep );
public:
	IntWithBoundaries ( int, int, int ) throw ( IntWithBoundExcep );
	int add ( int ) throw ( IntWithBoundExcep );
	int minus ( int ) throw ( IntWithBoundExcep );
	int multiply ( int ) throw ( IntWithBoundExcep );
	int divide ( int ) throw ( IntWithBoundExcep );
	int getValue ( void ) const;
	int operator+ ( int ) const;
	int operator- ( int ) const;
	int operator* ( int ) const;
	int operator/ ( int ) const;
	int operator+ ( IntWithBoundaries& ) const;
	int operator- ( IntWithBoundaries& ) const;
	int operator* ( IntWithBoundaries& ) const;
	int operator/ ( IntWithBoundaries& ) const;
	twb& operator+= ( int ) throw ( IntWithBoundExcep );
	twb& operator-= ( int ) throw ( IntWithBoundExcep );
	twb& operator*= ( int ) throw ( IntWithBoundExcep );
	twb& operator/= ( int ) throw ( IntWithBoundExcep );
	twb& operator+= ( IntWithBoundaries& ) throw ( IntWithBoundExcep );
	twb& operator-= ( IntWithBoundaries& ) throw ( IntWithBoundExcep );
	twb& operator*= ( IntWithBoundaries& ) throw ( IntWithBoundExcep );
	twb& operator/= ( IntWithBoundaries& ) throw ( IntWithBoundExcep );
	operator int();
};

#endif /* INTWITHBOUNDARIES_H */
