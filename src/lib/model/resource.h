#ifndef LABA_ITEM_RESOURCE_H
#define LABA_ITEM_RESOURCE_H

#include "item.h"

class Resource : public Item {
private:
    std::string m_rarity;
    std::string m_use;
    std::string m_properties;
public:
    Resource(
            const std::string &item_name,
            const int item_value,
            const double item_weight,
            const std::string &rarity,
            const std::string &use,
            const std::string &properties
    ) :
            Item(item_name, item_value, item_weight, "resource"),
            m_rarity(rarity), m_use(use),
            m_properties(properties) {}

    std::string get_type_item() const override;

    void info() const override;


    int get_id() const override;

    void set_id(int id) override;

    bool operator==(const Resource &other) const {
        if (dynamic_cast<const Resource *>(&other)) {
            auto other_resource = dynamic_cast<const Resource *>(&other);
            return  this->m_use == other_resource->m_use &&
                   this->m_properties == other_resource->m_properties && this->m_rarity == other_resource->m_rarity;
        }
        return false;
    }
};

#endif
