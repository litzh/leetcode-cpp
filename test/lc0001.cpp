#include <literals.h>
#include <vector>

#include <catch2/catch_test_macros.hpp>

namespace lc0001 {
extern std::vector<int> twoSum(const std::vector<int> &nums, int target);
}

using namespace lc0001;
TEST_CASE("Two Sum", "[LC0001]") {
    const auto nums = "[2, 7, 11, 15]"_VI;
    REQUIRE(twoSum(nums, 9) == "[0, 1]"_VI);
    REQUIRE(twoSum(nums, 13) == "[0, 2]"_VI);
    REQUIRE(twoSum(nums, 26) == "[2, 3]"_VI);
}

TEST_CASE("Two Sum Fail", "[LC0001]") {
    const auto nums = "[2, 7, 11, 15]"_VI;
    REQUIRE(twoSum(nums, 27) == "[]"_VI);
}

