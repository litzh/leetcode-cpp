#include <catch2/catch_test_macros.hpp>
#include <literals.h>

namespace lc0015 {
extern std::vector<std::vector<int>> threeSum(const std::vector<int> &nums);
}


using namespace lc0015;

TEST_CASE("3Sum", "[LC0015]") {
    REQUIRE(threeSum("[1,2,3]"_VI) == "[]"_VVI);
    REQUIRE(threeSum("[]"_VI) == "[]"_VVI);
    REQUIRE(threeSum("[-1,0,1,2,-1,-4]"_VI) == "[[-1,-1,2],[-1,0,1]]"_VVI);
    REQUIRE(threeSum("[0,0,0]"_VI) == "[[0,0,0]]"_VVI);
    REQUIRE(threeSum("[-2,2,0,1,-1]"_VI) == "[[-2,0,2],[-1,0,1]]"_VVI);
}
 