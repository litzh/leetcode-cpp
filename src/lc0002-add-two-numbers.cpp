#include <list_node.h>

namespace lc0002
{
ListNode *addTwoNumbers(const ListNode *l1, const ListNode *l2) {
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
        auto *node = new ListNode(sum);
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
}