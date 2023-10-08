
#include "../resource.h"

std::string Resource::get_type_item() const {
    return Item::get_type_item();
}

void Resource::info() const {
    Item::info();
    std::cout << "rarity:" << m_rarity << std::endl;
    std::cout << "use:" << m_use << std::endl;
    std::cout << "properties:" << m_properties << std::endl;
}

int Resource::get_id() const {
    return Item::get_id();
}

void Resource::set_id(int id) {
    Item::set_id(id);
}
