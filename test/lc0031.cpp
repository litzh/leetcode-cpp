#include <algorithm>
#include <literals.h>
#include <random>
#include <vector>

#include <catch2/catch_test_macros.hpp>

namespace lc0031 {
std::vector<int> &nextPermutation(std::vector<int> &nums);
}

using namespace lc0031;
TEST_CASE("Next Permutation", "[LC0031]") {
    auto vec = "[1,2,3]"_VI;
    REQUIRE(nextPermutation(vec) == "[1,3,2]"_VI);
    vec = "[3,2,1]"_VI;
    REQUIRE(nextPermutation(vec) == "[1,2,3]"_VI);
    vec = "[1,1,5]"_VI;
    REQUIRE(nextPermutation(vec) == "[1,5,1]"_VI);
}

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100
TEST_CASE("Next Permutation Fuzz", "[LC0031][.Fuzz]") {
    for (int n = 0; n < 10; ++n) {
        constexpr size_t batch = 100;
        std::vector<int> fuzz(batch);
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution dist(0, 100);
        for (size_t i = 0; i < batch; ++i) {
            fuzz[i] = dist(rng);
        }
        auto expect(fuzz);
        std::next_permutation(expect.begin(), expect.end());
        REQUIRE(nextPermutation(fuzz) == expect);
    }
}

