cmake_minimum_required(VERSION 3.22.0)
project(CMake_Classes)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(CMake_ClassesLib SHARED equilateraltriangle.h equilateraltriangle.cpp Figure.h Figure.cpp isoscelesTriangle.h isoscelesTriangle.cpp Parallelogram.h Parallelogram.cpp Quadrangle.h Quadrangle.cpp Rectangle.h Rectangle.cpp Rhombus.h Rhombus.cpp rightTriangle.h rightTriangle.cpp Square.h Square.cpp Triangle.h Triangle.cpp )
add_executable(CMake_ClassesExe DLL_VC++projects.cpp)
target_link_libraries(CMake_ClassesExe CMake_ClassesLib)









