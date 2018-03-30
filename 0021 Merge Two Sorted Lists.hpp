/*
  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

  Example:

  Input: 1->2->4, 1->3->4
  Output: 1->1->2->3->4->4
*/
#include <iostream>

// 这种全局执行函数，纯粹是为了刷排名
static auto _______ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
