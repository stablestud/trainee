#ifdef INTWITHBOUNDARIES_H
#define INTWITHBOUNDARIES_H

class IntWithBoundaries {
private:
	int value;
public:
	IntWithBoundaries ( int v, int min, int max );
	int add ( int v );
	int minus ( int v );
	int multiply ( int v );
	int divide ( int v );
	int getValue ( void );
};

#endif /* INTWITHBOUNDARIES_H */
