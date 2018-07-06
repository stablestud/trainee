#ifndef TOWER_OF_HANOI_H
#define TOWER_OF_HANOI_H

namespace TOH {
class disk {
friend tower::move_to, tower::tower; // Might cause an error //
private:
	int size;
	disk* next;
public:
	disk(int s) const : size(s), next(nullptr) {};
};

class tower {
	/* How do I save the disk to the tower? Natural solution would be a stack. */
	disk* top;
public:
	/* Move top disk to that tower, but also check if possible */
	tower(bool empty);
	void move_to (tower&);
	void print (void);
	void operator<< (tower&);
	void operator>> (tower&);
};

void operator<< (std::ostream, tower); // Can cause a error caused by namespace scope //
void print(tower&, tower&, tower&);
}

#endif /* TOWER_OF_HANOI_H */
