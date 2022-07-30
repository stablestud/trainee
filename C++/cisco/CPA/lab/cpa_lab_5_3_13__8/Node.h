#ifndef NODE_H
#define NODE_H

class Node
{
friend class List;
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
