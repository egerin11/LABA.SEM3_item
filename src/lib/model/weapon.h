#ifndef LABA_ITEM_WEAPON_H
#define LABA_ITEM_WEAPON_H

#include "item.h"

class Weapon : public Item {
private:
    std::string m_buf;
    std::string m_damage;
    std::string m_strength;
public:
    Weapon(
            const std::string &item_name,
            const double item_weight,
            std::string &new_buf,
            std::string &new_damage,
            std::string &new_strength
    ) :
            Item(item_name, 1, item_weight, "weapon"),
            m_buf(new_buf),
            m_damage(new_damage),
            m_strength(new_strength) {}

    std::string get_type_item() const override;

    void info() const override;


    int get_id() const override;


    void set_id(int id) override;

    bool operator==(const Item &other) const {
        if (dynamic_cast<const Weapon *>(&other)) {
            auto other_weapon = dynamic_cast<const Weapon *>(&other);
            return (this->m_buf == other_weapon->m_buf && this->m_damage == other_weapon->m_damage &&
                    this->m_strength == other_weapon->m_strength);
        }
        return false;
    }
};

#endif
