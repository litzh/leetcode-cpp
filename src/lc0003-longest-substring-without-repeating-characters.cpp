#include <cstddef>
#include <string>
#include <unordered_map>

namespace lc0003
{
int lengthOfLongestSubstring(const std::string&s)
{
    if (s.empty()) {
        return 0;
    }
    std::unordered_map<char, size_t> char_pos = {{s[0], 0}};
    size_t longest = 1;
    size_t len = 1;
    size_t i = 1;
    while (i < s.length()) {
        char c = s[i];
        auto it = char_pos.find(c);
        if (it == char_pos.end()) {
            len++;
            char_pos.insert({c, i});
            if (len > longest) {
                longest = len;
            }
            ++i;
        }
        else {
            len = i - it->second;
            if (len >= longest) {
                longest = len;
                char_pos[c] = i;
                ++i;
            }
            else {
                len = 1;
                size_t next = it->second + 1;
                char_pos.clear(); // 注意迭代器失效
                char_pos.insert({s[next], next});
                i = next + 1;
            }
        }
    }
    return static_cast<int>(longest);
}
}