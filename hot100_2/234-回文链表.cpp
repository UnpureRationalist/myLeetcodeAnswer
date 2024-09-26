#include "ListNode.h"

class Solution {
  ListNode *firstHalfEnd(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }

 public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr) {
      return true;
    }
    ListNode *first_half_end = firstHalfEnd(head);
    ListNode *second_half_start = reverseList(first_half_end->next);

    ListNode *p1 = head;
    ListNode *p2 = second_half_start;
    bool result = true;
    while (p2) {
      if (p1->val != p2->val) {
        result = false;
        break;
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    first_half_end->next = reverseList(second_half_start);
    return result;
  }
};
