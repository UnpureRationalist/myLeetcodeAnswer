#include "header.h"

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int pre = 0;
    ListNode temp;
    ListNode *head = &temp;

    while (l1 && l2) {
      int sum = l1->val + l2->val + pre;
      head->next = new ListNode(sum % 10);
      pre = sum / 10;
      l1 = l1->next;
      l2 = l2->next;
      head = head->next;
    }

    while (l1) {
      int sum = l1->val + pre;
      head->next = new ListNode(sum % 10);
      pre = sum / 10;
      l1 = l1->next;
      head = head->next;
    }

    while (l2) {
      int sum = l2->val + pre;
      head->next = new ListNode(sum % 10);
      pre = sum / 10;
      l2 = l2->next;
      head = head->next;
    }

    if (pre) {
      head->next = new ListNode(pre);
    }

    return temp.next;
  }
};
