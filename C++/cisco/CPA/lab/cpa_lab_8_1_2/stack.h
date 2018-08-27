#ifndef STACK_H
#define STACK_H

#include <iostream>

typedef double type;

class stack {
friend std::ostream& operator<< (std::ostream& o, stack& s);
	struct element {
		type cntr;	
		element* next;
		element(type);
	};
private:
	element* top;
public:
	stack() : top(0) {};
	stack(stack&) = delete;
	void operator<< (type);
	type operator>> (type&);
	type operator! (void);
};

std::ostream& operator<< (std::ostream& o, stack& s);

#endif
