#include <iostream>
#include <sstream>
#include <limits>
#include "../lib /function.h"

int get_valid_int() {
	std::string input;
	int value;
	bool is_valid = false;
	while (!is_valid) {
		std::cout << "enter number" << std::endl;
		std::getline(std::cin, input);
		std::istringstream iss(input);
		if (iss >> value && iss.eof()) {
			if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
				is_valid = true;
			} else {
				std::cout << "invalid input" << std::endl;
			}
		} else {
			std::cout << "invalid input" << std::endl;
		}
	}
	return value;
}
