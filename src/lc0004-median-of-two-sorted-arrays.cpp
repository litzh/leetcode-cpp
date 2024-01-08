#include <algorithm>
#include <cassert>
#include <cstddef>
#include <span>
#include <vector>
namespace lc0004 {
// 有序数列 A[0...N) 的中位数定义:
// 1. N 为奇数: A[(N+1)/2]
// 2. N 为偶数: avg(A[N/2]+A[N/2+1])
// 中位数基于序号，A 中包含重复元素时算法不变
int findKth(std::span<const int> nums1, std::span<const int> nums2, size_t k) {
    // 注意 k 从 1 开始
    while (true) {
        assert(nums1.size() + nums2.size() >= k);
        if (nums1.empty())
            return nums2[k - 1];
        else if (nums2.empty())
            return nums1[k - 1];
        else if (k == 1) {
            return std::min(nums1[0], nums2[0]);
        }
        size_t half = std::min({nums1.size(), nums2.size(), k / 2});
        assert(k >= half);
        k -= half;
        if (nums1[half - 1] > nums2[half - 1]) {
            nums2 = {nums2.begin() + half, nums2.end()};
        } else {
            nums1 = {nums1.begin() + half, nums1.end()};
        }
    }
}

double findMedianSortedArrays(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    assert(m <= 1000 && n <= 1000 && m + n >= 1);

    double median = 0.0;
    if ((m + n) % 2 == 1) {
        int mid = findKth(nums1, nums2, (m + n + 1) / 2);
        median = static_cast<double>(mid);
    } else {
        int left = findKth(nums1, nums2, (m + n) / 2);
        int right = findKth(nums1, nums2, (m + n) / 2 + 1);
        median = static_cast<double>(left + right) / 2.0;
    }
    return median;
}
} // namespace lc0004

