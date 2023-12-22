#include <limits.h>
static int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
            return 0;
        }
        rev *= 10;
        rev += x % 10;
        x /= 10;
    }
    return rev;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Reverse Integer", "[LC0007]") {
    REQUIRE(reverse(123) == 321);
    REQUIRE(reverse(-123) == -321);
    REQUIRE(reverse(120) == 21);
    REQUIRE(reverse(2147483647) == 0);
    REQUIRE(reverse(2143847412) == 2147483412);
    REQUIRE(reverse(-2147483648) == 0);
    REQUIRE(reverse(-2143847412) == -2147483412);
    REQUIRE(reverse(1463847412) == 2147483641);
}
