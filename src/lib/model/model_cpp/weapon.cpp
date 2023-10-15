//
// Created by egerin on 10/8/23.
//
#include "../weapon.h"

std::string Weapon::get_type_item() const {
    return m_type_item;
}

void Weapon::info() const {
//    Item::info();
    std::cout << "id:" << m_id << std::endl;
    std::cout << "type item: " << m_type_item << std::endl;
    std::cout << "name:" << m_name << std::endl;
    std::cout << "value:" << m_max_value << std::endl;
    std::cout << "weight:" << m_weight << std::endl;
    std::cout << "m_buf:" << m_buf << std::endl;
    std::cout << "m_damage:" << m_damage << std::endl;
    std::cout << "m_strength:" << m_strength << std::endl;
}

int Weapon::get_id() const {
    return m_id;
}

void Weapon::set_id(int id) {
    m_id = id;
}

void Weapon::set_max_value(int max_value) {
    m_max_value = max_value;
}

int Weapon::get_max_value() const {
    return m_max_value;
}

