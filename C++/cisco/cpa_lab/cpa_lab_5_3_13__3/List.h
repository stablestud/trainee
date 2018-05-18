#ifndef LIST_H
#define LIST_H

class List
{
private:
	Node* head;
	int length;
public:
	List ( void );
	~List ( void );
	void push ( int value );
	bool pop ( int& value );
	int size ( void );
};

#endif /* LIST_H */
