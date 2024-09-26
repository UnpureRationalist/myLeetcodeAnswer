#include <queue>
#include <vector>
#include "ListNode.h"
using namespace std;

class Solution {
  struct Compare {
    bool operator()(ListNode *lop, ListNode *rop) const { return lop->val > rop->val; }
  };

 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode dummy(-1);
    ListNode *pre = &dummy;
    priority_queue<ListNode *, vector<ListNode *>, Compare> q;
    for (const auto &head : lists) {
      if (head) {
        q.emplace(head);
      }
    }
    while (!q.empty()) {
      ListNode *cur = q.top();
      q.pop();
      pre->next = cur;
      pre = pre->next;
      if (cur->next) {
        q.emplace(cur->next);
      }
    }
    return dummy.next;
  }
};
