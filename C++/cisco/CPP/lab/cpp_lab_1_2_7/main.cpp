#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool enough_money(std::vector<std::pair<int, int>> &available, int money);

int main()
{
	// YOUR code

	std::vector<std::pair<int, int>> deposit {{ 10, 5 },
					  { 20, 6 },
					  { 50, 3 },
					  { 100, 4 },
					  { 200, 5 }};

	for (int i = 0, input; i < 2; i++) {
		std::cin >> input;

		if (enough_money(deposit, input))
			std::cout << "Enough money.\n";
		else
			std::cerr << "Not enough money/correct notes.\n";
	}

	return 0;
}

bool enough_money(std::vector<std::pair<int, int>> &avai, int money)
{
	std::vector<std::pair<int, int>>::reverse_iterator ritr = avai.rbegin();
	int money_sum = 0;

	// Iterate through every note
	for (; ritr < avai.rend(); ritr++) {
		// Check if enough notes are availabe and if note is not too big
		if (ritr->second == 0 || ritr->first + money_sum > money)
			continue;

		// Iterate through amount of available notes
		for (int count = ritr->second; count > 0; count--){
			if (money_sum + ritr->first > money)
				break;
			else
				money_sum += ritr->first;
		}
	}

	if (money_sum == money)
		return true;
	else
		return false;
}
