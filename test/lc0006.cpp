#include <catch2/catch_test_macros.hpp>

namespace lc0006 {
extern std::string convert(const std::string &s, int numRows);
}
using namespace lc0006;
TEST_CASE("Zigzag Conversion", "[LC0006]") {
    REQUIRE(convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    REQUIRE(convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    REQUIRE(convert("A", 1) == "A");
    REQUIRE(convert("", 2).empty());
}

