#include "header.h"

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {       // 快慢指针相遇，说明链表有环
        while (head != slow) {  // 寻找环的入口
          head = head->next;
          slow = slow->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
