#include <stdexcept>
#include <iostream>

#include "stack.h"

stack::element::element(type t) : cntr(t), next(0) {};

// aka Push
void stack::operator<< (type t)
{
	if (0 == top)
		top = new element(t);
	else {
		element* oldTop = top;
		top = new element(t);
		top->next = oldTop;
	}
}

type stack::operator>> (type& t)
{
	if (0 == top)
		throw std::domain_error("Stack is empty.");
	
	type val = top->cntr;
	element* newTop = top->next;

	delete top;
	top = newTop;

	return t = val;
}

std::ostream& operator<< (std::ostream& o, stack& s)
{
	o << "Stack:" << std::endl;

	for (stack::element* i = s.top; 0 != i; i = i->next)
		o << i->cntr << std::endl;

	return o;
}
