#include "inventory_data_model.h"

void InventoryDataModel::add_item(Item *item, int number) {
    int space;
    bool check = false;
    if (item->get_type_item() == "weapon") {
        item->set_id(++m_last_id);
        item->set_max_value(number);
        m_inventory.push_back(item);
        return;
    }
    for (int i = 0; i < m_inventory.size(); i++) {
        if (*m_inventory[i] == *item) {
            {
                if (item->get_max_value() <= m_max_value && m_inventory[i]->get_max_value() <= m_max_value)
                    space = m_max_value - m_inventory[i]->get_max_value();
                if (space >= number) {
                    number += m_inventory[i]->get_max_value();
                    m_inventory[i]->set_max_value(number);
                    check = true;
                    break;
                } else {
                    number -= space;
                    m_inventory[i]->set_max_value(m_max_value);
                }
            }
        }

    }
    if (!check) {
        item->set_id(++m_last_id);
        item->set_max_value(number);
        m_inventory.push_back(item);
    }
}

std::vector<Item *> InventoryDataModel::get_all_item() {
    return m_inventory;
}

bool InventoryDataModel::items() {
    return m_inventory.empty();
}

Item *InventoryDataModel::get_item_by_id(const int &id) const {
    for (int i = 0; i < m_inventory.size(); i++) {
        if (m_inventory[i]->get_id() == id) {
            return m_inventory[i];
        }
    }
    throw std::exception();
}

bool InventoryDataModel::update_item(Item *item) {
    for (int i = 0; i < m_inventory.size(); i++) {
        if (m_inventory[i]->get_id() == item->get_id()) {
            m_inventory[i] = item;
            return true;
        }
    }
    return false;
}

bool InventoryDataModel::delete_item(Item *item) {
    if (items()) {
        std::cout << "no items" << std::endl;
        return false;
    }
    for (int i = 0; i < m_inventory.size(); i++) {
        if (*m_inventory[i] == *item) {
            m_inventory.erase(m_inventory.begin() + i);
            m_last_id--;
        }
    }

    for (int j = 0; j <get_size(); j++) {
        m_inventory[j]->set_id(j+1);

    }
    return true;
}

unsigned long InventoryDataModel::get_size() {
    return m_inventory.size();
}
