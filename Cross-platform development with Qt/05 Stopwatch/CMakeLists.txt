cmake_minimum_required(VERSION 3.16)
project(MyTimerApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(MyTimerApp
    main.cpp
    stopwatch.h
    stopwatch.cpp
    mainwindow.h
    mainwindow.cpp
)

target_include_directories(MyTimerApp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(MyTimerApp PRIVATE Qt6::Widgets)
