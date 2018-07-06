#include "tower_of_hanoi.h"

TOH::tower::tower(bool empty)
{
	/* Create a filled tower, depending on constructor argument */
	if (false == empty) {
		top = new disk(1);
		top->next = new disk(2);
		top->next->next = new disk(3);
	}
}

void TOH::tower::move_to (TOH::tower& t)
{
	if (nullptr == top)
		/* throw exeption as THIS tower is empty */

	/* If the 'to move to' tower is empty or holds a bigger disk, allow the move */
	if (nullptr == t.top || t.top->size > top->size ) { /** This can cause an error if t.top is NULLPTR!
								Short-circut evaluation might not take affect! **/
		/* Save t's current top, and the next obj from this tower */
		disk* oldTtop = t.top;
		disk* next = top->next;

		/* Move this top to the top of t's */
		t.top = top;
		/* Add the t's old top to next at t's new top */
		t.top->next = oldTtop;
		/* This top gets removed, and top points now to its underlying obj */
		top = next;
	} else {
		/* Throw exception, t.top has a smaller disk, than the one 'to be moved' */
	}

	/* New top (head) of this tower is now its underlying disk or nullptr. */
}

void TOH::tower::operator<< (TOH::tower& t)
{
	t.move_to(*this);
}

void TOH::tower::operator>> (TOH::tower& t)
{
	move_to(t);
}

void TOH::tower::print(void) const
{
	/* Iterate through top */
}

void TOH::print(tower& t1, tower& t2, tower& t3) const
{
	t1.print();
	t2.print();
	t3.print();
}
