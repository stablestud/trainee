#include <exception>
#include <stdexcept>
#include <iostream>
#include "CharList.h"

/*
 * @author stablestud
 * @date 2018
 */


/* * * * * * * * * * * * * * * * * * *
 *  N O D E  --  D E F I N I T I O N *
 * * * * * * * * * * * * * * * * * * */

/*
 * Constructor: Node - default constructor
 * - - - - - - - - - - - - - - - - - - - - -
 * Initializes the object with the supplied value
 */

Node::Node ( const int v ) : value ( v ),
                       next ( nullptr ),
                       prev ( nullptr ) {}



/*
 * Constructor: Node - copy constructor
 * - - - - - - - - - - - - - - - - - - - -
 * Initilizes the object value copied from another object
 */

Node::Node ( Node& node ) : Node ( node.getValue() ) {}



/*
 * Constructor: Node - parameter pointer constructor
 * - - - - - - - - - - - - - - - - - - - - - - - - - -
 * Initializes the object with a value read from object pointer
 */

Node::Node (Node* node ) : Node ( node->getValue() ) {}



/*
 * Function: getValue
 * - - - - - - - - - - -
 * Read-only Interface to get the value of the Node
 *
 * returns: value of the element (Node)
 */

const char Node::getValue ( void )
{
        return this -> value;
}



/*
 * Function: getNext
 * - - - - - - - - - -
 * Read-only Interface to get the address of the next Node
 *
 * returns: address of the next Node
 */

const Node* const Node::getNext ( void )
{
        return this -> next;
}



/*
 * Function: getPrev
 * - - - - - - - - - -
 * Read-only Interface to get the address of the previous Node
 *
 * returns: address of the previous Node
 */

const Node* const Node::getPrev ( void )
{
        return this -> prev;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * C L A S S  L I S T -- F U N C T I O N  D E F I N I T I O N S            *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * Function: List - default ctor
 * - - - - - - - - - - - - - - - -
 * Initialize a new empty object
 */

List::List ( void ) : head ( nullptr ),
                      tail ( nullptr ),
                      size ( 0U ) {}



/*
 * Deconstructor: List - dtor
 * - - - - - - - - - - - - - - -
 * Deletes all dynamically created objects after end of this object
 */

List::~List ( void ) throw ( std::out_of_range )
{
        while ( this -> getSize() )
                this -> remove_at ( this -> getSize() - 1U );
}



/*
 * Constructor: List - copy constructor
 * - - - - - - - - - - - - - - - - - - - -
 * Copies all values from the other List without copying the address,
 * thus creating new objects which are being linked to each other.
 *
 * throws: if memory allocation fails
 */

List::List ( List& list ) throw ( std::bad_alloc ) : List()
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
        }
}



/* Function: push_front
 * - - - - - - - - - - - -
 * Add a value to the front (head) of the list
 *
 * value: value that should be added to the list
 *
 * throws: bad_alloc, if no memory can be allocated
 */

void List::push_front ( const char value ) throw ( std::bad_alloc )
{
        Node* new_node;

        /* Hope memory can fit a another element */
        try {
                new_node = new Node ( value );
        } catch ( std::bad_alloc ) {
                std::cerr << "push_front(): Couldn't allocate memory"
                        << std::endl;
                throw;
        }

        new_node -> next = this -> head;

        this -> head = new_node;

        if ( 0 == this -> getSize() )
                this -> tail = new_node;
        else
                this -> head -> next -> prev = this -> head;

        this -> size++;
}



/*
 * Function: push_back
 * - - - - - - - - - - -
 * Add a value to the back (tail) of the list
 *
 * value: value that should be added to the list
 *
 * throws: bad_alloc, if no memory can allocated
 */

void List::push_back ( const char value ) throw ( std::bad_alloc )
{
        Node* new_node;

        /* Hope memory can fit a another element */
        try {
                new_node = new Node ( value );
        } catch ( std::bad_alloc ) {
                std::cerr << "push_back(): Couldn't allocate memory"
                        << std::endl;
                throw;
        }

        /* If no element before */
        if ( 0 == this -> getSize() ) {
                this -> head = this -> tail = new_node;
        /* Else */
        } else {
                this -> tail -> next = new_node;
                new_node -> prev = this -> tail;
                this -> tail = new_node;
        }

        this -> size++;
}



/*
 * Function: pop_front
 * - - - - - - - - - - -
 * Return a value from the front of the list (head)
 *
 * returns: value that is on top of the list (head)
 * throws:  out_of_range, if list is empty
 */

char List::pop_front ( void ) throw ( std::out_of_range )
{
        /* List shouldn't be empty */
        if ( 0 == this -> getSize() )
                throw std::out_of_range ( "pop_front(): List is empty" );

        char value = this -> head -> getValue();

        /* If last element */
        if ( this -> head == this -> tail ) {
                delete this -> head;
                this -> head = this -> tail = nullptr;
        /* Else */
        } else {
                Node* old_head = this -> head;

                this -> head = this -> head -> next;
                this -> head -> prev = nullptr;

                delete old_head;
        }

        this -> size--;

        return value;
}



