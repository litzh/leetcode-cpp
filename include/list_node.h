#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <vector>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode* next) : val(x), next(next) {}
};

static ListNode* list_from_vector(const std::vector<int>& vec) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (auto& val : vec) {
        if (tail == nullptr) {
            tail = new ListNode(val);
            head = tail;
        } else {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }
    return head;
}

static std::vector<int> list_to_vector(const ListNode* head) {
    std::vector<int> vec;
    while (head != nullptr) {
        vec.push_back(head->val);
        head = head->next;
    }
    return vec;
}

static void list_freep(ListNode** headp) {
    const ListNode* head = *headp;
    while (head != nullptr) {
        const ListNode* node = head;
        head = head->next;
        delete node;
    }
    *headp = nullptr;
}

#endif
