#include "Node.h"
#include "List.h"

List::List ( void ) : head ( nullptr ), tail ( head ), size ( 0U ) {}

List::~List ( void )
{
	while ( nullptr != this -> head ) {
		Node* next = this -> head -> next;
		delete this -> head;
		this -> head = next;
	}
}

void List::push_front ( int value )
{
	Node* highest = new Node ( value );
	highest -> next = this -> head;

	this -> head = highest;

	if ( nullptr == this -> tail )
		this -> tail = highest;

	this -> size++;
}

void List::push_back ( int value )
{
	Node* lowest = new Node ( value );

	if ( nullptr == this -> tail ) {
		this -> tail = lowest;
		this -> head = this -> tail;
	} else {
		this -> tail -> next = lowest;
		this -> tail = this -> tail -> next;
	} 

	this -> size++;
}

bool List::pop_front ( int& value )
{
	if ( nullptr == this -> head )
		return false;
	else {
		value = this -> head -> getValue();

		if ( this -> head == this -> tail )
			this -> tail = nullptr;

		Node* old_head = this -> head;
		this -> head = this -> head -> next;

		delete old_head;

		this -> size--;

		return true;
	}
}

bool List::pop_back ( int& value )
{
	if ( nullptr == this -> tail )
		return false;
	else {
		value = this -> tail -> getValue();
		
		this -> size--;

		if ( this -> head == this -> tail ) {
			delete this -> tail;
			this -> head = nullptr;
			this -> tail = nullptr;
		} else {

			Node* head_pos = this -> head;
				
			while ( head_pos -> next != this -> tail )
				head_pos = head_pos -> next;

			head_pos -> next = nullptr;

			delete this -> tail;

			this -> tail = head_pos;
		}

		return true;
	}
}

int List::at ( unsigned index )
{
	/* If element out of range */
	if ( index >= this -> size )
		return 0;
	/* If last element */
	else if ( this -> size - 1U == index )
		return this -> tail -> getValue();
	else {
		Node* current = this -> head;

		for ( unsigned i = 0U; i < index; i++ )
			current = current -> next;

		return current -> getValue();
	}
}

void List::insert_at ( unsigned index, int value )
{
	/* Check if list is empty or index is larger then the list */
	if ( index > this -> size )
		return;
	else {
		Node* insert = new Node ( value );

		if ( 0U == index ) { 
			insert -> next = this -> head;
			this -> head = insert;

			if ( nullptr == this -> tail )
				this -> tail = insert;

		} else if ( this -> size == index ) {
			this -> tail -> next = insert;
			this -> tail = insert;
		} else {
			Node* prev = this -> head;

			for ( unsigned i = 0U; i < index - 1U; i++ )
				prev = prev -> next;

			insert -> next = prev -> next;
			prev -> next = insert;
		}

		this -> size++;
	}
}

void List::remove_at ( unsigned index )
{
	/* Check if index is out of range */
	if ( index >= this -> size )
		return;
	else {
		/* If first element in list */
		if ( 0U == index ) {
			if ( nullptr != this -> tail ) {
				Node* new_head = this -> head -> next;
				delete this -> head;
				this -> head = new_head;
			} else {
				delete this -> head;
				this -> head = this -> tail = nullptr;
			}
		/* If last element in list */
		} else if ( this -> size - 1 == index ) {
			Node* new_tail = this -> head;

			while ( nullptr != new_tail -> next -> next )
				new_tail = new_tail -> next;

			delete this -> tail;
			this -> tail = new_tail;
		/* If inbetween */
		} else {
			Node* prev = this -> head,* remove;

			for ( unsigned i = 0U; i < index - 1U; i++ )  
				prev = prev -> next;

			remove = prev -> next;
			prev -> next = remove -> next;
			delete remove;
		}

		this -> size--;
	}
}
		
unsigned List::getSize ( void )
{
	return this -> size;
}
