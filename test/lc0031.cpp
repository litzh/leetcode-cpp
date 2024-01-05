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
    auto cases = "[[1,2,3,4,5],[2,3,3],[1],[1,2,3,4,4]]"_VVI;
    for (auto &i: cases) {
        auto vec = i;
        auto exp = vec;
        bool end = true;
        do {
            end = std::next_permutation(exp.begin(), exp.end());
            nextPermutation(vec);
            REQUIRE(vec == exp);
        } while (end);
    }
}

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100
TEST_CASE("Next Permutation Fuzz", "[LC0031][Fuzz]") {
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

