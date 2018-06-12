#ifndef CHARLIST_H
#define CHARLIST_H

/*
 * A library which provides a class of linked list saving a single character.
 * A linked list can be created simply by using the class name 'List'.
 * To add a character to it, use the push_front()/push_back() methods.
 * To return the value pushed use pop_front()/pop_back().
 */

/*
 * @author stablestud
 * @date 2018
 */

#include <exception>
#include <stdexcept>

/**
 * Class Node
 *---------------------------
 * Class that stores a single character, with pointers to the next
 * and previous class object. Used by the class 'List'.
 */

class Node
{
friend class List;
private:
        char value;
        Node* next;
        Node* prev;
public:
        Node ( int );
        Node ( Node& );
        Node ( Node* );
        const char getValue ( void );
        const Node* const getNext ( void );
        const Node* const getPrev ( void );
};

/**
 * Class List
 *-------------------------------
 * Linked list with methods which aid in data management without to worry
 * about reallocation of e.g. an array
 *
 * In this setting the class can only save one char value per element.
 * To create new elements use:
 *  - push_back
 *  - push_front
 *  - insert_at
 * To remove existing elements use:
 *  - pop_back
 *  - pop_front
 *  - remove_at
 * To get values from the list use:
 *  - at
 *  - pop_front
 *  - pop_back
 * To get information about the list use:
 *  - getSize()
 * To search through the list use:
 *  - find
 *
 **/

class List
{
private:
        Node* head;
        Node* tail;
        unsigned size;
public:
        List ( void );
        ~List ( void ) throw ( std::out_of_range );
        List ( List& ) throw ( std::bad_alloc );

        /*
         * Append (back) or prepend (front) values to the list
         */
        void push_front ( const char ) throw ( std::bad_alloc );
        void push_back ( const char ) throw ( std::bad_alloc );

        /*
         * Drop value from list
         */
        char pop_front ( void ) throw ( std::out_of_range );
        char pop_back ( void ) throw ( std::out_of_range );

        /*
         * Directly access the elements (Node) interface
         */
        Node* at ( const unsigned ) throw ( std::out_of_range );

        /*
         * Manipulate list by removing or inserting inbetween the list
         */
        void insert_at ( const unsigned, const char ) throw ( std::bad_alloc, std::out_of_range );
        void remove_at ( const unsigned ) throw ( std::out_of_range );

        /*
         * Get the amount of stored elements in the list
         */
        const unsigned getSize ( void );

        /*
         * Search through the list, if found return true or false,
         * Optionally with a reference to the position at what element it
         * was found
         */
        const bool find ( const char, unsigned& ) throw ( std::out_of_range );
        const bool find ( const char ) throw ( std::out_of_range );
};

#endif /* CHARLIST_H */
