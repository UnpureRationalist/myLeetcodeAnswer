#include "ListNode.h"

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
