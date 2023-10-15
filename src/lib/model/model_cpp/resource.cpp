
#include "../resource.h"

std::string Resource::get_type_item() const {
    return m_type_item;
}

void Resource::info() const {
//    Item::info();
    std::cout << "id:" << m_id << std::endl;
    std::cout << "type item: " << m_type_item << std::endl;
    std::cout << "name:" << m_name << std::endl;
    std::cout << "value:" << m_max_value << std::endl;
    std::cout << "weight:" << m_weight << std::endl;
    std::cout << "rarity:" << m_rarity << std::endl;
    std::cout << "use:" << m_use << std::endl;
    std::cout << "properties:" << m_properties << std::endl;
}

int Resource::get_id() const {
    return m_id;
}

void Resource::set_id(int id) {
    m_id = id;
}

void Resource::set_max_value(int max_value) {
    m_max_value = max_value;
}

int Resource::get_max_value() const {
    return m_max_value;
}
