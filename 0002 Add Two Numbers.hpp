/*
  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

  You may assume the two numbers do not contain any leading zero, except the number 0 itself.

  Example

  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
  Output: 7 -> 0 -> 8
  Explanation: 342 + 465 = 807.
*/
#include <cstdlib>

// 这种全局执行函数，纯粹是为了刷排名
static auto _______ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers (ListNode* l1, ListNode* l2) {
        ListNode stackAnchor(0);
        ListNode *tail = &stackAnchor;
        div_t sum = {0, 0};
        while (sum.quot > 0 || l1 || l2) {
            if (l1) {
                sum.quot += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum.quot += l2->val;
                l2 = l2->next;
            }
            sum = div(sum.quot, 10);
            tail->next = new ListNode(sum.rem);
            tail = tail->next;
        }
        return stackAnchor.next;
    }
};

/*
  引入一个 C 标准库函数
  #include <cstdlib>
  div_t div(int number, int denom)

  描述
  C 库函数 div_t div(int numer, int denom) 把 numer（分子）除以 denom（分母）。

  声明
  下面是 div() 函数的声明。
  div_t div(int numer, int denom)

  参数
  numer -- 分子。
  denom -- 分母。

  返回值
  该函数返回定义在 <cstdlib> 中的结构中的值，该结构有两个成员，如 div_t:int quot; int rem;。
*/
