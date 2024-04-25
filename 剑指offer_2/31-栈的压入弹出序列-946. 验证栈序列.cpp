#include "header.h"

class Solution {
 public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    int n = popped.size();
    int push_idx = 0;
    int pop_idx = 0;
    stack<int> stk;
    while (pop_idx < n) {
      int pop_num = popped[pop_idx];
      if (stk.empty() || stk.top() != pop_num) {
        while (push_idx < n && pushed[push_idx] != pop_num) {
          stk.emplace(pushed[push_idx]);
          ++push_idx;
        }
        if (push_idx == n) {
          return false;
        }
        // pushed[push_idx] = popped[pos_idx]
        ++push_idx;
      } else {
        stk.pop();
      }
      ++pop_idx;
    }
    return true;
  }
};
