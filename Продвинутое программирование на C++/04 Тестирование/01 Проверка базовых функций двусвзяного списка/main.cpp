#pragma once
#include "list.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

TEST_CASE("Empty list returns true from Empty()") {
    List list;
    REQUIRE(list.Empty() == true);
}
ы
TEST_CASE("Empty list has size 0") {
    List list;
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Size increases after pushing elements") {
    List list;
    list.PushBack(42);
    list.PushFront(23);
    REQUIRE(list.Size() == 2);
}

TEST_CASE("Size decreases after popping elements") {
    List list;
    list.PushBack(42);
    list.PushFront(23);
    list.PopFront();
    REQUIRE(list.Size() == 1);
    list.PopBack();
    REQUIRE(list.Size() == 0);
}


