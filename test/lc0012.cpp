#include <leetcode.h>

#include <catch2/catch_test_macros.hpp>
#include <fstream>
#include <map>

using namespace lc0012;

std::map<int, std::string> roman_map;

static void load_roman_map() {
    std::ifstream infile(TEST_RESOURCE_DIR "/roman.txt");
    int arabic;
    std::string roman;
    while (infile >> arabic >> roman) {
        roman_map.insert({arabic, roman});
    }
}

TEST_CASE("Integer to Roman", "[LC0012]") {
    load_roman_map();
    REQUIRE(roman_map.size() == 3999);
    for (const auto& [num, roman] : roman_map) {
        REQUIRE(intToRoman(num) == roman);
    }
}
