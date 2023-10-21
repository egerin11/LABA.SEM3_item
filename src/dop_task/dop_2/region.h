#ifndef LABA_ITEM_REGION_H
#define LABA_ITEM_REGION_H

#include <cstdlib>
#include <ctime>
#include<iostream>
#include<vector>
#include "../../lib/function.h"
#include <map>

class Region {
public:
    Region() {}


    std::pair<std::vector<std::vector<int>>, int> fill_map();

    void print_map(std::vector<std::vector<int>> &map);

    void input_size_map();

    std::vector<int> count_politish_voices(std::vector<std::vector<int>> &, int);

    void pint_voices(std::vector<int> &voices);

    void print_winner(std::vector<int> &);


private:
    bool check_field_map(const std::vector<std::vector<int>> &chosen, int i, int j, int k) const;

    bool input_borden_map(std::vector<std::vector<int>> &chosen, int n, int i, int j, int k, int &volume_of_zone,
                          bool first);

    int count_winner(std::vector<int> &);


    int generate_rand(int min, int max);

    int num_politish;
    int row;


};


#endif
