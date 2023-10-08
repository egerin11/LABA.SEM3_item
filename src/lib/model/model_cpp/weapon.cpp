//
// Created by egerin on 10/8/23.
//
#include "../weapon.h"

std::string Weapon::get_type_item() const {
    return Item::get_type_item();
}

void Weapon::info() const {
    Item::info();
    std::cout << "m_buf:" << m_buf << std::endl;
    std::cout << "m_damage:" << m_damage << std::endl;
    std::cout << "m_strength:" << m_strength << std::endl;
}

int Weapon::get_id() const {
    return Item::get_id();
}

void Weapon::set_id(int id) {
    Item::set_id(id);
}

