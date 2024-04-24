#include "header.h"

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummyHead(-1, head);
    ListNode *pre = &dummyHead;
    ListNode *fast = head;
    while (n--) {
      fast = fast->next;
    }
    ListNode *slow = head;
    while (fast) {
      pre = pre->next;
      slow = slow->next;
      fast = fast->next;
    }
    pre->next = slow->next;
    delete slow;
    return dummyHead.next;
  }
};
