#include <algorithm>
#include <cstddef>
#include <set>
#include <unordered_map>
#include <vector>
namespace lc0015 {

std::vector<std::vector<int>> threeSum(const std::vector<int> &nums) {
    std::vector<int> sorted(nums);
    std::sort(sorted.begin(), sorted.end());
    std::vector<std::vector<int>> result;
    size_t i = 0;
    while (i < sorted.size()) {
        size_t l = i + 1, r = sorted.size() - 1;
        int num = sorted[i];
        while (l < r) {
            int left = sorted[l], right = sorted[r];
            int sum = num + left + right;
            if (sum < 0) {
                while (l < r && left == sorted[++l])
                    ;
            } else if (sum > 0) {
                while (l < r && right == sorted[--r])
                    ;
            } else {
                result.push_back({num, left, right});
                while (l < r && left == sorted[++l])
                    ;
                while (l < r && right == sorted[--r])
                    ;
            }
        }
        while (++i < sorted.size() && num == sorted[i])
            ;
    }
    return result;
}

std::vector<std::vector<int>> threeSumCount(const std::vector<int> &nums) {
    std::unordered_map<int, int> num_count;
    for (const auto &i: nums) {
        if (num_count.find(i) != num_count.end())
            num_count[i]++;
        else
            num_count.insert({i, 1});
    }
    std::set<std::vector<int>> result;
    for (auto &[num, count]: num_count) {
        for (const auto &[n, c]: num_count) {
            int target = -(num + n);
            if (target == num && target == n && count < 3)
                continue;
            if (target == num && count < 2)
                continue;
            if ((n == num || n == target) && c < 2)
                continue;
            if (c < 1)
                continue;
            if (const auto it = num_count.find(target); it != num_count.end()) {
                std::vector record{num, n, it->first};
                std::sort(record.begin(), record.end());
                result.insert(record);
            }
        }
        num_count[num] = 0;
    }
    return std::vector<std::vector<int>>{result.begin(), result.end()};
}
} // namespace lc0015

