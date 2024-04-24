#include "header.h"

class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};

// 递归
class Solution {
  ListNode *heler(ListNode *pre, ListNode *cur) {
    if (cur == nullptr) {
      return pre;
    }
    ListNode *next = cur->next;
    cur->next = pre;
    return heler(cur, next);
  }

 public:
  ListNode *reverseList(ListNode *head) { return heler(nullptr, head); }
};
