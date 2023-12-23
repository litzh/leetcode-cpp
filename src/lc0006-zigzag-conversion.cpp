#include <string>

namespace lc0006
{
std::string convert(const std::string& s, const int numRows) {
    const int len = static_cast<int>(s.size());
    if (numRows == 1 || len <= 1) {
        return s;
    }
    std::string result;
    for (int row = 0; row < numRows; ++row) {
        int n = 0;
        while (true) {
            const int cur = (numRows - 1) * 2 * n + row;
            if (const int prev = cur - row * 2; prev < len) {
                if (prev >= 0 && prev != cur &&
                    cur - prev != (numRows - 1) * 2) {
                    result.push_back(s[prev]);
                    }
            }
            if (cur < len) {
                result.push_back(s[cur]);
            } else {
                break;
            }
            ++n;
        }
    }
    return result;
}
}