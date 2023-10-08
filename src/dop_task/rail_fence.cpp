
#include "rail_fence.h"

std::vector<std::vector<std::string>> RailFence::encrypt() {
    std::vector<std::vector<std::string>> array(key, std::vector<std::string>(text.size(), " "));

    int j = 0;
    int flag = 0;
    for (int i = 0; i < text.length(); i++) {
        array[j][i] = text[i];
        if (j == key - 1) {
            flag = 1;
        } else if (j == 0)
            flag = 0;
        if (flag == 0) {
            j++;
        } else j--;
    }

    return array;
}

void RailFence::input_string() {
    std::cout << "input string " << std::endl;
    std::getline(std::cin, text);

}

void RailFence::input_key() {
    std::cout << "input key " << std::endl;
    key = get_valid_int();

}

void RailFence::print() {
    std::string string = array_to_string();
    std::cout << "encrypt string:" << string << std::endl;
}

std::string RailFence::array_to_string() {
    std::string string;
    std::vector<std::vector<std::string>> array = encrypt();

    for (int i = 0; i < key; i++) {
        for (int j = 0; j < text.length(); j++) {
            if (array[i][j] != " ")
                string += array[i][j];
        }
    }
    return string;
}



std::vector<std::string> RailFence::decrypt() {
    std::vector<std::vector<std::string>> array = encrypt();
    std::vector<std::string> result(text.length());

    int j = 0;
    int flag = 0;
    for (int i = 0; i < text.length(); i++) {
        result[i] = array[j][i];
        if (j == key - 1) {
            flag = 1;
        } else if (j == 0) {
            flag = 0;
        }
        if (flag == 0) {
            j++;
        } else {
            j--;
        }
    }
    return result;
}


void RailFence::print_decrypt() {
    std::cout<<"decrypt string";
    std::vector<std::string> array=decrypt();
    for(int i=0;i<array.size();i++)
    {
        std::cout<<array[i];
    }
    std::cout<<std::endl;
}





