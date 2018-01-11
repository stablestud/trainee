/*
 * vector.cpp
 *
 *  Created on: 12 Jan 2018
 *      Author: stablestud
 */
#include <iostream>
#include <string>
#include <vector>
#include <array>

int main(void) {
	std::array<std::string, 10> zahl {"Erste ", "Zweite ", "Dritte ", "Vierte ", "Fuenfte ", "Sechste ", "Siebte ", "Achte ", "Neunte ", "Zehnte "};
	std::vector<int> sugar (10);

	for(unsigned int i {0}; i < sugar.size();i++) {
		std::cout << zahl.at(i) << "Zahl: ";
		std::cin >> sugar.at(i);
	}

	sugar.resize(sugar.size() + 1);
	sugar.end();
	for(auto call : sugar)
		std::cout << call << '\n';
}


