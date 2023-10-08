#ifndef LABA_ITEM_INVENTORY_H
#define LABA_ITEM_INVENTORY_H

#include "../data_model/inventory_data_model.h"

class Inventory {
private:
    std::string name;
    double weight;
    std::string record1;
    std::string record2;
    std::string record3;
    int value;
    InventoryDataModel inventoryDataModel;
    const int max_value = 64;

    void input_weapon();

    void input_potion();

    void input_resource();

public:
    bool inv_info();

    void add();

    void update();
    void remove();
};

#endif
