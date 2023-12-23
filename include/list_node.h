#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__
#include <vector>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

static inline ListNode* list_from_vector(const std::vector<int> vec) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (auto& val : vec) {
        if (head == nullptr) {
            head = new ListNode(val);
            tail = head;
        } else {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }
    return head;
}

static inline std::vector<int> list_to_vector(ListNode* head) {
    std::vector<int> vec;
    while (head != nullptr) {
        vec.push_back(head->val);
        head = head->next;
    }
    return vec;
}

static inline void list_freep(ListNode** headp) {
    ListNode* head = *headp;
    while (head != nullptr) {
        ListNode* node = head;
        head = head->next;
        delete node;
    }
    *headp = nullptr;
}

#endif
