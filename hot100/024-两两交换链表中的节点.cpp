struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *nex) : val(x), next(nex) {}
};

class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    ListNode node{0, head};
    ListNode *pre_pair = &node;
    // do swap pairs
    ListNode *p = head;
    while (p && p->next) {
      ListNode *pre = p, *post = p->next;
      ListNode *next = post->next;
      // do swap
      post->next = pre;
      pre_pair->next = post;
      pre->next = next;
      pre_pair = pre;
      p = next;
    }
    return node.next;
  }
};