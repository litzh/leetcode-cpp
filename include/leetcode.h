#ifndef LEETCODE_H
#define LEETCODE_H
#include <list_node.h>

#include <string>
#include <vector>

namespace lc0001 {
extern std::vector<int> twoSum(const std::vector<int>& nums, int target);
}

namespace lc0002 {
extern ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2);
}

namespace lc0003 {
extern int lengthOfLongestSubstring(const std::string& s);
}

namespace lc0005 {
extern std::string longestPalindrome(const std::string& s);
}

namespace lc0006 {
extern std::string convert(const std::string& s, int numRows);
}

namespace lc0007 {
extern int reverse(int x);
}

namespace lc0008 {
extern int myAtoi(const std::string& s);
}

namespace lc0009 {
extern bool isPalindrome(int x);
}

#endif  // LEETCODE_H
