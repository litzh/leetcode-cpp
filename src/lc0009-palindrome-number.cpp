#include <cstdint>

static bool isPalindrome(const int x)
{
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

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Palindrome Number", "[LC0009]")
{
    REQUIRE(isPalindrome(-1) == false);
    REQUIRE(isPalindrome(0) == true);
    REQUIRE(isPalindrome(121) == true);
    REQUIRE(isPalindrome(10) == false);
}
