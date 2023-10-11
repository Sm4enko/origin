cmake_minimum_required(VERSION 3.20)
project(MyProject1)
add_executable(MyProject1 ConsoleApplication1.cpp.cpp)
add_subdirectory("K:\Temp\ConsoleApplication1\MinGW") # Укажите путь к libpq++
target_compile_features(MyProject1 PRIVATE cxx_std_17) # Включите C++17
target_link_libraries(MyProject1 pqxx) 