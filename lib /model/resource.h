#ifndef LABA_ITEM_RESOURCE_H
#define LABA_ITEM_RESOURCE_H
#pragma once

#include <utility>
#include "item.h"

class Resource : public Item {
private:
	std::string m_rarity;
	std::string m_use;
	std::string m_properties;
public:
	Resource(const std::string &item_name, const int item_value, const double item_weight, const std::string &rarity,
			 const std::string &use, const std::string &properties) : Item(item_name, item_value,
																		   item_weight),
																	  m_rarity(rarity), m_use(use),
																	  m_properties(properties) {}
	
	
//	[[nodiscard]] const std::string& get_rarity() const {
//		return m_rarity;
//	}
//
//	const std::string& get_use() const {
//		return m_use;
//	}
	
//	const std::string& get_properties() const {
//		return m_properties;
//	}
//	void set_rarity(const std::string& rarity) {
//		m_rarity = rarity;
//	}
//
//	void set_use(const std::string& use) {
//		m_use = use;
//	}
//
//	void set_properties(const std::string& properties) {
//		m_properties = properties;
//	}
	void info() const override {
		Item::info();
		std::cout << "rarity:" << m_rarity << std::endl;
		std::cout << "use:" << m_use << std::endl;
		std::cout << "properties:" << m_properties << std::endl;
	}

	 [[nodiscard]] int get_id() const override {
		 return Item::get_id();
	}

	void set_id(int id) override {
		Item::set_id(id);
	}
	bool operator==(const Resource &other) const {
		return name == other.name && weight == other.weight && m_use == other.m_use &&
			   m_properties == other.m_properties && m_rarity==other.m_rarity;
	}
	
};


#endif
