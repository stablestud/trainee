#ifndef NODE_H
#define NODE_H

class List;

class Node
{
friend List;
private:
	int value;
	Node* next;
	Node* prev;
public:
	Node ( int value );
	~Node ( void );
	int getValue ( void );
};

#endif /* NODE_H */
