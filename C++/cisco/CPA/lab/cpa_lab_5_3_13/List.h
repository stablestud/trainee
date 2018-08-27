#ifndef LIST_H
#define LIST_H

class List
{
private:
	Node* head;
public:
	List ( void );
	void push ( int value );
	bool pop ( int& value );
};

#endif /* LIST_H */
