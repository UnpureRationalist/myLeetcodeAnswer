#include "header.h"

class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode dummyHead(-1, nullptr);
    ListNode *pre = &dummyHead;
    while (list1 && list2) {
      if (list1->val <= list2->val) {
        pre->next = list1;
        list1 = list1->next;
      } else {
        pre->next = list2;
        list2 = list2->next;
      }
      pre = pre->next;
    }
    if (list1) {
      pre->next = list1;
    }
    if (list2) {
      pre->next = list2;
    }
    return dummyHead.next;
  }
};
