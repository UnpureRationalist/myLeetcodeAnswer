#include <utility>
#include "ListNode.h"
using namespace std;

class Solution {
  pair<ListNode *, ListNode *> reverse(ListNode *begin, ListNode *end) {
    ListNode *over = end->next;
    ListNode *pre = begin;
    ListNode *cur = begin->next;
    while (cur != over) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    begin->next = nullptr;
    return {pre, begin};
  }

 public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1) {
      return head;
    }
    ListNode temp{-1, head};
    ListNode *pre = &temp;
    ListNode *cur = head;
    while (cur) {
      ListNode *begin = cur;
      int num = k;
      while (cur && --num) {
        cur = cur->next;
      }
      if (cur) {
        // 对 [begin, cur] 做翻转
        ListNode *next = cur->next;
        auto res = reverse(begin, cur);
        pre->next = res.first;
        pre = res.second;
        cur = next;
      } else {
        pre->next = begin;
      }
    }
    return temp.next;
  }
};
