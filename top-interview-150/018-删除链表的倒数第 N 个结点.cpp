#include "header.h"

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode temp{-1, head};
    ListNode *fast = &temp;
    while (n--) {
      fast = fast->next;
    }
    ListNode *slow = &temp;
    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    // do delete
    slow->next = slow->next->next;
    return temp.next;
  }
};
