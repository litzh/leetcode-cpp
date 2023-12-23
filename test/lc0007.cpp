#include <leetcode.h>
#include <catch2/catch_test_macros.hpp>

using namespace lc0007;
TEST_CASE("Reverse Integer", "[LC0007]")
{
    REQUIRE(reverse(123) == 321);
    REQUIRE(reverse(-123) == -321);
    REQUIRE(reverse(120) == 21);
    REQUIRE(reverse(2147483647) == 0);
    REQUIRE(reverse(2143847412) == 2147483412);
    REQUIRE(reverse(-2147483648) == 0);
    REQUIRE(reverse(-2143847412) == -2147483412);
    REQUIRE(reverse(1463847412) == 2147483641);
}
