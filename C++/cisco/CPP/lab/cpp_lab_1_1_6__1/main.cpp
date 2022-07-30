
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector <int> v(8);
	for (unsigned i = 0; i < v.size(); ++i)
	{
		v[i] = i * 2;
	}

	for (std::vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;

	cout << v.size() << endl;

	v.push_back(42);

	cout << v.size() << endl;

	v.pop_back();

	cout << v.size() << endl;

	return 0;
}
