#include <leetcode.h>
#include <catch2/catch_test_macros.hpp>

using namespace lc0002;
TEST_CASE("Add Two Numbers", "[LC0002]")
{
    ListNode* l1 = list_from_vector(std::vector{2, 4, 3});
    ListNode* l2 = list_from_vector(std::vector{5, 6, 4});
    ListNode* l3 = addTwoNumbers(l1, l2);
    REQUIRE(list_to_vector(l3) == std::vector<int>{7, 0, 8});
    list_freep(&l1);
    list_freep(&l2);
    list_freep(&l3);
}

TEST_CASE("Dangling Carry", "[LC0002]")
{
    ListNode* l1 = list_from_vector(std::vector{9, 9, 9, 9, 9, 9, 9});
    ListNode* l2 = list_from_vector(std::vector{9, 9, 9, 9});
    ListNode* l3 = addTwoNumbers(l1, l2);
    REQUIRE(list_to_vector(l3) == std::vector<int>{8, 9, 9, 9, 0, 0, 0, 1});
    list_freep(&l1);
    list_freep(&l2);
    list_freep(&l3);
}
