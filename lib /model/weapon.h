
#ifndef LABA_ITEM_WEAPON_H
#define LABA_ITEM_WEAPON_H

#include <utility>

#include "item.h"

class Weapon : public Item {
private:
	std::string buf;
	std::string damage;
	std::string strength;
	//int last_id_;
public:
	Weapon(const std::string &item_name, const double item_weight, std::string &new_buf, std::string &new_damage,
		   std::string &new_strength) : Item(item_name, 1, item_weight), buf(new_buf), damage(new_damage),
										strength(new_strength) {}
	
	void info() const override {
		Item::info();
		std::cout << "buf:" << buf << std::endl;
		std::cout << "damage:" << damage << std::endl;
		std::cout << "strength:" << strength << std::endl;
	}
	
//	[[nodiscard]]  int get_id() const override {
//		return last_id_;
//	}
//
	void set_id(int id) override {
		Item::set_id(id);
	}

	void set_buf(const std::string &newBuf) {
		buf = newBuf;
	}
	
	void set_damage(const std::string &newDamage) {
		damage = newDamage;
	}
	
	void set_strength(const std::string &newStrength) {
		strength = newStrength;
	}
	
	const std::string &get_buf() const {
		return buf;
	}
	
	const std::string &get_damage() const {
		return damage;
	}
	
	const std::string &get_strength() const {
		return strength;
	}
};


#endif
