#include <cassert>
#include <list_node.h>
namespace lc0019 {
ListNode *removeNthFromEnd(ListNode *head, int n) {
    assert(n >= 1);
    assert(head != nullptr);
    ListNode *right = head;
    while (n > 0) {
        assert(right != nullptr);
        n--;
        right = right->next;
    }
    ListNode *left = nullptr;
    while (right != nullptr) {
        if (left == nullptr)
            left = head;
        else
            left = left->next;
        assert(left != nullptr);
        right = right->next;
    }
    if (left == nullptr) {
        return head->next;
    } else {
        ListNode *node = left->next;
        assert(node != nullptr);
        left->next = node->next;
        delete node;
    }
    return head;
}
} // namespace lc0019

