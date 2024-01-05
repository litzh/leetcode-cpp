#include <literals.h>
#include <vector>

#include <catch2/catch_test_macros.hpp>

namespace lc0033 {
int search(const std::vector<int> &nums, int target);
} // namespace lc0033

using namespace lc0033;
TEST_CASE("Search in Rotated Sorted Array", "[LC0033]") {
    REQUIRE(search("[4,5,6,7,0,1,2]"_VI, 0) == 4);
    REQUIRE(search("[4,5,6,7,0,1,2]"_VI, 3) == -1);
    REQUIRE(search("[1]"_VI, 0) == -1);
}

