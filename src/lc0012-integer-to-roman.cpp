#include <cassert>
#include <string>

namespace lc0012 {
// Symbol       Value
// I             1
// IV            4
// V             5
// IX            9
// X             10
// XL            40
// L             50
// XC            90
// C             100
// CD            400
// D             500
// CM            900
// M             1000
// 1 <= num <= 3999
std::string intToRoman(int num) {
    const struct {
        int val;
        const char* token;
    } tokens[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"},
    };
    // I to MMMCMXCIX
    assert(num >= 1 && num <= 3999);
    std::string roman;
    for (const auto [val, token] : tokens) {
        while (num >= val) {
            roman.append(token);
            num -= val;
        }
    }
    return roman;
}
}  // namespace lc0012
