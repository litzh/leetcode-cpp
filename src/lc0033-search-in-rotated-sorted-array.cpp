#include <cassert>
#include <cstddef>
#include <cstdio>
#include <vector>
namespace lc0033 {
// 1 <= nums.length <= 5000
// -1000 <= nums[i], target <= 1000
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
int search_min(const std::vector<int> &nums) {
    assert(nums.size() >= 1 && nums.size() <= 5000);
    size_t size = nums.size();
    int end = nums[size - 1];
    size_t l = 0, r = size - 1;
    size_t min = l;
    while (nums[l] > nums[r]) {
        size_t m = l + (r - l) / 2;
        assert(l < r && l <= m);
        if (m == l) {
            min = r;
            break;
        }
        if (nums[m] <= end) {
            r = m;
        } else {
            l = m;
        }
        min = l;
    }
    return min;
}

int search(const std::vector<int> &nums, int target) {
    assert(nums.size() >= 1 && nums.size() <= 5000);
    size_t size = nums.size();
    int end = nums[size - 1];
    size_t min = search_min(nums);
    size_t lower = min, upper = size - 1;
    if (target > end) {
        lower = 0, upper = min > 0 ? min - 1 : 0;
    }
    while (lower <= upper) {
        size_t mid = lower + (upper - lower) / 2;
        int num = nums[mid];
        if (num == target) {
            return static_cast<int>(mid);
        } else if (num > target) {
            if (mid == 0)
                break;
            upper = mid - 1;
        } else {
            if (mid >= size - 1)
                break;
            lower = mid + 1;
        }
    }
    return -1;
}
} // namespace lc0033

