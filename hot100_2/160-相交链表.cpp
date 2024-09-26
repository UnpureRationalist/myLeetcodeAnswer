#include "ListNode.h"

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
