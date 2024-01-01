#include <catch2/catch_test_macros.hpp>
#include <list_node.h>
#include <literals.h>

namespace lc0002 {
extern ListNode *addTwoNumbers(const ListNode *l1, const ListNode *l2);
}
using namespace lc0002;
TEST_CASE("Add Two Numbers", "[LC0002]") {
    ListNode *l1 = new ListNode("[2, 4, 3]"_VI);
    ListNode *l2 = new ListNode("[5, 6, 4]"_VI);
    ListNode *l3 = addTwoNumbers(l1, l2);
    REQUIRE(l3->v() == "[7, 0, 8]"_VI);
    list_freep(&l1);
    list_freep(&l2);
    list_freep(&l3);
}

TEST_CASE("Dangling Carry", "[LC0002]") {
    ListNode *l1 = new ListNode("[9, 9, 9, 9, 9, 9, 9]"_VI);
    ListNode *l2 = new ListNode("[9, 9, 9, 9]"_VI);
    ListNode *l3 = addTwoNumbers(l1, l2);
    REQUIRE(l3->v() == "[8, 9, 9, 9, 0, 0, 0, 1]"_VI);
    list_freep(&l1);
    list_freep(&l2);
    list_freep(&l3);

    l1 = new ListNode("[9, 9, 9, 9]"_VI);
    l2 = new ListNode("[9, 9, 9, 9, 9, 9, 9]"_VI);
    l3 = addTwoNumbers(l1, l2);
    REQUIRE(l3->v() == "[8, 9, 9, 9, 0, 0, 0, 1]"_VI);
    list_freep(&l1);
    list_freep(&l2);
    list_freep(&l3);
}

