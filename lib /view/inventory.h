//
// Created by egerin on 02.10.23.
//

#ifndef LABA_ITEM_INVENTORY_H
#define LABA_ITEM_INVENTORY_H

#include"../data_model/invertary_data_model.h"

class Inventory {

private:
	DynamicArray<std::any> inventory;
	InventoryDataModel inventoryDataModel;
public:
	void inv_info();
	
	void add_item();
};

void Inventory::inv_info() {
	for (int i = 0; i < inventory.get_size(); i++) {
		if (inventory[i].type() == typeid(Weapon)) {
			auto &otherPotion = std::any_cast<Weapon &>(inventory[i]);
			otherPotion.info();
			std::cout << std::endl;
		} else if (inventory[i].type() == typeid(Potion)) {
			auto &otherPotion = std::any_cast<Potion &>(inventory[i]);
			otherPotion.info();
			std::cout << std::endl;
		} else if (inventory[i].type() == typeid(Resource)) {
			auto &otherPotion = std::any_cast<Resource &>(inventory[i]);
			otherPotion.info();
			std::cout << std::endl;
		}
		
	}
}

void Inventory::add_item() {
	const int max_value = 64;
	int number;
	std::string name;
	double weight;
	std::string record1;
	std::string record2;
	std::string record3;
	int value;
	do {
		std::cout << "can you add weapon" << std::endl;
		std::cout << "can you add potion" << std::endl;
		std::cout << "can you add resource" << std::endl;
		number = get_valid_int();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
	} while (number < 0 || number > 3);
	switch (number) {
		case 1: {
			std::cout << "input name:" << std::endl;
			std::getline(std::cin, name);
			std::cout << "input weight:" << std::endl;
			std::cin >> weight;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "input buf" << std::endl;
			std::getline(std::cin, record1);
			std::cout << "input damage" << std::endl;
			std::getline(std::cin, record2);
			std::cout << "input strength" << std::endl;
			std::getline(std::cin, record3);
			Weapon weapon(name, weight, record1, record2, record3);
			weapon.set_id(last_id++);
			inventory.add(weapon);
			
		}
			break;
		case 2: {
			std::cout << "input name:" << std::endl;
			std::getline(std::cin, name);
			do {
				std::cout << "input value" << std::endl;
				value = get_valid_int();
			} while (value > max_value);
			std::cout << "input weight:" << std::endl;
			std::cin >> weight;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "input buf " << std::endl;
			std::getline(std::cin, record2);
			std::cout << "input rarity " << std::endl;
			std::getline(std::cin, record1);
			std::cout << "input treatment " << std::endl;
			std::getline(std::cin, record3);
			Potion potion(name, value, weight, record1, record2, record3);
			bool added_to_inventory = false;
			int temp2;
			for (int i = 0; i < inventory.get_size(); i++) {
				if (inventory[i].type() == typeid(Potion)) {
					auto &otherPotion = std::any_cast<Potion &>(inventory[i]);
					if (potion == otherPotion && potion.get_max_value() <= max_value &&
						otherPotion.get_max_value() <= max_value) {
						int temp = otherPotion.get_max_value();
						temp2 = max_value - temp;
						if (temp2 > value) {
							temp += value;
							otherPotion.set_max_value(temp);
							added_to_inventory = true;
							break;
						} else {
							temp += temp2;
							otherPotion.set_max_value(temp);
							temp2 -= value;
							potion.set_max_value(temp2);
							Potion potion2(name, temp2, weight, record1, record2, record3);
							potion2.set_id(last_id++);
							inventory.add(potion2);
							break;
						}
					}
				}
			}
			if (!added_to_inventory) {
				potion.set_id(last_id++);
				inventory.add(potion);
			}
			
		}
			break;
		case 3: {
			std::cout << "input name:" << std::endl;
			std::getline(std::cin, name);
			do {
				std::cout << "input value" << std::endl;
				value = get_valid_int();
			} while (value > max_value);
			std::cout << "input weight:" << std::endl;
			std::cin >> weight;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "input use " << std::endl;
			std::getline(std::cin, record2);
			std::cout << "input rarity " << std::endl;
			std::getline(std::cin, record1);
			std::cout << "input properties " << std::endl;
			std::getline(std::cin, record3);
			Resource resource(name, value, weight, record1, record2, record3);
			bool added_to_inventory = false;
			int temp2;
			for (int i = 0; i < inventory.get_size(); i++) {
				if (inventory[i].type() == typeid(Resource)) {
					auto &otherResource = std::any_cast<Resource &>(inventory[i]);
					if (resource == otherResource && resource.get_max_value() <= max_value &&
						otherResource.get_max_value() <= max_value) {
						int temp = otherResource.get_max_value();
						temp2 = max_value - temp;
						if (temp2 > value) {
							temp += value;
							otherResource.set_max_value(temp);
							added_to_inventory = true;
							break;
						} else {
							temp += temp2;
							otherResource.set_max_value(temp);
							temp2 -= value;
							Resource resource1(name, temp2, weight, record1, record2, record3);
							resource1.set_id(last_id++);
							inventory.add(resource1);
							break;
						}
					}
				}
			}
			if (!added_to_inventory) {
				resource.set_id(last_id++);
				inventory.add(resource);
			}
			
		}
			break;
	}
	//inventoryDataModel.add_new_item( inventory);
	
}


#endif //LABA_ITEM_INVENTORY_H
