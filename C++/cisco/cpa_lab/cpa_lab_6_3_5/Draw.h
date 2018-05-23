#ifndef DRAW_H
#define DRAW_H

#include <iostream>

struct POS {
	int x;
	int y;
};

typedef struct POS pos;

class Tree
{
public:
	virtual void draw ( pos* position ) const;
};

class Pinetree : public Tree
{
public:
	void draw ( pos* position ) const;
};

class Oaktree : public Tree
{
public:
	void draw ( pos* position ) const;
};

class Birchtree : public Tree
{
public:
	void draw ( pos* position ) const;
};

#endif /* DRAW_H */
