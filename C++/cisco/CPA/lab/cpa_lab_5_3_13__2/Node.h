#ifndef NODE_H
#define NODE_H

class Node
{
private:
	int value;
public:
	Node ( int value );
	~Node ( void );
	int getValue ( void );
	Node* next;
};

#endif /* NODE_H */
