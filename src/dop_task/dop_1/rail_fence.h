
#ifndef LABA_ITEM_RAIL_FENCE_H
#define LABA_ITEM_RAIL_FENCE_H

#include<iostream>
#include<vector>
#include "../../lib/function.h"

class RailFence {
public:
    void print();
    std::string array_to_string();
    std::vector<std::vector<std::string>> encrypt();
    void input_string();
    std::vector<std::string> decrypt();
    void input_key();
    void print_decrypt();
private:
    int key;
    std::string text;


};


#endif
