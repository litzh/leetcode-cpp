#include <catch2/catch_test_macros.hpp>
#include <string>

namespace lc0003 {
extern int lengthOfLongestSubstring(const std::string &s);
}
using namespace lc0003;
TEST_CASE("Longest Substring Without Repeating Characters", "[LC0003]") {
    REQUIRE(lengthOfLongestSubstring("") == 0);
    REQUIRE(lengthOfLongestSubstring("abcabcbb") == 3);
    REQUIRE(lengthOfLongestSubstring("bbbbb") == 1);
    REQUIRE(lengthOfLongestSubstring("pwwkew") == 3);
    REQUIRE(lengthOfLongestSubstring("vqblqcb") == 4);
    REQUIRE(lengthOfLongestSubstring("ohvhjdml") == 6);
}

