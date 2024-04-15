#include "header.h"

class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      char c = s[i];
      if (c == '(' || c == '[' || c == '{') {
        stk.push(c);
      } else {
        if (stk.empty()) {
          return false;
        }
        char left = stk.top();
        stk.pop();
        switch (c) {
          case ')':
            if (left != '(') {
              return false;
            }
            break;
          case ']':
            if (left != '[') {
              return false;
            }
            break;
          case '}':
            if (left != '{') {
              return false;
            }
            break;
        }
      }
    }
    return stk.empty();
  }
};
