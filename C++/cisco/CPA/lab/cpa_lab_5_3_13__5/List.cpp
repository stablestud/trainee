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

void List::push_bot ( int value )
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

bool List::pop_top ( int& value )
{
	if ( this -> head == nullptr )
		return false;

	if ( this -> head == this -> tail )
		this -> tail = nullptr;

	value = this -> head -> getValue();

	Node* old_head = this -> head;
	this -> head = this -> head -> next;

	delete old_head;

	this -> size--;

	return true;
}

bool List::pop_bot ( int& value )
{
	if ( this -> tail == nullptr )
		return false;

	value = this -> tail -> getValue();
	
	this -> size--;

	if ( this -> head == this -> tail ) {
		delete this -> tail;
		this -> head = nullptr;
		this -> tail = nullptr;
		return true;
	}

	Node* head_pos = this -> head;
		
	while ( head_pos -> next != this -> tail )
		head_pos = head_pos -> next;

	head_pos -> next = nullptr;

	delete this -> tail;

	this -> tail = head_pos;

	return true;
}

int List::getSize ( void )
{
	return this -> size;
}
