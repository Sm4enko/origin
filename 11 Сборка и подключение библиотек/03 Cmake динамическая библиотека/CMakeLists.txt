cmake_minimum_required(VERSION 3.22.0)
project(Name)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(nameDynamicLib SHARED Name.h Name.cpp)
add_executable(nameExe whatName.cpp)
target_link_libraries(nameExe nameDynamicLib)



