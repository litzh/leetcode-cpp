#include <cstdint>

namespace lc0009 {
bool isPalindrome(const int x) {
    if (x < 0) {
        return false;
    }
    int64_t xx = x;
    int64_t rev = 0;
    while (xx) {
        rev *= 10;
        rev += xx % 10;
        xx /= 10;
    }
    return x == rev;
}
} // namespace lc0009

