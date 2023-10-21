#include "region.h"

int Region::generate_rand(int min, int max) {
    return rand() % (max - min + 1) + min;
}


std::pair<std::vector<std::vector<int>>, int> Region::fill_map() {
    srand(time(nullptr));
    std::vector<std::vector<int>> map(row, std::vector<int>(row, 0));
    std::pair<std::vector<std::vector<int>>, int> pair;
    bool check = true;
    bool first = true;
    int k = 1;
    int counter_of_region = 0;
    while (check) {
        bool ret;
        int volume_of_zone = generate_rand(5, 7);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) {
                if (volume_of_zone != 0) {
                    ret = input_borden_map(map, num_politish, i, j, k, volume_of_zone, first);
                    if (!ret) {
                        first = false;
                    }
                }
            }
        }
        first = true;
        k++;
        check = false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) {
                if (map[i][j] == 0) {
                    check = true;
                }
            }
        }
        counter_of_region++;
    }
    pair.first = map;
    pair.second = counter_of_region;

    return pair;
}

void Region::print_map(std::vector<std::vector<int>> &map) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            std::cout  << abs(map[i][j]) << " ";
        }
        std::cout << std::endl;
    }
}

void Region::input_size_map() {
    std::cout << "input size " << std::endl;
    row = get_valid_int();

    std::cout << "input politish" << std::endl;
    num_politish = get_valid_int();
}


bool Region::check_field_map(const std::vector<std::vector<int>> &chosen, int i, int j, int k) const {

    if (i - 1 >= 0) {
        if (chosen[i - 1][j] == k) {
            return true;
        }
    }
    if (i + 1 < row) {
        if (chosen[i + 1][j] == k) {
            return true;
        }
    }
    if (j - 1 >= 0) {
        if (chosen[i][j - 1] == k) {
            return true;
        }
    }
    if (j + 1 < row) {
        if (chosen[i][j + 1] == k) {
            return true;
        }
    }
    return false;
}

bool Region::input_borden_map(std::vector<std::vector<int>> &chosen, int n, int i, int j, int k, int &volume_of_zone,
                              bool first) {
    bool ret = true;
    bool check = check_field_map(chosen, i, j, k);
    if (first) {
        check = true;
        first = false;
    }
    if (chosen[i][j] == 0 && volume_of_zone != 0 && check) {
        int random;
        random = generate_rand(0, 3);
        chosen[i][j] = k;
        ret = false;
        volume_of_zone--;
        switch (random) {
            case 0:
                if (i - 1 >= 0) input_borden_map(chosen, n, i - 1, j, k, volume_of_zone, first);
                break;
            case 1:
                if (i + 1 < n) input_borden_map(chosen, n, i + 1, j, k, volume_of_zone, first);
                break;
            case 2:
                if (j - 1 >= 0) input_borden_map(chosen, n, i, j - 1, k, volume_of_zone, first);
                break;
            case 3:
                if (j + 1 < n) input_borden_map(chosen, n, i, j + 1, k, volume_of_zone, first);
                break;
            default: {
            }
                break;
        }
    }
    return ret;
}

std::vector<int> Region::count_politish_voices(std::vector<std::vector<int>> &map, int couter) {
    std::vector<int> choice_people(num_politish);
    int counter = 1;
    int check = 1;
    while (check != couter + 1) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) {
                if (map[i][j] == counter) {
                    int voice = generate_rand(0, num_politish);
                    choice_people[voice]++;
                }
            }

        }
        counter++;
        check++;
    }
    return choice_people;
}

void Region::pint_voices(std::vector<int> &voices) {
    for (int i = 0; i < num_politish; i++) {
        std::cout << "politish " << i + 1 <<" "<< voices[i] << std::endl;
    }

}

int Region::count_winner(std::vector<int> &voices) {
    int max = voices[0];
    int count = 0;
    int temp = 0;
    for (int i = 0; i < num_politish; i++) {
        if (voices[i] > max) {
            max = voices[i];
            count = 1;
            temp = i;
        } else if (max == voices[i]) count++;
    }
    if (count == 1) return temp;
    else return 0;

}

void Region::print_winner(std::vector<int> &voices) {
    int check = count_winner(voices);
     std::cout<<"winner politish "<<check+1<<" "<<"his voices "<<" "<<voices[check]<<std::endl;
}

