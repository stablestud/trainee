#ifndef TOWER_OF_HANOI_H
#define TOWER_OF_HANOI_H

#include <iostream>
#include <stdexcept>

namespace TOH {
class tower;

class disk {
friend class tower;
private:
	int size;
	disk* next;
public:
	disk(int s) : size(s), next(nullptr) {};
};

class tower {
	/* How do I save the disk to the tower? Natural solution would be a stack. */
	disk* top;
public:
	/* Move top disk to that tower, but also check if possible */
	tower(bool empty);
	void move_to (tower&);
	void print (void) const;
	void operator<< (tower&);
	void operator>> (tower&);
	bool isOcc(void) const;
};

class game {
	tower t1, t2, t3;
	int steps;
public:
	game() : t1(false), t2(true), t3(true), steps(0) {}
	bool finito (void) const;
	void move (int from, int to);
	void print (void) const;
};
}

#endif /* TOWER_OF_HANOI_H */
