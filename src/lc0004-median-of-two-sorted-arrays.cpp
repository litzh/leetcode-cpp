#include <algorithm>
#include <cassert>
#include <cstddef>
#include <span>
#include <vector>
namespace lc0004 {
int findKth(std::span<const int> nums1, std::span<const int> nums2, size_t k) {
    // k 从 0 开始
    size_t step = std::min({nums1.size(), nums2.size(), (k + 1) / 2});
    while (step > 0) {
        // [0, count-1)[count-1, nums1.size)
        // [0, count-1)[count-1, nums2.size)
        if (nums1[step - 1] > nums2[step - 1]) {
            nums2 = {nums2.begin() + step, nums2.end()};
        } else {
            nums1 = {nums1.begin() + step, nums1.end()};
        }
        k -= step;
        step = std::min({nums1.size(), nums2.size(), (k + 1) / 2});
    }
    if (nums2.empty())
        return nums1[k];
    else if (nums1.empty())
        return nums2[k];
    else
        return std::min(nums1[0], nums2[0]);
}

double findMedianSortedArrays(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    assert(m <= 1000 && n <= 1000 && m + n >= 1);

    double median = 0.0;
    if ((m + n) % 2 == 1) {
        int mid = findKth(nums1, nums2, (m + n) / 2);
        median = static_cast<double>(mid);
    } else {
        int left = findKth(nums1, nums2, (m + n) / 2 - 1);
        int right = findKth(nums1, nums2, (m + n) / 2);
        median = static_cast<double>(left + right) / 2.0;
    }
    return median;
}
} // namespace lc0004

