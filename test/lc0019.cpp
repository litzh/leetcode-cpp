#include <catch2/catch_test_macros.hpp>
#include <list_node.h>
#include <literals.h>

namespace lc0019 {
ListNode *removeNthFromEnd(ListNode *head, int n);
}


using namespace lc0019;

TEST_CASE("Remove Nth Node From End of List", "[LC0019]") {
    ListNode *list = new ListNode("[1,2,3,4,5]"_VI);
    REQUIRE(removeNthFromEnd(list, 2)->v() == "[1,2,3,5]"_VI);
    list_freep(&list);

    list = new ListNode("[1]"_VI);
    REQUIRE(removeNthFromEnd(list, 1)->v() == "[]"_VI);
    list_freep(&list);

    list = new ListNode("[1,2]"_VI);
    REQUIRE(removeNthFromEnd(list, 1)->v() == "[1]"_VI);
    list_freep(&list);
}

