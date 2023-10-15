#ifndef LABA_ITEM_ITEM_H
#define LABA_ITEM_ITEM_H

#include <iostream>

class Item {
public:
    Item(std::string item_name, const int item_max_value, const double item_weight, const std::string type_item) :
            m_name(std::move(item_name)),
            m_max_value(item_max_value),
            m_weight(item_weight), m_id(0), m_type_item(type_item) {};

    virtual void info() const=0;

    virtual int get_id() const=0;

    virtual void set_id(int id) =0;

    virtual int get_max_value() const=0;

    virtual std::string get_type_item() const=0;


   virtual void set_max_value(int item_max_value)=0;

    bool operator==(const Item &other) {
        return m_type_item == other.m_type_item &&
               m_name == other.m_name &&
               m_weight == other.m_weight;
    }

protected:
    std::string m_name;
    int m_max_value;
    double m_weight;
    int m_id;
    std::string m_type_item;
};

#endif
