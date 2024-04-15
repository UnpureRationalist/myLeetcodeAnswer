#include "header.h"

class Solution {
  struct Compare {
    bool operator()(ListNode *lop, ListNode *rop) const { return lop->val > rop->val; }
  };

 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, Compare> q;
    for (auto &ptr : lists) {
      if (ptr) {
        q.push(ptr);
      }
    }
    ListNode dummy;
    ListNode *pre = &dummy;
    while (!q.empty()) {
      ListNode *cur = q.top();
      q.pop();
      pre->next = cur;
      pre = cur;
      if (cur->next) {
        q.push(cur->next);
      }
    }
    return dummy.next;
  }
};
