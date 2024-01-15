cmake_minimum_required(VERSION 3.5)

project(StopwatchApp)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.4.2/mingw_64" ${CMAKE_PREFIX_PATH})

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp
    stopwatch.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
