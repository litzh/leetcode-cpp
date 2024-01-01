#include <catch2/catch_test_macros.hpp>
#include <literals.h>

namespace lc0018 {
extern std::vector<std::vector<int>> fourSum(const std::vector<int> &nums, const int target);
} // namespace lc0018


using namespace lc0018;

TEST_CASE("4Sum", "[LC0018]") {
    REQUIRE(fourSum("[]"_VI, 0) == "[]"_VVI);
    REQUIRE(fourSum("[1]"_VI, 0) == "[]"_VVI);
    REQUIRE(fourSum("[2,2,2,2]"_VI, 8) == "[[2,2,2,2]]"_VVI);
    REQUIRE(fourSum("[2,2,2,2,2]"_VI, 8) == "[[2,2,2,2]]"_VVI);
    REQUIRE(fourSum("[1000000000,1000000000,1000000000,1000000000]"_VI, 0) == "[]"_VVI);
    REQUIRE(unordered_eq(fourSum("[1,0,-1,0,-2,2]"_VI, 0), "[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]"_VVI));
}

