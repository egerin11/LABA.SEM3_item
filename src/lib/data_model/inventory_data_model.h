#ifndef LABA_ITEM_INVERTARY_DATA_MODEL_H
#define LABA_ITEM_INVERTARY_DATA_MODEL_H

#include "../model/resource.h"
#include "../model/weapon.h"
#include "../model/potion.h"
#include "../function.h"
#include <limits>
#include <vector>

class InventoryDataModel
{
public:
	InventoryDataModel() : m_last_id(0){};
	
	Item* get_item_by_id(const int &id) const;

	bool update_item(Item *item);
bool delete_item(Item *item);
bool items();
void add_item(Item* item,int number);
std::vector<Item*> get_all_item();
unsigned long get_size();

private:
	std::vector<Item*> m_inventory;
	static const int m_max_value = 64;
	int m_last_id;
};



#endif
