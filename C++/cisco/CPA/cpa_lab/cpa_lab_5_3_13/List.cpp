#include "Node.h"
#include "List.h"

List::List ( void ) : head ( nullptr ) {}

void List::push ( int value )
{
	Node* new_head = new Node ( value );
	new_head -> next = this -> head;
	this -> head = new_head;
}

bool List::pop ( int& value )
{
	if ( !this -> head )
		return false;
	
	value = head -> getValue();

	Node* old_head = head;
	head = head -> next;

	delete old_head;

	return true;
}
