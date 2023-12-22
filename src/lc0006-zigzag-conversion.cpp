#include <string>

static std::string convert(const std::string& s, const int numRows) {
    const int len = static_cast<int>(s.size());
    if (numRows == 1 || len <= 1) {
        return s;
    }
    std::string result;
    for (int row = 0; row < numRows; ++row) {
        int n = 0;
        while (true) {
            const int cur = (numRows - 1) * 2 * n + row;
            const int prev = cur - row * 2;
            if (prev < len) {
                if (prev >= 0 && prev != cur &&
                    cur - prev != (numRows - 1) * 2) {
                    result.push_back(s[prev]);
                }
            }
            if (cur < len) {
                result.push_back(s[cur]);
            } else {
                break;
            }
            ++n;
        }
    }
    return result;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Zigzag Conversion", "[LC0006]") {
    REQUIRE(convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    REQUIRE(convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    REQUIRE(convert("A", 1) == "A");
}
