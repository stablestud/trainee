#ifndef PIECES_H
#define PIECES_H

typedef struct {
	unsigned x;
	unsigned y;
} pos;

class Figure {
private:
	// 0 = white, 1 = black
	bool team;
public:
	Figure ( bool whatSide ) : team ( whatSide ) {};
	Figure ( Figure &m );
};

/* Define a new game field where every cell get managed by the object. */
class Field {
private:
	Figure* table[8][8];
public:
	Field ( void ) : table { nullptr } {};
	void create ( Figure*, pos* ) throw ( std::logic_error, std::range_error );
	void remove ( pos* ) throw ( std::logic_error, std::range_error );
	void move ( pos* from, pos* to ) throw ( std::logic_error, std::range_error );
	void printTable ( void ) const;
};

#endif
