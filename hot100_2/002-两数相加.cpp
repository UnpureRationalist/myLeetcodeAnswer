#include "ListNode.h"

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    ListNode *head = &dummy;

    int pre = 0;
    while (l1 || l2) {
      int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + pre;
      pre = sum / 10;
      sum = sum % 10;
      head->next = new ListNode(sum);
      head = head->next;
      l1 = l1 ? l1->next : l1;
      l2 = l2 ? l2->next : l2;
    }

    if (pre) {
      head->next = new ListNode(pre);
    }

    return dummy.next;
  }
};
