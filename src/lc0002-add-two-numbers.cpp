#include <list_node.h>

static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    while (l1 != nullptr || l2 != nullptr || carry > 0) {
        int sum = carry;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        if (sum >= 10) {
            carry = 1;
            sum %= 10;
        } else {
            carry = 0;
        }
        auto* node = new ListNode(sum);
        if (head == nullptr) {
            head = node;
        }
        if (tail != nullptr) {
            tail->next = node;
        }
        tail = node;
    }
    return head;
}

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Add Two Numbers", "[LC0002]") {
    ListNode *l1 = list_from_vector(std::vector<int>{2, 4, 3});
    ListNode *l2 = list_from_vector(std::vector<int>{5, 6, 4});
    ListNode *l3 = addTwoNumbers(l1, l2);
    REQUIRE(list_to_vector(l3) == std::vector<int>{7, 0, 8});
}

TEST_CASE("Dangling Carry", "[LC0002]") {
    ListNode *l1 = list_from_vector(std::vector<int>{9, 9, 9, 9, 9, 9, 9});
    ListNode *l2 = list_from_vector(std::vector<int>{9, 9, 9, 9});
    ListNode *l3 = addTwoNumbers(l1, l2);
    REQUIRE(list_to_vector(l3) == std::vector<int>{8, 9, 9, 9, 0, 0, 0, 1});
}
