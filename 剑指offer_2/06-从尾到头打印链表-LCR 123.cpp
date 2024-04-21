#include "header.h"

class Solution {
 public:
  vector<int> reverseBookList(ListNode *head) {
    vector<int> res;
    while (head) {
      res.emplace_back(head->val);
      head = head->next;
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
