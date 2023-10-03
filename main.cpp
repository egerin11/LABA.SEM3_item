#include <iostream>

#include"lib /data_model/invertary_data_model.h"
#include "garbage/dynamic_array.h"
#include <any>
#include "lib /view/inventory.h"

int main() {
Inventory inventory1;
	InventoryDataModel inventoryDataModel;
	int number;
	//int number;
	DynamicArray<std::any> inventory;
	//inventoryDataModel.add_new_item();
//	std::string name;
//	double weight;
//	std::string record1;
//	std::string record2;
//	std::string record3;
//	std::cout << "input name:" << std::endl;
//	std::getline(std::cin, name);
//	std::cout << "input weight:" << std::endl;
//	std::cin >> weight;
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	std::cout << "input buf" << std::endl;
//	std::getline(std::cin, record1);
//	std::cout << "input damage" << std::endl;
//	std::getline(std::cin, record2);
//	std::cout << "input strength" << std::endl;
//	std::getline(std::cin, record3);
//	Weapon weapon(name, weight, record1, record2, record3);
//	weapon.info();
//	inventory.add(weapon);
//	inventory1.inv_info();
	//weapon.set_id(last_id++);
//	inventory.add(weapon);
	do {
		number = get_valid_int();

		switch (number) {
			case 1:
				inventory1.add_item();
				break;
			case 2:
				inventory1.inv_info();
				break;
			default: {
			}

		}
	} while (number != 3);
	
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
