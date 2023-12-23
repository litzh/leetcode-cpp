#include <leetcode.h>

#include <catch2/catch_test_macros.hpp>

using namespace lc0005;
TEST_CASE("Longest Palindromic Substring", "[LC0005]") {
    REQUIRE(longestPalindrome("").empty());
    REQUIRE(longestPalindrome("a") == "a");
    REQUIRE(longestPalindrome("babad") == "bab");
    REQUIRE(longestPalindrome("cbbd") == "bb");
}
