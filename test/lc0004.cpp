#include <literals.h>
#include <vector>

#include <catch2/catch_test_macros.hpp>

namespace lc0004 {
double findMedianSortedArrays(const std::vector<int> &nums1, const std::vector<int> &nums2);
} // namespace lc0004


using namespace lc0004;
TEST_CASE("Median of Two Sorted Arrays", "[LC0004]") {
    REQUIRE(findMedianSortedArrays("[0,0]"_VI, "[0,0]"_VI) == 0.0);
    REQUIRE(findMedianSortedArrays("[]"_VI, "[1]"_VI) == 1.0);
    REQUIRE(findMedianSortedArrays("[1]"_VI, "[]"_VI) == 1.0);
    REQUIRE(findMedianSortedArrays("[1,2,5,6,7]"_VI, "[3,4]"_VI) == 4.0);
    REQUIRE(findMedianSortedArrays("[1,3]"_VI, "[2]"_VI) == 2.0);
    REQUIRE(findMedianSortedArrays("[1,2]"_VI, "[3,4]"_VI) == 2.5);
}

