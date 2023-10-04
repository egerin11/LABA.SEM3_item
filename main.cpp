#include <iostream>

#include "lib /data_model/invertary_data_model.h"
#include "garbage/dynamic_array.h"

#include "lib /view/inventory.h"
int main()
{
	Inventory inventory1;
	int number;
	DynamicArray<std::any> inventory;

	do
	{
		number = get_valid_int();

		switch (number)
		{
		case 1:
			inventory1.add_item();
			break;
		case 2:
			inventory1.inv_info();
			break;
		case 3:
			inventory1.update();
			break;
		case 4:
			inventory1.remove_item();
			break;
		case 5:
			inventory1.parse();
			break;

		default:
		{
		}
		break;
		}

	} while (number != 6);

	std::cout << "Hello, World!" << std::endl;
	return 0;
}
