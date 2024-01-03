#include <cassert>
#include <list_node.h>

namespace lc0024 {
/*
 * prev->a->b->next
 * prev->b->a->next
 */
ListNode *swapPairsAux(ListNode *prev, ListNode *a, ListNode *b, ListNode *next) {
    assert(a != nullptr);
    if (b == nullptr)
        return a;
    if (prev != nullptr)
        prev->next = b;
    b->next = a;
    if (next == nullptr) {
        a->next = nullptr;
    } else {
        a->next = swapPairsAux(a, next, next->next, next->next == nullptr ? nullptr : next->next->next);
    }
    return b;
}

ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    return swapPairsAux(nullptr, head, head->next, head->next->next);
}
} // namespace lc0024

