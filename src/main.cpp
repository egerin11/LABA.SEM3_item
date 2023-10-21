#include "lib/view/inventory.h"
#include "dop_task/dop_1/rail_fence.h"
#include "dop_task/dop_2/region.h"

int main() {
    Inventory inventory;
    RailFence railFence;



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
                    railFence.input_string();
                    railFence.input_key();
                    railFence.print();
                    railFence.print_decrypt();
                }
                    break;
                case 7:{
                    Region region;
                    region.input_size_map();
                    std::pair<std::vector<std::vector<int>>, int> pair = region.fill_map();
                    region.print_map(pair.first);
                    std::vector<int> voices = region.count_politish_voices(pair.first, pair.second);
                    region.pint_voices(voices);
                    region.print_winner(voices);

                }
                    break;
                default: {
                }
                    break;
            }

        } while (number != 0);

    return 0;

}
