#include "Node.h"
#include "List.h"

List::List ( void ) : head ( nullptr ), length ( 0 ) {}

List::~List ( void )
{
	while ( head != nullptr ) {
		Node* jump = head -> next;
		delete head;
		head = jump;
	}
}

void List::push ( int value )
{
	Node* new_head = new Node ( value );
	new_head -> next = this -> head;
	this -> head = new_head;
	this -> length++;
}

bool List::pop ( int& value )
{
	if ( !this -> head )
		return false;
	
	value = head -> getValue();

	Node* old_head = head;
	head = head -> next;

	delete old_head;

	this -> length--;

	return true;
}

int List::size ( void )
{
	return this -> length;
}
