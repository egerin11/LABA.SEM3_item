//
// Created by egerin on 10/8/23.
//
#include "../potion.h"

void Potion::info() const {
//    Item::info();
    std::cout << "id:" << m_id << std::endl;
    std::cout << "type item: " << m_type_item << std::endl;
    std::cout << "name:" << m_name << std::endl;
    std::cout << "value:" << m_max_value << std::endl;
    std::cout << "weight:" << m_weight << std::endl;
    std::cout << "rarity:" << m_rarity << std::endl;
    std::cout << "treatment:" << m_treatment << std::endl;
    std::cout << "m_buf:" << m_buf << std::endl;
}

int Potion::get_id() const {
    return m_id;
}

std::string Potion::get_type_item() const {
    return m_type_item;
}

void Potion::set_id(int id) {
    m_id=id;
}

int Potion::get_max_value() const {
    return m_max_value;
}

void Potion::set_max_value(int max_value) {
    m_max_value=max_value;

}
