#include "header.h"

// 使用栈
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    stack<ListNode *> stk1;
    stack<ListNode *> stk2;
    while (headA) {
      stk1.emplace(headA);
      headA = headA->next;
    }
    while (headB) {
      stk2.emplace(headB);
      headB = headB->next;
    }
    ListNode *ans = nullptr;
    while (!stk1.empty() && !stk2.empty() && stk1.top() == stk2.top()) {
      ans = stk1.top();
      stk1.pop();
      stk2.pop();
    }
    return ans;
  }
};

// 不使用额外空间
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA;
    ListNode *pb = headB;
    while (pa != pb) {
      pa = pa == nullptr ? headB : pa->next;
      pb = pb == nullptr ? headA : pb->next;
    }
    return pa;
  }
};