#include <cassert>
#include <climits>
#include <string>
int myAtoi(const std::string& s) {
    const int len = static_cast<int>(s.size());
    int i = 0;
    int sign = 1;
    // 跳过开头空白
    while (i < len && s[i] == ' ') ++i;
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
    assert(s[i] >= '0' && s[i] <= '9');
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

#include <catch2/catch_test_macros.hpp>

TEST_CASE("String to Integer (atoi)", "[LC0008]") {
    REQUIRE(myAtoi("+1") == 1);
    REQUIRE(myAtoi("42") == 42);
    REQUIRE(myAtoi("   -42") == -42);
    REQUIRE(myAtoi("4193 with words") == 4193);
    REQUIRE(myAtoi("words and 987") == 0);
    REQUIRE(myAtoi("-91283472332") == -2147483648);
    REQUIRE(myAtoi("-2147483648") == -2147483648);
    REQUIRE(myAtoi("91283472332") == 2147483647);
    REQUIRE(myAtoi("3.14159") == 3);
    REQUIRE(myAtoi("  -0012a42") == -12);
}
