#include <iostream>
#include <sstream>
#include <limits>
#include "../lib/data_model/inventory_data_model.h"

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
void clear_screen() {
#if defined(__linux__)
    std::cout << "\033[2J\033[1;1H";
#elif defined(_WIN32)
    std::system("cls");
#else
    for (int i = 0; i < 32; i++)
        std::cout << std::endl;
#endif
}

