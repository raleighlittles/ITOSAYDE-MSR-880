cmake_minimum_required(VERSION 3.20)
project(itosayde_msr_880_driver_demo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall")

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} usb-1.0)