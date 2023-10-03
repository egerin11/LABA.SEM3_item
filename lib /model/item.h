
#ifndef LABA_ITEM_ITEM_H
#define LABA_ITEM_ITEM_H

#include <string>
#include <utility>
#include <iostream>

class Item {
public:
	Item(std::string item_name, const int item_max_value, const double item_weight) : name(
			std::move(item_name)),
																					  max_value(
																							  item_max_value),
																					  weight(item_weight) ,id_(0) {};
	
	virtual void info() const;
	
	[[nodiscard]] virtual int get_id() const;
	
	virtual void set_id(int id);
	
	std::string get_name() const {
		return name;
	}
	
	int get_max_value() const {
		return max_value;
	}
	
	double get_weight() const {
		return weight;
	}
	void set_name(const std::string& item_name) {
		name = item_name;
	}
	
	void set_max_value(int item_max_value) {
		max_value = item_max_value;
	}
	
	void set_weight(double item_weight) {
		weight = item_weight;
	}

protected:
	std::string name;
	int max_value;
	double weight;
	int id_;
	
};

void Item::info() const {
	std::cout<<id_<<std::endl;
	std::cout << "name:" << name << std::endl;
	std::cout << "value:" << max_value << std::endl;
	std::cout << "weight:" << weight << std::endl;
}

int Item::get_id() const {
	return id_;
}

void Item::set_id(int id) {
	id_ = id;
}


#endif
