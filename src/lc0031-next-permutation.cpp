#include <algorithm>
#include <cassert>
#include <vector>
namespace lc0031 {
/*
 * 1. 非递减序列是最小值，非递增序列是最大值
 * 2. 查找尾部最长非递增序列 V(c, rbegin]，这一部分已经是最大值，通过内部调整无法增大
 * 3. 在 V(c, rbegin] 从右向左查找第一个大于 V[c] 的值 V[u] 并交换
 * 4. 将 V[n, end) 倒序
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 */
std::vector<int> &nextPermutation(std::vector<int> &nums) {
    assert(nums.size() >= 1 && nums.size() <= 100);
    int prev = -1;
    auto cursor = nums.rbegin();
    while (cursor != nums.rend()) {
        if (*cursor < prev)
            break;
        prev = *cursor;
        ++cursor;
    }
    if (cursor != nums.rend()) {
        auto mid = nums.rbegin();
        auto it = mid;
        // FIXME: 可以用二分查找优化
        while (true) {
            if (*it > *cursor) {
                mid = it;
                break;
            }
            ++it;
        }
        auto temp = *mid;
        *mid = *cursor;
        *cursor = temp;
    }
    std::reverse(nums.rbegin(), cursor);
    return nums;
}
} // namespace lc0031

