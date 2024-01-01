#include <algorithm>
#include <cstdlib>
#include <vector>
namespace lc0016 {
int threeSumClosest(const std::vector<int> &nums, int target) {
    std::vector<int> sorted(nums);
    std::sort(sorted.begin(), sorted.end());
    int min_diff = 100000;
    size_t i = 0;
    for (size_t i = 0; i < sorted.size(); ++i) {
        size_t l = i + 1, r = sorted.size() - 1;
        while (l < r) {
            int sum = sorted[i] + sorted[l] + sorted[r];
            int diff = target - sum;
            if (std::abs(diff) < std::abs(min_diff)) {
                min_diff = diff;
            }
            if (sum < target) {
                ++l;
            } else if (sum > target) {
                --r;
            } else {
                return target;
            }
        }
    }
    return target - min_diff;
}
} // namespace lc0016

