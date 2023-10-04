#include <iostream>
#include <sstream>
#include <limits>
#include <fstream>
#include"../lib /data_model/invertary_data_model.h"

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

void parse_file(DynamicArray<std::any> &inventory) {
	InventoryDataModel inventoryDataModel;
	std::string buffer;
	std::ifstream file;
	file.open("items.txt");
	if (file.is_open()) {
		while (getline(file, buffer)) {
			std::string name;
			int max_value;
			double weight;
			int id;
			std::string string1;
			std::string string2;
			std::string string3;
			std::string type;
			std::istringstream iss(buffer);
			if (!(iss >> type >> name >> max_value >> weight >> id >> string1 >> string2 >> string3)) {
				if (type == "weapon") {
					Weapon weapon(name, weight, string1, string2, string3);
					weapon.set_id(id);
					inventoryDataModel.add<Weapon>(weapon,inventory);
				} else if (type == "potion") {
					Potion potion(name, max_value, weight, string1, string2, string3);
					potion.set_id(id);
					inventoryDataModel.add<Potion>(potion,inventory);
				}
				else if(type=="resource")
				{
					Resource resource(name, max_value, weight, string1, string2, string3);
					resource.set_id(id);
					inventoryDataModel.add<Resource>(resource,inventory);
				}
			}
		}
	}
	file.close();
}