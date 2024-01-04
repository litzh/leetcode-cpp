#include <algorithm>
#include <vector>
namespace lc0031 {
// n 个元素构成序列 N
// {A[N]} 是序列 N 的全排列，其中结果按照字典序升序排列
// A(n) 的 nextPermutation 是 A((n+1)%N)
// 2413
// 2431
// 3124
// 3142
// 3214
std::vector<int> &nextPermutation(std::vector<int> &nums) {
    std::next_permutation(nums.begin(), nums.end());
    return nums;
}
} // namespace lc0031

