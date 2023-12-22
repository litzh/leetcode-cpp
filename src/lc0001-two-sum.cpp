#include <cstddef>
#include <unordered_map>
#include <vector>

static std::vector<int> twoSum(const std::vector<int>&nums, int target)
{
    std::unordered_map<int, int> complement;
    std::vector<int> result;
    const int size = static_cast<int>(nums.size());
    for (int i = 0; i < size; ++i) {
        const auto it = complement.find(nums[i]);
        if (it != complement.end()) {
            result.push_back(it->second);
            result.push_back(i);
            break;
        }
        complement.insert({target - nums[i], i});
    }
    return result;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Two Sum", "[LC0001]")
{
    std::vector<int> nums{2, 7, 11, 15};
    REQUIRE(twoSum(nums, 9) == std::vector<int>{0, 1});
    REQUIRE(twoSum(nums, 13) == std::vector<int>{0, 2});
}
