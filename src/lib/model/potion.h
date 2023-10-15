#ifndef LABA_ITEM_POTION_H
#define LABA_ITEM_POTION_H

#include "item.h"

class Potion :  public Item {
private:
    std::string m_rarity;
    std::string m_buf;
    std::string m_treatment;

public:
    Potion(
            const std::string &item_name,
            const int item_value,
            const double item_weight,
            const std::string &rarity,
            const std::string &buf,
            const std::string &treatment
    ) :
            Item(item_name, item_value, item_weight, "potion"),
            m_rarity(rarity),
            m_buf(buf),
            m_treatment(treatment) {}

    void info() const override;
    void set_max_value(int max_value) override;
    int get_max_value() const override;
    int get_id() const override;

    std::string get_type_item() const override;

    void set_id(int id) override;

    bool operator==(const Potion &other) const {
        if (dynamic_cast<const Potion *>(&other)) {
            auto other_resource = dynamic_cast<const Potion *>(&other);
            return this->m_buf == other_resource->m_buf &&
                   this->m_treatment == other_resource->m_treatment
                   && this->m_rarity == other_resource->m_rarity;
        }
        return false;
    }
};

#endif
