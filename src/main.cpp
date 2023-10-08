

#include "lib/view/inventory.h"

int main() {
    Inventory inventory;


    int number;
    do {
        clear_screen();
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
            default: {
            }
                break;
        }

    } while (number != 0);

    return 0;
}
