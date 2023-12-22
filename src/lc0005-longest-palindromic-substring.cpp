#include <string>
std::string longestPalindrome(const std::string& s) {
    if (s.length() <= 1) {
        return s;
    }
    int begin = 0, end = 1;
    // 插入空格，处理偶数回文
    const int len = s.length();
    const int total = len * 2 - 1;
    for (int i = 1; i < total; ++i) {
        const int center = i / 2;
        for (int j = (i + 1) % 2; center - j >= 0 && center + i % 2 + j < len; ++j) {
            const int left = center - j;
            const int right = center + j + (i % 2);
            if (s[left] == s[right]) {
                if (right - left + 1 > end - begin) {
                    begin = left;
                    end = right + 1;
                }
            } else {
                break;
            }
        }
    }
    return s.substr(begin, end - begin);
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Longest Palindromic Substring", "[LC0005]") {
    REQUIRE(longestPalindrome("babad") == "bab");
    REQUIRE(longestPalindrome("cbbd") == "bb");
}