#include <catch2/catch_test_macros.hpp>
#include <fstream>
#include <literals.h>

namespace lc0022 {
std::vector<std::string> generateParenthesis(int n);
} // namespace lc0022

using namespace lc0022;

std::map<int, std::string> parentheses_map;

static void load_parentheses_map() {
    std::ifstream infile(TEST_RESOURCE_DIR "/parentheses-1-8.txt");
    int i = 0;
    std::string line;
    while (std::getline(infile, line)) {
        parentheses_map.insert({i, line});
        i++;
    }
}

TEST_CASE("Generate Parentheses", "[LC002]") {
    load_parentheses_map();
    for (int i = 1; i <= 8; ++i) {
        const std::string &line = parentheses_map[i];
        REQUIRE(str(generateParenthesis(i)) == operator""_S(line.c_str(), line.size()));
    }
}

