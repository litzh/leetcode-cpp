#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode()
        : val(0)
        , next(nullptr) {}
    explicit ListNode(const int x)
        : val(x)
        , next(nullptr) {}
    ListNode(const int x, ListNode *next)
        : val(x)
        , next(next) {}
    explicit ListNode(const std::vector<int> &vec) {
        ListNode *tail = nullptr;
        for (auto &val: vec) {
            if (tail == nullptr) {
                this->val = val;
                this->next = nullptr;
                tail = this;
            } else {
                tail->next = new ListNode(val);
                tail = tail->next;
            }
        }
    }
    std::vector<int> v() const {
        ListNode const *head = this;
        std::vector<int> vec;
        while (head != nullptr) {
            vec.push_back(head->val);
            head = head->next;
        }
        return vec;
    }
};

static void list_freep(ListNode **headp) {
    const ListNode *head = *headp;
    while (head != nullptr) {
        const ListNode *node = head;
        head = head->next;
        delete node;
    }
    *headp = nullptr;
}

#endif

