#include <iostream>
#include <deque>

using namespace std;

int main()

{
	deque<int> d1({1, 2, 3});
	deque<int> d2{4, 4, 3, 2};

	cout << d1.front() + d2.front() << " ";

	for (int d: d1)
	{
		cout << d + d2.back() << " ";
		d2.pop_back();
	}

	return 0;
}
