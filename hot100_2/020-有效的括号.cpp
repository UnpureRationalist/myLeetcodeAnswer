#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    int n = s.length();
    stack<char> stk;
    for (int i = 0; i < n; ++i) {
      char c = s[i];
      if (c == '(' || c == '[' || c == '{') {
        stk.push(c);
        continue;
      }
      if (stk.empty()) {
        return false;
      }
      char top = stk.top();
      stk.pop();
      if (c == ')' && top == '(' || c == ']' && top == '[' || c == '}' && top == '{') {
        continue;
      }
      return false;
    }
    return stk.empty();
  }
};
