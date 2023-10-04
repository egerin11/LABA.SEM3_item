
#ifndef LABA_ITEM_INVENTORY_H
#define LABA_ITEM_INVENTORY_H

#include"../data_model/invertary_data_model.h"
#pragma once
class Inventory {

private:
	std::string name;
	double weight;
	std::string record1;
	std::string record2;
	std::string record3;
	int value;
	DynamicArray<std::any> inventory;
	InventoryDataModel inventoryDataModel;
	const int max_value = 64;

public:
	void inv_info();
	
	void add_item();
	
	void update();
	void remove_item();
	void parse(){
		parse_file(inventory);
	}
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
	int number;
	
	do {
		std::cout << "can you add weapon" << std::endl;
		std::cout << "can you add potion" << std::endl;
		std::cout << "can you add resource" << std::endl;
		number = get_valid_int();
		
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
			inventoryDataModel.add<Weapon>(weapon, inventory);
			
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
			inventoryDataModel.add<Potion>(potion, inventory, value);
			
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
			inventoryDataModel.add<Resource>(resource, inventory, value);
			
		}
			break;
		default: {
		}
			break;
	}
	
}

void Inventory::update() {
	std::cout << "input item" << std::endl;
	inv_info();
	int number = get_valid_int();
	std::any item = inventoryDataModel.get_item_by_id(number, inventory);
	if (item.type() == typeid(Weapon)) {
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
		
		inventoryDataModel.add<Weapon>(weapon, number);
		inventoryDataModel.update_item<Weapon>(weapon, inventory);
	} else if (item.type() == typeid(Potion)) {
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
		inventoryDataModel.add<Potion>(potion, number);
		inventoryDataModel.update_item<Potion>(potion, inventory);
		
	} else {
		std::cout << "not item" << std::endl;
		return;
	}
}

void Inventory::remove_item() {

	inv_info();
	std::cout << "Input item ID: " << std::endl;
	int number = get_valid_int();
	
	std::any item = inventoryDataModel.get_item_by_id(number, inventory);
	
	if (item.has_value()) {
		try {
			if (item.type() == typeid(Potion)) {
				Potion potion = std::any_cast<Potion&>(item);
				inventoryDataModel.delete_item<Potion>(potion, inventory);
			} else if (item.type() == typeid(Weapon)) {
				Weapon weapon = std::any_cast<Weapon&>(item);
				inventoryDataModel.delete_item<Weapon>(weapon, inventory);
			} else if (item.type() == typeid(Resource)) {
				Resource resource = std::any_cast<Resource&>(item);
				inventoryDataModel.delete_item<Resource>(resource, inventory);
			} else {
				std::cout << "Invalid item type." << std::endl;
			}
		} catch (const std::bad_any_cast&) {}
	} else {
		std::cout << "Item not found." << std::endl;
	}
}

#endif
