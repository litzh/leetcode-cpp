#include <catch2/catch_test_macros.hpp>
#include <literals.h>
#include <random>

namespace lc0011 {
extern int maxArea(const std::vector<int> &height);
}

using namespace lc0011;

static int bf(const std::vector<int> &height) {
    size_t area = 0;
    int max_h = 0;
    for (size_t i = 0; i < height.size(); ++i) {
        max_h = std::max(height[i], max_h);
        if (height[i] < max_h) {
            continue;
        }
        for (size_t j = i + 1; j < height.size(); ++j) {
            const size_t w = j - i;
            const size_t h = std::min(height[i], height[j]);
            if (w * h > area) {
                area = w * h;
            }
        }
    }
    return static_cast<int>(area);
}

TEST_CASE("Container With Most Water", "[LC0011]") {
    REQUIRE(maxArea("[1, 8, 6, 2, 5, 4, 8, 3, 7]"_VI) == 49);
    REQUIRE(maxArea("[1, 1]"_VI) == 1);
    REQUIRE(maxArea("[1, 1, 100, 1, 1]"_VI) == 4);
}

/*
n == height.length
2 <= n <= 100000
0 <= height[i] <= 10000
*/
TEST_CASE("Container With Most Water Fuzz", "[LC0011][.Fuzz]") {
    constexpr size_t batch = 100;
    std::vector<int> fuzz(batch);
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 10000);
    for (size_t i = 0; i < batch; ++i) {
        fuzz.push_back(static_cast<int>(dist(rng)));
    }
    REQUIRE(maxArea(fuzz) == bf(fuzz));
}

