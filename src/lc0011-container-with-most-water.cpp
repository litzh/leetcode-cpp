#include <algorithm>
#include <cstddef>
#include <vector>

namespace lc0011 {
int maxArea(const std::vector<int>& height) {
    size_t left = 0;
    size_t right = height.size() - 1;
    int max_area = 0;
    while (left < right) {
        int lh = height[left];
        int rh = height[right];
        const int h = std::min(lh, rh);
        const int w = static_cast<int>(right - left);
        max_area = std::max(max_area, h * w);
        if (lh <= rh)
            while (left < right && height[left] <= lh) ++left;
        else
            while (right > left && height[right] <= rh) --right;
    }
    return max_area;
}
}  // namespace lc0011
