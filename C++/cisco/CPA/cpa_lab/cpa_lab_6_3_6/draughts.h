#ifndef PIECES_H
#define PIECES_H

typedef struct {
	unsigned x;
	unsigned y;
} pos;

class Figure {
private:
	// 0 = white, 1 = black
	const bool team;
public:
	Figure ( bool whatSide ) : team ( whatSide ) {};
        virtual ~Figure ( void ) {};
        virtual const unsigned getLevel ( void ) const;
        virtual const char* getCharacter ( void ) const;
        const bool getTeam ( void ) const;
        virtual Figure* move ( Figure &m ) const;
};

class Knight : public Figure {
public:
        Knight ( bool whatSide ) : Figure ( whatSide ) {};
        const unsigned getLevel ( void ) const;
        const char* getCharacter ( void ) const;
        Knight* move ( Figure &m ) const;
};

class King : public Figure {
public:
        King ( bool whatSide ) : Figure ( whatSide ) {};
        const unsigned getLevel ( void ) const;
        const char* getCharacter ( void ) const;
        King* move ( Figure &m ) const;
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
