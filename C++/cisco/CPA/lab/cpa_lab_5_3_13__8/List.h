#ifndef LIST_H
#define LIST_H

class Node;

class List
{
private:
	Node* head;
	Node* tail;
	unsigned size;
public:
	List ( void );
	~List ( void );
	List ( List& list );
	void push_front ( int value );
	void push_back ( int value );
	bool pop_front ( int& value );
	bool pop_back ( int& value );
	int at ( unsigned index );
	void insert_at ( unsigned index, int value );
	void remove_at ( unsigned index );
	unsigned getSize ( void );
};

#endif /* LIST_H */
