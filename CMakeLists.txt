cmake_minimum_required(VERSION 3.24)
project(laba_item)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba_item
        src/main.cpp
        src/lib/model/item.h
        src/lib/model/weapon.h
        src/lib/model/resource.h
        src/lib/model/potion.h
        src/garbage/function.cpp
        src/lib/function.h
        src/lib/data_model/inventory_data_model.cpp
        src/lib/data_model/inventory_data_model.h
        src/lib/view/inventory.cpp
        src/lib/view/inventory.h
        src/lib/model/model_cpp/resource.cpp
        src/lib/model/model_cpp/weapon.cpp
        src/lib/model/model_cpp/potion.cpp
        src/dop_task/rail_fence.cpp
        src/dop_task/rail_fence.h
)
