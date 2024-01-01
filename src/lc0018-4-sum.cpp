#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>
namespace lc0018 {

std::vector<std::vector<int>> fourSum(const std::vector<int> &nums, const int target) {
    std::vector<std::vector<int>> result;
    if (nums.size() < 4) {
        return result;
    }
    std::vector<int64_t> sorted(nums.begin(), nums.end());
    std::sort(sorted.begin(), sorted.end());
    size_t i = sorted.size() - 1;
    while (i >= 3) {
        size_t j = 0;
        int64_t tail = sorted[i];
        int64_t rest = target - tail;
        while (j < i) {
            size_t l = j + 1, r = i - 1;
            int64_t num = sorted[j];
            while (l < r) {
                int64_t left = sorted[l], right = sorted[r];
                int64_t sum = num + left + right;
                if (sum < rest) {
                    while (l < r && left == sorted[++l])
                        ;
                } else if (sum > rest) {
                    while (l < r && right == sorted[--r])
                        ;
                } else {
                    result.push_back({static_cast<int>(tail), static_cast<int>(num), static_cast<int>(left),
                                      static_cast<int>(right)});
                    while (l < r && left == sorted[++l])
                        ;
                    while (l < r && right == sorted[--r])
                        ;
                }
            }
            while (++j < i && num == sorted[j])
                ;
        }
        while (--i >= 3 && tail == sorted[i])
            ;
    }
    return result;
}

} // namespace lc0018

