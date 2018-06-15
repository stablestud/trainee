#ifndef INTWITHBOUNDARIES_H
#define INTWITHBOUNDARIES_H

#include <exception>
#include <stdexcept>

class IntWithBoundExcep : public std::logic_error {
public:
	IntWithBoundExcep ( int );
	const char* what ( void ) const noexcept;
};

class IntWithBoundaries {
private:
	int value;
	const int r_min;
	const int r_max;
	void validate ( void ) const;
public:
	IntWithBoundaries ( int, int, int ) throw ( IntWithBoundExcep );
	int operator+ ( int ) throw ( IntWithBoundExcep );
	int operator- ( int ) throw ( IntWithBoundExcep );
	int operator* ( int ) throw ( IntWithBoundExcep );
	int operator/ ( int ) throw ( IntWithBoundExcep );
	int operator+ ( IntWithBoundaries& ) throw ( IntWithBoundExcep );
	int operator- ( IntWithBoundaries& ) throw ( IntWithBoundExcep );
	int operator* ( IntWithBoundaries& ) throw ( IntWithBoundExcep );
	int operator/ ( IntWithBoundaries& ) throw ( IntWithBoundExcep );
	int add ( int ) throw ( IntWithBoundExcep );
	int minus ( int ) throw ( IntWithBoundExcep );
	int multiply ( int ) throw ( IntWithBoundExcep );
	int divide ( int ) throw ( IntWithBoundExcep );
	int getValue ( void ) const;
};

#endif /* INTWITHBOUNDARIES_H */
