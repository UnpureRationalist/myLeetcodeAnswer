struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *nex) : val(x), next(nex) {}
};

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