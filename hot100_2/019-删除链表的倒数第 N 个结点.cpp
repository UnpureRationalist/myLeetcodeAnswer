#include "ListNode.h"

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *pre = &dummy;
    while (n--) {
      head = head->next;
    }
    while (head) {
      pre = pre->next;
      head = head->next;
    }
    pre->next = pre->next->next;
    return dummy.next;
  }
};
