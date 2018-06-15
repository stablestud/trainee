#ifndef INTWITHBOUNDARIES_H
#define INTWITHBOUNDARIES_H

#include <exception>
#include <stdexcept>

class IntWithBoundExcep : public std::logic_error {
public:
	IntWithBoundExcep ( const int );
	const char* what ( void ) const noexcept;
};

class IntWithBoundaries {
private:
	int value;
	int r_min;
	int r_max;
public:
	IntWithBoundaries ( int, int, int );
	int add ( int );
	int minus ( int );
	int multiply ( int );
	int divide ( int );
	int getValue ( void );
};

#endif /* INTWITHBOUNDARIES_H */
