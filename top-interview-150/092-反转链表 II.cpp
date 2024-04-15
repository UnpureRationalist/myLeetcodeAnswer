#include "header.h"

class Solution {
  ListNode *reverse(ListNode *head, int num) {
    ListNode *cur = head->next;
    ListNode *pre = head;
    while (cur && num--) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    head->next = cur;
    return pre;
  }

 public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left >= right || head == nullptr || head->next == nullptr) {
      return head;
    }
    int num = right - left;
    ListNode temp{0, head};
    ListNode *pre = &temp;
    while (pre && --left) {
      pre = pre->next;
    }
    pre->next = reverse(pre->next, num);
    return temp.next;
  }
};
