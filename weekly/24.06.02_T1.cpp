#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumChairs(string s) {
    stack<char> stk;
    size_t ans = 0;
    for (const auto &c : s) {
      if (c == 'E') {
        stk.push('E');
      } else {
        stk.pop();
      }
      ans = max(ans, stk.size());
    }
    return ans;
  }
};
