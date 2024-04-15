#include "header.h"

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode temp{-1, nullptr};
    ListNode *pre = &temp;
    ListNode *cur = head;
    while (cur) {
      int value = cur->val;
      ListNode *backup = cur;
      while (cur && cur->val == value) {
        cur = cur->next;
      }
      if (backup->next == cur) {
        // 当前值不重复
        pre->next = backup;
        pre = backup;
        pre->next = nullptr;
      }
    }
    return temp.next;
  }
};
