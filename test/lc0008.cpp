#include <leetcode.h>
#include <catch2/catch_test_macros.hpp>

using namespace lc0008;
TEST_CASE("String to Integer (atoi)", "[LC0008]")
{
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
