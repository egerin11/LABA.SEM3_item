

#include "lib/view/inventory.h"
#include "lib/dop_task/rail_fence.h"

int main() {
    Inventory inventory;


    int number;
    do {
        inventory.menu();
        number = get_valid_int();

        switch (number) {
            case 1:
                inventory.add();
                break;
            case 2:
                inventory.inv_info();
                break;
            case 3:
                inventory.update();
                break;
            case 4:
                inventory.remove();
                break;
            case 5:
                inventory.parse();
                break;
            case 6: {
                RailFence railFence;
                railFence.input_string();
                railFence.input_key();
                railFence.print();
                railFence.print_decrypt();
            }
                break;
            default: {
            }
                break;
        }

    } while (number != 0);

    return 0;
}
