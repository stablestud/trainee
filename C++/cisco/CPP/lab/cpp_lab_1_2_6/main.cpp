#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	vector<string> ip_table {"127.0.0.1", "192.168.0.1", "192.168.1.100", "255.255.255.255"};
	// your code
	
	vector<string> new_ip_table(ip_table);

	int input;
	cin >> input;

	if (new_ip_table.begin() + input > new_ip_table.end()) {
		cerr << "Too big - value must be smaller than or"
		"equal to vector size\n";
		return 1;
	}

	
	for (vector<string>::iterator stritr = new_ip_table.begin();
		stritr < new_ip_table.begin() + input;
		stritr++)
		cout << *stritr << " ";

	cout << endl;

	return 0;
}
