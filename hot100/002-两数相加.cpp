struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *nex) : val(x), next(nex) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int pre_sum = 0;
    ListNode node;
    ListNode *head = &node;
    while (l1 && l2) {
      int sum = l1->val + l2->val + pre_sum;
      int val = sum % 10;
      pre_sum = sum / 10;
      ListNode *cur = new ListNode(val, nullptr);
      head->next = cur;
      head = head->next;
      l1 = l1->next;
      l2 = l2->next;
    }
    while (l1) {
      int sum = l1->val + pre_sum;
      int val = sum % 10;
      pre_sum = sum / 10;
      ListNode *cur = new ListNode(val, nullptr);
      head->next = cur;
      head = head->next;
      l1 = l1->next;
    }
    while (l2) {
      int sum = l2->val + pre_sum;
      int val = sum % 10;
      pre_sum = sum / 10;
      ListNode *cur = new ListNode(val, nullptr);
      head->next = cur;
      head = head->next;
      l2 = l2->next;
    }
    if (pre_sum != 0) {
      head->next = new ListNode(pre_sum, nullptr);
    }
    return node.next;
  }
};