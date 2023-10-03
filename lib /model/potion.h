
#ifndef LABA_ITEM_POTION_H
#define LABA_ITEM_POTION_H

#include "item.h"
#include <utility>

class Potion : public Item {
private:
	std::string m_rarity;
	std::string m_buf;
	std::string m_treatment;
	//int m_id;

public:
	Potion(const std::string &item_name, const int item_value, const double item_weight,
		   const std::string &rarity, const std::string &buf, const std::string treatment) : Item(item_name, item_value,
																								  item_weight),
																							 m_rarity(rarity),
																							 m_buf(buf),
																							 m_treatment(treatment) {}
	
	void info() const override {
		Item::info();
		std::cout << "rarity:" << m_rarity << std::endl;
		std::cout << "treatment:" << m_treatment << std::endl;
		std::cout << "buf:" << m_buf << std::endl;
	}
	
//	[[nodiscard]] int get_id() const override {
//		return m_id;
//	}
	
	void set_rarity(const std::string &rarity) {
		m_rarity = rarity;
	}
	
	void set_buf(const std::string &buf) {
		m_buf = buf;
	}
	
	void set_treatment(const std::string &treatment) {
		m_treatment = treatment;
	}
	
	void set_id(int id) override {
		Item::set_id(id);
	}
	
	const std::string &get_rarity() const {
		return m_rarity;
	}
	
	const std::string &get_buf() const {
		return m_buf;
	}
	
	const std::string &get_treatment() const {
		return m_treatment;
	}
	
	  bool operator==(const Potion &other) const {
		return name == other.name && weight == other.weight && m_buf == other.m_buf &&
			   m_treatment == other.m_treatment && m_rarity==other.m_rarity;
	}
//	Potion& operator+=(const Potion& other){
//		if(this!=&other){
//			max_value+=other.max_value;
//		}
//		return *this;
//	}
};


#endif
