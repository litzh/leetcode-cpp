#include <literals.h>
#include <vector>

#include <catch2/catch_test_macros.hpp>

namespace lc0033 {
int search_min(const std::vector<int> &nums);
int search(const std::vector<int> &nums, int target);
} // namespace lc0033

using namespace lc0033;

TEST_CASE("Search in Rotated Sorted Array Min", "[LC0033]") {
    REQUIRE(search_min("[1]"_VI) == 0);
    REQUIRE(search_min("[1,2]"_VI) == 0);
    REQUIRE(search_min("[2,1]"_VI) == 1);
    REQUIRE(search_min("[1,2,3]"_VI) == 0);
    REQUIRE(search_min("[3,1,2]"_VI) == 1);
    REQUIRE(search_min("[2,3,1]"_VI) == 2);
    REQUIRE(search_min("[1,2,3,4]"_VI) == 0);
    REQUIRE(search_min("[4,1,2,3]"_VI) == 1);
    REQUIRE(search_min("[3,4,1,2]"_VI) == 2);
    REQUIRE(search_min("[2,3,4,1]"_VI) == 3);
}

TEST_CASE("Search in Rotated Sorted Array", "[LC0033]") {
    REQUIRE(search("[1]"_VI, 0) == -1);
    REQUIRE(search("[1]"_VI, 1) == 0);
    REQUIRE(search("[1]"_VI, 2) == -1);
    REQUIRE(search("[3,5,1]"_VI, 5) == 1);
    REQUIRE(search("[4,5,6,7,0,1,2]"_VI, 4) == 0);
    REQUIRE(search("[4,5,6,7,0,1,2]"_VI, 5) == 1);
    REQUIRE(search("[4,5,6,7,0,1,2]"_VI, 6) == 2);
    REQUIRE(search("[4,5,6,7,0,1,2]"_VI, 7) == 3);
    REQUIRE(search("[4,5,6,7,0,1,2]"_VI, 0) == 4);
    REQUIRE(search("[4,5,6,7,0,1,2]"_VI, 1) == 5);
    REQUIRE(search("[4,5,6,7,0,1,2]"_VI, 2) == 6);
    REQUIRE(search("[4,5,6,7,0,1,2]"_VI, 3) == -1);
    REQUIRE(search("[4,5,6,7,0,1,2]"_VI, 8) == -1);
    REQUIRE(search("[1,2,3,4,5,7]"_VI, 0) == -1);
    REQUIRE(search("[1,2,3,4,5,7]"_VI, 1) == 0);
    REQUIRE(search("[1,2,3,4,5,7]"_VI, 2) == 1);
    REQUIRE(search("[1,2,3,4,5,7]"_VI, 3) == 2);
    REQUIRE(search("[1,2,3,4,5,7]"_VI, 4) == 3);
    REQUIRE(search("[1,2,3,4,5,7]"_VI, 5) == 4);
    REQUIRE(search("[1,2,3,4,5,7]"_VI, 6) == -1);
    REQUIRE(search("[1,2,3,4,5,7]"_VI, 7) == 5);
    REQUIRE(search("[1,2,3,4,5,7]"_VI, 8) == -1);
    REQUIRE(search("[5,1,3]"_VI, 5) == 0);
    REQUIRE(search("[5,1,3]"_VI, 1) == 1);
    REQUIRE(search("[5,1,3]"_VI, 3) == 2);
    REQUIRE(search("[5,1,3]"_VI, 0) == -1);
    REQUIRE(search("[5,1,3]"_VI, 6) == -1);
    REQUIRE(search("[3,1]"_VI, 0) == -1);
    REQUIRE(search("[3,1]"_VI, 3) == 0);
    REQUIRE(search("[3,1]"_VI, 1) == 1);
    REQUIRE(search("[3,1]"_VI, 2) == -1);
    REQUIRE(search("[3,1]"_VI, 4) == -1);
}

