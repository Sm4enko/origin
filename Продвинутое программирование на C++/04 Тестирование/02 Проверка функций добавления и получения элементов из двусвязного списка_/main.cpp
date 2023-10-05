#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "list.h"

TEST_CASE("PushBack and PushFront") {
    List list;
    list.PushBack(1);
    list.PushFront(2);
    list.PushBack(3);

    REQUIRE(list.Size() == 3);

    SECTION("Check values after PushBack and PushFront") {
       
    }
}

TEST_CASE("PopBack and PopFront") {
    List list;
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);

    SECTION("PopBack and PopFront from a non-empty list") {
        list.PushBack(1);
        list.PushFront(2);

        REQUIRE(list.PopBack() == 1);
        REQUIRE(list.PopFront() == 2);

        REQUIRE(list.Empty());
    }

    SECTION("PopBack and PopFront from an empty list") {
        REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
        REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
    }
}

TEST_CASE("Pop from an empty list") {
    List list;
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
}

TEST_CASE("Pop and Push on non-empty list") {
    List list;
    list.PushBack(1);
    list.PushFront(2);

    REQUIRE(list.PopBack() == 1);
    REQUIRE(list.PopFront() == 2);
    REQUIRE(list.Empty());

    list.PushBack(3);
    list.PushFront(4);

    REQUIRE(list.PopBack() == 3);
    REQUIRE(list.PopFront() == 4);
    REQUIRE(list.Empty());
}



