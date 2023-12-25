#include <climits>
#include <string>

namespace lc0008 {
int myAtoi(const std::string &s) {
    const int len = static_cast<int>(s.size());
    int i = 0;
    int sign = 1;
    // 跳过开头空白
    while (i < len && s[i] == ' ')
        ++i;
    // 处理正负号
    if (i < len) {
        if (s[i] == '-') {
            ++i;
            sign = -1;
        } else if (s[i] == '+') {
            ++i;
        }
    }
    // 非数字开头，返回0
    if (i >= len || s[i] < '0' || s[i] > '9') {
        return 0;
    }
    // 读取连续的数字
    int n = 0;
    while (i < len && s[i] >= '0' && s[i] <= '9') {
        if ((INT_MAX - s[i] + '0') / 10 < n) {
            if (sign > 0)
                return INT_MAX;
            return INT_MIN;
        }
        n *= 10;
        n += s[i] - '0';
        ++i;
    }
    return n * sign;
}
} // namespace lc0008

