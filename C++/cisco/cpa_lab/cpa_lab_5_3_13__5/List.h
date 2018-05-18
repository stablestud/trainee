#ifndef LIST_H
#define LIST_H

class List
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	List ( void );
	~List ( void );
	void push_top ( int value );
	void push_bot ( int value );
	bool pop_top ( int& value );
	bool pop_bot ( int& value );
	int getSize ( void );
};

#endif /* LIST_H */
