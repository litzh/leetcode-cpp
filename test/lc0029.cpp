#include <literals.h>

#include <catch2/catch_test_macros.hpp>

namespace lc0029 {
int divide(int dividend, int divisor);
}

using namespace lc0029;
TEST_CASE("Divide Two Integers", "[LC0029]") {
    REQUIRE(divide(0, 1) == 0);
    REQUIRE(divide(1, 1) == 1);
    REQUIRE(divide(10, 3) == 3);
    REQUIRE(divide(-10, 3) == -3);
    REQUIRE(divide(-10, -3) == 3);
    REQUIRE(divide(7, -3) == -2);
    REQUIRE(divide(-2147483647, 1073741824) == -1);
    REQUIRE(divide(-2147483648, 1073741824) == -2);
    REQUIRE(divide(2147483647, -1073741824) == -1);
    REQUIRE(divide(-2147483648, 2147483647) == -1);
    REQUIRE(divide(-2147483647, -2147483648) == 0);
    REQUIRE(divide(-2147483648, -1) == 2147483647);
    REQUIRE(divide(-2147483648, 1) == -2147483648);
}

