#include "CharList.h"

char Node::getValue ( void )
{
	return this -> value;
}

List::List ( void ) : head ( nullptr ), tail ( head ), size ( 0U ) {}

List::~List ( void )
{
	//while ( nullptr != this -> head ) {
	for ( unsigned i = 0; i < this -> getSize(); i++ ) {
		Node* eliminate = this -> head;
		this -> head = this -> head -> next;
		delete eliminate;
	}
}

List::List ( List& list )
{
	if ( list.getSize() ) {
		/* Go from Node to Node and create a copy, and bind them */
		this -> head = new Node ( list.at ( 0 ) );
		this -> size = 1U;
		Node* current = this -> head;

		for ( unsigned i = 1U; i < list.getSize(); i++ ) {
			current -> next = new Node ( list.at ( i ) );
			Node* prevptr = current;
			current = current -> next;
			current -> prev = prevptr;
			this -> size++;
		}

		this -> tail = current;
	} else {
		this -> head = this -> tail = nullptr;
		this -> size = 0U;
	}
}

void List::push_front ( char value )
{
	Node* highest = new Node ( value );
	highest -> next = this -> head;

	this -> head = highest;

	if ( nullptr == this -> tail )
		this -> tail = highest;
	else
		this -> head -> next -> prev = this -> head;

	this -> size++;
}

void List::push_back ( char value )
{
	Node* lowest = new Node ( value );

	if ( nullptr == this -> tail ) {
		this -> tail = lowest;
		this -> head = this -> tail;
	} else {
		this -> tail -> next = lowest;
		this -> tail -> next -> prev = this -> tail;
		this -> tail = this -> tail -> next;
	}

	this -> size++;
}

bool List::pop_front ( char& value )
{
	if ( nullptr == this -> head )
		return false;
	else {
		value = this -> head -> getValue();

		if ( this -> head == this -> tail )
			this -> tail = nullptr;

		Node* old_head = this -> head;
		this -> head = this -> head -> next;

		if ( nullptr != this -> head )
			this -> head -> prev = nullptr;

		delete old_head;

		this -> size--;

		return true;
	}
}

bool List::pop_back ( char& value )
{
	if ( nullptr == this -> tail )
		return false;
	else {
		value = this -> tail -> getValue();

		this -> size--;

		if ( this -> head == this -> tail ) {
			delete this -> tail;
			this -> head = this -> tail = nullptr;
		} else {
			Node* new_tail = this -> tail -> prev;

			this -> tail -> prev -> next = nullptr;

			delete this -> tail;

			this -> tail = new_tail;
		}

		return true;
	}
}

char List::at ( unsigned index )
{
	/* If element out of range */
	if ( index >= this -> getSize() )
		return 0;

	/* If last element */
	else if ( this -> getSize() - 1U == index )
		return this -> tail -> getValue();
	else {
		Node* current = this -> head;

		for ( unsigned i = 0U; i < index; i++ )
			current = current -> next;

		return current -> getValue();
	}
}

bool List::insert_at ( unsigned index, char value )
{
	/* Check if list is empty or index is larger then the list */
	if ( index > this -> getSize() )
		return false;
	else {
		Node* insert = new Node ( value );

		if ( 0U == index ) {
			insert -> next = this -> head;

			if ( nullptr != this -> head )
				this -> head -> prev = insert;
			else
				this -> tail = insert;

			this -> head = insert;

		} else if ( this -> getSize() == index ) {
			this -> tail -> next = insert;
			insert -> prev = this -> tail;
			this -> tail = insert;
		} else {
			Node* previous = this -> head;

			for ( unsigned i = 0U; i < index - 1U; i++ )
				previous = previous -> next;

			insert -> next = previous -> next;
			insert -> prev = previous;
			previous -> next = insert;
			insert -> next -> prev = insert;
		}

		this -> size++;

                return true;
	}
}

bool List::remove_at ( unsigned index )
{
	/* Check if index is out of range */
	if ( this -> getSize() <= index )
		return true;
	else {
		/* If first element in list */
		if ( 0U == index ) {
			/* If more than one element */
			if ( nullptr != this -> head -> next ) {
				Node* new_head = this -> head -> next;
				delete this -> head;
				new_head -> prev = nullptr;
				this -> head = new_head;
			/* one element */
			} else {
				delete this -> head;
				this -> head = this -> tail = nullptr;
			}
		/* If last element in list */
		} else if ( this -> getSize() - 1 == index ) {
			Node* old_tail = this -> tail;

			this -> tail = this -> tail -> prev;
			this -> tail -> next = nullptr;

			delete old_tail;
		/* If inbetween */
		} else {
			Node* current = this -> head;

			for ( unsigned i = 0U; i < index; i++ )
				current = current -> next;

			current -> prev -> next = current -> next;
			current -> next -> prev = current -> prev;
			delete current;
		}

		this -> size--;

                return true;
	}
}

unsigned List::getSize ( void )
{
	return this -> size;
}

bool List::find ( char search, unsigned& pos )
{
        if ( 0 == this -> size )
                return false;

        for ( unsigned i = 0; i < this -> size; i++ ) {
                if ( this -> at ( i ) == search ) {
                        pos = i;
                        return true;
                }
        }

        return false;
}

bool List::find ( char search )
{
        unsigned aux;
        return find ( search, aux );
}
