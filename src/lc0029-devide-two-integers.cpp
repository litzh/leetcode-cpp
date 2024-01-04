#include <cassert>
#include <climits>
namespace lc0029 {
/*
 * dividend 被除数
 * divisor 除数
 * quotient 商
 * remainder 余数
 * dividend = divisor * quotient + remainder
 */

int partial_divide(int dividend, int divisor) {
    assert(divisor > 0 && dividend > 0);
    if (dividend < divisor)
        return 0;
    if (dividend == divisor)
        return 1;
    int quotient = 1;
    int product = divisor;
    while (product < dividend - product) {
        quotient <<= 1;
        product <<= 1;
    }
    return quotient + partial_divide(dividend - product, divisor);
}

int divide(int dividend, int divisor) {
    // 禁止处以 0
    assert(divisor != 0);
    // 0 除以任何数得 0
    if (dividend == 0)
        return 0;
    // 相等的数相除得 1
    if (dividend == divisor)
        return 1;
    int keep = 0;
    // 取绝对值并保留符号，需要处理 -INT_MIN 越界问题
    if (divisor == INT_MIN)
        return 0;
    int divisor_sign = divisor > 0 ? 1 : -1;
    if (divisor < 0)
        divisor = -divisor;
    int dividend_sign = dividend > 0 ? 1 : -1;
    if (dividend == INT_MIN) {
        dividend += divisor;
        assert(dividend < 0);
        keep = 1;
    }
    if (dividend < 0)
        dividend = -dividend;
    int quotient = partial_divide(dividend, divisor);
    if (divisor_sign != dividend_sign) {
        quotient = -quotient;
        quotient -= keep;
    } else if (quotient <= INT_MAX - keep) {
        quotient += keep;
    }
    return quotient;
}
} // namespace lc0029

