
#ifndef LABA_ITEM_INVERTARY_DATA_MODEL_H
#define LABA_ITEM_INVERTARY_DATA_MODEL_H
#pragma once

#include "../../garbage/dynamic_array.h"
#include "../model/resource.h"
#include "../model/weapon.h"
#include "../model/potion.h"
#include "../function.h"
#include <limits>
class InventoryDataModel
{
public:
	InventoryDataModel() : last_id(0){};

	static std::any get_item_by_id(const int &id, DynamicArray<std::any> &inventory);

	template <typename T>
	bool update_item(T &item, DynamicArray<std::any> &inventory);

	template <typename T>
	void add(T &item, DynamicArray<std::any> &inventory, int value);

	template <typename T>
	void add(T &item, DynamicArray<std::any> &inventory);

	template <typename T>
	void add(T &item, const int &id)
	{
		item.set_id(id);
	}

	template <typename T>
	void delete_item(T &item, DynamicArray<std::any> &inventory);

private:
	const int max_value = 64;
	int last_id;
};

template <typename T>
void InventoryDataModel::add(T &item, DynamicArray<std::any> &inventory)
{
	item.set_id(++last_id);
	inventory.add(item);
}

template <typename T>
void InventoryDataModel::add(T &item, DynamicArray<std::any> &inventory, int value)
{
	bool added_to_inventory = false;
	for (int i = 0; i < inventory.get_size(); i++)
	{
		if (inventory[i].type() == typeid(T))
		{
			auto &otherItem = std::any_cast<T &>(inventory[i]);
			if (item == otherItem && item.get_max_value() <= max_value &&
				otherItem.get_max_value() <= max_value)
			{
				int space_available = max_value - otherItem.get_max_value();
				if (space_available >= value)
				{
					otherItem.set_max_value(otherItem.get_max_value() + value);
					added_to_inventory = true;
					break;
				}
				else
				{
					value -= space_available;
					otherItem.set_max_value(max_value);
				}
			}
		}
	}

	if (!added_to_inventory)
	{
		item.set_id(++last_id);
		item.set_max_value(value);
		inventory.add(item);
	}
}

std::any InventoryDataModel::get_item_by_id(const int &id, DynamicArray<std::any> &inventory)
{
	for (int i = 0; i < inventory.get_size(); i++)
	{
		if (inventory[i].has_value())
		{
			if (inventory[i].type() == typeid(Potion))
			{
				auto &potion = std::any_cast<Potion &>(inventory[i]);
				if (potion.get_id() == id)
				{
					return potion;
				}
			}
			else if (inventory[i].type() == typeid(Weapon))
			{
				auto &weapon = std::any_cast<Weapon &>(inventory[i]);
				if (weapon.get_id() == id)
				{
					return weapon;
				}
			}
			else if (inventory[i].type() == typeid(Resource))
			{
				auto &resource = std::any_cast<Resource &>(inventory[i]);
				if (resource.get_id() == id)
				{
					return resource;
				}
			}
		}
	}
	return nullptr;
}

template <typename T>
void InventoryDataModel::delete_item(T &item, DynamicArray<std::any> &inventory)
{

	int index_to_remove = -1;
	for (int i = 0; i < inventory.get_size(); i++)
	{
		try
		{
			T &current_item = std::any_cast<T &>(inventory[i]);
			if (current_item.get_id() == item.get_id())
			{
				index_to_remove = i;
			}
		}
		catch (const std::bad_any_cast &)
		{
		}
	}

	if (index_to_remove != -1)
	{
		inventory.remove(index_to_remove);

		for (int i = index_to_remove; i < inventory.get_size(); i++)
		{
			try
			{
				T &current_item = std::any_cast<T &>(inventory[i]);
				current_item.set_id(i + 1);
			}
			catch (const std::bad_any_cast &)
			{
			}
		}
	}
}

template <typename T>
bool InventoryDataModel::update_item(T &item, DynamicArray<std::any> &inventory)
{
	for (int i = 0; i < inventory.get_size(); i++)
	{
		if (inventory[i].has_value())
		{
			try
			{
				T &currentItem = std::any_cast<T &>(inventory[i]);
				if (currentItem.get_id() == item.get_id())
				{

					currentItem = item;
					return true;
				}
			}
			catch (const std::bad_any_cast &)
			{
			}
		}
	}
	return false;
}

#endif
