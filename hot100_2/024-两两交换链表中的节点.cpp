#include "ListNode.h"

class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode dummy(-1, head);
    ListNode *pre = &dummy;

    while (pre->next && pre->next->next) {
      ListNode *cur = pre->next;
      ListNode *next = pre->next->next;
      ListNode *nextNode = next->next;
      pre->next = next;
      next->next = cur;
      cur->next = nextNode;
      pre = cur;
    }

    return dummy.next;
  }
};
