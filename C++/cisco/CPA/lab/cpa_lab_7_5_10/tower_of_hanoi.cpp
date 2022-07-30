#include <iostream>
#include <stdexcept>
#include "tower_of_hanoi.h"

TOH::tower::tower(bool empty) : top(nullptr)
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
		throw std::domain_error("Can't move as source tower holds no disk.");

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
		throw std::domain_error("Can't move to tower, destination has a smaller disk.");
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
	disk* ptr = top;

	if (ptr == nullptr)
		std::cout << "empty";

	int loops = 0;
	int lookup_tbl[3];

	while (ptr != nullptr) {
		lookup_tbl[loops++] = ptr->size;
		ptr = ptr->next;
	}

	for (int i = loops; i > 0; i--)
		std::cout << lookup_tbl[i - 1] << ' ';
}

bool TOH::tower::isOcc(void) const
{
	if (nullptr == top)
		return false;
	else if (nullptr == top->next)
		return false;
	else if (nullptr == top->next->next)
		return false;
	/* Following checks should not be needed, but safe is safe */
	else if ((1 != top->size) || (2 != top->next->size) || (3 != top->next->next->size))
		return false;
	else
		return true;
}

void TOH::game::move(int from, int to)
{
	if (from > 3 || from < 0)
		throw std::domain_error("No 'from' tower of that size");

	if (to > 3 || to < 0)
		throw std::domain_error("No 'to' tower of that size");
	
	if (to == from)
		throw std::domain_error("Source and destination tower are the same.");

	static tower* const lookup_tb[3] = { &t1, &t2, &t3 };
	*lookup_tb[to - 1] << *lookup_tb[from - 1];
	steps++;
}

bool TOH::game::finito(void) const
{
	if ((t1.isOcc() == t2.isOcc()) && t3.isOcc()) {
		std::cout << "You did it with " << steps << " steps." << std::endl;
		print();
		return true;
	} else 
		return false;
}

void TOH::game::print(void) const
{
	std::cout << "Tower1: ";
	t1.print();
	std::cout << std::endl;

	std::cout << "Tower2: ";
	t2.print();
	std::cout << std::endl;

	std::cout << "Tower3: ";
	t3.print();
	std::cout << std::endl;
}
