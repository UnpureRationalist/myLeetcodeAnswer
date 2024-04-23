#include "header.h"

class Solution {
 public:
  void deleteNode(ListNode *node) {
    ListNode *next = node->next;
    node->val = next->val;
    node->next = next->next;
    delete next;
  }
};

// 相关题：Leetcode 203. 移除链表元素
class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode dummyHead(0, head);
    ListNode *pre = &dummyHead;
    ListNode *cur = head;
    while (cur) {
      ListNode *next = cur->next;
      if (cur->val == val) {
        pre->next = next;
        cur = next;
      } else {
        pre = cur;
        cur = next;
      }
    }
    return dummyHead.next;
  }
};
