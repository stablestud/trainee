#ifndef PIECES_H
#define PIECES_H

typedef struct {
	unsigned x;
	unsigned y;
} pos;

class Piece
{
private:
	// 0 = white, 1 = black
	bool team;
public:
	Piece ( bool whatSide ) : team ( whatSide ) {};
	Piece ( Piece &&m );
};

/* Define a new game field where every cell get managed by the object. */
class Field
{
private:
	Piece* field[8][8];
public:
	Field ( void ) : field { nullptr } {};
	void create ( Piece*, pos* );
	void move ( pos* );
};

#endif
