cmake_minimum_required(VERSION 3.24)
project(laba_item)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba_item main.cpp "lib /model/item.h" "lib /model/weapon.h" "lib /model/resource.h" "lib /model/potion.h" "garbage/dynamic_array.h" "lib /data_model/invertary_data_model.h" garbage/function.cpp "lib /function.h" "lib /view/inventory.h")
