#include "header.h"

class Solution {
  pair<int, ListNode *> getLength(ListNode *head) {
    int n = 0;
    ListNode *pre = nullptr;
    while (head) {
      ++n;
      pre = head;
      head = head->next;
    }
    return {n, pre};
  }

 public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr) {
      return head;
    }
    auto res = getLength(head);
    int n = res.first;
    ListNode *last = res.second;
    k = k % n;
    if (k == 0) {
      return head;
    }
    int num = n - k;
    ListNode *cur = head;
    while (--num) {
      cur = cur->next;
    }
    ListNode *ans = cur->next;
    cur->next = nullptr;
    last->next = head;
    return ans;
  }
};
