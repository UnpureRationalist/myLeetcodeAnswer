#include "header.h"

class Solution {
 public:
  ListNode *partition(ListNode *head, int x) {
    if (head == nullptr) {
      return head;
    }
    ListNode temp{-1, head};
    ListNode *small_pre = &temp;
    ListNode *bigger_head = nullptr;
    ListNode *bigger_pre = nullptr;
    ListNode *cur = head;
    while (cur) {
      int value = cur->val;
      if (value < x) {
        small_pre->next = cur;
        small_pre = cur;
        cur = cur->next;
      } else {
        if (bigger_head == nullptr) {
          bigger_head = cur;
          bigger_pre = bigger_head;
          cur = cur->next;
        } else {
          bigger_pre->next = cur;
          bigger_pre = cur;
          cur = cur->next;
        }
        bigger_pre->next = nullptr;
      }
    }
    small_pre->next = bigger_head;
    return temp.next;
  }
};
