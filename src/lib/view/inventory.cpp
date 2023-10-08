#include "inventory.h"


void Inventory::input_weapon() {
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

}

void Inventory::input_potion() {
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
}

void Inventory::input_resource() {
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

}

void Inventory::add() {
    int number;
    Item *new_item;
    do {
        std::cout << "can you add weapon" << std::endl;
        std::cout << "can you add potion" << std::endl;
        std::cout << "can you add resource" << std::endl;
        number = get_valid_int();

    } while (number < 0 || number > 3);
    switch (number) {
        case 1: {
            input_weapon();
            Weapon weapon(name, weight, record1, record2, record3);
            new_item = new Weapon(weapon);
            inventoryDataModel.add_item(new_item, 1);

        }
            break;
        case 2: {
            input_potion();
            Potion potion(name, value, weight, record1, record2, record3);
            new_item = new Potion(potion);
            inventoryDataModel.add_item(new_item, value);

        }
            break;
        case 3: {
            input_resource();
            Resource resource(name, value, weight, record1, record2, record3);
            new_item = new Resource(resource);
            inventoryDataModel.add_item(new_item, value);

        }
            break;
        default: {
        }
            break;
    }

}


bool Inventory::inv_info() {
    if (inventoryDataModel.items()) {
        std::cout << "no items" << std::endl;
        return false;
    }
    std::vector<Item *> item = inventoryDataModel.get_all_item();

    for (int i = 0; i < item.size(); i++) {
        item[i]->info();
        std::cout << std::endl;
    }
    return true;
}

void Inventory::update() {
    inv_info();
    std::vector<Item *> items = inventoryDataModel.get_all_item();

    std::cout << "input id item" << std::endl;
    int number;
    do {
        number = get_valid_int();
    } while (number > items.size() || number <= 0);

    if (items[number - 1]->get_type_item() == "weapon") {
        input_weapon();
        Weapon weapon(name, weight, record1, record2, record3);
        auto *item = dynamic_cast<Weapon *>(items[number - 1]);
        if (item) {
            weapon.set_id(number);
            *item = weapon;
            inventoryDataModel.update_item(item);
        }
    } else if (items[number - 1]->get_type_item() == "potion") {
        input_potion();
        Potion potion(name, value, weight, record1, record2, record3);
        auto *item = dynamic_cast<Potion *>(items[number - 1]);
        if (item) {
            potion.set_id(number);
            *item = potion;
            inventoryDataModel.update_item(item);
        }
    } else {
        input_resource();
        Resource resource(name, value, weight, record1, record2, record3);
        auto *item = dynamic_cast<Resource *>(items[number - 1]);
        if (item) {
            resource.set_id(number);
            *item = resource;
            inventoryDataModel.update_item(item);
        }
    }
}

void Inventory::remove() {
    if (!inv_info()) {
        return;
    }
    std::cout << "input id item" << std::endl;
    int number;
    do {
        number = get_valid_int();
    } while (number > inventoryDataModel.get_size() || number <= 0);
    Item *item = inventoryDataModel.get_item_by_id(number);
    inventoryDataModel.delete_item(item);

}

void Inventory::parse() {
    if (inventoryDataModel.parse_file()) {
    } else return;
}

void Inventory::menu() {
    clear_screen();
    std::cout << "\tMENU" << std::endl;
    std::cout << "\tADD 1" << std::endl;
    std::cout << "\tVIEW 2" << std::endl;
    std::cout << "\tUPDATE 3" << std::endl;
    std::cout << "\tREMOVE 4" << std::endl;
    std::cout << "\tPARSE 5" << std::endl;
    std::cout << "\tDOP 6" << std::endl;
    std::cout << "\tEXIT 0" << std::endl;


}


