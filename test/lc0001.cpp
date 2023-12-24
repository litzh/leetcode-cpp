#include <leetcode.h>

#include <catch2/catch_test_macros.hpp>

using namespace lc0001;
TEST_CASE("Two Sum", "[LC0001]") {
    const std::vector nums{2, 7, 11, 15};
    REQUIRE(twoSum(nums, 9) == std::vector<int>{0, 1});
    REQUIRE(twoSum(nums, 13) == std::vector<int>{0, 2});
    REQUIRE(twoSum(nums, 26) == std::vector<int>{2, 3});
}

TEST_CASE("Two Sum Fail", "[LC0001]") {
    const std::vector nums{2, 7, 11, 15};
    REQUIRE(twoSum(nums, 27).empty());
}
