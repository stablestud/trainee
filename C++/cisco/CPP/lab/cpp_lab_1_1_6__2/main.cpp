#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<float> v(5);

	//your code
	float x;
	cin >> x;

	v = {x, x + 5.f, x + 0.5f, x + 2.3f, x + 4.7f};

	float sum = 0;
	for (auto itr : v)
		sum += itr;

	cout << "sum: " << sum << " avg: " << sum / v.size() << endl;

	return 0;
}
