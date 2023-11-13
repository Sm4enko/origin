cmake_minimum_required(VERSION 3.0)

project(WTDBO2) 

find_package(Wt REQUIRED)

find_package(PostgreSQL REQUIRED)

include_directories(${Wt_INCLUDE_DIRS})
include_directories(${PostgreSQL_INCLUDE_DIRS})

set(SOURCES
    WTDBO2.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${Wt_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${PostgreSQL_LIBRARIES})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/wtdbo.dll
    ${CMAKE_SOURCE_DIR}/wtdbod.dll
    ${CMAKE_SOURCE_DIR}/wtdbopostgresd.dll
    ${CMAKE_BINARY_DIR})

    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/wtdbo.dll
    ${CMAKE_SOURCE_DIR}/wtdbod.dll
    ${CMAKE_SOURCE_DIR}/wtdbopostgresd.dll
    ${CMAKE_BINARY_DIR})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

