//
// Created by egerin on 10/8/23.
//
#include "../item.h"


void Item::info() const {
    std::cout << "id:" << m_id << std::endl;
    std::cout << "type item: " << m_type_item << std::endl;
    std::cout << "name:" << m_name << std::endl;
    std::cout << "value:" << m_max_value << std::endl;
    std::cout << "weight:" << m_weight << std::endl;
}

int Item::get_id() const {
    return m_id;
}

void Item::set_id(int id) {
    m_id = id;
}

int Item::get_max_value() const {
    return m_max_value;
}

void Item::set_max_value(int item_max_value) {
    m_max_value = item_max_value;
}
