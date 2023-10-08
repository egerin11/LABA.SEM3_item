//
// Created by egerin on 10/8/23.
//
#include "../potion.h"

void Potion::info() const {
    Item::info();
    std::cout << "rarity:" << m_rarity << std::endl;
    std::cout << "treatment:" << m_treatment << std::endl;
    std::cout << "m_buf:" << m_buf << std::endl;
}

int Potion::get_id() const {
    return Item::get_id();
}

std::string Potion::get_type_item() const {
    return Item::get_type_item();
}

void Potion::set_id(int id) {
    Item::set_id(id);
}
