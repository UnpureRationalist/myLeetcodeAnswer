struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *nex) : val(x), next(nex) {}
};

class Solution {
 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode node{0, head};
    ListNode *slow = &node;
    ListNode *slow_pre = &node;
    ListNode *fast = &node;
    int step = 0;
    while (fast) {
      if (step < n) {
        step++;
        fast = fast->next;
      } else {
        slow_pre = slow;
        slow = slow->next;
        fast = fast->next;
      }
    }
    // do delete
    slow_pre->next = slow->next;
    return node.next;
  }
};