#include "Node.h"
#include "List.h"

List::List ( void ) : head ( nullptr ), tail ( head ), size ( 0 ) {}

List::~List ( void )
{
	while ( this -> head != nullptr ) {
		Node* jump = this -> head -> next;
		delete this -> head;
		this -> head = jump;
	}
}

void List::push_top ( int value )
{
	Node* highest = new Node ( value );
	highest -> next = this -> head;

	this -> head = highest;

	if ( this -> tail == nullptr )
		this -> tail = highest;

	this -> size++;
}

void List::push_back ( int value )
{
	Node* lowest = new Node ( value );

	if ( this -> tail == nullptr ) {
		this -> tail = lowest;
		this -> head = this -> tail;
	} else {
		this -> tail -> next = lowest;
		this -> tail = this -> tail -> next;
	} 

	this -> size++;
}

bool List::pop ( int& value )
{
	if ( head == nullptr )
		return false;

	if ( head == tail )
		this -> tail = nullptr;

	value = this -> head -> getValue();

	Node* old_head = this -> head;
	this -> head = this -> head -> next;

	delete old_head;

	this -> size--;

	return true;
}

int List::getSize ( void )
{
	return this -> size;
}
