#include <unordered_map>
#include <vector>

namespace lc0001
{
std::vector<int> twoSum(const std::vector<int>&nums, const int target)
{
    std::unordered_map<int, int> complement;
    std::vector<int> result;
    const int size = static_cast<int>(nums.size());
    for (int i = 0; i < size; ++i) {
        if (const auto it = complement.find(nums[i]); it != complement.end()) {
            result.push_back(it->second);
            result.push_back(i);
            break;
        }
        complement.insert({target - nums[i], i});
    }
    return result;
}
}