/*
 * Function: pop_back
 * - - - - - - - - - - -
 * Return a value from the back of the list (tail)
 *
 * returns: value that lais on the bottom of the list (tail)
 * throws:  out_of_range, if list is empty
 */

char List::pop_back ( void ) throw ( std::out_of_range )
{
        /* List shouldn't be empty */
        if ( 0 == this -> getSize() )
                throw std::out_of_range ( "pop_back(): List is empty" );

        char value = this -> tail -> getValue();

        /* If last element */
        if ( this -> head == this -> tail ) {
                delete this -> tail;
                this -> tail = this -> head = nullptr;
        /* Else */
        } else {
                Node* old_tail = this -> tail;

                this -> tail = this -> tail -> prev;
                this -> tail -> next = nullptr;

                delete old_tail;
        }

        this -> size--;

        return value;
}



/*
 * Function: at
 * - - - - - - - -
 * Get the element of the list at position pos
 *
 * pos: position of the element that should be returned
 *
 * returns: pointer to pos element of type Node (Node*)
 * throws:  out_of_range, if pos was greater than the list length
 */

Node* List::at ( const unsigned pos ) throw ( std::out_of_range )
{
        /* Shouldn't access non existing elements */
        if ( this -> getSize() <= pos )
                throw std::out_of_range ( "at(): Out of range" );

        Node* value;

        if ( this -> getSize() - 1U == pos ) {
                value = this -> tail;
        } else {
                value = this -> head;

                for ( unsigned i = 0U; i < pos; i++ )
                        value = value ->  next;
        }

        return value;
}



/*
 * Function: insert_at
 * - - - - - - - - - - -
 * Insert a value into the list
 *
 * pos:   position of the list the value should be inserted
 * value: value that should be inserted
 *
 * throws:  bad_alloc,    memory allocation of the new element has failed
 *          out_of_range, relaying exception from function at()
 */

void List::insert_at ( const unsigned pos, char value ) throw ( std::bad_alloc,
                                                          std::out_of_range )
{
        /* Insert at position 0 */
        if ( 0U == pos ) {
                this -> push_front ( value );
        /* Insert behind last element */
        } else if ( this -> getSize() == pos ) {
                this -> push_back ( value );
        /* Somewhere inbetween */
        } else {
                Node* insert;

                /* Hope memory can fit a another element */
                try {
                        insert = new Node ( value );
                } catch ( std::bad_alloc& ba ) {
                        std::cerr << "insert_at(): Couldn't allocate memory"
                                << std::endl;
                        throw;
                }

                Node* previous = this -> at ( pos );

                insert -> next = previous;
                insert -> prev = previous -> prev;
                previous -> prev -> next = insert;
                previous -> prev = insert;

                this -> size++;
        }
}



/*
 * Function: remove_at
 * - - - - - - - - - - -
 * Remove an element from the list
 *
 * pos: postion of element that should be deleted
 *
 * throws: out_of_range, relaying exception from function at()
 *
 */

void List::remove_at ( const unsigned pos ) throw ( std::out_of_range )
{
        /* If first element */
        if ( 0U == pos ) {
                this -> pop_front();
        /* If last element */
        } else if ( this -> getSize() - 1 == pos ) {
                this -> pop_back();
        /* If inbetween */
        } else {
                Node* bye = this -> at ( pos );

                bye -> prev -> next = bye -> next;
                bye -> next -> prev = bye -> prev;

                delete bye;

                this -> size--;
        }

}



/*
 * Function: getSize
 * - - - - - - - - - -
 * Return the amount of stored elements in the list
 */

const unsigned List::getSize ( void )
{
        return this -> size;
}



/*
 * Function: find
 * - - - - - - - - -
 * Find a value in the list
 *
 * search: value to search for
 * pos:    reference that returns the position of the element
 *         which holds the searched value
 *
 * returns: whether the value was found (true) or not (false)
 * throws:  out_of_range, if list is empty, relaying from function at()
 */

const bool List::find ( const char search, unsigned& pos ) throw ( std::out_of_range )
{
        if ( 0 == this -> size )
                return false;

        for ( unsigned i = 0; i < this -> size; i++ ) {
                if ( this -> at ( i ) -> getValue() == search ) {
                        pos = i;
                        return true;
                }
        }

        return false;
}



/*
 * Function: find
 * - - - - - - - - -
 * Overloaded find function, does not require a reference parameter
 *
 * search: value to search for
 *
 * returns: whether the value was found (true) or not (false)
 * throws: out_of_range, relaying from overloaded function find(char, unsigned&)
 */

const bool List::find ( const char search ) throw ( std::out_of_range )
{
        unsigned temp;
        return find ( search, temp );
}
