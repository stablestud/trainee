#ifndef INTLIST_H
#define INTLIST_H

class Node
{
friend class List;
private:
	int value;
	Node* next;
	Node* prev;
public:
        Node ( int value ) : value ( value ), next ( nullptr ), prev ( nullptr ) {};
	int getValue ( void );
};

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
	bool insert_at ( unsigned index, int value );
	bool remove_at ( unsigned index );
	unsigned getSize ( void );
};

#endif /* INTLIST_H */
