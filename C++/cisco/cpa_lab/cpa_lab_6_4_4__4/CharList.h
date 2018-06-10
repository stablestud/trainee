#ifndef INTLIST_H
#define INTLIST_H

class Node
{
friend class List;
private:
	char value;
	Node* next;
	Node* prev;
public:
        Node ( int value ) : value ( value ), next ( nullptr ), prev ( nullptr ) {};
	char getValue ( void );
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
	void push_front ( char value );
	void push_back ( char value );
	bool pop_front ( char& value );
	bool pop_back ( char& value );
	char at ( unsigned index );
	bool insert_at ( unsigned index, char value );
	bool remove_at ( unsigned index );
	unsigned getSize ( void );
        bool find ( char search, unsigned& pos );
        bool find ( char search );
};

#endif /* INTLIST_H */
