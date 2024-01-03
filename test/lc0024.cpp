#include <catch2/catch_test_macros.hpp>
#include <list_node.h>
#include <literals.h>

namespace lc0024 {
ListNode *swapPairs(ListNode *head);
}
using namespace lc0024;
TEST_CASE("Swap Nodes in Pairs", "[LC0024]") {
    ListNode *list = new ListNode("[1, 2, 3, 4]"_VI);
    ListNode *result = swapPairs(list);
    REQUIRE(result->v() == "[2, 1, 4, 3]"_VI);
    list_freep(&result);

    result = swapPairs(nullptr);
    REQUIRE(result == nullptr);

    list = new ListNode("[1]"_VI);
    result = swapPairs(list);
    REQUIRE(result->v() == "[1]"_VI);
    list_freep(&result);

    list = new ListNode("[1, 2, 3]"_VI);
    result = swapPairs(list);
    REQUIRE(result->v() == "[2, 1, 3]"_VI);
    list_freep(&result);
}

