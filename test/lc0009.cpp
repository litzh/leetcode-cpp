#include <leetcode.h>

#include <catch2/catch_test_macros.hpp>

using namespace lc0009;
TEST_CASE("Palindrome Number", "[LC0009]") {
    REQUIRE(isPalindrome(-1) == false);
    REQUIRE(isPalindrome(0) == true);
    REQUIRE(isPalindrome(121) == true);
    REQUIRE(isPalindrome(10) == false);
}
