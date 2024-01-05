#include <cstddef>
#include <vector>
namespace lc0033 {
// 1 <= nums.length <= 5000
// -1000 <= nums[i], target <= 1000
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
int search(const std::vector<int> &nums, int target) {
    // [i+1,i+2,...,n][0,1,...,i]
    // 查找 n 的位置
    size_t size = nums.size();
    size_t mid = size / 2;
    return target;
}
} // namespace lc0033

