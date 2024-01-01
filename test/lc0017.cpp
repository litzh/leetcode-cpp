#include <catch2/catch_test_macros.hpp>
#include <literals.h>


namespace lc0017 {
std::vector<std::string> letterCombinations(const std::string &digits);
}

using namespace lc0017;

TEST_CASE("Letter Combinations of a Phone Number", "[LC0017]") {
    REQUIRE(letterCombinations("23") == R"(["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"])"_VS);
    REQUIRE(letterCombinations("") == R"([])"_VS);
    REQUIRE(letterCombinations("9") == R"(["w", "x", "y", "z"])"_VS);
    REQUIRE(letterCombinations("92") ==
            R"(["wa", "wb", "wc", "xa", "xb", "xc", "ya", "yb", "yc", "za", "zb", "zc"])"_VS);
}

