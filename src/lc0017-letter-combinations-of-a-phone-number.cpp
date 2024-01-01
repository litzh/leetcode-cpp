#include <cassert>
#include <string>
#include <vector>

namespace lc0017 {
const char *keyboard[] = {"abc", "def", "ghi", "jkl", "nmo", "pqrs", "tuv", "wxyz"};
const size_t key_len[] = {3, 3, 3, 3, 3, 4, 3, 4};
std::vector<std::string> letterCombinations(const std::string &digits) {
    assert(digits.size() >= 0 && digits.size() <= 4);
    if (digits.empty())
        return {};
    std::vector<std::string> result;
    size_t width = digits.size();
    size_t height = 1;
    for (size_t i = 0; i < width; ++i) {
        assert(digits[i] >= '2' && digits[i] <= '9');
        height *= key_len[digits[i] - '2'];
    }
    result.resize(height);
    for (size_t i = 0; i < height; ++i) {
        result[i].resize(width);
        size_t segment = height;
        for (size_t j = 0; j < width; ++j) {
            size_t key_offset = digits[j] - '2';
            segment /= key_len[key_offset];
            size_t offset = (i / segment) % key_len[key_offset];
            result[i][j] = keyboard[key_offset][offset];
        }
    }
    return result;
}
} // namespace lc0017

